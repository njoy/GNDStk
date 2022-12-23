
namespace detail {

// -----------------------------------------------------------------------------
// Enumerators
// -----------------------------------------------------------------------------

// PrecisionContext
enum class PrecisionContext {
   metadata, // for GNDStk metadata values
   data,     // for block data, a.k.a. XML "plain character data"
   general   // for both of the above
};

// PrecisionType
enum class PrecisionType {
   // Use formatting that's available through C++ input and output streams.
   stream,

   // For input, prefer using strtof(), strtod(), and strtold() (for float,
   // double, and long double, respectively) over using an input stream. Our
   // experience suggests that these are faster for reading big data vectors.
   strto,

   // Use GNDStk's ability to use to_chars()/from_chars(), if conditional
   // compilation and SFINAE indicate that they're available in std:: with
   // the C++ distro that's being used.
   fixed,
   scientific,
   shortest
};


// -----------------------------------------------------------------------------
// Classes behind GNDStk's own floating-point manipulators.
// These match with our to/from_chars()-related PrecisionType values.
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
it into a GNDStk Node in some form. Here, now, we're concerned only with the
process of producing a decimal representation of the number.

Naturally, for the decimal representation, we'll use a std::string.

So: given a floating-point number, we wish to produce a string. We already
know that C++ provides more than one way to do this. A basic and reasonably
flexible way is to begin with an output string stream (a std::ostringstream),
use its operator<< to write the floating-point number, and then call the
std::ostringstream's str() function to get the std::string. Prior to <<-ing
the number, we could set up properties we want, such as precision, by using
I/O manipulators. For example, oss << std::setprecision(10) << thenumber,
where oss is the std::ostringstream.

GNDStk provides that methodology. To do so, objects of the below Precision
class contain a std::ostringstream, the properties of which can be set by
calling << on the Precision object. Precision's operator<< passes on its
arguments to the std::ostringstream, where those arguments are "stored," so
to speak, in the std::ostringstream, to be used when the std::ostringstream
is used for writing a floating-point number.

However, for the fun and profit of our users, we wish to provide something
extra. Sufficiently recent C++-17 enabled compilers provide the to_chars()
set of functions, with "round trip guarantees" for decimal representations
of floating-point numbers, as well as the ability to produce the *shortest*
such representation. The round-trip guarantee essentially means that if we
start with, say, a double-precision number (at the time of this writing,
probably 64 bits in memory), use to_chars() to make a string, and then read
the string with from_chars(), then we're guaranteed to recover exactly the
same 64 bits in memory - precisely the same double we began with.

Aside: the guarantee requires that from_chars(), not necessarily any string-
to-floating-point process, be used to read from a string that was earlier
produced by to_chars(). Also, obviously, such a guarantee simply cannot be
honored if different compilers, computing platforms, or floating-point sizes
are used for to_chars() versus from_chars(). Under those circumstances, no
algorithm in the universe could make the "round-trip" guarantee.

The above discussion speaks in terms of output: operator<<, std::ostringstream,
etc. Our Precision class, below, handles *input* in the analogous manner.
*/


// -----------------------------------------------------------------------------
// Precision<CONTEXT,REAL>
// Set properties for: in the given context, the given floating-point type.
// -----------------------------------------------------------------------------

template<PrecisionContext CONTEXT, class REAL>
class Precision {

   // The following hold properties that can be set by using operator<< and
   // operator>>. The properties might or might not be used when writing or
   // reading floating-point numbers; that depends on the *type flags below.
   static std::ostringstream oss;
   static std::istringstream iss;

   // The value of the following determines whether the above *stringstreams
   // will be used when writing or reading floating-point numbers, or whether
   // to_chars() and from_chars() will be used instead, or perhaps (for input)
   // whether the strto*() family of functions are used.
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
   // to_chars() and from_chars() to be GNDStk's default at this time (they're
   // slower, and they require a later-model compiler than our users may have),
   // we'll use an #ifdef to remove this code unless someone asks for it.

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
   bool write(const T &value, std::string &str, int) const
   {
      // todo: compute a T-dependent sufficient size
      std::string chars(100,'\0');

      // todo: check to_chars' return value
      if (otype == PrecisionType::fixed) {
         // fixed
         std::to_chars(chars.data(), chars.data() + chars.size(), value,
                       std::chars_format::fixed);
      } else if (otype == PrecisionType::scientific) {
         // scientific
         std::to_chars(chars.data(), chars.data() + chars.size(), value,
                       std::chars_format::scientific);
      } else {
         // shortest
         std::to_chars(chars.data(), chars.data() + chars.size(), value);
      }

      str = chars.data(); // ensure output std::string stops at the first \0
      return true;
   }
#endif

   template<class T>
   bool write(const T &, std::string &, double) const
   {
      // Tell the caller that floating-point to_chars() isn't available.
      // In this case the "write to string" didn't happen here, and MUST
      // instead be done by the caller.
      return false;
   }

