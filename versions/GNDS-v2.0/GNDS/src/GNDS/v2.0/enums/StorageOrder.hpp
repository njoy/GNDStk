
#pragma once

#include "GNDStk.hpp"

namespace GNDS {
namespace v2_0 {
namespace enums {

using namespace njoy::GNDStk::enums;

/**
 *  @class
 *  @brief Enumeration class giving acceptable storage order values
 */
enum class StorageOrder {
   rowMajor = 1,
   columnMajor = 2
};

/**
 *  @brief Return whether or not a string is a valid storage order
 *
 *  @param[in] string    the string to be verified
 *
 *  @return true/false
 */
inline bool isStorageOrder(const std::string &string)
{
   return isSymbolForEnum<StorageOrder>(string);
}

} // namespace enums
} // namespace v2_0
} // namespace GNDS

/**
 *  @brief Template specialisation to convert StorageOrder to/from strings
 */
template<>
struct njoy::GNDStk::enums::EnumMap<GNDS::v2_0::enums::StorageOrder> {
   using T = getEnum<EnumMap>;
   static inline const map2string<T> values {
      { T::rowMajor, "row-major" },
      { T::columnMajor, "column-major" }
   };
   static inline const auto symbols = reverseMap(values);
};
