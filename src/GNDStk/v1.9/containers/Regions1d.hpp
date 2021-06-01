
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V1_9_CONTAINERS_REGIONS1D
#define NJOY_GNDSTK_V1_9_CONTAINERS_REGIONS1D

// core interface
#include "GNDStk.hpp"

// v1.9 dependencies
#include "GNDStk/v1.9/containers/XYs1d.hpp"
#include "GNDStk/v1.9/containers/Axes.hpp"

namespace njoy {
namespace GNDStk {
namespace v1_9 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// containers::
// class Regions1d
// -----------------------------------------------------------------------------

namespace containers {

class Regions1d : public Component<Regions1d> {

   // ------------------------
   // For Component
   // ------------------------

   friend class Component<Regions1d>;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "containers"; }
   static auto className() { return "Regions1d"; }
   static auto GNDSName() { return "regions1d"; }

   // Core Interface construct to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         std::optional<XMLName>{}
            / Meta<>("label") |
         std::optional<Float64>{}
            / Meta<>("outerDomainValue") |
         // children
         containers::XYs1d{}
            / --Child<>("XYs1d") |
         std::optional<containers::Axes>{}
            / --Child<>("axes")
      ;
   }

public:

   // Base classes
   using BaseComponent = Component<Regions1d>;
   using BaseBodyText = BodyText<false>;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static const struct {
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      std::optional<XMLName> label;
      std::optional<Float64> outerDomainValue;

      // children
      containers::XYs1d XYs1d;
      std::optional<containers::Axes> axes;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

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

   // XYs1d
   const auto &XYs1d() const
    { return content.XYs1d; }
   auto &XYs1d()
    { return content.XYs1d; }

   // axes
   const auto &axes() const
    { return content.axes; }
   auto &axes()
    { return content.axes; }

   // ------------------------
   // Setters
   // non-const
   // ------------------------

   // label
   auto &label(const std::optional<XMLName> &obj)
    { content.label = obj; return *this; }

   // outerDomainValue
   auto &outerDomainValue(const std::optional<Float64> &obj)
    { content.outerDomainValue = obj; return *this; }

   // XYs1d
   auto &XYs1d(const containers::XYs1d &obj)
    { content.XYs1d = obj; return *this; }

   // axes
   auto &axes(const std::optional<containers::Axes> &obj)
    { content.axes = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Regions1d() :
      Component{
         BaseBodyText{},
         content.label,
         content.outerDomainValue,
         content.XYs1d,
         content.axes
      }
   {
      bodyTextUpdate(content);
      construct();
   }

   // copy
   Regions1d(const Regions1d &other) :
      Component{
         other,
         content.label,
         content.outerDomainValue,
         content.XYs1d,
         content.axes
      },
      content{other.content}
   {
      bodyTextUpdate(content);
      construct(other);
   }

   // move
   Regions1d(Regions1d &&other) :
      Component{
         other,
         content.label,
         content.outerDomainValue,
         content.XYs1d,
         content.axes
      },
      content{std::move(other.content)}
   {
      bodyTextUpdate(content);
      construct(other);
   }

   // from node
   Regions1d(const Node &node) :
      Component{
         BaseBodyText{},
         content.label,
         content.outerDomainValue,
         content.XYs1d,
         content.axes
      }
   {
      fromNode(node);
      bodyTextUpdate(content);
      construct(node);
   }

   // from fields
   explicit Regions1d(
      const std::optional<XMLName> &label,
      const std::optional<Float64> &outerDomainValue,
      const containers::XYs1d &XYs1d,
      const std::optional<containers::Axes> &axes
   ) :
      Component{
         BaseBodyText{},
         content.label,
         content.outerDomainValue,
         content.XYs1d,
         content.axes
      },
      content{
         label,
         outerDomainValue,
         XYs1d,
         axes
      }
   {
      bodyTextUpdate(content);
      construct();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Regions1d &operator=(const Regions1d &) = default;

   // move
   Regions1d &operator=(Regions1d &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v1.9/containers/Regions1d/src/custom.hpp"

}; // class Regions1d

} // namespace containers

} // namespace v1_9
} // namespace GNDStk
} // namespace njoy

#endif
