
#ifndef NJOY_GNDSTK_ENUMS_INTERPOLATION
#define NJOY_GNDSTK_ENUMS_INTERPOLATION

namespace enums {

   /**
    *  @class
    *  @brief Enumeration class for interpolation values
    */
   enum class Interpolation {
      flat   = 1,
      linlin = 2,
      linlog = 3,
      loglin = 4,
      loglog = 5,
      chargedparticle = 6
   };

   /**
    *  @brief Return whether or not a string is a valid interpolation value
    *
    *  @param[in] string    the string to be verified
    *
    *  @return true/false
    */
   inline bool isInterpolation(const std::string &string)
   {
      return isSymbol<Interpolation>(string);
   }

   /**
    *  @brief Template specialisation to convert Interpolation to/from strings
    */
   template<>
   struct Map<Interpolation> {
      static inline const map2string<Interpolation> values {
         { Interpolation::flat, "flat" },
         { Interpolation::linlin, "lin-lin" },
         { Interpolation::linlog, "lin-log" },
         { Interpolation::loglin, "log-lin" },
         { Interpolation::loglog, "log-log" },
         { Interpolation::chargedparticle, "charged-particle" }
      };
      static inline const auto symbols = reverseMap(values);
   };

} // namespace enums

#endif
