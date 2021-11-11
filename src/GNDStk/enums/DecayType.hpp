#ifndef NJOY_GNDSTK_DECAYTYPE
#define NJOY_GNDSTK_DECAYTYPE

namespace enums {

  /**
   *  @class
   *  @brief Enumeration class for interpolation decay type values
   */
  enum class DecayType {

    SpontaneousFission = 1,
    BetaMinus,
    BetaPlus,
    ElectronCapture,
    ElectroMagnetic,
    IsomericTransition,
    Neutron,
    Proton,
    Deuteron,
    Triton,
    Alpha,
    AtomicRelaxation
  };

  /**
   *  @brief Return whether or not a string is a valid relation type
   *
   *  @param[in] string    the string to be verified
   *
   *  @return true/false
   */
  inline bool isDecayType( const std::string& string ) {

    return isSymbol< DecayType >( string );
  }

  /**
   *  @brief Template specialisation to convert DecayType to/from strings
   */
  template <>
  class Map< GNDStk::enums::DecayType > {
  public:

    static inline const std::map< GNDStk::enums::DecayType,
                                  const std::string > values{

      { GNDStk::enums::DecayType::SpontaneousFission, "SF" },
      { GNDStk::enums::DecayType::BetaMinus, "beta-" },
      { GNDStk::enums::DecayType::BetaPlus, "beta+" },
      { GNDStk::enums::DecayType::ElectronCapture, "EC" },
      { GNDStk::enums::DecayType::ElectroMagnetic, "electroMagnetic" },
      { GNDStk::enums::DecayType::IsomericTransition, "IT" },
      { GNDStk::enums::DecayType::Neutron, "n" },
      { GNDStk::enums::DecayType::Proton, "p" },
      { GNDStk::enums::DecayType::Deuteron, "d" },
      { GNDStk::enums::DecayType::Triton, "t" },
      { GNDStk::enums::DecayType::Alpha, "alpha" },
      { GNDStk::enums::DecayType::AtomicRelaxation, "atomicRelaxation" }
    };

    static inline const std::map< const std::string,
                                  GNDStk::enums::DecayType > symbols{

      { "SF", GNDStk::enums::DecayType::SpontaneousFission },
      { "beta-", GNDStk::enums::DecayType::BetaMinus },
      { "beta+", GNDStk::enums::DecayType::BetaPlus },
      { "EC", GNDStk::enums::DecayType::ElectronCapture },
      { "electroMagnetic", GNDStk::enums::DecayType::ElectroMagnetic },
      { "IT", GNDStk::enums::DecayType::IsomericTransition },
      { "n", GNDStk::enums::DecayType::Neutron },
      { "p", GNDStk::enums::DecayType::Proton },
      { "d", GNDStk::enums::DecayType::Deuteron },
      { "t", GNDStk::enums::DecayType::Triton },
      { "alpha", GNDStk::enums::DecayType::Alpha },
      { "atomicRelaxation", GNDStk::enums::DecayType::AtomicRelaxation }
    };
  };

} // namespace enums

#endif
