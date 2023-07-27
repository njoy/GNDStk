
#ifndef NJOY_GNDSTK_ENUMS_DECAYTYPE
#define NJOY_GNDSTK_ENUMS_DECAYTYPE

namespace enums {

   /**
    *  @class
    *  @brief Enumeration class for interpolation decay type values
    */
   enum class DecayType {
      SpontaneousFission = 1,
      BetaMinus,
      BetaPlus,
      ElectronCapture,
      ElectroMagnetic,
      IsomericTransition,
      Neutron,
      Proton,
      Deuteron,
      Triton,
      Alpha,
      AtomicRelaxation
   };

   /**
    *  @brief Return whether or not a string is a valid relation type
    *
    *  @param[in] string    the string to be verified
    *
    *  @return true/false
    */
   inline bool isDecayType(const std::string &string)
   {
      return isSymbol<DecayType>(string);
   }

   /**
    *  @brief Template specialisation to convert DecayType to/from strings
    */
   template<>
   struct Map<DecayType> {
      static inline const map2string<DecayType> values {
         { DecayType::SpontaneousFission, "SF" },
         { DecayType::BetaMinus, "beta-" },
         { DecayType::BetaPlus, "beta+" },
         { DecayType::ElectronCapture, "EC" },
         { DecayType::ElectroMagnetic, "electroMagnetic" },
         { DecayType::IsomericTransition, "IT" },
         { DecayType::Neutron, "n" },
         { DecayType::Proton, "p" },
         { DecayType::Deuteron, "d" },
         { DecayType::Triton, "t" },
         { DecayType::Alpha, "alpha" },
         { DecayType::AtomicRelaxation, "atomicRelaxation" }
      };
      static inline const auto symbols = reverseMap(values);
   };

} // namespace enums

#endif
