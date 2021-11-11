
#ifndef NJOY_GNDSTK_INTERPOLATION
#define NJOY_GNDSTK_INTERPOLATION

namespace enums {

  /**
   *  @class
   *  @brief Enumeration class for interpolation values
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
   *  @brief Return whether or not a string is a valid interpolation value
   *
   *  @param[in] string    the string to be verified
   *
   *  @return true/false
   */
  inline bool isInterpolation( const std::string& string ) {

    return isSymbol< Interpolation >( string );
  }

  /**
   *  @brief Template specialisation to convert Interpolation to/from strings
   */
  template <>
  class Map< GNDStk::enums::Interpolation > {
  public:

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

} // namespace enums

#endif
