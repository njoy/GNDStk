
#ifndef NJOY_GNDSTK_ENUMS_INTERACTION
#define NJOY_GNDSTK_ENUMS_INTERACTION

namespace enums {

   /**
    *  @class
    *  @brief Enumeration class giving acceptable interaction values
    */
   enum class Interaction {
      nuclear = 1,
      atomic = 2,
      thermalNeutronScatteringLaw = 3
   };

   /**
    *  @brief Return whether or not a string is a valid interaction
    *
    *  @param[in] string    the string to be verified
    *
    *  @return true/false
    */
   inline bool isInteraction(const std::string &string)
   {
      return isSymbol<Interaction>(string);
   }

   /**
    *  @brief Template specialisation to convert Interaction to/from strings
    */
   template<>
   struct Map<Interaction> {
      static inline const map2string<Interaction> values {
         { Interaction::nuclear, "nuclear" },
         { Interaction::atomic, "atomic" },
         { Interaction::thermalNeutronScatteringLaw, "thermalNeutronScatteringLaw" }
      };
      static inline const auto symbols = reverseMap(values);
   };

} // namespace enums

#endif
