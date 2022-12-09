
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_CONTAINERS_REGIONS2D
#define TEST_V2_0_CONTAINERS_REGIONS2D

#include "test/v2.0/containers/Axes.hpp"
#include "test/v2.0/containers/Function2ds.hpp"
#include "test/v2.0/containers/Uncertainty.hpp"

namespace test {
namespace v2_0 {
namespace containers {

// -----------------------------------------------------------------------------
// containers::
// class Regions2d
// -----------------------------------------------------------------------------

class Regions2d : public Component<containers::Regions2d> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "containers"; }
   static auto CLASS() { return "Regions2d"; }
   static auto FIELD() { return "regions2d"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::optional<XMLName>{}
            / Meta<>("label") |
         std::optional<Float64>{}
            / Meta<>("outerDomainValue") |
         // children
         std::optional<containers::Axes>{}
            / --Child<>("axes") |
         containers::Function2ds{}
            / --Child<>("function2ds") |
         std::optional<containers::Uncertainty>{}
            / --Child<>("uncertainty")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::optional<XMLName>> label{this};
   Field<std::optional<Float64>> outerDomainValue{this};

   // children
   Field<std::optional<containers::Axes>> axes{this};
   Field<containers::Function2ds> function2ds{this};
   Field<std::optional<containers::Uncertainty>> uncertainty{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->outerDomainValue, \
      this->axes, \
      this->function2ds, \
      this->uncertainty)

   // default, and from fields
   explicit Regions2d(
      const wrapper<std::optional<XMLName>> &label = {},
      const wrapper<std::optional<Float64>> &outerDomainValue = {},
      const wrapper<std::optional<containers::Axes>> &axes = {},
      const wrapper<containers::Function2ds> &function2ds = {},
      const wrapper<std::optional<containers::Uncertainty>> &uncertainty = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      outerDomainValue(this,outerDomainValue),
      axes(this,axes),
      function2ds(this,function2ds),
      uncertainty(this,uncertainty)
   {
      Component::finish();
   }

   // from node
   explicit Regions2d(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Regions2d(const Regions2d &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Regions2d(Regions2d &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Regions2d &operator=(const Regions2d &) = default;
   Regions2d &operator=(Regions2d &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/containers/Regions2d/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Regions2d

} // namespace containers
} // namespace v2_0
} // namespace test

#endif
