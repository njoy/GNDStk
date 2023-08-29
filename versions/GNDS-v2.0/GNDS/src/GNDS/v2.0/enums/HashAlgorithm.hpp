
#pragma once

#include "GNDStk.hpp"

namespace GNDS {
namespace v2_0 {
namespace enums {

using namespace njoy::GNDStk::enums;

/**
 *  @class
 *  @brief Enumeration class for hash algorithm values
 */
enum class HashAlgorithm {
   md5 = 1,
   sha1 = 2
};

/**
 *  @brief Return whether or not a string is a valid hash algorithm value
 *
 *  @param[in] string    the string to be verified
 *
 *  @return true/false
 */
inline bool isHashAlgorithm(const std::string &string)
{
   return isSymbolForEnum<HashAlgorithm>(string);
}

} // namespace enums
} // namespace v2_0
} // namespace GNDS

/**
 *  @brief Template specialisation to convert HashAlgorithm to/from strings
 */
template<>
struct njoy::GNDStk::enums::EnumMap<GNDS::v2_0::enums::HashAlgorithm> {
   using T = getEnum<EnumMap>;
   static inline const map2string<T> values {
      { T::md5, "md5" },
      { T::sha1, "sha1" }
   };
   static inline const auto symbols = reverseMap(values);
};
