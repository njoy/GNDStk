
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_CONTAINERS_YS1D
#define TEST_V2_0_CONTAINERS_YS1D

#include "test/v2.0/containers/Axes.hpp"
#include "test/v2.0/containers/Values.hpp"

namespace test {
namespace v2_0 {
namespace containers {

// -----------------------------------------------------------------------------
// containers::
// class Ys1d
// -----------------------------------------------------------------------------

class Ys1d : public Component<containers::Ys1d> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "containers"; }
   static auto CLASS() { return "Ys1d"; }
   static auto FIELD() { return "Ys1d"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         Defaulted<enums::Interpolation>{enums::Interpolation::linlin}
            / Meta<>("interpolation") |
         std::optional<XMLName>{}
            / Meta<>("label") |
         // children
         --Child<containers::Axes>("axes") |
         --Child<containers::Values>("values")
      ;
   }

public:
   using Component::construct;

   // defaults
   static inline const struct Defaults {
      static inline const enums::Interpolation interpolation = enums::Interpolation::linlin;
   } defaults;

   // metadata
   Field<Defaulted<enums::Interpolation>> interpolation{this,defaults.interpolation};
   Field<std::optional<XMLName>> label{this};

   // children
   Field<containers::Axes> axes{this};
   Field<containers::Values> values{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->interpolation, \
      this->label, \
      this->axes, \
      this->values)

   // default
   Ys1d() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields
   // std::optional replaces Defaulted; this class knows the default(s)
   explicit Ys1d(
      const wrapper<std::optional<enums::Interpolation>> &interpolation,
      const wrapper<std::optional<XMLName>> &label = {},
      const wrapper<containers::Axes> &axes = {},
      const wrapper<containers::Values> &values = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      interpolation(this,defaults.interpolation,interpolation),
      label(this,label),
      axes(this,axes),
      values(this,values)
   {
      Component::finish();
   }

   // from node
   explicit Ys1d(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Ys1d(const Ys1d &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      interpolation(this,other.interpolation),
      label(this,other.label),
      axes(this,other.axes),
      values(this,other.values)
   {
      Component::finish(other);
   }

   // move
   Ys1d(Ys1d &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      interpolation(this,std::move(other.interpolation)),
      label(this,std::move(other.label)),
      axes(this,std::move(other.axes)),
      values(this,std::move(other.values))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Ys1d &operator=(const Ys1d &) = default;
   Ys1d &operator=(Ys1d &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/containers/Ys1d/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Ys1d

} // namespace containers
} // namespace v2_0
} // namespace test

#endif
