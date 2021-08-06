
namespace detail {

// -----------------------------------------------------------------------------
// Enumerators
// -----------------------------------------------------------------------------

// PrecisionContext
enum class PrecisionContext {
   metadata, // for GNDStk metadata values
   data,     // for "body text", a.k.a. XML "plain character data"
   general   // one-stop shop to set the formatting for both of the above
};

// PrecisionType
enum class PrecisionType {
   // use formatting available through C++ output stream manipulators...
   none,

   // use std::to_chars()...
   fixed,
   scientific,
   shortest
};



// -----------------------------------------------------------------------------
// Classes for GNDStk's own floating-point manipulators
// These align with our three custom PrecisionType values
// -----------------------------------------------------------------------------

class Fixed { };
class Scientific { };
class Shortest { };



// -----------------------------------------------------------------------------
// Precision class
// -----------------------------------------------------------------------------

/*
DISCUSSION

The goal that underlies the current code is as follows. Somewhere, we have
a floating-point number (a float, a double, or a long double), and we wish
to produce a decimal representation of that number.

What we plan to *do* with the decimal representation isn't relevant here.
Perhaps we'll write it to std::cout, or to some other output stream. Perhaps
we don't wish to do anything with it stream-wise, but instead plan to place
it into a GNDStk Tree. Here, now, we're concerned only with the process of
producing a decimal representation of the number.

Naturally, for the decimal representation, we'll use a std::string.

So: given a floating-point number, we want to produce a string. We already
know that C++ provides more than one way to do this. A basic and reasonably
flexible way is to begin with an output string stream (a std::ostringstream),
use its operator<< to write the floating-point number, and then call the
std::ostringstream's str() function to get the std::string. Prior to <<-ing
the number, we could set up properties we want, such as precision, by using
I/O manipulators. For example, oss << std::setprecision(10) << thenumber,
where oss is the std::ostringstream.

GNDStk provides that methodology. To do so, objects of the below Precision
class contain a std::ostringstream, oss, the properties of which can be set
in the usual way (call << on the Precision object; it passes them on to oss.)

However, for the fun and profit of our users, we wish to provide something
extra. Sufficiently recent C++-17 enabled compilers provide the to_chars()
set of functions, with "round trip guarantees" for decimal representations
of floating-point numbers, as well as the ability to produce the *shortest*
such representation. The round-trip guarantee essentially means that if we
start with, say, a double-precision number (at the time of this writing,
probably 64 bits in memory), use to_chars() to make a string, and then read
the string with from_chars(), then we're guaranteed to recover exactly the
same 64 bits in memory; that is, precisely the same double we began with.
Along with the "shortest representation" requirement, we can write shortest-
possible decimal representations, with *no* loss of information.

Aside: the guarantee requires that from_chars(), not necessarily any string-
to-floating-point process, be used on the string produced by to_chars().
Also, obviously, such a requirement might be broken if different compilers,
computing platforms, or floating-point sizes are used for to_chars() versus
from_chars(). Under those circumstances, no algorithm in the universe could
make the guarantee.

todo Write more details, and provide some examples. Discuss how *input* is
involved, and the relationship between input and output that someone should
understand when using this system.
*/



// -----------------------------------------------------------------------------
// Precision<CONTEXT,REAL>
// In the given context: the given floating-point type
// -----------------------------------------------------------------------------

template<PrecisionContext CONTEXT, class REAL>
class Precision {

   // The purpose of the following std::ostringstream is to "store" I/O
   // properties that someone might set by using manipulators. Those properties
   // might be used by write(), depending on the "otype" flag below.
   static std::ostringstream oss;

   // Similar, but for input
   static std::istringstream iss;

   // The value of the following determines whether oss (above) will be used
   // by write() to create a string, or whether write() will use to_chars().
   static PrecisionType otype;

   // for input
   static PrecisionType itype;

public:

   // todo Needs comment
   bool tie = false;

   // write
   std::string write(const REAL &value)
   {
      if (otype == PrecisionType::none) {
         oss.str("");
         oss.clear();
         oss << value; // uses properties in oss
         return oss.str();
      }

      // todo: Perhaps use a REAL-dependent sufficient size, not just 100 :-/
      std::string chars(100,'\0');

      if (otype == PrecisionType::fixed)
         std::to_chars(chars.data(), chars.data()+chars.size(), value,
                       std::chars_format::fixed);
      else if (otype == PrecisionType::scientific)
         std::to_chars(chars.data(), chars.data()+chars.size(), value,
                       std::chars_format::scientific);
      else
         std::to_chars(chars.data(), chars.data()+chars.size(), value);

      return chars.data(); // ensure output std::string stops at \0
   }

   // read
   REAL read(const std::string &str)
   {
      REAL value;

      if (itype == PrecisionType::none) {
         iss.str(str);
         iss.clear();
         iss >> value; // uses properties in iss
         return value;
      }

      // Provide a clean slate for from_chars(), which skips white space but
      // doesn't like '+'. So, we'll skip the white space, and then any '+'.
      const char *first = str.data();
      while (isspace(*first))
         first++;
      if (*first == '+')
         first++;

      std::from_chars(first, str.data()+str.size(), value);
      return value;
   }

