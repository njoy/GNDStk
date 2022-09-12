
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_TRANSPORT_BRANCHING3D
#define TEST_V2_0_TRANSPORT_BRANCHING3D

#include "test/v2.0/key.hpp"

namespace test {
namespace v2_0 {
namespace transport {

// -----------------------------------------------------------------------------
// transport::
// class Branching3d
// -----------------------------------------------------------------------------

class Branching3d : public Component<transport::Branching3d> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "transport"; }
   static auto CLASS() { return "Branching3d"; }
   static auto FIELD() { return "branching3d"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("label") |
         XMLName{}
            / Meta<>("productFrame")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<XMLName> label{this};
   Field<XMLName> productFrame{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->productFrame)

   // default, and from fields
   explicit Branching3d(
      const wrapper<XMLName> &label = {},
      const wrapper<XMLName> &productFrame = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      productFrame(this,productFrame)
   {
      Component::finish();
   }

   // from node
   explicit Branching3d(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Branching3d(const Branching3d &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Branching3d(Branching3d &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Branching3d &operator=(const Branching3d &) = default;
   Branching3d &operator=(Branching3d &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/transport/Branching3d/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Branching3d

} // namespace transport
} // namespace v2_0
} // namespace test

#endif