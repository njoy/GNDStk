#ifndef NJOY_GNDSTK_ENUMS_UNITS_ENERGY
#define NJOY_GNDSTK_ENUMS_UNITS_ENERGY

// system includes

// other includes
#include "utility/enumeration.hpp"

namespace njoy {
namespace GNDStk {
namespace enums {
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
  bool isEnergyUnit( const std::string& string ) {

    return utility::enumeration::isSymbol< Energy >( string );
  }

} // units namespace
} // enums namespace
} // GNDStk namespace
} // njoy namespace

namespace njoy {
namespace utility {
namespace enumeration {

  /**
   *  @brief Template specialisation to convert Energy to/from strings
   */
  template <>
  struct Map< GNDStk::enums::units::Energy > {

    static inline const std::map< GNDStk::enums::units::Energy,
                                  const std::string > values{

      { GNDStk::enums::units::Energy::eV,  "eV" },
      { GNDStk::enums::units::Energy::MeV, "MeV" }
    };

    static inline const std::map< const std::string,
                                  GNDStk::enums::units::Energy > symbols{

      { "eV",  GNDStk::enums::units::Energy::eV },
      { "MeV", GNDStk::enums::units::Energy::MeV }
    };
  };

} // enumeration namespace
} // utility namespace
} // njoy namespace

#endif
