
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_POPS_HALFLIFE
#define TEST_V2_0_POPS_HALFLIFE

#include "test/v2.0/documentation/Documentation.hpp"
#include "test/v2.0/pops/Uncertainty.hpp"
#include "test/v2.0/containers/String.hpp"
#include "test/v2.0/containers/Double.hpp"

namespace test {
namespace v2_0 {
namespace pops {

// -----------------------------------------------------------------------------
// pops::
// class Halflife
// -----------------------------------------------------------------------------

class Halflife : public Component<pops::Halflife> {
   friend class Component;

   using _t = std::variant<
      containers::String,
      containers::Double
   >;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "pops"; }
   static auto CLASS() { return "Halflife"; }
   static auto FIELD() { return "halflife"; }

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
         _t{}
            / --(Child<>("string") || Child<>("Double"))
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

   // children - variant
   Field<_t> _stringDouble{this};
   FieldPart<decltype(_stringDouble),containers::String> string{_stringDouble};
   FieldPart<decltype(_stringDouble),containers::Double> Double{_stringDouble};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->unit, \
      this->value, \
      this->documentation, \
      this->uncertainty, \
      this->_stringDouble)

   // default
   Halflife() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields
   explicit Halflife(
      const wrapper<std::optional<XMLName>> &label,
      const wrapper<std::optional<XMLName>> &unit = {},
      const wrapper<std::optional<XMLName>> &value = {},
      const wrapper<std::optional<documentation::Documentation>> &documentation = {},
      const wrapper<std::optional<pops::Uncertainty>> &uncertainty = {},
      const wrapper<_t> &_stringDouble = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      unit(this,unit),
      value(this,value),
      documentation(this,documentation),
      uncertainty(this,uncertainty),
      _stringDouble(this,_stringDouble)
   {
      Component::finish();
   }

   // from node
   explicit Halflife(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Halflife(const Halflife &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      label(this,other.label),
      unit(this,other.unit),
      value(this,other.value),
      documentation(this,other.documentation),
      uncertainty(this,other.uncertainty),
      _stringDouble(this,other._stringDouble)
   {
      Component::finish(other);
   }

   // move
   Halflife(Halflife &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      label(this,std::move(other.label)),
      unit(this,std::move(other.unit)),
      value(this,std::move(other.value)),
      documentation(this,std::move(other.documentation)),
      uncertainty(this,std::move(other.uncertainty)),
      _stringDouble(this,std::move(other._stringDouble))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Halflife &operator=(const Halflife &) = default;
   Halflife &operator=(Halflife &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/pops/Halflife/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Halflife

} // namespace pops
} // namespace v2_0
} // namespace test

#endif
