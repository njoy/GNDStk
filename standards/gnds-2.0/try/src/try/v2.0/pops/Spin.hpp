
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_POPS_SPIN
#define TRY_V2_0_POPS_SPIN

#include "try/v2.0/documentation/Documentation.hpp"
#include "try/v2.0/pops/Uncertainty.hpp"
#include "try/v2.0/unknownNamespace/Fraction.hpp"

namespace try {
namespace v2_0 {
namespace pops {

// -----------------------------------------------------------------------------
// pops::
// class Spin
// -----------------------------------------------------------------------------

class Spin : public Component<pops::Spin> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "pops"; }
   static auto CLASS() { return "Spin"; }
   static auto FIELD() { return "spin"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::optional<XMLName>{}
            / Meta<>("label") |
         std::optional<XMLName>{}
            / Meta<>("unit") |
         XMLName{}
            / Meta<>("value") |
         // children
         std::optional<documentation::Documentation>{}
            / --Child<>("documentation") |
         std::optional<pops::Uncertainty>{}
            / --Child<>("uncertainty") |
         std::optional<unknownNamespace::Fraction>{}
            / ++Child<>("fraction")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::optional<XMLName>> label{this};
   Field<std::optional<XMLName>> unit{this};
   Field<XMLName> value{this};

   // children
   Field<std::optional<documentation::Documentation>> documentation{this};
   Field<std::optional<pops::Uncertainty>> uncertainty{this};
   Field<std::optional<std::vector<unknownNamespace::Fraction>>> fraction{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->unit, \
      this->value, \
      this->documentation, \
      this->uncertainty, \
      this->fraction)

   // default, and from fields
   explicit Spin(
      const wrapper<std::optional<XMLName>> &label = {},
      const wrapper<std::optional<XMLName>> &unit = {},
      const wrapper<XMLName> &value = {},
      const wrapper<std::optional<documentation::Documentation>> &documentation = {},
      const wrapper<std::optional<pops::Uncertainty>> &uncertainty = {},
      const wrapper<std::optional<std::vector<unknownNamespace::Fraction>>> &fraction = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      unit(this,unit),
      value(this,value),
      documentation(this,documentation),
      uncertainty(this,uncertainty),
      fraction(this,fraction)
   {
      Component::finish();
   }

   // from node
   explicit Spin(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Spin(const Spin &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Spin(Spin &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Spin &operator=(const Spin &) = default;
   Spin &operator=(Spin &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/pops/Spin/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Spin

} // namespace pops
} // namespace v2_0
} // namespace try

#endif
