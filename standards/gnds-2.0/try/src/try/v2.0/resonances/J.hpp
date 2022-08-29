
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_RESONANCES_J
#define TRY_V2_0_RESONANCES_J

#include "try/v2.0/resonances/LevelSpacing.hpp"
#include "try/v2.0/resonances/Widths.hpp"

namespace try {
namespace v2_0 {
namespace resonances {

// -----------------------------------------------------------------------------
// resonances::
// class J
// -----------------------------------------------------------------------------

class J : public Component<resonances::J> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "resonances"; }
   static auto CLASS() { return "J"; }
   static auto FIELD() { return "J"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("label") |
         Fraction32{}
            / Meta<>("value") |
         // children
         resonances::LevelSpacing{}
            / --Child<>("levelSpacing") |
         resonances::Widths{}
            / --Child<>("widths")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<XMLName> label{this};
   Field<Fraction32> value{this};

   // children
   Field<resonances::LevelSpacing> levelSpacing{this};
   Field<resonances::Widths> widths{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->value, \
      this->levelSpacing, \
      this->widths)

   // default, and from fields
   explicit J(
      const wrapper<XMLName> &label = {},
      const wrapper<Fraction32> &value = {},
      const wrapper<resonances::LevelSpacing> &levelSpacing = {},
      const wrapper<resonances::Widths> &widths = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      value(this,value),
      levelSpacing(this,levelSpacing),
      widths(this,widths)
   {
      Component::finish();
   }

   // from node
   explicit J(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   J(const J &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   J(J &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   J &operator=(const J &) = default;
   J &operator=(J &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/resonances/J/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class J

} // namespace resonances
} // namespace v2_0
} // namespace try

#endif
