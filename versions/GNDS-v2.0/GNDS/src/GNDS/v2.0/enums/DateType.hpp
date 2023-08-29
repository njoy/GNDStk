
#pragma once

#include "GNDStk.hpp"

namespace GNDS {
namespace v2_0 {
namespace enums {

using namespace njoy::GNDStk::enums;

/**
 *  @class
 *  @brief Enumeration class for date type values
 */
enum class DateType {
   accepted = 1,
   available,
   copyrighted,
   collected,
   created,
   issued,
   submitted,
   updated,
   valid,
   withdrawn
};

/**
 *  @brief Return whether or not a string is a valid date type
 *
 *  @param[in] string    the string to be verified
 *
 *  @return true/false
 */
inline bool isDateType(const std::string &string)
{
   return isSymbolForEnum<DateType>(string);
}

} // namespace enums
} // namespace v2_0
} // namespace GNDS

/**
 *  @brief Template specialisation to convert DateType to/from strings
 */
template<>
struct njoy::GNDStk::enums::EnumMap<GNDS::v2_0::enums::DateType> {
   using T = getEnum<EnumMap>;
   static inline const map2string<T> values {
      { T::accepted, "accepted" },
      { T::available, "available" },
      { T::copyrighted, "copyrighted" },
      { T::collected, "collected" },
      { T::created, "created" },
      { T::issued, "issued" },
      { T::submitted, "submitted" },
      { T::updated, "updated" },
      { T::valid, "valid" },
      { T::withdrawn, "withdrawn" }
   };
   static inline const auto symbols = reverseMap(values);
};