   // ------------------------
   // Helpers for read()
   // ------------------------

   // We use a trailing return type so that we can write value, not T{}, in the
   // SFINAE test call. Using T{}, as we did in write(), but here for the (NON-
   // const &) from_chars() parameter, would in normal circumstances be a C++
   // error (rvalue passed to non-const lvalue reference). Here, the attempt to
   // do so would instead make the SFINAE fail always, defeating its purpose.

#ifdef GNDSTK_PRECISION
   template<class T>
   auto read(const std::string &str, T &value, int) const ->
      std::enable_if_t<
         std::is_same_v<
            decltype(std::from_chars((char*)0, (char*)0, value)),
            std::from_chars_result
         >,
         bool
      >
   {
      // Provide a clean slate for from_chars(), which skips white space
      // but doesn't like '+'. So we'll skip the white space ourselves,
      // and then skip any '+' as well.
      const char *first = str.data();
      while (isspace(*first))
         first++;
      if (*first == '+')
         first++;

      std::from_chars(first, str.data() + str.size(), value);
      return true;
   }
#endif

   template<class T>
   bool read(const std::string &, T &, double) const
   {
      // Tell the caller that floating-point from_chars() isn't available.
      // In this case the "read from string" didn't happen here, and MUST
      // instead be done by the caller.
      return false;
   }

public:

   // ------------------------
   // write single value
   // ------------------------

   // The value's std::string representation is returned
   std::string write(const REAL &value) const
   {
      // N.B.: the two code blocks below can't be reordered,
      // because of the potential fall-through.

      // CASE: fixed, scientific, shortest
      if (
         otype == PrecisionType::fixed ||
         otype == PrecisionType::scientific ||
         otype == PrecisionType::shortest
      ) {
         // Use std::to_chars(), if it exists for REAL;
         // otherwise, FALL THROUGH and use the ostringstream.
         std::string str;
         if (write(value,str,0))
            return str;
      }

      // CASE: strto, stream
      // Use the ostringstream. Note that here, in write(), the PrecisionType::
      // strto case arrives here - in the PrecisionType::stream case - because
      // strto does something special only for *input*. See the read()s, below.
      oss.clear();  // <== clear any existing error flags
      oss.str("");  // <== clear any previously printed value
      oss << value; // with whatever properties oss happens to have right now
      return oss.str();
   }

   // ------------------------
   // read single value
   // ------------------------

   // The value (as obtained from the std::string) is returned
   REAL read(const std::string &str) const
   {
      // CASE: strto
      // One would probably use the strto*() functions for speed, relative
      // to the other options. In that spirit, check for this case first.
      if (itype == PrecisionType::strto) {
         if constexpr (std::is_same_v<REAL,float>)
            return strtof (str.data(), nullptr);
         if constexpr (std::is_same_v<REAL,double>)
            return strtod (str.data(), nullptr);
         if constexpr (std::is_same_v<REAL,long double>)
            return strtold(str.data(), nullptr);
      }

      REAL value;

      // CASE: fixed, scientific, shortest
      if (
         itype == PrecisionType::fixed ||
         itype == PrecisionType::scientific ||
         itype == PrecisionType::shortest
      ) {
         // Use std::from_chars(), if it exists for REAL;
         // otherwise, FALL THROUGH and use the istringstream.
         if (read(str,value,0))
            return value;
      }

      // CASE: stream
      // Use the istringstream
      iss.clear();  // <== clear any existing error flags
      iss.str(str); // <== set str as the brand-new input string
      iss >> value; // with whatever properties iss happens to have right now
      return value;
   }

   // ------------------------
   // read vector of values:
   // private OpenMP version
   // ------------------------

private:

#ifdef _OPENMP
   bool readOpenMP(const std::string &str, std::vector<REAL> &vec) const
   {
      // Number of threads.
      // If there's just *one* thread, then we certainly won't bother with the
      // overhead of using OpenMP. Instead, we'll return to the serial read().
      const int nthreads = detail::get_nthreads();
      if (nthreads == 1)
         return false;

      // String size.
      const std::size_t size = str.size();

      // Assume, as a approximation that probably isn't too terrible, that the
      // printed floating-point numbers in the input string average around some
      // number nchars of characters in length, including separating whitespace.
      // Compute a rough estimate of how many floating-points are in the string.
      // If that value is less than some minimum threshold, then don't deal with
      // OpenMP's overhead, and instead return to the serial read().
      // todo: It might be worth factoring float vs. double vs. long double into
      // this computation. It also might be worth considering the actual number
      // of threads, as computed above - and possibly, in borderline situations,
      // reducing the number of threads but still using more than just one.
      static const std::size_t NCHARS = 10, MINFLOATS = 200;
      if (size/NCHARS < MINFLOATS)
         return false;

      // Compute an approximate splitting of the input string into substrings,
      // each to be handled by a different thread.
      std::vector<const char *> loc;
      loc.reserve(nthreads+1);
      for (int t = 0; t < nthreads; ++t)
         loc.push_back(&str[t*(size/nthreads)]);
      loc.push_back(&str[size]); // simplifies some logic below

      // Refine the approximate splitting so that borders occur at whitespace.
      for (int t = 1; t < nthreads; ++t) {
         while (loc[t-1] < loc[t] && !isspace(*(loc[t]  ))) loc[t]--;
         while (loc[t-1] < loc[t] &&  isspace(*(loc[t]-1))) loc[t]--;
      }

      // Set number of threads
      detail::set_nthreads(nthreads);
      std::vector<std::vector<REAL>> subvec(nthreads);

      // CASE: strto
      if (itype == PrecisionType::strto) {
         if constexpr (std::is_floating_point_v<REAL>) {
            #pragma omp parallel
            {
               const int t = detail::this_thread();
               char *end = (char *)loc[t];
               REAL element;

               for (const char *begin = end; end < loc[t+1]; begin = end+1) {
                  if constexpr (std::is_same_v<REAL,float>)
                     if (element = strtof (begin,&end), end <= begin) break;
                  if constexpr (std::is_same_v<REAL,double>)
                     if (element = strtod (begin,&end), end <= begin) break;
                  if constexpr (std::is_same_v<REAL,long double>)
                     if (element = strtold(begin,&end), end <= begin) break;
                  subvec[t].push_back(element);
               }
            }

            // Splice the per-thread vectors; then we're done
            std::size_t total = vec.size(); // vec wasn't necessarily cleared
            for (int t = 0; t < nthreads; ++t)
               total += subvec[t].size();
            vec.reserve(total);
            for (int t = 0; t < nthreads; ++t)
               vec.insert(vec.end(), subvec[t].begin(), subvec[t].end());
            return true;
         }
         // Fall through...
      }

      // todo Implement parallel support for other than PrecisionType::strto
      return false;
   }
   #endif // #ifdef _OPENMP

public:

   // ------------------------
   // read vector of values
   // ------------------------

   // Values obtained from the std::string parameter
   // are read into the std::vector parameter
   void read(
      const std::string &str,
      std::vector<REAL> &vec, const bool clear = true
   ) const {
      // Clear the vector, unless the caller has indicated otherwise.
      if (clear)
         vec.clear();

      // If the string is empty, there's nothing more to do.
      if (str.size() == 0)
         return;

      // If OpenMP is available, AND circumstances are such that the
      // readOpenMP() function actually does the reading, then we're
      // done in this function. Else, continue and do the read below.
      #ifdef _OPENMP
      if (readOpenMP(str,vec))
         return;
      #endif

      REAL element;

      // CASE: strto
      if (itype == PrecisionType::strto) {
         // Otherwise, we'll need to fall through to other cases, and in fact
         // we wouldn't want to enter the below do-loop...
         if constexpr (std::is_floating_point_v<REAL>) {
            const char *begin = str.data();
            char *end;

            do {
               if constexpr (std::is_same_v<REAL,float>)
                  element = strtof (begin,&end);
               if constexpr (std::is_same_v<REAL,double>)
                  element = strtod (begin,&end);
               if constexpr (std::is_same_v<REAL,long double>)
                  element = strtold(begin,&end);
               if (end == begin) break;
               vec.push_back(element);
               begin = end+1;
            } while (*end);
            return; // done
         }
         // Fall through...
      }

      // CASE: fixed, scientific, shortest
      if (
         itype == PrecisionType::fixed ||
         itype == PrecisionType::scientific ||
         itype == PrecisionType::shortest
      ) {
         // The following amounts to a test of whether std::from_chars()
         // exists for REAL. We proceed here if and only if it does; and
         // otherwise fall through to the stream case.
         if (read("1",element,0)) {
            std::istringstream i(str);
            std::string tmpstr;
            while (i >> tmpstr)
               vec.push_back(read(tmpstr,element,0));
         }
         // Fall through...
      }

      // CASE: stream
      // Use the istringstream
      iss.clear();  // <== clear any existing error flags
      iss.str(str); // <== set str as the brand-new input string
      while (iss >> element)
         vec.push_back(element);
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
   // manipulators
   // ------------------------

   // When you use the below specializations of operator<< and operator>>, i.e.
   // the ones for GNDStk's special PrecisionType options, this bool (which is
   // public, so that you can set it) says whether using a special manipulator
   // for input should automatically use it for output; and vice versa. Our
   // special manipulators cause std::to_chars() and std::from_chars() to be
   // used, if they're available. std::to_chars() and std::from_chars() are
   // designed to be ideal when used with each other (although they don't NEED
   // to be used together). Therefore, it makes sense that we'd want to "tie"
   // their use together, at least by default.
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
// Static initialization
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
PrecisionType Precision<CONTEXT,REAL>::itype = PrecisionType::strto;


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
