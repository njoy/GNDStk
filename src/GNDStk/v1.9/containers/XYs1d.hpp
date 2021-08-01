
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V1_9_CONTAINERS_XYS1D
#define NJOY_GNDSTK_V1_9_CONTAINERS_XYS1D

// core interface
#include "GNDStk.hpp"

// v1.9 dependencies
#include "GNDStk/v1.9/containers/Axes.hpp"
#include "GNDStk/v1.9/containers/Values.hpp"

namespace njoy {
namespace GNDStk {
namespace v1_9 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// containers::
// class XYs1d
// -----------------------------------------------------------------------------

namespace containers {

class XYs1d : public Component<XYs1d> {

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "containers"; }
   static auto className() { return "XYs1d"; }
   static auto GNDSName() { return "XYs1d"; }

   // Core Interface object to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         std::optional<Integer32>{}
            / key::meta::index |
         Defaulted<enums::Interpolation>{enums::Interpolation::linlin}
            / key::meta::interpolation |
         std::optional<XMLName>{}
            / key::meta::label |
         std::optional<Float64>{}
            / key::meta::outerDomainValue |
         // children
         std::optional<containers::Axes>{}
            / --key::child::axes |
         containers::Values{}
            / --key::child::values
      ;
   }

public:

   using Component::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static const struct {
      const enums::Interpolation interpolation{enums::Interpolation::linlin};
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      std::optional<Integer32> index;
      Defaulted<enums::Interpolation> interpolation{enums::Interpolation::linlin};
      std::optional<XMLName> label;
      std::optional<Float64> outerDomainValue;

      // children
      std::optional<containers::Axes> axes;
      containers::Values values;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // index
   const std::optional<Integer32> &
   index() const
    { return content.index; }
   std::optional<Integer32> &
   index()
    { return content.index; }

   // interpolation
   const enums::Interpolation
   interpolation() const
    { return content.interpolation.value(); }
   enums::Interpolation
   interpolation()
    { return content.interpolation.value(); }

   // label
   const std::optional<XMLName> &
   label() const
    { return content.label; }
   std::optional<XMLName> &
   label()
    { return content.label; }

   // outerDomainValue
   const std::optional<Float64> &
   outerDomainValue() const
    { return content.outerDomainValue; }
   std::optional<Float64> &
   outerDomainValue()
    { return content.outerDomainValue; }

   // axes
   const std::optional<containers::Axes> &
   axes() const
    { return content.axes; }
   std::optional<containers::Axes> &
   axes()
    { return content.axes; }

   // values
   const containers::Values &
   values() const
    { return content.values; }
   containers::Values &
   values()
    { return content.values; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // index(value)
   auto &index(const std::optional<Integer32> &obj)
    { index() = obj; return *this; }

   // interpolation(value)
   auto &interpolation(const Defaulted<enums::Interpolation> &obj)
    { content.interpolation = obj; return *this; }
   auto &interpolation(const enums::Interpolation &obj)
    { content.interpolation = obj; return *this; }

   // label(value)
   auto &label(const std::optional<XMLName> &obj)
    { label() = obj; return *this; }

   // outerDomainValue(value)
   auto &outerDomainValue(const std::optional<Float64> &obj)
    { outerDomainValue() = obj; return *this; }

   // axes(value)
   auto &axes(const std::optional<containers::Axes> &obj)
    { axes() = obj; return *this; }

   // values(value)
   auto &values(const containers::Values &obj)
    { values() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   XYs1d() :
      Component{
         BodyText{},
         content.index,
         content.interpolation,
         content.label,
         content.outerDomainValue,
         content.axes,
         content.values
      }
   {
      Component::finish();
   }

   // copy
   XYs1d(const XYs1d &other) :
      Component{
         other,
         content.index,
         content.interpolation,
         content.label,
         content.outerDomainValue,
         content.axes,
         content.values
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   XYs1d(XYs1d &&other) :
      Component{
         other,
         content.index,
         content.interpolation,
         content.label,
         content.outerDomainValue,
         content.axes,
         content.values
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   XYs1d(const Node &node) :
      Component{
         BodyText{},
         content.index,
         content.interpolation,
         content.label,
         content.outerDomainValue,
         content.axes,
         content.values
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit XYs1d(
      const std::optional<Integer32> &index,
      const Defaulted<enums::Interpolation> &interpolation,
      const std::optional<XMLName> &label,
      const std::optional<Float64> &outerDomainValue,
      const std::optional<containers::Axes> &axes,
      const containers::Values &values
   ) :
      Component{
         BodyText{},
         content.index,
         content.interpolation,
         content.label,
         content.outerDomainValue,
         content.axes,
         content.values
      },
      content{
         index,
         interpolation,
         label,
         outerDomainValue,
         axes,
         values
      }
   {
      Component::finish();
   }

   // from fields, with T replacing Defaulted<T>
   explicit XYs1d(
      const std::optional<Integer32> &index,
      const enums::Interpolation &interpolation,
      const std::optional<XMLName> &label,
      const std::optional<Float64> &outerDomainValue,
      const std::optional<containers::Axes> &axes,
      const containers::Values &values
   ) :
      Component{
         BodyText{},
         content.index,
         content.interpolation,
         content.label,
         content.outerDomainValue,
         content.axes,
         content.values
      },
      content{
         index,
         interpolation == enums::Interpolation::linlin
            ? Defaulted<enums::Interpolation>{enums::Interpolation::linlin}
            : Defaulted<enums::Interpolation>{enums::Interpolation::linlin,interpolation},
         label,
         outerDomainValue,
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
   XYs1d &operator=(const XYs1d &) = default;

   // move
   XYs1d &operator=(XYs1d &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v1.9/containers/XYs1d/src/custom.hpp"

}; // class XYs1d

} // namespace containers

} // namespace v1_9
} // namespace GNDStk
} // namespace njoy

#endif
