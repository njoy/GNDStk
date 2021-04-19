#ifndef NJOY_GNDSTK_ENUMS_UNITS_ENERGY
#define NJOY_GNDSTK_ENUMS_UNITS_ENERGY

// system includes

// other includes

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

  using enums::fromString;
  using enums::toString;
  using enums::operator>>;
  using enums::operator<<;

  /**
   *  @brief Return whether or not a string is a valid energy unit
   *
   *  @param[in] string    the string to be verified
   *
   *  @return true/false
   */
  inline bool isEnergyUnit( const std::string& string ) {

    return GNDStk::enums::isSymbol< GNDStk::enums::units::Energy >( string );
  }

} // units namespace

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

} // enums namespace

#endif
