
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_CONTAINERS_XYS1D
#define TRY_V2_0_CONTAINERS_XYS1D

#include "try/v2.0/containers/Axes.hpp"
#include "try/v2.0/containers/Values.hpp"

namespace try {
namespace v2_0 {
namespace containers {

// -----------------------------------------------------------------------------
// containers::
// class XYs1d
// -----------------------------------------------------------------------------

class XYs1d : public Component<containers::XYs1d> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "containers"; }
   static auto CLASS() { return "XYs1d"; }
   static auto FIELD() { return "XYs1d"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::optional<Integer32>{}
            / Meta<>("index") |
         Defaulted<enums::Interpolation>{enums::Interpolation::linlin}
            / Meta<>("interpolation") |
         std::optional<XMLName>{}
            / Meta<>("label") |
         std::optional<Float64>{}
            / Meta<>("outerDomainValue") |
         // children
         std::optional<containers::Axes>{}
            / --Child<>("axes") |
         containers::Values{}
            / --Child<>("values")
      ;
   }

public:
   using Component::construct;

   // defaults
   static inline const struct Defaults {
      static inline const enums::Interpolation interpolation = enums::Interpolation::linlin;
   } defaults;

   // metadata
   Field<std::optional<Integer32>> index{this};
   Field<Defaulted<enums::Interpolation>> interpolation{this,defaults.interpolation};
   Field<std::optional<XMLName>> label{this};
   Field<std::optional<Float64>> outerDomainValue{this};

   // children
   Field<std::optional<containers::Axes>> axes{this};
   Field<containers::Values> values{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->index, \
      this->interpolation, \
      this->label, \
      this->outerDomainValue, \
      this->axes, \
      this->values)

   // default, and from fields
   // std::optional replaces Defaulted; this class knows the default(s)
   explicit XYs1d(
      const wrapper<std::optional<Integer32>> &index = {},
      const wrapper<std::optional<enums::Interpolation>> &interpolation = {},
      const wrapper<std::optional<XMLName>> &label = {},
      const wrapper<std::optional<Float64>> &outerDomainValue = {},
      const wrapper<std::optional<containers::Axes>> &axes = {},
      const wrapper<containers::Values> &values = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      index(this,index),
      interpolation(this,defaults.interpolation,interpolation),
      label(this,label),
      outerDomainValue(this,outerDomainValue),
      axes(this,axes),
      values(this,values)
   {
      Component::finish();
   }

   // from node
   explicit XYs1d(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   XYs1d(const XYs1d &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   XYs1d(XYs1d &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   XYs1d &operator=(const XYs1d &) = default;
   XYs1d &operator=(XYs1d &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/containers/XYs1d/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class XYs1d

} // namespace containers
} // namespace v2_0
} // namespace try

#endif
