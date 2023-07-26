
#ifndef NJOY_GNDSTK_ENUMS_INTERPOLATIONQUALIFIER
#define NJOY_GNDSTK_ENUMS_INTERPOLATIONQUALIFIER

namespace enums {

   /**
    *  @class
    *  @brief Enumeration class for interpolation qualifier values
    */
   enum class InterpolationQualifier {
      direct = 1,
      unitBase,
      correspondingEnergies,
      correspondingPoints
   };

   /**
    *  @brief Return whether or not a string is a valid interpolation qualifier
    *         value
    *
    *  @param[in] string    the string to be verified
    *
    *  @return true/false
    */
   inline bool isInterpolationQualifier(const std::string &string)
   {
      return isSymbol<InterpolationQualifier>(string);
   }

   /**
    *  @brief Template specialisation to convert InterpolationQualifier to/from strings
    */
   template<>
   struct Map<InterpolationQualifier>
   {
      static inline const std::map<InterpolationQualifier,std::string> values {
         { InterpolationQualifier::direct, "direct" },
         { InterpolationQualifier::unitBase, "unitBase" },
         { InterpolationQualifier::correspondingEnergies, "correspondingEnergies" },
         { InterpolationQualifier::correspondingPoints, "correspondingPoints" }
      };

      static inline const std::map<std::string,InterpolationQualifier> symbols {
         { "direct", InterpolationQualifier::direct },
         { "unitBase", InterpolationQualifier::unitBase },
         { "correspondingEnergies", InterpolationQualifier::correspondingEnergies },
         { "correspondingPoints", InterpolationQualifier::correspondingPoints }
      };
   };

} // namespace enums

#endif
