
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_TSL_E_MAX
#define TRY_V2_0_TSL_E_MAX

#include "try/v2.0/key.hpp"

namespace try {
namespace v2_0 {
namespace tsl {

// -----------------------------------------------------------------------------
// tsl::
// class E_max
// -----------------------------------------------------------------------------

class E_max : public Component<tsl::E_max> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "tsl"; }
   static auto CLASS() { return "E_max"; }
   static auto FIELD() { return "e_max"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::optional<XMLName>{}
            / Meta<>("unit") |
         std::optional<Float64>{}
            / Meta<>("value")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::optional<XMLName>> unit{this};
   Field<std::optional<Float64>> value{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->unit, \
      this->value)

   // default, and from fields
   explicit E_max(
      const wrapper<std::optional<XMLName>> &unit = {},
      const wrapper<std::optional<Float64>> &value = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      unit(this,unit),
      value(this,value)
   {
      Component::finish();
   }

   // from node
   explicit E_max(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   E_max(const E_max &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   E_max(E_max &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   E_max &operator=(const E_max &) = default;
   E_max &operator=(E_max &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/tsl/E_max/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class E_max

} // namespace tsl
} // namespace v2_0
} // namespace try

#endif