
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_ATOMIC_REALANOMALOUSFACTOR
#define NJOY_GNDSTK_V2_0_ATOMIC_REALANOMALOUSFACTOR

// core interface
#include "GNDStk.hpp"

// v2.0 dependencies
#include "GNDStk/v2.0/containers/XYs1d.hpp"
#include "GNDStk/v2.0/containers/Regions1d.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// atomic::
// class RealAnomalousFactor
// -----------------------------------------------------------------------------

namespace atomic {

class RealAnomalousFactor : public Component<RealAnomalousFactor> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "atomic"; }
   static auto className() { return "RealAnomalousFactor"; }
   static auto GNDSName() { return "realAnomalousFactor"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // children
         std::optional<containers::XYs1d>{}
            / --Child<>("XYs1d") |
         std::optional<containers::Regions1d>{}
            / --Child<>("regions1d")
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
      // children
      std::optional<containers::XYs1d> XYs1d;
      std::optional<containers::Regions1d> regions1d;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // XYs1d
   const std::optional<containers::XYs1d> &XYs1d() const
      { return content.XYs1d; }
   std::optional<containers::XYs1d> &XYs1d()
      { return content.XYs1d; }

   // regions1d
   const std::optional<containers::Regions1d> &regions1d() const
      { return content.regions1d; }
   std::optional<containers::Regions1d> &regions1d()
      { return content.regions1d; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // XYs1d(value)
   RealAnomalousFactor &XYs1d(const std::optional<containers::XYs1d> &obj)
      { XYs1d() = obj; return *this; }

   // regions1d(value)
   RealAnomalousFactor &regions1d(const std::optional<containers::Regions1d> &obj)
      { regions1d() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   RealAnomalousFactor() :
      Component{
         BodyText{},
         content.XYs1d,
         content.regions1d
      }
   {
      Component::finish();
   }

   // copy
   RealAnomalousFactor(const RealAnomalousFactor &other) :
      Component{
         other,
         content.XYs1d,
         content.regions1d
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   RealAnomalousFactor(RealAnomalousFactor &&other) :
      Component{
         other,
         content.XYs1d,
         content.regions1d
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   RealAnomalousFactor(const Node &node) :
      Component{
         BodyText{},
         content.XYs1d,
         content.regions1d
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit RealAnomalousFactor(
      const std::optional<containers::XYs1d> &XYs1d,
      const std::optional<containers::Regions1d> &regions1d
   ) :
      Component{
         BodyText{},
         content.XYs1d,
         content.regions1d
      },
      content{
         XYs1d,
         regions1d
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   RealAnomalousFactor &operator=(const RealAnomalousFactor &) = default;

   // move
   RealAnomalousFactor &operator=(RealAnomalousFactor &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/atomic/RealAnomalousFactor/src/custom.hpp"

}; // class RealAnomalousFactor

} // namespace atomic
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif
