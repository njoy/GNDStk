
#ifndef NJOY_GNDSTK_INTERACTION
#define NJOY_GNDSTK_INTERACTION

namespace enums {

  /**
   *  @class
   *  @brief Enumeration class giving acceptable interaction schemes
   *
   *  See GNDS v1.9 specifications section 3.5.3
   */
  enum class Interaction {

    nuclear = 1,
    atomic = 2,
    thermalNeutronScatteringLaw = 3
  };

  /**
   *  @brief Return whether or not a string is a valid interaction scheme
   *
   *  @param[in] string    the string to be verified
   *
   *  @return true/false
   */
  inline bool isInteractionScheme( const std::string& string ) {

    return isSymbol< Interaction >( string );
  }

  /**
   *  @brief Template specialisation to convert Interaction to/from strings
   */
  template <>
  class Map< GNDStk::enums::Interaction > {
  public:

    static inline const std::map< GNDStk::enums::Interaction,
                                  const std::string > values{

      { GNDStk::enums::Interaction::nuclear, "nuclear" },
      { GNDStk::enums::Interaction::atomic, "atomic" },
      { GNDStk::enums::Interaction::thermalNeutronScatteringLaw, "thermalNeutronScatteringLaw" }
    };

    static inline const std::map< const std::string,
                                  GNDStk::enums::Interaction > symbols{

      { "nuclear", GNDStk::enums::Interaction::nuclear },
      { "atomic", GNDStk::enums::Interaction::atomic },
      { "thermalNeutronScatteringLaw", GNDStk::enums::Interaction::thermalNeutronScatteringLaw }
    };
  };

} // namespace enums

#endif
