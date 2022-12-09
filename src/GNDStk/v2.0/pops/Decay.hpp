
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_POPS_DECAY
#define NJOY_GNDSTK_V2_0_POPS_DECAY

// core interface
#include "GNDStk.hpp"

// v2.0 dependencies
#include "GNDStk/v2.0/pops/Products.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// pops::
// class Decay
// -----------------------------------------------------------------------------

namespace pops {

class Decay : public Component<Decay> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "pops"; }
   static auto className() { return "Decay"; }
   static auto GNDSName() { return "decay"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         Defaulted<bool>{false}
            / Meta<>("complete") |
         Integer32{}
            / Meta<>("index") |
         std::optional<enums::DecayType>{}
            / Meta<>("mode") |
         // children
         std::optional<pops::Products>{}
            / --Child<>("products")
      ;
   }

public:

   using Component::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static inline const struct Defaults {
      static inline const bool complete = false;
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      Defaulted<bool> complete{false};
      Integer32 index;
      std::optional<enums::DecayType> mode;
      // children
      std::optional<pops::Products> products;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // complete
   const Defaulted<bool> &complete() const
      { return content.complete; }
   Defaulted<bool> &complete()
      { return content.complete; }

   // index
   const Integer32 &index() const
      { return content.index; }
   Integer32 &index()
      { return content.index; }

   // mode
   const std::optional<enums::DecayType> &mode() const
      { return content.mode; }
   std::optional<enums::DecayType> &mode()
      { return content.mode; }

   // products
   const std::optional<pops::Products> &products() const
      { return content.products; }
   std::optional<pops::Products> &products()
      { return content.products; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // complete(value)
   Decay &complete(const Defaulted<bool> &obj)
      { content.complete = obj; return *this; }
   Decay &complete(const std::optional<bool> &obj)
      { content.complete = obj; return *this; }

   // index(value)
   Decay &index(const Integer32 &obj)
      { index() = obj; return *this; }

   // mode(value)
   Decay &mode(const std::optional<enums::DecayType> &obj)
      { mode() = obj; return *this; }

   // products(value)
   Decay &products(const std::optional<pops::Products> &obj)
      { products() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Decay() :
      Component{
         BodyText{},
         content.complete,
         content.index,
         content.mode,
         content.products
      }
   {
      Component::finish();
   }

   // copy
   Decay(const Decay &other) :
      Component{
         other,
         content.complete,
         content.index,
         content.mode,
         content.products
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Decay(Decay &&other) :
      Component{
         other,
         content.complete,
         content.index,
         content.mode,
         content.products
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Decay(const Node &node) :
      Component{
         BodyText{},
         content.complete,
         content.index,
         content.mode,
         content.products
      }
   {
      Component::finish(node);
   }

   // from fields
   // std::optional replaces Defaulted; this class knows the default(s)
   explicit Decay(
      const std::optional<bool> &complete,
      const Integer32 &index,
      const std::optional<enums::DecayType> &mode,
      const std::optional<pops::Products> &products
   ) :
      Component{
         BodyText{},
         content.complete,
         content.index,
         content.mode,
         content.products
      },
      content{
         Defaulted<bool>(defaults.complete,complete),
         index,
         mode,
         products
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Decay &operator=(const Decay &) = default;

   // move
   Decay &operator=(Decay &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/pops/Decay/src/custom.hpp"

}; // class Decay

} // namespace pops
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif
