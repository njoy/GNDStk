
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_POPS_NUCLEUS
#define TEST_V2_0_POPS_NUCLEUS

#include "test/v2.0/pops/Charge.hpp"
#include "test/v2.0/pops/Energy.hpp"
#include "test/v2.0/pops/Halflife.hpp"
#include "test/v2.0/pops/Spin.hpp"
#include "test/v2.0/pops/Parity.hpp"
#include "test/v2.0/pops/DecayData.hpp"
#include "test/v2.0/fissionFragmentData/FissionFragmentData.hpp"

namespace test {
namespace v2_0 {
namespace pops {

// -----------------------------------------------------------------------------
// pops::
// class Nucleus
// -----------------------------------------------------------------------------

class Nucleus : public Component<pops::Nucleus> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "pops"; }
   static auto CLASS() { return "Nucleus"; }
   static auto FIELD() { return "nucleus"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("id") |
         Integer32{}
            / Meta<>("index") |
         // children
         --Child<std::optional<pops::Charge>>("charge") |
         --Child<std::optional<pops::Energy>>("energy") |
         --Child<std::optional<pops::Halflife>>("halflife") |
         --Child<std::optional<pops::Spin>>("spin") |
         --Child<std::optional<pops::Parity>>("parity") |
         --Child<std::optional<pops::DecayData>>("decayData") |
         --Child<std::optional<fissionFragmentData::FissionFragmentData>>("fissionFragmentData")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<XMLName> id{this};
   Field<Integer32> index{this};

   // children
   Field<std::optional<pops::Charge>> charge{this};
   Field<std::optional<pops::Energy>> energy{this};
   Field<std::optional<pops::Halflife>> halflife{this};
   Field<std::optional<pops::Spin>> spin{this};
   Field<std::optional<pops::Parity>> parity{this};
   Field<std::optional<pops::DecayData>> decayData{this};
   Field<std::optional<fissionFragmentData::FissionFragmentData>> fissionFragmentData{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->id, \
      this->index, \
      this->charge, \
      this->energy, \
      this->halflife, \
      this->spin, \
      this->parity, \
      this->decayData, \
      this->fissionFragmentData)

   // default
   Nucleus() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields
   explicit Nucleus(
      const wrapper<XMLName> &id,
      const wrapper<Integer32> &index = {},
      const wrapper<std::optional<pops::Charge>> &charge = {},
      const wrapper<std::optional<pops::Energy>> &energy = {},
      const wrapper<std::optional<pops::Halflife>> &halflife = {},
      const wrapper<std::optional<pops::Spin>> &spin = {},
      const wrapper<std::optional<pops::Parity>> &parity = {},
      const wrapper<std::optional<pops::DecayData>> &decayData = {},
      const wrapper<std::optional<fissionFragmentData::FissionFragmentData>> &fissionFragmentData = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      id(this,id),
      index(this,index),
      charge(this,charge),
      energy(this,energy),
      halflife(this,halflife),
      spin(this,spin),
      parity(this,parity),
      decayData(this,decayData),
      fissionFragmentData(this,fissionFragmentData)
   {
      Component::finish();
   }

   // from node
   explicit Nucleus(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Nucleus(const Nucleus &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      id(this,other.id),
      index(this,other.index),
      charge(this,other.charge),
      energy(this,other.energy),
      halflife(this,other.halflife),
      spin(this,other.spin),
      parity(this,other.parity),
      decayData(this,other.decayData),
      fissionFragmentData(this,other.fissionFragmentData)
   {
      Component::finish(other);
   }

   // move
   Nucleus(Nucleus &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      id(this,std::move(other.id)),
      index(this,std::move(other.index)),
      charge(this,std::move(other.charge)),
      energy(this,std::move(other.energy)),
      halflife(this,std::move(other.halflife)),
      spin(this,std::move(other.spin)),
      parity(this,std::move(other.parity)),
      decayData(this,std::move(other.decayData)),
      fissionFragmentData(this,std::move(other.fissionFragmentData))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Nucleus &operator=(const Nucleus &) = default;
   Nucleus &operator=(Nucleus &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/pops/Nucleus/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Nucleus

} // namespace pops
} // namespace v2_0
} // namespace test

#endif
