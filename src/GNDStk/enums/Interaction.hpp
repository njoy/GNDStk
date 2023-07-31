
#ifndef NJOY_GNDSTK_ENUMS_INTERACTION
#define NJOY_GNDSTK_ENUMS_INTERACTION

namespace enums {

   /**
    *  @class
    *  @brief Enumeration class giving acceptable interaction values
    *
    *  See GNDS v1.9 specifications section 3.5.3
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
   struct Map<Interaction>
   {
      static inline const std::map<Interaction,std::string> values {
         { Interaction::nuclear, "nuclear" },
         { Interaction::atomic, "atomic" },
         { Interaction::thermalNeutronScatteringLaw, "thermalNeutronScatteringLaw" }
      };

      static inline const std::map<std::string,Interaction> symbols {
         { "nuclear", Interaction::nuclear },
         { "atomic", Interaction::atomic },
         { "thermalNeutronScatteringLaw", Interaction::thermalNeutronScatteringLaw }
      };
   };

} // namespace enums

#endif
