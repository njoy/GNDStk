
#ifndef NJOY_GNDSTK_ENUMS_ENERGY
#define NJOY_GNDSTK_ENUMS_ENERGY

namespace enums {

namespace units {

   /**
    *  @class
    *  @brief Enumeration class giving acceptable units for energy
    *
    *  See GNDS v1.9 specifications section 5.1.1
    */
   enum class Energy {
      eV,
      MeV
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
   inline bool isEnergyUnit(const std::string &string)
   {
      return isSymbol<units::Energy>(string);
   }

} // namespace units


/**
 *  @brief Template specialisation to convert Energy to/from strings
 */
template<>
struct Map<units::Energy>
{
   static inline const std::map<units::Energy,std::string> values {
      { units::Energy::eV, "eV" },
      { units::Energy::MeV, "MeV" }
   };

   static inline const std::map<std::string,units::Energy> symbols {
      { "eV", units::Energy::eV },
      { "MeV", units::Energy::MeV }
   };
};

} // namespace enums

#endif
