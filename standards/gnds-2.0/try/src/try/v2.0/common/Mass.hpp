
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_COMMON_MASS
#define TRY_V2_0_COMMON_MASS

#include "try/v2.0/documentation/Documentation.hpp"
#include "try/v2.0/containers/Uncertainty.hpp"
#include "try/v2.0/containers/Double.hpp"

namespace try {
namespace v2_0 {
namespace common {

// -----------------------------------------------------------------------------
// common::
// class Mass
// -----------------------------------------------------------------------------

class Mass : public Component<common::Mass> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "common"; }
   static auto CLASS() { return "Mass"; }
   static auto FIELD() { return "mass"; }

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
         std::optional<documentation::Documentation>{}
            / --Child<>("documentation") |
         std::optional<containers::Uncertainty>{}
            / --Child<>("uncertainty") |
         containers::Double{}
            / ++Child<>("Double")
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
   Field<std::optional<containers::Uncertainty>> uncertainty{this};
   Field<std::vector<containers::Double>> Double{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->unit, \
      this->value, \
      this->documentation, \
      this->uncertainty, \
      this->Double)

   // default, and from fields
   explicit Mass(
      const wrapper<std::optional<XMLName>> &label = {},
      const wrapper<std::optional<XMLName>> &unit = {},
      const wrapper<std::optional<XMLName>> &value = {},
      const wrapper<std::optional<documentation::Documentation>> &documentation = {},
      const wrapper<std::optional<containers::Uncertainty>> &uncertainty = {},
      const wrapper<std::vector<containers::Double>> &Double = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      unit(this,unit),
      value(this,value),
      documentation(this,documentation),
      uncertainty(this,uncertainty),
      Double(this,Double)
   {
      Component::finish();
   }

   // from node
   explicit Mass(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Mass(const Mass &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Mass(Mass &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Mass &operator=(const Mass &) = default;
   Mass &operator=(Mass &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/common/Mass/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Mass

} // namespace common
} // namespace v2_0
} // namespace try

#endif
