
// THIS FILE WAS AUTOGENERATED!
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

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         std::optional<int>{}
            / Meta<>("index") |
         Defaulted<enums::Interpolation>{enums::Interpolation::linlin}
            / Meta<>("interpolation") |
         std::optional<std::string>{}
            / Meta<>("label") |
         std::optional<double>{}
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
      std::optional<int> index;
      Defaulted<enums::Interpolation> interpolation{enums::Interpolation::linlin};
      std::optional<std::string> label;
      std::optional<double> outerDomainValue;
      // children
      std::optional<containers::Axes> axes;
      containers::Values values;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // index
   const std::optional<int> &index() const
      { return content.index; }
   std::optional<int> &index()
      { return content.index; }

   // interpolation
   const Defaulted<enums::Interpolation> &interpolation() const
      { return content.interpolation; }
   Defaulted<enums::Interpolation> &interpolation()
      { return content.interpolation; }

   // label
   const std::optional<std::string> &label() const
      { return content.label; }
   std::optional<std::string> &label()
      { return content.label; }

   // outerDomainValue
   const std::optional<double> &outerDomainValue() const
      { return content.outerDomainValue; }
   std::optional<double> &outerDomainValue()
      { return content.outerDomainValue; }

   // axes
   const std::optional<containers::Axes> &axes() const
      { return content.axes; }
   std::optional<containers::Axes> &axes()
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

   // index(value)
   XYs1d &index(const std::optional<int> &obj)
      { index() = obj; return *this; }

   // interpolation(value)
   XYs1d &interpolation(const Defaulted<enums::Interpolation> &obj)
      { content.interpolation = obj; return *this; }
   XYs1d &interpolation(const std::optional<enums::Interpolation> &obj)
      { content.interpolation = obj; return *this; }

   // label(value)
   XYs1d &label(const std::optional<std::string> &obj)
      { label() = obj; return *this; }

   // outerDomainValue(value)
   XYs1d &outerDomainValue(const std::optional<double> &obj)
      { outerDomainValue() = obj; return *this; }

   // axes(value)
   XYs1d &axes(const std::optional<containers::Axes> &obj)
      { axes() = obj; return *this; }

   // values(value)
   XYs1d &values(const containers::Values &obj)
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
   // std::optional replaces Defaulted; this class knows the default(s)
   explicit XYs1d(
      const std::optional<int> &index,
      const std::optional<enums::Interpolation> &interpolation,
      const std::optional<std::string> &label,
      const std::optional<double> &outerDomainValue,
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
         Defaulted<enums::Interpolation>(defaults.interpolation,interpolation),
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
