
#ifndef NJOY_GNDSTK_ENUMS_ENCODING
#define NJOY_GNDSTK_ENUMS_ENCODING

namespace enums {

   /**
    *  @class
    *  @brief Enumeration class giving acceptable encoding values
    *
    *  See GNDS v1.9 specifications section 3.5.3
    */
   enum class Encoding {
      ascii = 1,
      utf8 = 2
   };

   /**
    *  @brief Return whether or not a string is a valid encoding
    *
    *  @param[in] string    the string to be verified
    *
    *  @return true/false
    */
   inline bool isEncoding(const std::string &string)
   {
      return isSymbol<Encoding>(string);
   }

   /**
    *  @brief Template specialisation to convert Encoding to/from strings
    */
   template<>
   struct Map<Encoding>
   {
      static inline const std::map<Encoding,std::string> values {
         { Encoding::ascii, "ascii" },
         { Encoding::utf8, "utf8" }
      };

      static inline const std::map<std::string,Encoding> symbols {
         { "ascii", Encoding::ascii },
         { "utf8", Encoding::utf8 }
      };
   };

} // namespace enums

#endif
