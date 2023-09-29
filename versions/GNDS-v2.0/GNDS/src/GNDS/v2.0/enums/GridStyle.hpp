
#pragma once

#include "GNDStk.hpp"

namespace GNDS {
namespace v2_0 {
namespace enums {

using namespace njoy::GNDStk::enums;

/**
 *  @class
 *  @brief Enumeration class giving acceptable grid style values
 */
enum class GridStyle {
   none,
   link,
   points,
   boundaries,
   parameters
};

/**
 *  @brief Return whether or not a string is a valid grid style
 *
 *  @param[in] string    the string to be verified
 *
 *  @return true/false
 */
inline bool isGridStyle(const std::string &string)
{
   return isSymbolForEnum<GridStyle>(string);
}

} // namespace enums
} // namespace v2_0
} // namespace GNDS

/**
 *  @brief Template specialisation to convert GridStyle to/from strings
 */
template<>
struct njoy::GNDStk::enums::EnumMap<GNDS::v2_0::enums::GridStyle> {
   using T = getEnum<EnumMap>;
   static inline const map2string<T> values {
      { T::none, "none" },
      { T::link, "link" },
      { T::points, "points" },
      { T::boundaries, "boundaries" },
      { T::parameters, "parameters" }
   };
   static inline const auto symbols = reverseMap(values);
};
