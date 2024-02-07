
#pragma once

#include "GNDStk.hpp"

namespace GNDS {
namespace v2_0 {
namespace enums {

using namespace njoy::GNDStk::enums;

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
   return isSymbolForEnum<Interpolation>(string);
}

} // namespace enums
} // namespace v2_0
} // namespace GNDS

/**
 *  @brief Template specialisation to convert Interpolation to/from strings
 */
template<>
struct njoy::GNDStk::enums::EnumMap<GNDS::v2_0::enums::Interpolation> {
   using T = getEnum<EnumMap>;
   static inline const map2string<T> values {
      { T::flat, "flat" },
      { T::linlin, "lin-lin" },
      { T::linlog, "lin-log" },
      { T::loglin, "log-lin" },
      { T::loglog, "log-log" },
      { T::chargedparticle, "charged-particle" }
   };
   static inline const auto symbols = reverseMap(values);
};
