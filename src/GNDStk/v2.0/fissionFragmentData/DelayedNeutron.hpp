
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_FISSIONFRAGMENTDATA_DELAYEDNEUTRON
#define NJOY_GNDSTK_V2_0_FISSIONFRAGMENTDATA_DELAYEDNEUTRON

// core interface
#include "GNDStk.hpp"

// v2.0 dependencies
#include "GNDStk/v2.0/pops/Product.hpp"
#include "GNDStk/v2.0/fissionFragmentData/Rate.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// fissionFragmentData::
// class DelayedNeutron
// -----------------------------------------------------------------------------

namespace fissionFragmentData {

class DelayedNeutron : public Component<DelayedNeutron> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "fissionFragmentData"; }
   static auto className() { return "DelayedNeutron"; }
   static auto GNDSName() { return "delayedNeutron"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("label") |
         // children
         pops::Product{}
            / --Child<>("product") |
         fissionFragmentData::Rate{}
            / --Child<>("rate")
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
      XMLName label;
      // children
      pops::Product product;
      fissionFragmentData::Rate rate;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // label
   const XMLName &label() const
      { return content.label; }
   XMLName &label()
      { return content.label; }

   // product
   const pops::Product &product() const
      { return content.product; }
   pops::Product &product()
      { return content.product; }

   // rate
   const fissionFragmentData::Rate &rate() const
      { return content.rate; }
   fissionFragmentData::Rate &rate()
      { return content.rate; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // label(value)
   DelayedNeutron &label(const XMLName &obj)
      { label() = obj; return *this; }

   // product(value)
   DelayedNeutron &product(const pops::Product &obj)
      { product() = obj; return *this; }

   // rate(value)
   DelayedNeutron &rate(const fissionFragmentData::Rate &obj)
      { rate() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   DelayedNeutron() :
      Component{
         BodyText{},
         content.label,
         content.product,
         content.rate
      }
   {
      Component::finish();
   }

   // copy
   DelayedNeutron(const DelayedNeutron &other) :
      Component{
         other,
         content.label,
         content.product,
         content.rate
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   DelayedNeutron(DelayedNeutron &&other) :
      Component{
         other,
         content.label,
         content.product,
         content.rate
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   DelayedNeutron(const Node &node) :
      Component{
         BodyText{},
         content.label,
         content.product,
         content.rate
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit DelayedNeutron(
      const XMLName &label,
      const pops::Product &product,
      const fissionFragmentData::Rate &rate
   ) :
      Component{
         BodyText{},
         content.label,
         content.product,
         content.rate
      },
      content{
         label,
         product,
         rate
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   DelayedNeutron &operator=(const DelayedNeutron &) = default;

   // move
   DelayedNeutron &operator=(DelayedNeutron &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/fissionFragmentData/DelayedNeutron/src/custom.hpp"

}; // class DelayedNeutron

} // namespace fissionFragmentData
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif