#ifndef NJOY_GNDSTK_INTERPOLATION
#define NJOY_GNDSTK_INTERPOLATION

// system includes

// other includes

namespace enums {

  /**
   *  @class
   *  @brief Enumeration class giving acceptable interpolation schemes
   *
   *  See GNDS v1.9 specifications section 3.5.3
   */
  enum class Interpolation {

    flat   = 1,
    linlin = 2,
    linlog = 3,
    loglin = 4,
    loglog = 5,
    chargedparticle = 6
  };

  /**
   *  @brief Return whether or not a string is a valid interpolation scheme
   *
   *  @param[in] string    the string to be verified
   *
   *  @return true/false
   */
  inline bool isInterpolationScheme( const std::string& string ) {

    return isSymbol< Interpolation >( string );
  }

  /**
   *  @brief Template specialisation to convert Length to/from strings
   */
  template <>
  struct Map< GNDStk::enums::Interpolation > {

    static inline const std::map< GNDStk::enums::Interpolation,
                                  const std::string > values{

      { GNDStk::enums::Interpolation::flat,  "flat" },
      { GNDStk::enums::Interpolation::linlin, "lin-lin" },
      { GNDStk::enums::Interpolation::linlog, "lin-log" },
      { GNDStk::enums::Interpolation::loglin, "log-lin" },
      { GNDStk::enums::Interpolation::loglog, "log-log" },
      { GNDStk::enums::Interpolation::chargedparticle, "charged-particle" }
    };

    static inline const std::map< const std::string,
                                  GNDStk::enums::Interpolation > symbols{

      { "flat",  GNDStk::enums::Interpolation::flat },
      { "lin-lin", GNDStk::enums::Interpolation::linlin },
      { "lin-log", GNDStk::enums::Interpolation::linlog },
      { "log-lin", GNDStk::enums::Interpolation::loglin },
      { "log-log", GNDStk::enums::Interpolation::loglog },
      { "charged-particle", GNDStk::enums::Interpolation::chargedparticle }
    };
  };

} // enums namespace

#endif
