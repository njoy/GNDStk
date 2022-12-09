
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_FISSIONTRANSPORT_DELAYEDNEUTRONKE
#define TEST_V2_0_FISSIONTRANSPORT_DELAYEDNEUTRONKE

#include "test/v2.0/containers/XYs1d.hpp"
#include "test/v2.0/containers/Polynomial1d.hpp"

namespace test {
namespace v2_0 {
namespace fissionTransport {

// -----------------------------------------------------------------------------
// fissionTransport::
// class DelayedNeutronKE
// -----------------------------------------------------------------------------

class DelayedNeutronKE : public Component<fissionTransport::DelayedNeutronKE> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "fissionTransport"; }
   static auto CLASS() { return "DelayedNeutronKE"; }
   static auto FIELD() { return "delayedNeutronKE"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         std::optional<containers::XYs1d>{}
            / --Child<>("XYs1d") |
         std::optional<containers::Polynomial1d>{}
            / --Child<>("polynomial1d")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::optional<containers::XYs1d>> XYs1d{this};
   Field<std::optional<containers::Polynomial1d>> polynomial1d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->XYs1d, \
      this->polynomial1d)

   // default, and from fields
   explicit DelayedNeutronKE(
      const wrapper<std::optional<containers::XYs1d>> &XYs1d = {},
      const wrapper<std::optional<containers::Polynomial1d>> &polynomial1d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      XYs1d(this,XYs1d),
      polynomial1d(this,polynomial1d)
   {
      Component::finish();
   }

   // from node
   explicit DelayedNeutronKE(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   DelayedNeutronKE(const DelayedNeutronKE &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   DelayedNeutronKE(DelayedNeutronKE &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   DelayedNeutronKE &operator=(const DelayedNeutronKE &) = default;
   DelayedNeutronKE &operator=(DelayedNeutronKE &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/fissionTransport/DelayedNeutronKE/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class DelayedNeutronKE

} // namespace fissionTransport
} // namespace v2_0
} // namespace test

#endif
