
namespace detail {

// -----------------------------------------------------------------------------
// Enumerators
// -----------------------------------------------------------------------------

// PrecisionContext
enum class PrecisionContext {
   metadata, // for GNDStk metadata values
   data,     // for "body text", a.k.a. XML "plain character data"
   general   // for both of the above together
};

// PrecisionType
enum class PrecisionType {
   // use formatting that's available through C++ input and output streams
   stream,
   // use GNDStk's ability to use to_chars()/from_chars() if SFINAE detects
   // that they're available in std:: with the C++ distro that's being used
   fixed,
   scientific,
   shortest
};



// -----------------------------------------------------------------------------
// Classes behind GNDStk's own floating-point manipulators
// These match with our three custom PrecisionType values
// -----------------------------------------------------------------------------

class Fixed { };
class Scientific { };
class Shortest { };



// -----------------------------------------------------------------------------
// Precision class
// -----------------------------------------------------------------------------

/*
------------------------
DISCUSSION
------------------------

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
class contain a std::ostringstream, the properties of which can be set in
the usual way: by calling << on the Precision object, which will pass on
its arguments to the std::ostringstream.

However, for the fun and profit of our users, we wish to provide something
extra. Sufficiently recent C++-17 enabled compilers provide the to_chars()
set of functions, with "round trip guarantees" for decimal representations
of floating-point numbers, as well as the ability to produce the *shortest*
such representation. The round-trip guarantee essentially means that if we
start with, say, a double-precision number (at the time of this writing,
probably 64 bits in memory), use to_chars() to make a string, and then read
the string with from_chars(), then we're guaranteed to recover exactly the
same 64 bits in memory - that is, precisely the same double we began with.
Along with the "shortest representation" requirement, we can write shortest-
possible decimal representations, with *no* loss of information.

Aside: the guarantee requires that from_chars(), not necessarily any string-
to-floating-point process, be used on the string produced by to_chars().
Also, obviously, such a requirement might be broken if different compilers,
computing platforms, or floating-point sizes are used for to_chars() versus
from_chars(). Under those circumstances, no algorithm in the universe could
make the guarantee.

The above discussion speaks in term of output: operator<<, std::ostringstream,
etc. Note that our Precision class, below, handles *input* just as fully.
*/



// -----------------------------------------------------------------------------
// Precision<CONTEXT,REAL>
// Set properties for: in the given context, the given floating-point type.
// -----------------------------------------------------------------------------

template<PrecisionContext CONTEXT, class REAL>
class Precision {

   // The following hold properties that can be set by using operator<< and
   // operator>>. The properties might or might not be used when writing or
   // reading floating-point numbers, depending on the *type flags below.
   static std::ostringstream oss;
   static std::istringstream iss;

   // The value of the following determines whether the above *stringstreams
   // will be used when writing or reading floating-point numbers, or whether
   // to_chars() and from_chars() will be used instead.
   static PrecisionType otype;
   static PrecisionType itype;

   // ------------------------
   // Helpers for write()
   // ------------------------

   // The first takes a final int parameter, and has SFINAE to ensure that
   // the necessary to_chars() functions are available. The second takes a
   // final double parameter, and has no SFINAE. A call to this helper sends
   // 0 as a final parameter. So, int is preferred but the SFINAE must pass.
   // If it doesn't, 0 converts to double and the second version is called.
   // Thus the final parameter helps with overloading; its value isn't used.

#ifdef GNDSTK_PRECISION
   // OK, apparently it may be impossible to make the SFINAE work as intended
   // in the event that the std::chars_format enum class doesn't even exist,
   // so that the token [chars_format] (which is used in both the SFINAE and
   // in the function body itself) doesn't even make sense to the compiler.
   // Perhaps we can find a way around this. For now, given that we don't want
   // to_chars() and from_chars() to be GNDStk's default at this time, we'll
   // use an #ifdef to remove this code altogether unless someone wants it.

   template<
      class T,
      class = std::enable_if_t<std::is_same_v<
         decltype(std::to_chars(
            (char*)0, (char*)0, T{})),
         std::to_chars_result
      >>,
      class = std::enable_if_t<std::is_same_v<
         decltype(std::to_chars(
            (char*)0, (char*)0, T{}, std::chars_format::fixed)),
         std::to_chars_result
      >>
   >
   bool write(const T &value, std::string &str, int)
   {
      // todo: Use a T-dependent sufficient size
      std::string chars(100,'\0');

      // todo: check to_chars' return value
      if (otype == PrecisionType::fixed)
         std::to_chars(chars.data(), chars.data() + chars.size(), value,
                       std::chars_format::fixed);
      else if (otype == PrecisionType::scientific)
         std::to_chars(chars.data(), chars.data() + chars.size(), value,
                       std::chars_format::scientific);
      else
         std::to_chars(chars.data(), chars.data() + chars.size(), value);

      str = chars.data(); // ensure output std::string stops at \0
      return true;
   }
#endif

   template<class T>
   bool write(const T &, std::string &, double)
   {
      // tell the caller that floating-point to_chars() isn't available
      return false;
   }

   // ------------------------
   // Helpers for read()
   // ------------------------

