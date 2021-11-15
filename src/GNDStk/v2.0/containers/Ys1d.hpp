
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_CONTAINERS_YS1D
#define NJOY_GNDSTK_V2_0_CONTAINERS_YS1D

// core interface
#include "GNDStk.hpp"

// v2.0 dependencies
#include "GNDStk/v2.0/containers/Axes.hpp"
#include "GNDStk/v2.0/containers/Values.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// containers::
// class Ys1d
// -----------------------------------------------------------------------------

namespace containers {

class Ys1d : public Component<Ys1d> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "containers"; }
   static auto className() { return "Ys1d"; }
   static auto GNDSName() { return "Ys1d"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         Defaulted<enums::Interpolation>{enums::Interpolation::linlin}
            / Meta<>("interpolation") |
         std::optional<XMLName>{}
            / Meta<>("label") |
         // children
         containers::Axes{}
            / --Child<>("axes") |
         containers::Values{}
            / --Child<>("values")
      ;
   }

public:

   using Component::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static inline const struct Defaults {
      static inline const enums::Interpolation interpolation = enums::Interpolation::linlin;
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      Defaulted<enums::Interpolation> interpolation{enums::Interpolation::linlin};
      std::optional<XMLName> label;
      // children
      containers::Axes axes;
      containers::Values values;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // interpolation
   const Defaulted<enums::Interpolation> &interpolation() const
      { return content.interpolation; }
   Defaulted<enums::Interpolation> &interpolation()
      { return content.interpolation; }

   // label
   const std::optional<XMLName> &label() const
      { return content.label; }
   std::optional<XMLName> &label()
      { return content.label; }

   // axes
   const containers::Axes &axes() const
      { return content.axes; }
   containers::Axes &axes()
      { return content.axes; }

   // values
   const containers::Values &values() const
      { return content.values; }
   containers::Values &values()
      { return content.values; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // interpolation(value)
   Ys1d &interpolation(const Defaulted<enums::Interpolation> &obj)
      { content.interpolation = obj; return *this; }
   Ys1d &interpolation(const std::optional<enums::Interpolation> &obj)
      { content.interpolation = obj; return *this; }

   // label(value)
   Ys1d &label(const std::optional<XMLName> &obj)
      { label() = obj; return *this; }

   // axes(value)
   Ys1d &axes(const containers::Axes &obj)
      { axes() = obj; return *this; }

   // values(value)
   Ys1d &values(const containers::Values &obj)
      { values() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Ys1d() :
      Component{
         BodyText{},
         content.interpolation,
         content.label,
         content.axes,
         content.values
      }
   {
      Component::finish();
   }

   // copy
   Ys1d(const Ys1d &other) :
      Component{
         other,
         content.interpolation,
         content.label,
         content.axes,
         content.values
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Ys1d(Ys1d &&other) :
      Component{
         other,
         content.interpolation,
         content.label,
         content.axes,
         content.values
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Ys1d(const Node &node) :
      Component{
         BodyText{},
         content.interpolation,
         content.label,
         content.axes,
         content.values
      }
   {
      Component::finish(node);
   }

   // from fields
   // std::optional replaces Defaulted; this class knows the default(s)
   explicit Ys1d(
      const std::optional<enums::Interpolation> &interpolation,
      const std::optional<XMLName> &label,
      const containers::Axes &axes,
      const containers::Values &values
   ) :
      Component{
         BodyText{},
         content.interpolation,
         content.label,
         content.axes,
         content.values
      },
      content{
         Defaulted<enums::Interpolation>(defaults.interpolation,interpolation),
         label,
         axes,
         values
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Ys1d &operator=(const Ys1d &) = default;

   // move
   Ys1d &operator=(Ys1d &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/containers/Ys1d/src/custom.hpp"

}; // class Ys1d

} // namespace containers
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif
