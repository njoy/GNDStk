
#pragma once

#include "GNDStk.hpp"

namespace GNDS {
namespace v2_0 {
namespace enums {

using namespace njoy::GNDStk::enums;

/**
 *  @class
 *  @brief Enumeration class giving acceptable units for length
 */
enum class Length {
   m,
   cm,
   fm
};

/**
 *  @brief Return whether or not a string is a valid energy unit
 *
 *  @param[in] string    the string to be verified
 *
 *  @return true/false
 */
inline bool isLengthUnit(const std::string &string)
{
   return isSymbolForEnum<Length>(string);
}

} // namespace enums
} // namespace v2_0
} // namespace GNDS

/**
 *  @brief Template specialisation to convert Length to/from strings
 */
template<>
struct njoy::GNDStk::enums::EnumMap<GNDS::v2_0::enums::Length> {
   using T = getEnum<EnumMap>;
   static inline const map2string<T> values {
      { T::m, "m" },
      { T::cm, "cm" },
      { T::fm, "fm" }
   };
   static inline const auto symbols = reverseMap(values);
};
