
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_CONTAINERS_DOUBLE
#define TEST_V2_0_CONTAINERS_DOUBLE

#include "test/v2.0/containers/Uncertainty.hpp"

namespace test {
namespace v2_0 {
namespace containers {

// -----------------------------------------------------------------------------
// containers::
// class Double
// -----------------------------------------------------------------------------

class Double :
   public Component<containers::Double>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "containers"; }
   static auto CLASS() { return "Double"; }
   static auto FIELD() { return "double"; }

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
         Float64{}
            / Meta<>("value") |

         // children
         --Child<std::optional<containers::Uncertainty>>("uncertainty")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::optional<XMLName>> label{this};
   Field<std::optional<XMLName>> unit{this};
   Field<Float64> value{this};

   // children
   Field<std::optional<containers::Uncertainty>> uncertainty{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->label, \
      this->unit, \
      this->value, \
      this->uncertainty)

   // default
   Double() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Double(
      const wrapper<std::optional<XMLName>> &label,
      const wrapper<std::optional<XMLName>> &unit = {},
      const wrapper<Float64> &value = {},
      const wrapper<std::optional<containers::Uncertainty>> &uncertainty = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      unit(this,unit),
      value(this,value),
      uncertainty(this,uncertainty)
   {
      Component::finish();
   }

   // from node
   explicit Double(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Double(const Double &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      unit(this,other.unit),
      value(this,other.value),
      uncertainty(this,other.uncertainty)
   {
      Component::finish(other);
   }

   // move
   Double(Double &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      unit(this,std::move(other.unit)),
      value(this,std::move(other.value)),
      uncertainty(this,std::move(other.uncertainty))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Double &operator=(const Double &) = default;
   Double &operator=(Double &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/containers/Double/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Double

} // namespace containers
} // namespace v2_0
} // namespace test

#endif
