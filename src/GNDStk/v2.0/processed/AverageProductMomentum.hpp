
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_PROCESSED_AVERAGEPRODUCTMOMENTUM
#define NJOY_GNDSTK_V2_0_PROCESSED_AVERAGEPRODUCTMOMENTUM

// core interface
#include "GNDStk.hpp"

// v2.0 dependencies
#include "GNDStk/v2.0/containers/XYs1d.hpp"
#include "GNDStk/v2.0/containers/Gridded1d.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// processed::
// class AverageProductMomentum
// -----------------------------------------------------------------------------

namespace processed {

class AverageProductMomentum : public Component<AverageProductMomentum> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "processed"; }
   static auto className() { return "AverageProductMomentum"; }
   static auto GNDSName() { return "averageProductMomentum"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // children
         std::optional<containers::XYs1d>{}
            / --Child<>("XYs1d") |
         std::optional<containers::Gridded1d>{}
            / --Child<>("gridded1d")
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
      std::optional<containers::Gridded1d> gridded1d;
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

   // gridded1d
   const std::optional<containers::Gridded1d> &gridded1d() const
      { return content.gridded1d; }
   std::optional<containers::Gridded1d> &gridded1d()
      { return content.gridded1d; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // XYs1d(value)
   AverageProductMomentum &XYs1d(const std::optional<containers::XYs1d> &obj)
      { XYs1d() = obj; return *this; }

   // gridded1d(value)
   AverageProductMomentum &gridded1d(const std::optional<containers::Gridded1d> &obj)
      { gridded1d() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   AverageProductMomentum() :
      Component{
         BodyText{},
         content.XYs1d,
         content.gridded1d
      }
   {
      Component::finish();
   }

   // copy
   AverageProductMomentum(const AverageProductMomentum &other) :
      Component{
         other,
         content.XYs1d,
         content.gridded1d
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   AverageProductMomentum(AverageProductMomentum &&other) :
      Component{
         other,
         content.XYs1d,
         content.gridded1d
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   AverageProductMomentum(const Node &node) :
      Component{
         BodyText{},
         content.XYs1d,
         content.gridded1d
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit AverageProductMomentum(
      const std::optional<containers::XYs1d> &XYs1d,
      const std::optional<containers::Gridded1d> &gridded1d
   ) :
      Component{
         BodyText{},
         content.XYs1d,
         content.gridded1d
      },
      content{
         XYs1d,
         gridded1d
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   AverageProductMomentum &operator=(const AverageProductMomentum &) = default;

   // move
   AverageProductMomentum &operator=(AverageProductMomentum &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/processed/AverageProductMomentum/src/custom.hpp"

}; // class AverageProductMomentum

} // namespace processed
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif
