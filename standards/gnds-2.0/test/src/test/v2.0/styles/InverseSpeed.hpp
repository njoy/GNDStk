
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_STYLES_INVERSESPEED
#define TEST_V2_0_STYLES_INVERSESPEED

#include "test/v2.0/containers/Gridded1d.hpp"

namespace test {
namespace v2_0 {
namespace styles {

// -----------------------------------------------------------------------------
// styles::
// class InverseSpeed
// -----------------------------------------------------------------------------

class InverseSpeed : public Component<styles::InverseSpeed> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "styles"; }
   static auto CLASS() { return "InverseSpeed"; }
   static auto FIELD() { return "inverseSpeed"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::optional<XMLName>{}
            / Meta<>("label") |
         // children
         --Child<containers::Gridded1d>("gridded1d")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::optional<XMLName>> label{this};

   // children
   Field<containers::Gridded1d> gridded1d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->gridded1d)

   // default
   InverseSpeed() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields
   explicit InverseSpeed(
      const wrapper<std::optional<XMLName>> &label,
      const wrapper<containers::Gridded1d> &gridded1d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      gridded1d(this,gridded1d)
   {
      Component::finish();
   }

   // from node
   explicit InverseSpeed(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   InverseSpeed(const InverseSpeed &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      label(this,other.label),
      gridded1d(this,other.gridded1d)
   {
      Component::finish(other);
   }

   // move
   InverseSpeed(InverseSpeed &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      label(this,std::move(other.label)),
      gridded1d(this,std::move(other.gridded1d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   InverseSpeed &operator=(const InverseSpeed &) = default;
   InverseSpeed &operator=(InverseSpeed &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/styles/InverseSpeed/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class InverseSpeed

} // namespace styles
} // namespace v2_0
} // namespace test

#endif
