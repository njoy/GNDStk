
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_CONTAINERS_GRIDDED1D
#define TEST_V2_0_CONTAINERS_GRIDDED1D

#include "test/v2.0/containers/Array.hpp"
#include "test/v2.0/containers/Axes.hpp"

namespace test {
namespace v2_0 {
namespace containers {

// -----------------------------------------------------------------------------
// containers::
// class Gridded1d
// -----------------------------------------------------------------------------

class Gridded1d : public Component<containers::Gridded1d> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "containers"; }
   static auto CLASS() { return "Gridded1d"; }
   static auto FIELD() { return "gridded1d"; }

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
   explicit Gridded1d(
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
   explicit Gridded1d(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Gridded1d(const Gridded1d &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Gridded1d(Gridded1d &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Gridded1d &operator=(const Gridded1d &) = default;
   Gridded1d &operator=(Gridded1d &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/containers/Gridded1d/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Gridded1d

} // namespace containers
} // namespace v2_0
} // namespace test

#endif
