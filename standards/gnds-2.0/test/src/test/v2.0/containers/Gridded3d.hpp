
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_CONTAINERS_GRIDDED3D
#define TEST_V2_0_CONTAINERS_GRIDDED3D

#include "test/v2.0/containers/Array.hpp"
#include "test/v2.0/containers/Axes.hpp"

namespace test {
namespace v2_0 {
namespace containers {

// -----------------------------------------------------------------------------
// containers::
// class Gridded3d
// -----------------------------------------------------------------------------

class Gridded3d : public Component<containers::Gridded3d> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "containers"; }
   static auto CLASS() { return "Gridded3d"; }
   static auto FIELD() { return "gridded3d"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::optional<XMLName>{}
            / Meta<>("label") |
         // children
         containers::Array{}
            / --Child<>("array") |
         containers::Axes{}
            / --Child<>("axes")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::optional<XMLName>> label{this};

   // children
   Field<containers::Array> array{this};
   Field<containers::Axes> axes{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->array, \
      this->axes)

   // default, and from fields
   explicit Gridded3d(
      const wrapper<std::optional<XMLName>> &label = {},
      const wrapper<containers::Array> &array = {},
      const wrapper<containers::Axes> &axes = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      array(this,array),
      axes(this,axes)
   {
      Component::finish();
   }

   // from node
   explicit Gridded3d(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Gridded3d(const Gridded3d &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Gridded3d(Gridded3d &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Gridded3d &operator=(const Gridded3d &) = default;
   Gridded3d &operator=(Gridded3d &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/containers/Gridded3d/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Gridded3d

} // namespace containers
} // namespace v2_0
} // namespace test

#endif