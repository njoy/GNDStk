
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_CONTAINERS_REGIONS1D
#define TRY_V2_0_CONTAINERS_REGIONS1D

#include "try/v2.0/containers/Axes.hpp"
#include "try/v2.0/containers/Function1ds.hpp"

namespace try {
namespace v2_0 {
namespace containers {

// -----------------------------------------------------------------------------
// containers::
// class Regions1d
// -----------------------------------------------------------------------------

class Regions1d : public Component<containers::Regions1d> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "containers"; }
   static auto CLASS() { return "Regions1d"; }
   static auto FIELD() { return "regions1d"; }

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
         containers::Function1ds{}
            / --Child<>("function1ds")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::optional<XMLName>> label{this};
   Field<std::optional<Float64>> outerDomainValue{this};

   // children
   Field<std::optional<containers::Axes>> axes{this};
   Field<containers::Function1ds> function1ds{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->outerDomainValue, \
      this->axes, \
      this->function1ds)

   // default, and from fields
   explicit Regions1d(
      const wrapper<std::optional<XMLName>> &label = {},
      const wrapper<std::optional<Float64>> &outerDomainValue = {},
      const wrapper<std::optional<containers::Axes>> &axes = {},
      const wrapper<containers::Function1ds> &function1ds = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      outerDomainValue(this,outerDomainValue),
      axes(this,axes),
      function1ds(this,function1ds)
   {
      Component::finish();
   }

   // from node
   explicit Regions1d(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Regions1d(const Regions1d &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Regions1d(Regions1d &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Regions1d &operator=(const Regions1d &) = default;
   Regions1d &operator=(Regions1d &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/containers/Regions1d/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Regions1d

} // namespace containers
} // namespace v2_0
} // namespace try

#endif
