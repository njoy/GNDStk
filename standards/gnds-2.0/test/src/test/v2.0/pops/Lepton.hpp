
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_POPS_LEPTON
#define TEST_V2_0_POPS_LEPTON

#include "test/v2.0/pops/Charge.hpp"
#include "test/v2.0/pops/Halflife.hpp"
#include "test/v2.0/pops/Mass.hpp"
#include "test/v2.0/pops/Spin.hpp"
#include "test/v2.0/pops/Parity.hpp"
#include "test/v2.0/pops/DecayData.hpp"

namespace test {
namespace v2_0 {
namespace pops {

// -----------------------------------------------------------------------------
// pops::
// class Lepton
// -----------------------------------------------------------------------------

class Lepton : public Component<pops::Lepton> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "pops"; }
   static auto CLASS() { return "Lepton"; }
   static auto FIELD() { return "lepton"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::optional<XMLName>{}
            / Meta<>("generation") |
         XMLName{}
            / Meta<>("id") |
         // children
         --Child<std::optional<pops::Charge>>("charge") |
         --Child<std::optional<pops::Halflife>>("halflife") |
         --Child<std::optional<pops::Mass>>("mass") |
         --Child<std::optional<pops::Spin>>("spin") |
         --Child<std::optional<pops::Parity>>("parity") |
         --Child<std::optional<pops::DecayData>>("decayData")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::optional<XMLName>> generation{this};
   Field<XMLName> id{this};

   // children
   Field<std::optional<pops::Charge>> charge{this};
   Field<std::optional<pops::Halflife>> halflife{this};
   Field<std::optional<pops::Mass>> mass{this};
   Field<std::optional<pops::Spin>> spin{this};
   Field<std::optional<pops::Parity>> parity{this};
   Field<std::optional<pops::DecayData>> decayData{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->generation, \
      this->id, \
      this->charge, \
      this->halflife, \
      this->mass, \
      this->spin, \
      this->parity, \
      this->decayData)

   // default
   Lepton() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields
   explicit Lepton(
      const wrapper<std::optional<XMLName>> &generation,
      const wrapper<XMLName> &id = {},
      const wrapper<std::optional<pops::Charge>> &charge = {},
      const wrapper<std::optional<pops::Halflife>> &halflife = {},
      const wrapper<std::optional<pops::Mass>> &mass = {},
      const wrapper<std::optional<pops::Spin>> &spin = {},
      const wrapper<std::optional<pops::Parity>> &parity = {},
      const wrapper<std::optional<pops::DecayData>> &decayData = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      generation(this,generation),
      id(this,id),
      charge(this,charge),
      halflife(this,halflife),
      mass(this,mass),
      spin(this,spin),
      parity(this,parity),
      decayData(this,decayData)
   {
      Component::finish();
   }

   // from node
   explicit Lepton(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Lepton(const Lepton &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      generation(this,other.generation),
      id(this,other.id),
      charge(this,other.charge),
      halflife(this,other.halflife),
      mass(this,other.mass),
      spin(this,other.spin),
      parity(this,other.parity),
      decayData(this,other.decayData)
   {
      Component::finish(other);
   }

   // move
   Lepton(Lepton &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      generation(this,std::move(other.generation)),
      id(this,std::move(other.id)),
      charge(this,std::move(other.charge)),
      halflife(this,std::move(other.halflife)),
      mass(this,std::move(other.mass)),
      spin(this,std::move(other.spin)),
      parity(this,std::move(other.parity)),
      decayData(this,std::move(other.decayData))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Lepton &operator=(const Lepton &) = default;
   Lepton &operator=(Lepton &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/pops/Lepton/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Lepton

} // namespace pops
} // namespace v2_0
} // namespace test

#endif
