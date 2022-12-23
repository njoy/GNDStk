
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_POPS_NUCLIDE
#define TEST_V2_0_POPS_NUCLIDE

#include "test/v2.0/pops/Charge.hpp"
#include "test/v2.0/pops/Mass.hpp"
#include "test/v2.0/pops/Spin.hpp"
#include "test/v2.0/pops/Parity.hpp"
#include "test/v2.0/pops/Nucleus.hpp"
#include "test/v2.0/pops/DecayData.hpp"
#include "test/v2.0/fissionFragmentData/FissionFragmentData.hpp"

namespace test {
namespace v2_0 {
namespace pops {

// -----------------------------------------------------------------------------
// pops::
// class Nuclide
// -----------------------------------------------------------------------------

class Nuclide : public Component<pops::Nuclide> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "pops"; }
   static auto CLASS() { return "Nuclide"; }
   static auto FIELD() { return "nuclide"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("id") |
         // children
         --Child<std::optional<pops::Charge>>("charge") |
         --Child<std::optional<pops::Mass>>("mass") |
         --Child<std::optional<pops::Spin>>("spin") |
         --Child<std::optional<pops::Parity>>("parity") |
         --Child<std::optional<pops::Nucleus>>("nucleus") |
         --Child<std::optional<pops::DecayData>>("decayData") |
         --Child<std::optional<fissionFragmentData::FissionFragmentData>>("fissionFragmentData")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<XMLName> id{this};

   // children
   Field<std::optional<pops::Charge>> charge{this};
   Field<std::optional<pops::Mass>> mass{this};
   Field<std::optional<pops::Spin>> spin{this};
   Field<std::optional<pops::Parity>> parity{this};
   Field<std::optional<pops::Nucleus>> nucleus{this};
   Field<std::optional<pops::DecayData>> decayData{this};
   Field<std::optional<fissionFragmentData::FissionFragmentData>> fissionFragmentData{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->id, \
      this->charge, \
      this->mass, \
      this->spin, \
      this->parity, \
      this->nucleus, \
      this->decayData, \
      this->fissionFragmentData)

   // default
   Nuclide() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields
   explicit Nuclide(
      const wrapper<XMLName> &id,
      const wrapper<std::optional<pops::Charge>> &charge = {},
      const wrapper<std::optional<pops::Mass>> &mass = {},
      const wrapper<std::optional<pops::Spin>> &spin = {},
      const wrapper<std::optional<pops::Parity>> &parity = {},
      const wrapper<std::optional<pops::Nucleus>> &nucleus = {},
      const wrapper<std::optional<pops::DecayData>> &decayData = {},
      const wrapper<std::optional<fissionFragmentData::FissionFragmentData>> &fissionFragmentData = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      id(this,id),
      charge(this,charge),
      mass(this,mass),
      spin(this,spin),
      parity(this,parity),
      nucleus(this,nucleus),
      decayData(this,decayData),
      fissionFragmentData(this,fissionFragmentData)
   {
      Component::finish();
   }

   // from node
   explicit Nuclide(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Nuclide(const Nuclide &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      id(this,other.id),
      charge(this,other.charge),
      mass(this,other.mass),
      spin(this,other.spin),
      parity(this,other.parity),
      nucleus(this,other.nucleus),
      decayData(this,other.decayData),
      fissionFragmentData(this,other.fissionFragmentData)
   {
      Component::finish(other);
   }

   // move
   Nuclide(Nuclide &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      id(this,std::move(other.id)),
      charge(this,std::move(other.charge)),
      mass(this,std::move(other.mass)),
      spin(this,std::move(other.spin)),
      parity(this,std::move(other.parity)),
      nucleus(this,std::move(other.nucleus)),
      decayData(this,std::move(other.decayData)),
      fissionFragmentData(this,std::move(other.fissionFragmentData))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Nuclide &operator=(const Nuclide &) = default;
   Nuclide &operator=(Nuclide &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/pops/Nuclide/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Nuclide

} // namespace pops
} // namespace v2_0
} // namespace test

#endif
