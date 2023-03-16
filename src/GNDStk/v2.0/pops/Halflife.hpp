
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_POPS_HALFLIFE
#define NJOY_GNDSTK_V2_0_POPS_HALFLIFE

// core interface
#include "GNDStk.hpp"

// v2.0 dependencies
#include "GNDStk/v2.0/containers/Double.hpp"
#include "GNDStk/v2.0/containers/String.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// pops::
// class Halflife
// -----------------------------------------------------------------------------

namespace pops {

class Halflife : public Component<Halflife> {

   using _t = std::variant<
      containers::Double,
      containers::String
   >;

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "pops"; }
   static auto className() { return "Halflife"; }
   static auto GNDSName() { return "halflife"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // children
         _t{}
            / --(Child<>("Double") || Child<>("string"))
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
      _t _Doublestring;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // _Doublestring
   const _t &_Doublestring() const
      { return content._Doublestring; }
   _t &_Doublestring()
      { return content._Doublestring; }

   // Double
   const containers::Double *Double() const
      { return getter<containers::Double>(_Doublestring(), "Double"); }
   containers::Double *Double()
      { return getter<containers::Double>(_Doublestring(), "Double"); }

   // string
   const containers::String *string() const
      { return getter<containers::String>(_Doublestring(), "string"); }
   containers::String *string()
      { return getter<containers::String>(_Doublestring(), "string"); }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // _Doublestring(value)
   Halflife &_Doublestring(const _t &obj)
      { _Doublestring() = obj; return *this; }

   // Double(value)
   Halflife &Double(const std::optional<containers::Double> &obj)
      { if (obj) _Doublestring(obj.value()); return *this; }

   // string(value)
   Halflife &string(const std::optional<containers::String> &obj)
      { if (obj) _Doublestring(obj.value()); return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Halflife() :
      Component{
         BodyText{},
         content._Doublestring
      }
   {
      Component::finish();
   }

   // copy
   Halflife(const Halflife &other) :
      Component{
         other,
         content._Doublestring
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Halflife(Halflife &&other) :
      Component{
         other,
         content._Doublestring
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Halflife(const Node &node) :
      Component{
         BodyText{},
         content._Doublestring
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Halflife(
      const _t &_Doublestring
   ) :
      Component{
         BodyText{},
         content._Doublestring
      },
      content{
         _Doublestring
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Halflife &operator=(const Halflife &) = default;

   // move
   Halflife &operator=(Halflife &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/pops/Halflife/src/custom.hpp"

}; // class Halflife

} // namespace pops
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif
