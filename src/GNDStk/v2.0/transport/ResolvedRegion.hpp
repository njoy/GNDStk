
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_TRANSPORT_RESOLVEDREGION
#define NJOY_GNDSTK_V2_0_TRANSPORT_RESOLVEDREGION

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
// transport::
// class ResolvedRegion
// -----------------------------------------------------------------------------

namespace transport {

class ResolvedRegion : public Component<ResolvedRegion> {

   using _t = std::variant<
      containers::XYs1d,
      containers::Regions1d
   >;

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "transport"; }
   static auto className() { return "ResolvedRegion"; }
   static auto GNDSName() { return "resolvedRegion"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // children
         _t{}
            / --(Child<>("XYs1d") || Child<>("regions1d"))
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
      // children - variant
      _t _XYs1dregions1d;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // _XYs1dregions1d
   const _t &_XYs1dregions1d() const
      { return content._XYs1dregions1d; }
   _t &_XYs1dregions1d()
      { return content._XYs1dregions1d; }

   // XYs1d
   const containers::XYs1d *XYs1d() const
      { return getter<containers::XYs1d>(_XYs1dregions1d(), "XYs1d"); }
   containers::XYs1d *XYs1d()
      { return getter<containers::XYs1d>(_XYs1dregions1d(), "XYs1d"); }

   // regions1d
   const containers::Regions1d *regions1d() const
      { return getter<containers::Regions1d>(_XYs1dregions1d(), "regions1d"); }
   containers::Regions1d *regions1d()
      { return getter<containers::Regions1d>(_XYs1dregions1d(), "regions1d"); }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // _XYs1dregions1d(value)
   ResolvedRegion &_XYs1dregions1d(const _t &obj)
      { _XYs1dregions1d() = obj; return *this; }

   // XYs1d(value)
   ResolvedRegion &XYs1d(const std::optional<containers::XYs1d> &obj)
      { if (obj) _XYs1dregions1d(obj.value()); return *this; }

   // regions1d(value)
   ResolvedRegion &regions1d(const std::optional<containers::Regions1d> &obj)
      { if (obj) _XYs1dregions1d(obj.value()); return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   ResolvedRegion() :
      Component{
         BodyText{},
         content._XYs1dregions1d
      }
   {
      Component::finish();
   }

   // copy
   ResolvedRegion(const ResolvedRegion &other) :
      Component{
         other,
         content._XYs1dregions1d
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   ResolvedRegion(ResolvedRegion &&other) :
      Component{
         other,
         content._XYs1dregions1d
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   ResolvedRegion(const Node &node) :
      Component{
         BodyText{},
         content._XYs1dregions1d
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit ResolvedRegion(
      const _t &_XYs1dregions1d
   ) :
      Component{
         BodyText{},
         content._XYs1dregions1d
      },
      content{
         _XYs1dregions1d
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   ResolvedRegion &operator=(const ResolvedRegion &) = default;

   // move
   ResolvedRegion &operator=(ResolvedRegion &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/transport/ResolvedRegion/src/custom.hpp"

}; // class ResolvedRegion

} // namespace transport
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif