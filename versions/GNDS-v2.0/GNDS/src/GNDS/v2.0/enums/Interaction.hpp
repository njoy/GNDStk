
#pragma once

#include "GNDStk.hpp"

namespace GNDS {
namespace v2_0 {
namespace enums {

using namespace njoy::GNDStk::enums;

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
   return isSymbolForEnum<Interaction>(string);
}

} // namespace enums
} // namespace v2_0
} // namespace GNDS

/**
 *  @brief Template specialisation to convert Interaction to/from strings
 */
template<>
struct njoy::GNDStk::enums::EnumMap<GNDS::v2_0::enums::Interaction> {
   using T = getEnum<EnumMap>;
   static inline const map2string<T> values {
      { T::nuclear, "nuclear" },
      { T::atomic, "atomic" },
      { T::thermalNeutronScatteringLaw, "thermalNeutronScatteringLaw" }
   };
   static inline const auto symbols = reverseMap(values);
};
