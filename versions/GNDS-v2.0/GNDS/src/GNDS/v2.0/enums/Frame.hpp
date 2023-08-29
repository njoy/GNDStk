
#pragma once

#include "GNDStk.hpp"

namespace GNDS {
namespace v2_0 {
namespace enums {

using namespace njoy::GNDStk::enums;

/**
 *  @class
 *  @brief Enumeration class for reference frame values
 */
enum class Frame {
   lab = 1,
   centerOfMass = 2
};

/**
 *  @brief Return whether or not a string is a valid frame
 *
 *  @param[in] string    the string to be verified
 *
 *  @return true/false
 */
inline bool isFrame(const std::string &string)
{
   return isSymbolForEnum<Frame>(string);
}

} // namespace enums
} // namespace v2_0
} // namespace GNDS

/**
 *  @brief Template specialisation to convert Frame to/from strings
 */
template<>
struct njoy::GNDStk::enums::EnumMap<GNDS::v2_0::enums::Frame> {
   using T = getEnum<EnumMap>;
   static inline const map2string<T> values {
      { T::lab, "lab" },
      { T::centerOfMass, "centerOfMass" }
   };
   static inline const auto symbols = reverseMap(values);
};
