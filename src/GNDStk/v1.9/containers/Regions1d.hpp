
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

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "containers"; }
   static auto className() { return "Regions1d"; }
   static auto GNDSName() { return "regions1d"; }

   // Core Interface object to extract metadata and child nodes
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
            / ++Child<>("XYs1d") |
         std::optional<containers::Axes>{}
            / --Child<>("axes")
      ;
   }

public:

   using Component::construct;

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
      std::vector<containers::XYs1d> XYs1d;
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

   // XYs1d(index)
   const auto &XYs1d(const std::size_t index) const
    { return getter(XYs1d(), index, "XYs1d"); }
   auto &XYs1d(const std::size_t index)
    { return getter(XYs1d(), index, "XYs1d"); }

   // XYs1d(label)
   const auto &XYs1d(const std::string &label) const
    { return getter(XYs1d(), label, "XYs1d"); }
   auto &XYs1d(const std::string &label)
    { return getter(XYs1d(), label, "XYs1d"); }

   // axes
   const auto &axes() const
    { return content.axes; }
   auto &axes()
    { return content.axes; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // label(value)
   auto &label(const std::optional<XMLName> &obj)
    { label() = obj; return *this; }

   // outerDomainValue(value)
   auto &outerDomainValue(const std::optional<Float64> &obj)
    { outerDomainValue() = obj; return *this; }

   // XYs1d(value)
   auto &XYs1d(const std::vector<containers::XYs1d> &obj)
    { XYs1d() = obj; return *this; }

   // XYs1d(index,value)
   auto &XYs1d(
      const std::size_t index,
      const containers::XYs1d &obj
   ) {
      XYs1d(index) = obj; return *this;
   }

   // XYs1d(label,value)
   auto &XYs1d(
      const std::string &label,
      const containers::XYs1d &obj
   ) {
      XYs1d(label) = obj; return *this;
   }

   // axes(value)
   auto &axes(const std::optional<containers::Axes> &obj)
    { axes() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Regions1d() :
      Component{
         BodyText{},
         content.label,
         content.outerDomainValue,
         content.XYs1d,
         content.axes
      }
   {
      Component::finish();
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
      Component::finish(other);
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
      Component::finish(other);
   }

   // from node
   Regions1d(const Node &node) :
      Component{
         BodyText{},
         content.label,
         content.outerDomainValue,
         content.XYs1d,
         content.axes
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Regions1d(
      const std::optional<XMLName> &label,
      const std::optional<Float64> &outerDomainValue,
      const std::vector<containers::XYs1d> &XYs1d,
      const std::optional<containers::Axes> &axes
   ) :
      Component{
         BodyText{},
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
      Component::finish();
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
