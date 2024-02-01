
// -----------------------------------------------------------------------------
// chars
// -----------------------------------------------------------------------------

// Remark. <charconv> is supposed to have:
//    enum class chars_format {
//       scientific = ...,
//       fixed = ...,
//       hex = ...,
//       general = fixed | scientific
//    };
// At the time of this writing, g++ appears to have it, but clang++ does not.

template<class = SIMPLE_JSON_FLOATING>
class chars {
   std::string str;

   // SIZE here is overkill, but should certainly be adequate
   static inline const size_t SIZE = 1000;
   static inline char buf[SIZE];

public:

   // ------------------------
   // Construction
   // ------------------------

   // default
   chars() { }

   // from float, double, or long double
   template<
      class T,
      class = std::enable_if_t<
         detail::isfloating<T> && detail::invar<T,number::variant>
      >
   >
   chars(
      const T &from,
      const std::chars_format format = std::chars_format::general
   ) :
      str(buf, std::to_chars(buf,buf+SIZE,from,format).ptr - buf)
   { }

   // ------------------------
   // Conversion
   // ------------------------

   // to std::string
   operator const std::string &() const { return str; }
   operator std::string &() { return str; }

   // to literal
   operator literal() const
   {
      return literal(str);
   }
};
