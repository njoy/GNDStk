
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_POPS_AVERAGEENERGIES
#define TEST_V2_0_POPS_AVERAGEENERGIES

#include "test/v2.0/pops/AverageEnergy.hpp"

namespace test {
namespace v2_0 {
namespace pops {

// -----------------------------------------------------------------------------
// pops::
// class AverageEnergies
// -----------------------------------------------------------------------------

class AverageEnergies : public Component<pops::AverageEnergies> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "pops"; }
   static auto CLASS() { return "AverageEnergies"; }
   static auto FIELD() { return "averageEnergies"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         pops::AverageEnergy{}
            / ++Child<>("averageEnergy")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::vector<pops::AverageEnergy>> averageEnergy{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->averageEnergy)

   // default, and from fields
   explicit AverageEnergies(
      const wrapper<std::vector<pops::AverageEnergy>> &averageEnergy = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      averageEnergy(this,averageEnergy)
   {
      Component::finish();
   }

   // from node
   explicit AverageEnergies(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   AverageEnergies(const AverageEnergies &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   AverageEnergies(AverageEnergies &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   AverageEnergies &operator=(const AverageEnergies &) = default;
   AverageEnergies &operator=(AverageEnergies &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/pops/AverageEnergies/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class AverageEnergies

} // namespace pops
} // namespace v2_0
} // namespace test

#endif
