
#ifndef NJOY_GNDSTK_ENUMS_LENGTH
#define NJOY_GNDSTK_ENUMS_LENGTH

namespace enums {

   /**
    *  @class
    *  @brief Enumeration class giving acceptable units for length
    */
   enum class Length {
      m,
      cm,
      fm
   };

   /**
    *  @brief Return whether or not a string is a valid energy unit
    *
    *  @param[in] string    the string to be verified
    *
    *  @return true/false
    */
   inline bool isLengthUnit(const std::string &string)
   {
      return isSymbol<Length>(string);
   }

   /**
    *  @brief Template specialisation to convert Length to/from strings
    */
   template<>
   struct Map<Length> {
      static inline const map2string<Length> values {
         { Length::m, "m" },
         { Length::cm, "cm" },
         { Length::fm, "fm" }
      };
      static inline const auto symbols = reverseMap(values);
   };

} // namespace enums

#endif
