
#ifndef NJOY_GNDSTK_ENUMS_LENGTH
#define NJOY_GNDSTK_ENUMS_LENGTH

namespace enums {

   /**
    *  @class
    *  @brief Enumeration class giving acceptable units for length
    *
    *  See GNDS v1.9 specifications section 5.1.1
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
struct Map<Length>
{
   static inline const std::map<Length,std::string> values {
      { Length::m, "m" },
      { Length::cm, "cm" },
      { Length::fm, "fm" }
   };

   static inline const std::map<std::string,Length> symbols {
      { "m", Length::m },
      { "cm", Length::cm },
      { "fm", Length::fm }
   };
};

} // namespace enums

#endif
