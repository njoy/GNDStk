
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_POPS_DECAYMODES
#define TEST_V2_0_POPS_DECAYMODES

#include "test/v2.0/pops/DecayMode.hpp"

namespace test {
namespace v2_0 {
namespace pops {

// -----------------------------------------------------------------------------
// pops::
// class DecayModes
// -----------------------------------------------------------------------------

class DecayModes : public Component<pops::DecayModes> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "pops"; }
   static auto CLASS() { return "DecayModes"; }
   static auto FIELD() { return "decayModes"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         ++Child<pops::DecayMode>("decayMode")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::vector<pops::DecayMode>> decayMode{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->decayMode)

   // default
   DecayModes() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields
   explicit DecayModes(
      const wrapper<std::vector<pops::DecayMode>> &decayMode
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      decayMode(this,decayMode)
   {
      Component::finish();
   }

   // from node
   explicit DecayModes(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   DecayModes(const DecayModes &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      decayMode(this,other.decayMode)
   {
      Component::finish(other);
   }

   // move
   DecayModes(DecayModes &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      decayMode(this,std::move(other.decayMode))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   DecayModes &operator=(const DecayModes &) = default;
   DecayModes &operator=(DecayModes &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/pops/DecayModes/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class DecayModes

} // namespace pops
} // namespace v2_0
} // namespace test

#endif
