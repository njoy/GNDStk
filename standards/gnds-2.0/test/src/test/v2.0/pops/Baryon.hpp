
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_POPS_BARYON
#define TEST_V2_0_POPS_BARYON

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
// class Baryon
// -----------------------------------------------------------------------------

class Baryon : public Component<pops::Baryon> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "pops"; }
   static auto CLASS() { return "Baryon"; }
   static auto FIELD() { return "baryon"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
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

   // default, and from fields
   explicit Baryon(
      const wrapper<XMLName> &id = {},
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
   explicit Baryon(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Baryon(const Baryon &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Baryon(Baryon &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Baryon &operator=(const Baryon &) = default;
   Baryon &operator=(Baryon &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/pops/Baryon/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Baryon

} // namespace pops
} // namespace v2_0
} // namespace test

#endif