   // ------------------------
   // For C++ I/O stream
   // manipulators
   // ------------------------

   // operator<<
   // Relays the general C++ manipulator to the std::ostringstream.
   // Important: with this (detail::) class, use write(), above, for creating
   // a string with a decimal representation of a floating-point number. Such
   // a string might be used with your own output stream somewhere, or perhaps
   // used for some other purpose for which you'd use such a string. Here, we
   // presume that the argument is a stream manipulator of some sort. If it's
   // something that would print - a number, say - then that's not what this
   // function is about. See the discussion earlier in this file.
   template<class MANIP>
   Precision &operator<<(const MANIP &manip)
   {
      otype = PrecisionType::none;
      oss << manip;
      return *this;
   }

   // operator>>
   template<class MANIP>
   Precision &operator>>(const MANIP &manip)
   {
      itype = PrecisionType::none;
      iss >> manip;
      return *this;
   }

   // ------------------------
   // For special GNDStk
   // manipulators
   // ------------------------

   // operator<<
   // According to the given GNDStk manipulator, arranges for write()
   // to use GNDStk's formatting capabilities.
   Precision &operator<<(const Fixed &)
   {
      otype = PrecisionType::fixed;
      if (tie) itype = PrecisionType::fixed;
      return *this;
   }

   Precision &operator<<(const Scientific &)
   {
      otype = PrecisionType::scientific;
      if (tie) itype = PrecisionType::fixed;
      return *this;
   }

   Precision &operator<<(const Shortest &)
   {
      otype = PrecisionType::shortest;
      if (tie) itype = PrecisionType::fixed;
      return *this;
   }

   // operator>>
   Precision &operator>>(const Fixed &)
   {
      itype = PrecisionType::fixed;
      if (tie) otype = PrecisionType::fixed;
      return *this;
   }

   Precision &operator>>(const Scientific &)
   {
      itype = PrecisionType::scientific;
      if (tie) otype = PrecisionType::fixed;
      return *this;
   }

   Precision &operator>>(const Shortest &)
   {
      itype = PrecisionType::shortest;
      if (tie) otype = PrecisionType::fixed;
      return *this;
   }
};

template<PrecisionContext CONTEXT, class REAL>
std::ostringstream Precision<CONTEXT,REAL>::oss;

template<PrecisionContext CONTEXT, class REAL>
std::istringstream Precision<CONTEXT,REAL>::iss;

template<PrecisionContext CONTEXT, class REAL>
PrecisionType Precision<CONTEXT,REAL>::otype = PrecisionType::shortest;

template<PrecisionContext CONTEXT, class REAL>
PrecisionType Precision<CONTEXT,REAL>::itype = PrecisionType::shortest;



// -----------------------------------------------------------------------------
// Precision<CONTEXT,void>
// In the given context: float, double, and long double
// -----------------------------------------------------------------------------

template<PrecisionContext CONTEXT>
class Precision<CONTEXT,void> {
public:
   // operator<<
   template<class MANIP>
   Precision &operator<<(const MANIP &manip)
   {
      Precision<CONTEXT, float      >{} << manip;
      Precision<CONTEXT, double     >{} << manip;
      Precision<CONTEXT, long double>{} << manip;
      return *this;
   }

   // operator>>
   template<class MANIP>
   Precision &operator>>(const MANIP &manip)
   {
      Precision<CONTEXT, float      >{} >> manip;
      Precision<CONTEXT, double     >{} >> manip;
      Precision<CONTEXT, long double>{} >> manip;
      return *this;
   }
};



// -----------------------------------------------------------------------------
// Precision<general,REAL>
// In metadata and data: the given floating-point type
// -----------------------------------------------------------------------------

template<class REAL>
class Precision<PrecisionContext::general,REAL> {
public:
   // operator<<
   template<class MANIP>
   Precision &operator<<(const MANIP &manip)
   {
      Precision<PrecisionContext::metadata, REAL>{} << manip;
      Precision<PrecisionContext::data,     REAL>{} << manip;
      return *this;
   }

   // operator>>
   template<class MANIP>
   Precision &operator>>(const MANIP &manip)
   {
      Precision<PrecisionContext::metadata, REAL>{} >> manip;
      Precision<PrecisionContext::data,     REAL>{} >> manip;
      return *this;
   }
};



// -----------------------------------------------------------------------------
// Precision<general,void>
// In metadata and data: float, double, and long double
// And, this disambiguates Precision's partial specializations
// -----------------------------------------------------------------------------

template<>
class Precision<PrecisionContext::general,void> {
public:
   // operator<<
   template<class MANIP>
   Precision &operator<<(const MANIP &manip)
   {
      Precision<PrecisionContext::metadata, void>{} << manip;
      Precision<PrecisionContext::data,     void>{} << manip;
      return *this;
   }

   // operator>>
   template<class MANIP>
   Precision &operator>>(const MANIP &manip)
   {
      Precision<PrecisionContext::metadata, void>{} >> manip;
      Precision<PrecisionContext::data,     void>{} >> manip;
      return *this;
   }
};

} // namespace detail
