
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_FISSIONFRAGMENTDATA_FISSIONFRAGMENTDATA
#define TEST_V2_0_FISSIONFRAGMENTDATA_FISSIONFRAGMENTDATA

#include "test/v2.0/fissionFragmentData/DelayedNeutrons.hpp"
#include "test/v2.0/fissionTransport/FissionEnergyReleased.hpp"
#include "test/v2.0/fpy/ProductYields.hpp"

namespace test {
namespace v2_0 {
namespace fissionFragmentData {

// -----------------------------------------------------------------------------
// fissionFragmentData::
// class FissionFragmentData
// -----------------------------------------------------------------------------

class FissionFragmentData : public Component<fissionFragmentData::FissionFragmentData> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "fissionFragmentData"; }
   static auto CLASS() { return "FissionFragmentData"; }
   static auto FIELD() { return "fissionFragmentData"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         std::optional<fissionFragmentData::DelayedNeutrons>{}
            / --Child<>("delayedNeutrons") |
         std::optional<fissionTransport::FissionEnergyReleased>{}
            / --Child<>("fissionEnergyReleased") |
         std::optional<fpy::ProductYields>{}
            / --Child<>("productYields")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::optional<fissionFragmentData::DelayedNeutrons>> delayedNeutrons{this};
   Field<std::optional<fissionTransport::FissionEnergyReleased>> fissionEnergyReleased{this};
   Field<std::optional<fpy::ProductYields>> productYields{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->delayedNeutrons, \
      this->fissionEnergyReleased, \
      this->productYields)

   // default, and from fields
   explicit FissionFragmentData(
      const wrapper<std::optional<fissionFragmentData::DelayedNeutrons>> &delayedNeutrons = {},
      const wrapper<std::optional<fissionTransport::FissionEnergyReleased>> &fissionEnergyReleased = {},
      const wrapper<std::optional<fpy::ProductYields>> &productYields = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      delayedNeutrons(this,delayedNeutrons),
      fissionEnergyReleased(this,fissionEnergyReleased),
      productYields(this,productYields)
   {
      Component::finish();
   }

   // from node
   explicit FissionFragmentData(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   FissionFragmentData(const FissionFragmentData &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   FissionFragmentData(FissionFragmentData &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   FissionFragmentData &operator=(const FissionFragmentData &) = default;
   FissionFragmentData &operator=(FissionFragmentData &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/fissionFragmentData/FissionFragmentData/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class FissionFragmentData

} // namespace fissionFragmentData
} // namespace v2_0
} // namespace test

#endif
