
#pragma once

#include "GNDStk.hpp"

namespace GNDS {
namespace v2_0 {
namespace enums {

using namespace njoy::GNDStk::enums;

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
   return isSymbolForEnum<DecayType>(string);
}

} // namespace enums
} // namespace v2_0
} // namespace GNDS

/**
 *  @brief Template specialisation to convert DecayType to/from strings
 */
template<>
struct njoy::GNDStk::enums::EnumMap<GNDS::v2_0::enums::DecayType> {
   using T = getEnum<EnumMap>;
   static inline const map2string<T> values {
      { T::SpontaneousFission, "SF" },
      { T::BetaMinus, "beta-" },
      { T::BetaPlus, "beta+" },
      { T::ElectronCapture, "EC" },
      { T::ElectroMagnetic, "electroMagnetic" },
      { T::IsomericTransition, "IT" },
      { T::Neutron, "n" },
      { T::Proton, "p" },
      { T::Deuteron, "d" },
      { T::Triton, "t" },
      { T::Alpha, "alpha" },
      { T::AtomicRelaxation, "atomicRelaxation" }
   };
   static inline const auto symbols = reverseMap(values);
};
