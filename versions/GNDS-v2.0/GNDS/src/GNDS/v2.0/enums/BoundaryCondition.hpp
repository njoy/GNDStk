
#pragma once

#include "GNDStk.hpp"

namespace GNDS {
namespace v2_0 {
namespace enums {

using namespace njoy::GNDStk::enums;

/**
 *  @class
 *  @brief Enumeration class for reference boundary condition values
 */
enum class BoundaryCondition {
   EliminateShiftFunction = 1,
   NegativeOrbitalMomentum,
   Brune,
   Given
};

/**
 *  @brief Return whether or not a string is a valid boundary condition
 *
 *  @param[in] string    the string to be verified
 *
 *  @return true/false
 */
inline bool isBoundaryCondition(const std::string &string)
{
   return isSymbolForEnum<BoundaryCondition>(string);
}

} // namespace enums
} // namespace v2_0
} // namespace GNDS

/**
 *  @brief Template specialisation to convert BoundaryCondition to/from strings
 */
template<>
struct njoy::GNDStk::enums::EnumMap<GNDS::v2_0::enums::BoundaryCondition> {
   using T = getEnum<EnumMap>;
   static inline const map2string<T> values {
      { T::EliminateShiftFunction, "EliminateShiftFunction" },
      { T::NegativeOrbitalMomentum, "NegativeOrbitalMomentum" },
      { T::Brune, "Brune" },
      { T::Given, "Given" }
   };
   static inline const auto symbols = reverseMap(values);
};
