
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_POPS_METASTABLE
#define NJOY_GNDSTK_V2_0_POPS_METASTABLE

// core interface
#include "GNDStk.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// pops::
// class MetaStable
// -----------------------------------------------------------------------------

namespace pops {

class MetaStable : public Component<MetaStable> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "pops"; }
   static auto className() { return "MetaStable"; }
   static auto GNDSName() { return "metaStable"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("id") |
         Integer32{}
            / Meta<>("metaStableIndex") |
         XMLName{}
            / Meta<>("pid")
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
      XMLName id;
      Integer32 metaStableIndex;
      XMLName pid;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // id
   const XMLName &id() const
      { return content.id; }
   XMLName &id()
      { return content.id; }

   // metaStableIndex
   const Integer32 &metaStableIndex() const
      { return content.metaStableIndex; }
   Integer32 &metaStableIndex()
      { return content.metaStableIndex; }

   // pid
   const XMLName &pid() const
      { return content.pid; }
   XMLName &pid()
      { return content.pid; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // id(value)
   MetaStable &id(const XMLName &obj)
      { id() = obj; return *this; }

   // metaStableIndex(value)
   MetaStable &metaStableIndex(const Integer32 &obj)
      { metaStableIndex() = obj; return *this; }

   // pid(value)
   MetaStable &pid(const XMLName &obj)
      { pid() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   MetaStable() :
      Component{
         BodyText{},
         content.id,
         content.metaStableIndex,
         content.pid
      }
   {
      Component::finish();
   }

   // copy
   MetaStable(const MetaStable &other) :
      Component{
         other,
         content.id,
         content.metaStableIndex,
         content.pid
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   MetaStable(MetaStable &&other) :
      Component{
         other,
         content.id,
         content.metaStableIndex,
         content.pid
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   MetaStable(const Node &node) :
      Component{
         BodyText{},
         content.id,
         content.metaStableIndex,
         content.pid
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit MetaStable(
      const XMLName &id,
      const Integer32 &metaStableIndex,
      const XMLName &pid
   ) :
      Component{
         BodyText{},
         content.id,
         content.metaStableIndex,
         content.pid
      },
      content{
         id,
         metaStableIndex,
         pid
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   MetaStable &operator=(const MetaStable &) = default;

   // move
   MetaStable &operator=(MetaStable &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/pops/MetaStable/src/custom.hpp"

}; // class MetaStable

} // namespace pops
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif