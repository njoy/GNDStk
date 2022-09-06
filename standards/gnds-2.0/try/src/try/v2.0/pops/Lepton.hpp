
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_POPS_LEPTON
#define TRY_V2_0_POPS_LEPTON

#include "try/v2.0/pops/Charge.hpp"
#include "try/v2.0/pops/Halflife.hpp"
#include "try/v2.0/pops/Mass.hpp"
#include "try/v2.0/pops/Spin.hpp"
#include "try/v2.0/pops/Parity.hpp"
#include "try/v2.0/pops/DecayData.hpp"

namespace try {
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
         std::optional<pops::Charge>{}
            / --Child<>("charge") |
         std::optional<pops::Halflife>{}
            / --Child<>("halflife") |
         std::optional<pops::Mass>{}
            / --Child<>("mass") |
         std::optional<pops::Spin>{}
            / --Child<>("spin") |
         std::optional<pops::Parity>{}
            / --Child<>("parity") |
         std::optional<pops::DecayData>{}
            / --Child<>("decayData")
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

   // default, and from fields
   explicit Lepton(
      const wrapper<std::optional<XMLName>> &generation = {},
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
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Lepton(Lepton &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
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

   #include "try/v2.0/pops/Lepton/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Lepton

} // namespace pops
} // namespace v2_0
} // namespace try

#endif