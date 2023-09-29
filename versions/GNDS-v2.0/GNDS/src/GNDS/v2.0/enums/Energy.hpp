
#pragma once

#include "GNDStk.hpp"

namespace GNDS {
namespace v2_0 {
namespace enums {

using namespace njoy::GNDStk::enums;

/**
 *  @class
 *  @brief Enumeration class giving acceptable units for energy
 */
enum class Energy {
   eV,
   MeV
};

/**
 *  @brief Return whether or not a string is a valid energy unit
 *
 *  @param[in] string    the string to be verified
 *
 *  @return true/false
 */
inline bool isEnergyUnit(const std::string &string)
{
   return isSymbolForEnum<Energy>(string);
}

} // namespace enums
} // namespace v2_0
} // namespace GNDS

/**
 *  @brief Template specialisation to convert Energy to/from strings
 */
template<>
struct njoy::GNDStk::enums::EnumMap<GNDS::v2_0::enums::Energy> {
   using T = getEnum<EnumMap>;
   static inline const map2string<T> values {
      { T::eV, "eV" },
      { T::MeV, "MeV" }
   };
   static inline const auto symbols = reverseMap(values);
};
