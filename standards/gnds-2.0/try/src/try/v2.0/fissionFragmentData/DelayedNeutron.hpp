
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_FISSIONFRAGMENTDATA_DELAYEDNEUTRON
#define TRY_V2_0_FISSIONFRAGMENTDATA_DELAYEDNEUTRON

#include "try/v2.0/fissionFragmentData/Rate.hpp"
#include "try/v2.0/common/Product.hpp"

namespace try {
namespace v2_0 {
namespace fissionFragmentData {

// -----------------------------------------------------------------------------
// fissionFragmentData::
// class DelayedNeutron
// -----------------------------------------------------------------------------

class DelayedNeutron : public Component<fissionFragmentData::DelayedNeutron> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "fissionFragmentData"; }
   static auto CLASS() { return "DelayedNeutron"; }
   static auto FIELD() { return "delayedNeutron"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("label") |
         // children
         fissionFragmentData::Rate{}
            / --Child<>("rate") |
         common::Product{}
            / --Child<>("product")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<XMLName> label{this};

   // children
   Field<fissionFragmentData::Rate> rate{this};
   Field<common::Product> product{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->rate, \
      this->product)

   // default, and from fields
   explicit DelayedNeutron(
      const wrapper<XMLName> &label = {},
      const wrapper<fissionFragmentData::Rate> &rate = {},
      const wrapper<common::Product> &product = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      rate(this,rate),
      product(this,product)
   {
      Component::finish();
   }

   // from node
   explicit DelayedNeutron(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   DelayedNeutron(const DelayedNeutron &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   DelayedNeutron(DelayedNeutron &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   DelayedNeutron &operator=(const DelayedNeutron &) = default;
   DelayedNeutron &operator=(DelayedNeutron &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/fissionFragmentData/DelayedNeutron/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class DelayedNeutron

} // namespace fissionFragmentData
} // namespace v2_0
} // namespace try

#endif
