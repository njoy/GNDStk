#ifndef NJOY_GNDSTK_INTERPOLATION
#define NJOY_GNDSTK_INTERPOLATION

// system includes

// other includes
#include "utility/enumeration.hpp"

namespace njoy {
namespace GNDStk {
namespace enums {

  /**
   *  @class
   *  @brief Enumeration class giving acceptable grid styles
   *
   *  See GNDS v1.9 specifications section 5.1.3
   */
  enum class GridStyle {

    none,
    points,
    boundaries,
    parameters
  };

  using utility::enumeration::fromString;
  using utility::enumeration::toString;
  using utility::enumeration::operator>>;
  using utility::enumeration::operator<<;

  /**
   *  @brief Return whether or not a string is a valid grid style
   *
   *  @param[in] string    the string to be verified
   *
   *  @return true/false
   */
  bool isGridStyle( const std::string& string ) {

    return utility::enumeration::isSymbol< GridStyle >( string );
  }

} // enums namespace
} // GNDStk namespace
} // njoy namespace

namespace njoy {
namespace utility {
namespace enumeration {

  /**
   *  @brief Template specialisation to convert Length to/from strings
   */
  template <>
  struct Map< GNDStk::enums::GridStyle > {

    static inline const std::map< GNDStk::enums::GridStyle,
                                  const std::string > values{

      { GNDStk::enums::GridStyle::none,       "none" },
      { GNDStk::enums::GridStyle::points,     "points" },
      { GNDStk::enums::GridStyle::boundaries, "boundaries" },
      { GNDStk::enums::GridStyle::parameters, "parameters" }
    };

    static inline const std::map< const std::string,
                                  GNDStk::enums::GridStyle > symbols{

      { "none",  GNDStk::enums::GridStyle::none },
      { "points", GNDStk::enums::GridStyle::points },
      { "boundaries", GNDStk::enums::GridStyle::boundaries },
      { "parameters", GNDStk::enums::GridStyle::parameters }
    };
  };

} // enumeration namespace
} // utility namespace
} // njoy namespace

#endif
