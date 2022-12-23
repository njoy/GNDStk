
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_TSL_SCATTERINGATOMS
#define TEST_V2_0_TSL_SCATTERINGATOMS

#include "test/v2.0/tsl/ScatteringAtom.hpp"

namespace test {
namespace v2_0 {
namespace tsl {

// -----------------------------------------------------------------------------
// tsl::
// class ScatteringAtoms
// -----------------------------------------------------------------------------

class ScatteringAtoms : public Component<tsl::ScatteringAtoms> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "tsl"; }
   static auto CLASS() { return "ScatteringAtoms"; }
   static auto FIELD() { return "scatteringAtoms"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         ++Child<tsl::ScatteringAtom>("scatteringAtom")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::vector<tsl::ScatteringAtom>> scatteringAtom{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->scatteringAtom)

   // default
   ScatteringAtoms() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields
   explicit ScatteringAtoms(
      const wrapper<std::vector<tsl::ScatteringAtom>> &scatteringAtom
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      scatteringAtom(this,scatteringAtom)
   {
      Component::finish();
   }

   // from node
   explicit ScatteringAtoms(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ScatteringAtoms(const ScatteringAtoms &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      scatteringAtom(this,other.scatteringAtom)
   {
      Component::finish(other);
   }

   // move
   ScatteringAtoms(ScatteringAtoms &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      scatteringAtom(this,std::move(other.scatteringAtom))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   ScatteringAtoms &operator=(const ScatteringAtoms &) = default;
   ScatteringAtoms &operator=(ScatteringAtoms &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/tsl/ScatteringAtoms/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ScatteringAtoms

} // namespace tsl
} // namespace v2_0
} // namespace test

#endif
