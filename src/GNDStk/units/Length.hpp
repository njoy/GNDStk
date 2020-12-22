#ifndef NJOY_GNDSTK_UNITS_LENGTH
#define NJOY_GNDSTK_UNITS_LENGTH

// system includes

// other includes
#include "utility/enumeration.hpp"

namespace njoy {
namespace GNDStk {
namespace units {

  /**
   *  @class
   *  @brief Enumeration class giving acceptable units for length
   *
   *  See GNDS v1.9 specifications section 5.1.1
   */
  enum class Length {

    m,
    cm,
    fm
  };

  using utility::enumeration::fromString;
  using utility::enumeration::toString;
  using utility::enumeration::operator>>;
  using utility::enumeration::operator<<;

  /**
   *  @brief Return whether or not a string is a valid energy unit
   *
   *  @param[in] string    the string to be verified
   *
   *  @return true/false
   */
  bool isLengthUnit( const std::string& string ) {

    return utility::enumeration::isSymbol< Length >( string );
  }

} // units namespace
} // GNDStk namespace
} // njoy namespace

namespace njoy {
namespace utility {
namespace enumeration {

  /**
   *  @brief Template specialisation to convert Length to/from strings
   */
  template <>
  struct Map< GNDStk::units::Length > {

    static inline const std::map< GNDStk::units::Length,
                                  const std::string > values{

      { GNDStk::units::Length::m,  "m" },
      { GNDStk::units::Length::cm, "cm" },
      { GNDStk::units::Length::fm, "fm" }
    };

    static inline const std::map< const std::string,
                                  GNDStk::units::Length > symbols{

      { "m",  GNDStk::units::Length::m },
      { "cm", GNDStk::units::Length::cm },
      { "fm", GNDStk::units::Length::fm }
    };
  };

} // enumeration namespace
} // utility namespace
} // njoy namespace

#endif
