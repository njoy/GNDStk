
#ifndef NJOY_GNDSTK_ENUMS_BOUNDARYCONDITION
#define NJOY_GNDSTK_ENUMS_BOUNDARYCONDITION

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
   inline bool isBoundaryCondition(const std::string &string)
   {
      return isSymbol<BoundaryCondition>(string);
   }

   /**
    *  @brief Template specialisation to convert BoundaryCondition to/from strings
    */
   template<>
   struct Map<BoundaryCondition>
   {
      static inline const std::map<BoundaryCondition,std::string> values {
         { BoundaryCondition::EliminateShiftFunction, "EliminateShiftFunction" },
         { BoundaryCondition::NegativeOrbitalMomentum, "NegativeOrbitalMomentum" },
         { BoundaryCondition::Brune, "Brune" },
         { BoundaryCondition::Given, "Given" }
      };

      static inline const std::map<std::string,BoundaryCondition> symbols {
         { "EliminateShiftFunction", BoundaryCondition::EliminateShiftFunction },
         { "NegativeOrbitalMomentum", BoundaryCondition::NegativeOrbitalMomentum },
         { "Brune", BoundaryCondition::Brune },
         { "Given", BoundaryCondition::Given }
      };
   };

} // namespace enums

#endif
