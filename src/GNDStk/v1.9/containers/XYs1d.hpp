
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
   // for Component
   // ------------------------

   friend class Component<XYs1d>;

   static auto className() { return "XYs1d"; }
   static auto GNDSField() { return "XYs1d"; }

   static auto keys()
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

   // ------------------------
   // relevant defaults
   // FYI for users
   // ------------------------

   static const struct {
      const enums::Interpolation interpolation{enums::Interpolation::linlin};
   } defaults;

   // ------------------------
   // raw GNDS content
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
   // getters
   // const and non-const
   // ------------------------

   // index
   const auto &index() const
    { return content.index; }
   auto &index()
    { return content.index; }

   // interpolation
   const auto &interpolation() const
    { return content.interpolation.value(); }
   auto &interpolation()
    { return content.interpolation.value(); }

   // label
   const auto &label() const
    { return content.label; }
   auto &label()
    { return content.label; }

   // outerDomainValue
   const auto &outerDomainValue() const
    { return content.outerDomainValue; }
   auto &outerDomainValue()
    { return content.outerDomainValue; }

   // axes
   const auto &axes() const
    { return content.axes; }
   auto &axes()
    { return content.axes; }

   // values
   const auto &values() const
    { return content.values; }
   auto &values()
    { return content.values; }

   // ------------------------
   // setters
   // non-const only
   // ------------------------

   // index
   auto &index(const std::optional<Integer32> &obj)
    { content.index = obj; return *this; }

   // interpolation
   auto &interpolation(const Defaulted<enums::Interpolation> &obj)
    { content.interpolation = obj; return *this; }
   auto &interpolation(const enums::Interpolation &obj)
    { content.interpolation = obj; return *this; }

   // label
   auto &label(const std::optional<XMLName> &obj)
    { content.label = obj; return *this; }

   // outerDomainValue
   auto &outerDomainValue(const std::optional<Float64> &obj)
    { content.outerDomainValue = obj; return *this; }

   // axes
   auto &axes(const std::optional<containers::Axes> &obj)
    { content.axes = obj; return *this; }

   // values
   auto &values(const containers::Values &obj)
    { content.values = obj; return *this; }

   // ------------------------
   // construction
   // ------------------------

   // default
   XYs1d() :
      Component{
         content.index,
         content.interpolation,
         content.label,
         content.outerDomainValue,
         content.axes,
         content.values
      }
   {
      construct();
   }

   // copy
   XYs1d(const XYs1d &other) :
      Component{
         content.index,
         content.interpolation,
         content.label,
         content.outerDomainValue,
         content.axes,
         content.values
      },
      content{other.content}
   {
      construct();
   }

   // move
   XYs1d(XYs1d &&other) :
      Component{
         content.index,
         content.interpolation,
         content.label,
         content.outerDomainValue,
         content.axes,
         content.values
      },
      content{std::move(other.content)}
   {
      construct();
   }

   // from node
   XYs1d(const Node &node) :
      Component{
         content.index,
         content.interpolation,
         content.label,
         content.outerDomainValue,
         content.axes,
         content.values
      }
   {
      query(node);
      construct();
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
      construct();
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
      construct();
   }

   // ------------------------
   // assignment
   // ------------------------

   // copy
   XYs1d &operator=(const XYs1d &) = default;

   // move
   XYs1d &operator=(XYs1d &&) = default;

   // ------------------------
   // custom functionality
   // ------------------------

   #include "GNDStk/v1.9/containers/XYs1d/src/custom.hpp"

}; // class XYs1d

} // namespace containers

} // namespace v1_9
} // namespace GNDStk
} // namespace njoy

#endif
