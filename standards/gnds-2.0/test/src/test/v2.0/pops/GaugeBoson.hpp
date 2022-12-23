
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_POPS_GAUGEBOSON
#define TEST_V2_0_POPS_GAUGEBOSON

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
// class GaugeBoson
// -----------------------------------------------------------------------------

class GaugeBoson : public Component<pops::GaugeBoson> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "pops"; }
   static auto CLASS() { return "GaugeBoson"; }
   static auto FIELD() { return "gaugeBoson"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
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
      this->id, \
      this->charge, \
      this->halflife, \
      this->mass, \
      this->spin, \
      this->parity, \
      this->decayData)

   // default
   GaugeBoson() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields
   explicit GaugeBoson(
      const wrapper<XMLName> &id,
      const wrapper<std::optional<pops::Charge>> &charge = {},
      const wrapper<std::optional<pops::Halflife>> &halflife = {},
      const wrapper<std::optional<pops::Mass>> &mass = {},
      const wrapper<std::optional<pops::Spin>> &spin = {},
      const wrapper<std::optional<pops::Parity>> &parity = {},
      const wrapper<std::optional<pops::DecayData>> &decayData = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
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
   explicit GaugeBoson(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   GaugeBoson(const GaugeBoson &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
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
   GaugeBoson(GaugeBoson &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
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

   GaugeBoson &operator=(const GaugeBoson &) = default;
   GaugeBoson &operator=(GaugeBoson &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/pops/GaugeBoson/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class GaugeBoson

} // namespace pops
} // namespace v2_0
} // namespace test

#endif
