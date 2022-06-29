
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDSTK_V1_9_CONTAINERS_REGIONS1D
#define GNDSTK_V1_9_CONTAINERS_REGIONS1D

// GNDStk Core Interface
#include "GNDStk.hpp"

// Dependencies
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

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         std::optional<std::string>{}
            / Meta<>("label") |
         std::optional<double>{}
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

   static inline const struct Defaults {
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      std::optional<std::string> label;
      std::optional<double> outerDomainValue;
      // children
      std::vector<containers::XYs1d> XYs1d;
      std::optional<containers::Axes> axes;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

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

   // XYs1d
   const std::vector<containers::XYs1d> &XYs1d() const
      { return content.XYs1d; }
   std::vector<containers::XYs1d> &XYs1d()
      { return content.XYs1d; }

   // XYs1d(index)
   const containers::XYs1d &XYs1d(const std::size_t index) const
      { return getter(XYs1d(), index, "XYs1d"); }
   containers::XYs1d &XYs1d(const std::size_t index)
      { return getter(XYs1d(), index, "XYs1d"); }

   // XYs1d(label)
   const containers::XYs1d &XYs1d(const std::string &label) const
      { return getter(XYs1d(), label, "XYs1d"); }
   containers::XYs1d &XYs1d(const std::string &label)
      { return getter(XYs1d(), label, "XYs1d"); }

   // axes
   const std::optional<containers::Axes> &axes() const
      { return content.axes; }
   std::optional<containers::Axes> &axes()
      { return content.axes; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // label(value)
   Regions1d &label(const std::optional<std::string> &obj)
      { label() = obj; return *this; }

   // outerDomainValue(value)
   Regions1d &outerDomainValue(const std::optional<double> &obj)
      { outerDomainValue() = obj; return *this; }

   // XYs1d(value)
   Regions1d &XYs1d(const std::vector<containers::XYs1d> &obj)
      { XYs1d() = obj; return *this; }

   // XYs1d(index,value)
   Regions1d &XYs1d(
      const std::size_t index,
      const containers::XYs1d &obj
   ) {
      XYs1d(index) = obj; return *this;
   }

   // XYs1d(label,value)
   Regions1d &XYs1d(
      const std::string &label,
      const containers::XYs1d &obj
   ) {
      XYs1d(label) = obj; return *this;
   }

   // XYs1d(value) for vector push_back
   Regions1d &XYs1d(const containers::XYs1d &obj)
      { setter(XYs1d(), obj); return *this; }

   // axes(value)
   Regions1d &axes(const std::optional<containers::Axes> &obj)
      { axes() = obj; return *this; }

   // ------------------------
   // Constructors
   // ------------------------

   // default, and from fields
   explicit Regions1d(
      const std::optional<std::string> &label =
         std::optional<std::string>{},
      const std::optional<double> &outerDomainValue =
         std::optional<double>{},
      const std::vector<containers::XYs1d> &XYs1d =
         std::vector<containers::XYs1d>{},
      const std::optional<containers::Axes> &axes =
         std::optional<containers::Axes>{}
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

   // copy
   Regions1d(const Regions1d &other) :
      Component{
         other.baseBodyText(),
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
         other.baseBodyText(),
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
