
#ifndef NJOY_GNDSTK_ENUMS_ENERGY
#define NJOY_GNDSTK_ENUMS_ENERGY

namespace enums {

   /**
    *  @class
    *  @brief Enumeration class giving acceptable units for energy
    */
   enum class Energy {
      eV,
      MeV
   };

   /**
    *  @brief Return whether or not a string is a valid energy unit
    *
    *  @param[in] string    the string to be verified
    *
    *  @return true/false
    */
   inline bool isEnergyUnit(const std::string &string)
   {
      return isSymbol<Energy>(string);
   }

   /**
    *  @brief Template specialisation to convert Energy to/from strings
    */
   template<>
   struct Map<Energy> {
      static inline const map2string<Energy> values {
         { Energy::eV, "eV" },
         { Energy::MeV, "MeV" }
      };
      static inline const auto symbols = reverseMap(values);
   };

} // namespace enums

#endif
