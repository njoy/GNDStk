
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_TSL_BRAGGEDGES
#define TEST_V2_0_TSL_BRAGGEDGES

#include "test/v2.0/tsl/BraggEdge.hpp"

namespace test {
namespace v2_0 {
namespace tsl {

// -----------------------------------------------------------------------------
// tsl::
// class BraggEdges
// -----------------------------------------------------------------------------

class BraggEdges : public Component<tsl::BraggEdges> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "tsl"; }
   static auto CLASS() { return "BraggEdges"; }
   static auto FIELD() { return "BraggEdges"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         tsl::BraggEdge{}
            / ++Child<>("BraggEdge")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::vector<tsl::BraggEdge>> BraggEdge{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->BraggEdge)

   // default, and from fields
   explicit BraggEdges(
      const wrapper<std::vector<tsl::BraggEdge>> &BraggEdge = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      BraggEdge(this,BraggEdge)
   {
      Component::finish();
   }

   // from node
   explicit BraggEdges(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   BraggEdges(const BraggEdges &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   BraggEdges(BraggEdges &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   BraggEdges &operator=(const BraggEdges &) = default;
   BraggEdges &operator=(BraggEdges &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/tsl/BraggEdges/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class BraggEdges

} // namespace tsl
} // namespace v2_0
} // namespace test

#endif
