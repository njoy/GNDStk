
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_CONTAINERS_XYS3D
#define TEST_V2_0_CONTAINERS_XYS3D

#include "test/v2.0/containers/Axes.hpp"
#include "test/v2.0/containers/Function2ds.hpp"
#include "test/v2.0/containers/Uncertainty.hpp"

namespace test {
namespace v2_0 {
namespace containers {

// -----------------------------------------------------------------------------
// containers::
// class XYs3d
// -----------------------------------------------------------------------------

class XYs3d : public Component<containers::XYs3d> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "containers"; }
   static auto CLASS() { return "XYs3d"; }
   static auto FIELD() { return "XYs3d"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         Defaulted<enums::Interpolation>{enums::Interpolation::linlin}
            / Meta<>("interpolation") |
         std::optional<XMLName>{}
            / Meta<>("interpolationQualifier") |
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

   // defaults
   static inline const struct Defaults {
      static inline const enums::Interpolation interpolation = enums::Interpolation::linlin;
   } defaults;

   // metadata
   Field<Defaulted<enums::Interpolation>> interpolation{this,defaults.interpolation};
   Field<std::optional<XMLName>> interpolationQualifier{this};

   // children
   Field<std::optional<containers::Axes>> axes{this};
   Field<containers::Function2ds> function2ds{this};
   Field<std::optional<containers::Uncertainty>> uncertainty{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->interpolation, \
      this->interpolationQualifier, \
      this->axes, \
      this->function2ds, \
      this->uncertainty)

   // default, and from fields
   // std::optional replaces Defaulted; this class knows the default(s)
   explicit XYs3d(
      const wrapper<std::optional<enums::Interpolation>> &interpolation = {},
      const wrapper<std::optional<XMLName>> &interpolationQualifier = {},
      const wrapper<std::optional<containers::Axes>> &axes = {},
      const wrapper<containers::Function2ds> &function2ds = {},
      const wrapper<std::optional<containers::Uncertainty>> &uncertainty = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      interpolation(this,defaults.interpolation,interpolation),
      interpolationQualifier(this,interpolationQualifier),
      axes(this,axes),
      function2ds(this,function2ds),
      uncertainty(this,uncertainty)
   {
      Component::finish();
   }

   // from node
   explicit XYs3d(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   XYs3d(const XYs3d &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   XYs3d(XYs3d &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   XYs3d &operator=(const XYs3d &) = default;
   XYs3d &operator=(XYs3d &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/containers/XYs3d/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class XYs3d

} // namespace containers
} // namespace v2_0
} // namespace test

#endif
