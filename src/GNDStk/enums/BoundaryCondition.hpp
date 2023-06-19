#ifndef NJOY_GNDSTK_BOUNDARYCONDITION
#define NJOY_GNDSTK_BOUNDARYCONDITION

namespace enums {

  /**
   *  @class
   *  @brief Enumeration class for reference boundary condition values
   */
  enum class BoundaryCondition {

    EliminateShiftFunction = 1,
    NegativeOrbitalMomentum,
    Brune,
    Given
  };

  /**
   *  @brief Return whether or not a string is a valid boundary condition
   *
   *  @param[in] string    the string to be verified
   *
   *  @return true/false
   */
  inline bool isBoundaryCondition( const std::string& string ) {

    return isSymbol< BoundaryCondition >( string );
  }

  /**
   *  @brief Template specialisation to convert BoundaryCondition to/from strings
   */
  template <>
  class Map< GNDStk::enums::BoundaryCondition > {
  public:

    static inline const std::map< GNDStk::enums::BoundaryCondition,
                                  const std::string > values{

      { GNDStk::enums::BoundaryCondition::EliminateShiftFunction, "EliminateShiftFunction" },
      { GNDStk::enums::BoundaryCondition::NegativeOrbitalMomentum, "NegativeOrbitalMomentum" },
      { GNDStk::enums::BoundaryCondition::Brune, "Brune" },
      { GNDStk::enums::BoundaryCondition::Given, "Given" }
    };

    static inline const std::map< const std::string,
                                  GNDStk::enums::BoundaryCondition > symbols{

      { "EliminateShiftFunction", GNDStk::enums::BoundaryCondition::EliminateShiftFunction },
      { "NegativeOrbitalMomentum", GNDStk::enums::BoundaryCondition::NegativeOrbitalMomentum },
      { "Brune", GNDStk::enums::BoundaryCondition::Brune },
      { "Given", GNDStk::enums::BoundaryCondition::Given }
    };
  };

} // namespace enums

#endif
