
#ifndef NJOY_GNDSTK_ENUMS_LENGTH
#define NJOY_GNDSTK_ENUMS_LENGTH

namespace enums {

namespace units {

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

   using enums::fromString;
   using enums::toString;
   using enums::operator>>;
   using enums::operator<<;

   /**
    *  @brief Return whether or not a string is a valid energy unit
    *
    *  @param[in] string    the string to be verified
    *
    *  @return true/false
    */
   inline bool isLengthUnit(const std::string &string)
   {
      return isSymbol<units::Length>(string);
   }

} // namespace units


/**
 *  @brief Template specialisation to convert Length to/from strings
 */
template<>
struct Map<units::Length>
{
   static inline const std::map<units::Length,std::string> values {
      { units::Length::m, "m" },
      { units::Length::cm, "cm" },
      { units::Length::fm, "fm" }
   };

   static inline const std::map<std::string,units::Length> symbols {
      { "m", units::Length::m },
      { "cm", units::Length::cm },
      { "fm", units::Length::fm }
   };
};

} // namespace enums

#endif
