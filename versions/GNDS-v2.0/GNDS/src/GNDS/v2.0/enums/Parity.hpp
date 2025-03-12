
#pragma once

#include "GNDStk.hpp"

namespace GNDS {
namespace v2_0 {
namespace enums {

using namespace njoy::GNDStk::enums;

/**
 *  @class
 *  @brief Enumeration class for particle parity values
 */
enum class Parity {
   minus = -1,
   plus = +1
};

/**
 *  @brief Return whether or not a string is a valid parity
 *
 *  @param[in] string    the string to be verified
 *
 *  @return true/false
 */
inline bool isParity(const std::string &string)
{
   return isSymbolForEnum<Parity>(string);
}

} // namespace enums
} // namespace v2_0
} // namespace GNDS

/**
 *  @brief Template specialisation to convert Parity to/from strings
 */
template<>
struct njoy::GNDStk::enums::EnumMap<GNDS::v2_0::enums::Parity> {
   using T = getEnum<EnumMap>;
   static inline const map2string<T> values {
      { T::minus, "-1" },
      { T::plus, "+1" }
   };
   static inline const auto symbols = reverseMap(values);
};
