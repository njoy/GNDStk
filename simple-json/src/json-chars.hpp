
// -----------------------------------------------------------------------------
// chars
// -----------------------------------------------------------------------------

class chars {
   std::string str;

   // SIZE here is overkill, but should be adequate
   static inline constexpr size_t SIZE = 100;
   static inline char buffer[SIZE];

public:

   // ------------------------
   // Construction
   // ------------------------

   // default
   chars() { }

   // from any T in number::variant
   template<class T, class = require<invar<T,number::variant>>>
   chars(
      #ifdef JSON_CHARS
         const T &from, const std::chars_format &format = json::format
      #else
         const T &from
      #endif
   ) {
      std::to_chars_result res;

      if constexpr (integral<T>)
         res = same<T,unsigned char>
             ? std::to_chars(buffer, buffer+SIZE, (unsigned short)from)
             : same<T,  signed char>
             ? std::to_chars(buffer, buffer+SIZE, (  signed short)from)
             : std::to_chars(buffer, buffer+SIZE, from);
      else {
         #ifdef JSON_CHARS
            res = std::to_chars(buffer, buffer+SIZE, from, format);
         #else
            assert(false);
         #endif
      }

      if (res.ec == std::errc()) // std::errc() == default => no error
         str = (*res.ptr = '\0', buffer);
      else
         error("Error returned by std::to_chars(). Message is:\n" +
                std::make_error_code(res.ec).message() + '.');
   }

   // ------------------------
   // Conversion
   // ------------------------

   // to std::string
   operator const std::string &() const { return str; }
   operator std::string &() { return str; }

   // to literal (whose construction from std::string is explicit)
   operator literal() const
   {
      return literal(str);
   }
};
