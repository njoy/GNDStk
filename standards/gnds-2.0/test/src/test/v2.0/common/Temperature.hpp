
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_COMMON_TEMPERATURE
#define TEST_V2_0_COMMON_TEMPERATURE

#include "test/v2.0/documentation/Documentation.hpp"
#include "test/v2.0/containers/Uncertainty.hpp"

namespace test {
namespace v2_0 {
namespace common {

// -----------------------------------------------------------------------------
// common::
// class Temperature
// -----------------------------------------------------------------------------

class Temperature : public Component<common::Temperature> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "common"; }
   static auto CLASS() { return "Temperature"; }
   static auto FIELD() { return "temperature"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::optional<XMLName>{}
            / Meta<>("label") |
         std::optional<XMLName>{}
            / Meta<>("unit") |
         std::optional<Float64>{}
            / Meta<>("value") |
         // children
         std::optional<documentation::Documentation>{}
            / --Child<>("documentation") |
         std::optional<containers::Uncertainty>{}
            / --Child<>("uncertainty")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::optional<XMLName>> label{this};
   Field<std::optional<XMLName>> unit{this};
   Field<std::optional<Float64>> value{this};

   // children
   Field<std::optional<documentation::Documentation>> documentation{this};
   Field<std::optional<containers::Uncertainty>> uncertainty{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->unit, \
      this->value, \
      this->documentation, \
      this->uncertainty)

   // default, and from fields
   explicit Temperature(
      const wrapper<std::optional<XMLName>> &label = {},
      const wrapper<std::optional<XMLName>> &unit = {},
      const wrapper<std::optional<Float64>> &value = {},
      const wrapper<std::optional<documentation::Documentation>> &documentation = {},
      const wrapper<std::optional<containers::Uncertainty>> &uncertainty = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      unit(this,unit),
      value(this,value),
      documentation(this,documentation),
      uncertainty(this,uncertainty)
   {
      Component::finish();
   }

   // from node
   explicit Temperature(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Temperature(const Temperature &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Temperature(Temperature &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Temperature &operator=(const Temperature &) = default;
   Temperature &operator=(Temperature &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/common/Temperature/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Temperature

} // namespace common
} // namespace v2_0
} // namespace test

#endif