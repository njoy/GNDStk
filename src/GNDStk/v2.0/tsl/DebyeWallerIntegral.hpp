
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_TSL_DEBYEWALLERINTEGRAL
#define NJOY_GNDSTK_V2_0_TSL_DEBYEWALLERINTEGRAL

// core interface
#include "GNDStk.hpp"

// v2.0 dependencies
#include "GNDStk/v2.0/containers/XYs1d.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// tsl::
// class DebyeWallerIntegral
// -----------------------------------------------------------------------------

namespace tsl {

class DebyeWallerIntegral : public Component<DebyeWallerIntegral> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "tsl"; }
   static auto className() { return "DebyeWallerIntegral"; }
   static auto GNDSName() { return "DebyeWallerIntegral"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // children
         containers::XYs1d{}
            / --Child<>("XYs1d")
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
      containers::XYs1d XYs1d;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // XYs1d
   const containers::XYs1d &XYs1d() const
      { return content.XYs1d; }
   containers::XYs1d &XYs1d()
      { return content.XYs1d; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // XYs1d(value)
   DebyeWallerIntegral &XYs1d(const containers::XYs1d &obj)
      { XYs1d() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   DebyeWallerIntegral() :
      Component{
         BodyText{},
         content.XYs1d
      }
   {
      Component::finish();
   }

   // copy
   DebyeWallerIntegral(const DebyeWallerIntegral &other) :
      Component{
         other,
         content.XYs1d
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   DebyeWallerIntegral(DebyeWallerIntegral &&other) :
      Component{
         other,
         content.XYs1d
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   DebyeWallerIntegral(const Node &node) :
      Component{
         BodyText{},
         content.XYs1d
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit DebyeWallerIntegral(
      const containers::XYs1d &XYs1d
   ) :
      Component{
         BodyText{},
         content.XYs1d
      },
      content{
         XYs1d
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   DebyeWallerIntegral &operator=(const DebyeWallerIntegral &) = default;

   // move
   DebyeWallerIntegral &operator=(DebyeWallerIntegral &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/tsl/DebyeWallerIntegral/src/custom.hpp"

}; // class DebyeWallerIntegral

} // namespace tsl
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif
