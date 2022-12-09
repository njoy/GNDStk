
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_POPS_PARITY
#define TEST_V2_0_POPS_PARITY

#include "test/v2.0/documentation/Documentation.hpp"
#include "test/v2.0/pops/Uncertainty.hpp"
#include "test/v2.0/containers/Integer.hpp"

namespace test {
namespace v2_0 {
namespace pops {

// -----------------------------------------------------------------------------
// pops::
// class Parity
// -----------------------------------------------------------------------------

class Parity : public Component<pops::Parity> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "pops"; }
   static auto CLASS() { return "Parity"; }
   static auto FIELD() { return "parity"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::optional<XMLName>{}
            / Meta<>("label") |
         std::optional<XMLName>{}
            / Meta<>("unit") |
         std::optional<XMLName>{}
            / Meta<>("value") |
         // children
         --Child<std::optional<documentation::Documentation>>("documentation") |
         --Child<std::optional<pops::Uncertainty>>("uncertainty") |
         ++Child<std::optional<containers::Integer>>("integer")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::optional<XMLName>> label{this};
   Field<std::optional<XMLName>> unit{this};
   Field<std::optional<XMLName>> value{this};

   // children
   Field<std::optional<documentation::Documentation>> documentation{this};
   Field<std::optional<pops::Uncertainty>> uncertainty{this};
   Field<std::optional<std::vector<containers::Integer>>> integer{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->unit, \
      this->value, \
      this->documentation, \
      this->uncertainty, \
      this->integer)

   // default
   Parity() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields
   explicit Parity(
      const wrapper<std::optional<XMLName>> &label,
      const wrapper<std::optional<XMLName>> &unit = {},
      const wrapper<std::optional<XMLName>> &value = {},
      const wrapper<std::optional<documentation::Documentation>> &documentation = {},
      const wrapper<std::optional<pops::Uncertainty>> &uncertainty = {},
      const wrapper<std::optional<std::vector<containers::Integer>>> &integer = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      unit(this,unit),
      value(this,value),
      documentation(this,documentation),
      uncertainty(this,uncertainty),
      integer(this,integer)
   {
      Component::finish();
   }

   // from node
   explicit Parity(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Parity(const Parity &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      label(this,other.label),
      unit(this,other.unit),
      value(this,other.value),
      documentation(this,other.documentation),
      uncertainty(this,other.uncertainty),
      integer(this,other.integer)
   {
      Component::finish(other);
   }

   // move
   Parity(Parity &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      label(this,std::move(other.label)),
      unit(this,std::move(other.unit)),
      value(this,std::move(other.value)),
      documentation(this,std::move(other.documentation)),
      uncertainty(this,std::move(other.uncertainty)),
      integer(this,std::move(other.integer))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Parity &operator=(const Parity &) = default;
   Parity &operator=(Parity &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/pops/Parity/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Parity

} // namespace pops
} // namespace v2_0
} // namespace test

#endif
