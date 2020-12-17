#ifndef NJOY_GNDSTK_UNITS_ENERGY
#define NJOY_GNDSTK_UNITS_ENERGY

// system includes

// other includes
#include "utility/enumerations.hpp"

namespace njoy {
namespace GNDStk {
namespace units {

  /**
   *  @class
   *  @brief Enumeration class giving acceptable units for energy
   *
   *  See GNDS v1.9 specifications section 5.1.1
   */
  enum class Energy {

    eV,
    MeV
  };

  using utility::fromString;
  using utility::toString;
  using utility::operator>>;
  using utility::operator<<;

  /**
   *  @brief Return whether or not a string is a valid energy unit
   *
   *  @param[in] string    the string to be verified
   *
   *  @return true/false
   */
  bool isEnergyUnit( const std::string& string ) {

    return utility::isSymbol< Energy >( string );
  }

} // units namespace
} // GNDStk namespace
} // njoy namespace

namespace njoy {
namespace utility {

  template <>
  struct EnumerationMap< GNDStk::units::Energy > {

    static inline const std::map< GNDStk::units::Energy, const std::string > values{

      { GNDStk::units::Energy::eV,  "eV" },
      { GNDStk::units::Energy::MeV, "MeV" }
    };

    static inline const std::map< const std::string, GNDStk::units::Energy > symbols{

      { "eV",  GNDStk::units::Energy::eV },
      { "MeV", GNDStk::units::Energy::MeV }
    };
  };

} // utility namespace
} // njoy namespace

#endif