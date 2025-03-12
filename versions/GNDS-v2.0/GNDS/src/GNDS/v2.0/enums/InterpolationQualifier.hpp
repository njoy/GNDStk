
#pragma once

#include "GNDStk.hpp"

namespace GNDS {
namespace v2_0 {
namespace enums {

using namespace njoy::GNDStk::enums;

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
   return isSymbolForEnum<InterpolationQualifier>(string);
}

} // namespace enums
} // namespace v2_0
} // namespace GNDS

/**
 *  @brief Template specialisation to convert InterpolationQualifier to/from strings
 */
template<>
struct njoy::GNDStk::enums::EnumMap<GNDS::v2_0::enums::InterpolationQualifier> {
   using T = getEnum<EnumMap>;
   static inline const map2string<T> values {
      { T::direct, "direct" },
      { T::unitBase, "unitBase" },
      { T::correspondingEnergies, "correspondingEnergies" },
      { T::correspondingPoints, "correspondingPoints" }
   };
   static inline const auto symbols = reverseMap(values);
};
