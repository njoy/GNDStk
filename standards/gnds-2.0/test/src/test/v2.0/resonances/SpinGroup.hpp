
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_RESONANCES_SPINGROUP
#define TEST_V2_0_RESONANCES_SPINGROUP

#include "test/v2.0/resonances/Channels.hpp"
#include "test/v2.0/resonances/ResonanceParameters.hpp"

namespace test {
namespace v2_0 {
namespace resonances {

// -----------------------------------------------------------------------------
// resonances::
// class SpinGroup
// -----------------------------------------------------------------------------

class SpinGroup : public Component<resonances::SpinGroup> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "resonances"; }
   static auto CLASS() { return "SpinGroup"; }
   static auto FIELD() { return "spinGroup"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("label") |
         Fraction32{}
            / Meta<>("spin") |
         Defaulted<Integer32>{1}
            / Meta<>("parity") |
         // children
         resonances::Channels{}
            / --Child<>("channels") |
         resonances::ResonanceParameters{}
            / --Child<>("resonanceParameters")
      ;
   }

public:
   using Component::construct;

   // defaults
   static inline const struct Defaults {
      static inline const Integer32 parity = 1;
   } defaults;

   // metadata
   Field<XMLName> label{this};
   Field<Fraction32> spin{this};
   Field<Defaulted<Integer32>> parity{this,defaults.parity};

   // children
   Field<resonances::Channels> channels{this};
   Field<resonances::ResonanceParameters> resonanceParameters{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->spin, \
      this->parity, \
      this->channels, \
      this->resonanceParameters)

   // default, and from fields
   // std::optional replaces Defaulted; this class knows the default(s)
   explicit SpinGroup(
      const wrapper<XMLName> &label = {},
      const wrapper<Fraction32> &spin = {},
      const wrapper<std::optional<Integer32>> &parity = {},
      const wrapper<resonances::Channels> &channels = {},
      const wrapper<resonances::ResonanceParameters> &resonanceParameters = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      spin(this,spin),
      parity(this,defaults.parity,parity),
      channels(this,channels),
      resonanceParameters(this,resonanceParameters)
   {
      Component::finish();
   }

   // from node
   explicit SpinGroup(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   SpinGroup(const SpinGroup &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   SpinGroup(SpinGroup &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   SpinGroup &operator=(const SpinGroup &) = default;
   SpinGroup &operator=(SpinGroup &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/resonances/SpinGroup/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class SpinGroup

} // namespace resonances
} // namespace v2_0
} // namespace test

#endif