#ifndef NJOY_GNDSTK_ENUMS_UNITS_LENGTH
#define NJOY_GNDSTK_ENUMS_UNITS_LENGTH

// system includes

// other includes

namespace enums {
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
  inline bool isLengthUnit( const std::string& string ) {

    return GNDStk::enums::isSymbol< GNDStk::enums::units::Length >( string );
  }

} // units namespace

  /**
   *  @brief Template specialisation to convert Length to/from strings
   */
  template <>
  struct Map< GNDStk::enums::units::Length > {

    static inline const std::map< GNDStk::enums::units::Length,
                                  const std::string > values{

      { GNDStk::enums::units::Length::m,  "m" },
      { GNDStk::enums::units::Length::cm, "cm" },
      { GNDStk::enums::units::Length::fm, "fm" }
    };

    static inline const std::map< const std::string,
                                  GNDStk::enums::units::Length > symbols{

      { "m",  GNDStk::enums::units::Length::m },
      { "cm", GNDStk::enums::units::Length::cm },
      { "fm", GNDStk::enums::units::Length::fm }
    };
  };

} // enums namespace

#endif
