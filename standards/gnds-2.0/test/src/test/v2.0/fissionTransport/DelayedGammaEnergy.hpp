
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_FISSIONTRANSPORT_DELAYEDGAMMAENERGY
#define TEST_V2_0_FISSIONTRANSPORT_DELAYEDGAMMAENERGY

#include "test/v2.0/containers/Polynomial1d.hpp"

namespace test {
namespace v2_0 {
namespace fissionTransport {

// -----------------------------------------------------------------------------
// fissionTransport::
// class DelayedGammaEnergy
// -----------------------------------------------------------------------------

class DelayedGammaEnergy : public Component<fissionTransport::DelayedGammaEnergy> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "fissionTransport"; }
   static auto CLASS() { return "DelayedGammaEnergy"; }
   static auto FIELD() { return "delayedGammaEnergy"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         std::optional<containers::Polynomial1d>{}
            / --Child<>("polynomial1d")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::optional<containers::Polynomial1d>> polynomial1d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->polynomial1d)

   // default, and from fields
   explicit DelayedGammaEnergy(
      const wrapper<std::optional<containers::Polynomial1d>> &polynomial1d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      polynomial1d(this,polynomial1d)
   {
      Component::finish();
   }

   // from node
   explicit DelayedGammaEnergy(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   DelayedGammaEnergy(const DelayedGammaEnergy &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   DelayedGammaEnergy(DelayedGammaEnergy &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   DelayedGammaEnergy &operator=(const DelayedGammaEnergy &) = default;
   DelayedGammaEnergy &operator=(DelayedGammaEnergy &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/fissionTransport/DelayedGammaEnergy/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class DelayedGammaEnergy

} // namespace fissionTransport
} // namespace v2_0
} // namespace test

#endif