   // We use a trailing return type so that we can write value, not T{}, in the
   // SFINAE test call. Using T{}, as we did in write(), but here for the (NON-
   // const &) from_chars() parameter, would in normal circumstances be a C++
   // error (rvalue passed to non-const lvalue reference). Here, the attempt to
   // do so would make the SFINAE fail always, defeating its purpose.

   template<class T>
   auto read(const std::string &str, T &value, int) ->
      std::enable_if_t<
         std::is_same_v<
            decltype(std::from_chars((char*)0, (char*)0, value)),
            std::from_chars_result
         >,
         bool
      >
   {
      // Provide a clean slate for from_chars(), which skips white space
      // but doesn't like '+'. So we'll skip the white space, AND any '+'.
      const char *first = str.data();
      while (isspace(*first))
         first++;
      if (*first == '+')
         first++;

      std::from_chars(first, str.data() + str.size(), value);
      return true;
   }

   template<class T>
   bool read(const std::string &, T &, double)
   {
      // tell the caller that floating-point from_chars() isn't available
      return false;
   }

public:

   // ------------------------
   // write
   // ------------------------

   std::string write(const REAL &value)
   {
      if (otype != PrecisionType::stream) {
         // Use std::to_chars() for REAL, if it exists;
         // else fall through and use the ostringstream
         std::string str;
         if (write(value,str,0))
            return str;
      }

      // Use the ostringstream
      oss.str("");
      oss.clear();
      oss << value;
      return oss.str();
   }

   // ------------------------
   // read
   // ------------------------

   REAL read(const std::string &str)
   {
      REAL value = REAL(0);

      if (itype != PrecisionType::stream) {
         // Use std::from_chars() for REAL, if it exists;
         // else fall through and use the istringstream
         if (read(str,value,0))
            return value;
      }

      // Use the istringstream
      iss.str(str);
      iss.clear();
      iss >> value;
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
      otype = PrecisionType::stream;
      oss << manip;
      return *this;
   }

   // operator>>
   template<class MANIP>
   Precision &operator>>(const MANIP &manip)
   {
      itype = PrecisionType::stream;
      iss >> manip;
      return *this;
   }

   // ------------------------
   // For special GNDStk
   // manipulators...
   // ------------------------

   // When you use the below specializations of operator<< and operator>>, i.e.
   // the ones for GNDStk's special PrecisionType options, this bool (which is
   // public, so that you can set it) says whether using a special manipulator
   // for input should automatically use it for output; and vice versa. Our
   // special manipulators cause std::to_chars() and std::from_chars() to be
   // used, if they're available. std::to_chars() and std::from_chars() are
   // designed to be ideal when uses with each other (although they don't need
   // to be used together); so, it makes sense that we'd want to "tie" their
   // use together, at least by default.
   bool tie = true;

   // ------------------------
   // operator<<
   // ------------------------

   Precision &operator<<(const Fixed &)
   {
      otype = PrecisionType::fixed;
      if (tie) itype = otype;
      return *this;
   }

   Precision &operator<<(const Scientific &)
   {
      otype = PrecisionType::scientific;
      if (tie) itype = otype;
      return *this;
   }

   Precision &operator<<(const Shortest &)
   {
      otype = PrecisionType::shortest;
      if (tie) itype = otype;
      return *this;
   }

   // ------------------------
   // operator>>
   // ------------------------

   Precision &operator>>(const Fixed &)
   {
      itype = PrecisionType::fixed;
      if (tie) otype = itype;
      return *this;
   }

   Precision &operator>>(const Scientific &)
   {
      itype = PrecisionType::scientific;
      if (tie) otype = itype;
      return *this;
   }

   Precision &operator>>(const Shortest &)
   {
      itype = PrecisionType::shortest;
      if (tie) otype = itype;
      return *this;
   }
};



// -----------------------------------------------------------------------------
// static initialization
// -----------------------------------------------------------------------------

template<PrecisionContext CONTEXT, class REAL>
std::ostringstream Precision<CONTEXT,REAL>::oss;

template<PrecisionContext CONTEXT, class REAL>
std::istringstream Precision<CONTEXT,REAL>::iss;

// The following two initializations arrange for GNDStk to use standard stream
// capabilities when it writes and reads floating-point numbers. We don't
// default to GNDStk's special std::to_chars()- and std::from_chars()-based
// capabilities because, even though a case could be made for preferring them,
// std::to_chars() and std::from_chars() aren't widely supported at the time
// of this writing, and require late-model compilers that not all users might
// have. So, you must *ask* for GNDStk's special capabilities if you want them.

template<PrecisionContext CONTEXT, class REAL>
PrecisionType Precision<CONTEXT,REAL>::otype = PrecisionType::stream;

template<PrecisionContext CONTEXT, class REAL>
PrecisionType Precision<CONTEXT,REAL>::itype = PrecisionType::stream;



// -----------------------------------------------------------------------------
// Precision<CONTEXT,void>
// Set properties for: in the given context, float, double, and long double.
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
// Set properties for: in metadata and data, the given floating-point type.
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
// Set properties for: in metadata and data, float, double, and long double.
// Note that this disambiguates Precision's partial specializations.
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
