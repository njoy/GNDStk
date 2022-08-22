
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_TRANSPORT_A
#define NJOY_GNDSTK_V2_0_TRANSPORT_A

// core interface
#include "GNDStk.hpp"

// v2.0 dependencies
#include "GNDStk/v2.0/containers/XYs2d.hpp"
#include "GNDStk/v2.0/containers/Regions2d.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// transport::
// class A
// -----------------------------------------------------------------------------

namespace transport {

class A : public Component<A> {

   using _t = std::variant<
      containers::XYs2d,
      containers::Regions2d
   >;

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "transport"; }
   static auto className() { return "A"; }
   static auto GNDSName() { return "a"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // children
         _t{}
            / --(Child<>("XYs2d") || Child<>("regions2d"))
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
      _t _XYs2dregions2d;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // _XYs2dregions2d
   const _t &_XYs2dregions2d() const
      { return content._XYs2dregions2d; }
   _t &_XYs2dregions2d()
      { return content._XYs2dregions2d; }

   // XYs2d
   const containers::XYs2d *XYs2d() const
      { return getter<containers::XYs2d>(_XYs2dregions2d(), "XYs2d"); }
   containers::XYs2d *XYs2d()
      { return getter<containers::XYs2d>(_XYs2dregions2d(), "XYs2d"); }

   // regions2d
   const containers::Regions2d *regions2d() const
      { return getter<containers::Regions2d>(_XYs2dregions2d(), "regions2d"); }
   containers::Regions2d *regions2d()
      { return getter<containers::Regions2d>(_XYs2dregions2d(), "regions2d"); }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // _XYs2dregions2d(value)
   A &_XYs2dregions2d(const _t &obj)
      { _XYs2dregions2d() = obj; return *this; }

   // XYs2d(value)
   A &XYs2d(const std::optional<containers::XYs2d> &obj)
      { if (obj) _XYs2dregions2d(obj.value()); return *this; }

   // regions2d(value)
   A &regions2d(const std::optional<containers::Regions2d> &obj)
      { if (obj) _XYs2dregions2d(obj.value()); return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   A() :
      Component{
         BodyText{},
         content._XYs2dregions2d
      }
   {
      Component::finish();
   }

   // copy
   A(const A &other) :
      Component{
         other,
         content._XYs2dregions2d
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   A(A &&other) :
      Component{
         other,
         content._XYs2dregions2d
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   A(const Node &node) :
      Component{
         BodyText{},
         content._XYs2dregions2d
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit A(
      const _t &_XYs2dregions2d
   ) :
      Component{
         BodyText{},
         content._XYs2dregions2d
      },
      content{
         _XYs2dregions2d
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   A &operator=(const A &) = default;

   // move
   A &operator=(A &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/transport/A/src/custom.hpp"

}; // class A

} // namespace transport
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif
