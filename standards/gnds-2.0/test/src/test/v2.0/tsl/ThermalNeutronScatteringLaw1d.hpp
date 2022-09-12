
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_TSL_THERMALNEUTRONSCATTERINGLAW1D
#define TEST_V2_0_TSL_THERMALNEUTRONSCATTERINGLAW1D

#include "test/v2.0/key.hpp"

namespace test {
namespace v2_0 {
namespace tsl {

// -----------------------------------------------------------------------------
// tsl::
// class ThermalNeutronScatteringLaw1d
// -----------------------------------------------------------------------------

class ThermalNeutronScatteringLaw1d : public Component<tsl::ThermalNeutronScatteringLaw1d> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "tsl"; }
   static auto CLASS() { return "ThermalNeutronScatteringLaw1d"; }
   static auto FIELD() { return "thermalNeutronScatteringLaw1d"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("label") |
         XMLName{}
            / Meta<>("href")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<XMLName> label{this};
   Field<XMLName> href{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->href)

   // default, and from fields
   explicit ThermalNeutronScatteringLaw1d(
      const wrapper<XMLName> &label = {},
      const wrapper<XMLName> &href = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      href(this,href)
   {
      Component::finish();
   }

   // from node
   explicit ThermalNeutronScatteringLaw1d(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ThermalNeutronScatteringLaw1d(const ThermalNeutronScatteringLaw1d &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   ThermalNeutronScatteringLaw1d(ThermalNeutronScatteringLaw1d &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   ThermalNeutronScatteringLaw1d &operator=(const ThermalNeutronScatteringLaw1d &) = default;
   ThermalNeutronScatteringLaw1d &operator=(ThermalNeutronScatteringLaw1d &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/tsl/ThermalNeutronScatteringLaw1d/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ThermalNeutronScatteringLaw1d

} // namespace tsl
} // namespace v2_0
} // namespace test

#endif