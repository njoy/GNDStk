
#pragma once

#include "GNDStk.hpp"

namespace GNDS {
namespace v2_0 {
namespace enums {

using namespace njoy::GNDStk::enums;

/**
 *  @class
 *  @brief Enumeration class giving acceptable encoding values
 */
enum class Encoding {
   ascii = 1,
   utf8 = 2
};

/**
 *  @brief Return whether or not a string is a valid encoding
 *
 *  @param[in] string    the string to be verified
 *
 *  @return true/false
 */
inline bool isEncoding(const std::string &string)
{
   return isSymbolForEnum<Encoding>(string);
}

} // namespace enums
} // namespace v2_0
} // namespace GNDS

/**
 *  @brief Template specialisation to convert Encoding to/from strings
 */
template<>
struct njoy::GNDStk::enums::EnumMap<GNDS::v2_0::enums::Encoding> {
   using T = getEnum<EnumMap>;
   static inline const map2string<T> values {
      { T::ascii, "ascii" },
      { T::utf8, "utf8" }
   };
   static inline const auto symbols = reverseMap(values);
};
