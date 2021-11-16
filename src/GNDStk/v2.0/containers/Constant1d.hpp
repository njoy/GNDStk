
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_CONTAINERS_CONSTANT1D
#define NJOY_GNDSTK_V2_0_CONTAINERS_CONSTANT1D

// core interface
#include "GNDStk.hpp"

// v2.0 dependencies
#include "GNDStk/v2.0/containers/Axes.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// containers::
// class Constant1d
// -----------------------------------------------------------------------------

namespace containers {

class Constant1d : public Component<Constant1d> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "containers"; }
   static auto className() { return "Constant1d"; }
   static auto GNDSName() { return "constant1d"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         std::optional<Float64>{}
            / Meta<>("domainMax") |
         std::optional<Float64>{}
            / Meta<>("domainMin") |
         std::optional<XMLName>{}
            / Meta<>("label") |
         std::optional<Float64>{}
            / Meta<>("outerDomainValue") |
         std::optional<Float64>{}
            / Meta<>("value") |
         // children
         containers::Axes{}
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
      std::optional<Float64> domainMax;
      std::optional<Float64> domainMin;
      std::optional<XMLName> label;
      std::optional<Float64> outerDomainValue;
      std::optional<Float64> value;
      // children
      containers::Axes axes;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // domainMax
   const std::optional<Float64> &domainMax() const
      { return content.domainMax; }
   std::optional<Float64> &domainMax()
      { return content.domainMax; }

   // domainMin
   const std::optional<Float64> &domainMin() const
      { return content.domainMin; }
   std::optional<Float64> &domainMin()
      { return content.domainMin; }

   // label
   const std::optional<XMLName> &label() const
      { return content.label; }
   std::optional<XMLName> &label()
      { return content.label; }

   // outerDomainValue
   const std::optional<Float64> &outerDomainValue() const
      { return content.outerDomainValue; }
   std::optional<Float64> &outerDomainValue()
      { return content.outerDomainValue; }

   // value
   const std::optional<Float64> &value() const
      { return content.value; }
   std::optional<Float64> &value()
      { return content.value; }

   // axes
   const containers::Axes &axes() const
      { return content.axes; }
   containers::Axes &axes()
      { return content.axes; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // domainMax(value)
   Constant1d &domainMax(const std::optional<Float64> &obj)
      { domainMax() = obj; return *this; }

   // domainMin(value)
   Constant1d &domainMin(const std::optional<Float64> &obj)
      { domainMin() = obj; return *this; }

   // label(value)
   Constant1d &label(const std::optional<XMLName> &obj)
      { label() = obj; return *this; }

   // outerDomainValue(value)
   Constant1d &outerDomainValue(const std::optional<Float64> &obj)
      { outerDomainValue() = obj; return *this; }

   // value(value)
   Constant1d &value(const std::optional<Float64> &obj)
      { value() = obj; return *this; }

   // axes(value)
   Constant1d &axes(const containers::Axes &obj)
      { axes() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Constant1d() :
      Component{
         BodyText{},
         content.domainMax,
         content.domainMin,
         content.label,
         content.outerDomainValue,
         content.value,
         content.axes
      }
   {
      Component::finish();
   }

   // copy
   Constant1d(const Constant1d &other) :
      Component{
         other,
         content.domainMax,
         content.domainMin,
         content.label,
         content.outerDomainValue,
         content.value,
         content.axes
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Constant1d(Constant1d &&other) :
      Component{
         other,
         content.domainMax,
         content.domainMin,
         content.label,
         content.outerDomainValue,
         content.value,
         content.axes
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Constant1d(const Node &node) :
      Component{
         BodyText{},
         content.domainMax,
         content.domainMin,
         content.label,
         content.outerDomainValue,
         content.value,
         content.axes
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Constant1d(
      const std::optional<Float64> &domainMax,
      const std::optional<Float64> &domainMin,
      const std::optional<XMLName> &label,
      const std::optional<Float64> &outerDomainValue,
      const std::optional<Float64> &value,
      const containers::Axes &axes
   ) :
      Component{
         BodyText{},
         content.domainMax,
         content.domainMin,
         content.label,
         content.outerDomainValue,
         content.value,
         content.axes
      },
      content{
         domainMax,
         domainMin,
         label,
         outerDomainValue,
         value,
         axes
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Constant1d &operator=(const Constant1d &) = default;

   // move
   Constant1d &operator=(Constant1d &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/containers/Constant1d/src/custom.hpp"

}; // class Constant1d

} // namespace containers
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif