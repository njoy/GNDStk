
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_TSL_BOUNDATOMCROSSSECTION
#define TRY_V2_0_TSL_BOUNDATOMCROSSSECTION

#include "try/v2.0/key.hpp"

namespace try {
namespace v2_0 {
namespace tsl {

// -----------------------------------------------------------------------------
// tsl::
// class BoundAtomCrossSection
// -----------------------------------------------------------------------------

class BoundAtomCrossSection : public Component<tsl::BoundAtomCrossSection> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "tsl"; }
   static auto CLASS() { return "BoundAtomCrossSection"; }
   static auto FIELD() { return "boundAtomCrossSection"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("unit") |
         Float64{}
            / Meta<>("value")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<XMLName> unit{this};
   Field<Float64> value{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->unit, \
      this->value)

   // default, and from fields
   explicit BoundAtomCrossSection(
      const wrapper<XMLName> &unit = {},
      const wrapper<Float64> &value = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      unit(this,unit),
      value(this,value)
   {
      Component::finish();
   }

   // from node
   explicit BoundAtomCrossSection(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   BoundAtomCrossSection(const BoundAtomCrossSection &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   BoundAtomCrossSection(BoundAtomCrossSection &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   BoundAtomCrossSection &operator=(const BoundAtomCrossSection &) = default;
   BoundAtomCrossSection &operator=(BoundAtomCrossSection &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/tsl/BoundAtomCrossSection/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class BoundAtomCrossSection

} // namespace tsl
} // namespace v2_0
} // namespace try

#endif