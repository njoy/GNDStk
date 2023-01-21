
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_POPS_Q
#define TEST_V2_0_POPS_Q

#include "test/v2.0/documentation/Documentation.hpp"
#include "test/v2.0/pops/Uncertainty.hpp"
#include "test/v2.0/containers/Double.hpp"

namespace test {
namespace v2_0 {
namespace pops {

// -----------------------------------------------------------------------------
// pops::
// class Q
// -----------------------------------------------------------------------------

class Q :
   public Component<pops::Q>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "pops"; }
   static auto CLASS() { return "Q"; }
   static auto FIELD() { return "Q"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::optional<XMLName>{}
            / Meta<>("label") |
         std::optional<XMLName>{}
            / Meta<>("unit") |
         XMLName{}
            / Meta<>("value") |

         // children
         --Child<std::optional<documentation::Documentation>>("documentation") |
         --Child<std::optional<pops::Uncertainty>>("uncertainty") |
         ++Child<containers::Double>("double")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::optional<XMLName>> label{this};
   Field<std::optional<XMLName>> unit{this};
   Field<XMLName> value{this};

   // children
   Field<std::optional<documentation::Documentation>> documentation{this};
   Field<std::optional<pops::Uncertainty>> uncertainty{this};
   Field<std::vector<containers::Double>> Double{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->label, \
      this->unit, \
      this->value, \
      this->documentation, \
      this->uncertainty, \
      this->Double)

   // default
   Q() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Q(
      const wrapper<std::optional<XMLName>> &label,
      const wrapper<std::optional<XMLName>> &unit = {},
      const wrapper<XMLName> &value = {},
      const wrapper<std::optional<documentation::Documentation>> &documentation = {},
      const wrapper<std::optional<pops::Uncertainty>> &uncertainty = {},
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
   explicit Q(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Q(const Q &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      unit(this,other.unit),
      value(this,other.value),
      documentation(this,other.documentation),
      uncertainty(this,other.uncertainty),
      Double(this,other.Double)
   {
      Component::finish(other);
   }

   // move
   Q(Q &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      unit(this,std::move(other.unit)),
      value(this,std::move(other.value)),
      documentation(this,std::move(other.documentation)),
      uncertainty(this,std::move(other.uncertainty)),
      Double(this,std::move(other.Double))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Q &operator=(const Q &) = default;
   Q &operator=(Q &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/pops/Q/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Q

} // namespace pops
} // namespace v2_0
} // namespace test

#endif
