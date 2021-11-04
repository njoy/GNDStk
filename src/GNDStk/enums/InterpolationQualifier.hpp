#ifndef NJOY_GNDSTK_INTERPOLATIONQUALIFIER
#define NJOY_GNDSTK_INTERPOLATIONQUALIFIER

namespace enums {

  /**
   *  @class
   *  @brief Enumeration class for interpolation qualifier values
   */
  enum class InterpolationQualifier {

    direct = 1,
    unitBase,
    correspondingEnergies,
    correspondingPoints
  };

  /**
   *  @brief Return whether or not a string is a valid parity
   *
   *  @param[in] string    the string to be verified
   *
   *  @return true/false
   */
  inline bool isInterpolationQualifier( const std::string& string ) {

    return isSymbol< InterpolationQualifier >( string );
  }

  /**
   *  @brief Template specialisation to convert InterpolationQualifier to/from strings
   */
  template <>
  class Map< GNDStk::enums::InterpolationQualifier > {
  public:

    static inline const std::map< GNDStk::enums::InterpolationQualifier,
                                  const std::string > values{

      { GNDStk::enums::InterpolationQualifier::direct, "direct" },
      { GNDStk::enums::InterpolationQualifier::unitBase, "unitBase" },
      { GNDStk::enums::InterpolationQualifier::correspondingEnergies, "correspondingEnergies" },
      { GNDStk::enums::InterpolationQualifier::correspondingPoints, "correspondingPoints" }
    };

    static inline const std::map< const std::string,
                                  GNDStk::enums::InterpolationQualifier > symbols{

      { "direct", GNDStk::enums::InterpolationQualifier::direct },
      { "unitBase", GNDStk::enums::InterpolationQualifier::unitBase },
      { "correspondingEnergies", GNDStk::enums::InterpolationQualifier::correspondingEnergies },
      { "correspondingPoints", GNDStk::enums::InterpolationQualifier::correspondingPoints }
    };
  };

} // namespace enums

#endif
