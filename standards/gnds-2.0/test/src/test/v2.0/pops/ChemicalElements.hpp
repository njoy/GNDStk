
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_POPS_CHEMICALELEMENTS
#define TEST_V2_0_POPS_CHEMICALELEMENTS

#include "test/v2.0/pops/ChemicalElement.hpp"

namespace test {
namespace v2_0 {
namespace pops {

// -----------------------------------------------------------------------------
// pops::
// class ChemicalElements
// -----------------------------------------------------------------------------

class ChemicalElements : public Component<pops::ChemicalElements> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "pops"; }
   static auto CLASS() { return "ChemicalElements"; }
   static auto FIELD() { return "chemicalElements"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         ++Child<std::optional<pops::ChemicalElement>>("chemicalElement")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::optional<std::vector<pops::ChemicalElement>>> chemicalElement{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->chemicalElement)

   // default
   ChemicalElements() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields
   explicit ChemicalElements(
      const wrapper<std::optional<std::vector<pops::ChemicalElement>>> &chemicalElement
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      chemicalElement(this,chemicalElement)
   {
      Component::finish();
   }

   // from node
   explicit ChemicalElements(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ChemicalElements(const ChemicalElements &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      chemicalElement(this,other.chemicalElement)
   {
      Component::finish(other);
   }

   // move
   ChemicalElements(ChemicalElements &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      chemicalElement(this,std::move(other.chemicalElement))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   ChemicalElements &operator=(const ChemicalElements &) = default;
   ChemicalElements &operator=(ChemicalElements &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/pops/ChemicalElements/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ChemicalElements

} // namespace pops
} // namespace v2_0
} // namespace test

#endif
