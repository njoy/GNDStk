
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_POPS_INTENSITY
#define TEST_V2_0_POPS_INTENSITY

#include "test/v2.0/documentation/Documentation.hpp"
#include "test/v2.0/pops/Uncertainty.hpp"

namespace test {
namespace v2_0 {
namespace pops {

// -----------------------------------------------------------------------------
// pops::
// class Intensity
// -----------------------------------------------------------------------------

class Intensity :
   public Component<pops::Intensity>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "pops"; }
   static auto CLASS() { return "Intensity"; }
   static auto NODENAME() { return "intensity"; }

   // Core Interface multi-query to transfer information to/from core Nodes
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
         std::optional<Float64>{}
            / Meta<>("value") |

         // children
         --Child<std::optional<documentation::Documentation>>
            ("documentation") |
         --Child<std::optional<pops::Uncertainty>>
            ("uncertainty")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "unit",
         "value",
         "documentation",
         "uncertainty"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "unit",
         "value",
         "documentation",
         "uncertainty"
      };
      return names;
   }

   // ------------------------
   // Public interface
   // ------------------------

public:

   using component_t = Component;
   using Component::construct;

   // ------------------------
   // Data members
   // ------------------------

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::optional<XMLName>>
      label{this};
   Field<std::optional<XMLName>>
      unit{this};
   Field<std::optional<Float64>>
      value{this};

   // children
   Field<std::optional<documentation::Documentation>>
      documentation{this};
   Field<std::optional<pops::Uncertainty>>
      uncertainty{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->unit, \
      this->value, \
      this->documentation, \
      this->uncertainty \
   )

   // default
   Intensity() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Intensity(
      const wrapper<std::optional<XMLName>>
         &label,
      const wrapper<std::optional<XMLName>>
         &unit = {},
      const wrapper<std::optional<Float64>>
         &value = {},
      const wrapper<std::optional<documentation::Documentation>>
         &documentation = {},
      const wrapper<std::optional<pops::Uncertainty>>
         &uncertainty = {}
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
   explicit Intensity(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Intensity(const Intensity &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      unit(this,other.unit),
      value(this,other.value),
      documentation(this,other.documentation),
      uncertainty(this,other.uncertainty)
   {
      Component::finish(other);
   }

   // move
   Intensity(Intensity &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      unit(this,std::move(other.unit)),
      value(this,std::move(other.value)),
      documentation(this,std::move(other.documentation)),
      uncertainty(this,std::move(other.uncertainty))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Intensity &operator=(const Intensity &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         unit = other.unit;
         value = other.value;
         documentation = other.documentation;
         uncertainty = other.uncertainty;
      }
      return *this;
   }

   // move
   Intensity &operator=(Intensity &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         unit = std::move(other.unit);
         value = std::move(other.value);
         documentation = std::move(other.documentation);
         uncertainty = std::move(other.uncertainty);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/pops/Intensity/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Intensity

} // namespace pops
} // namespace v2_0
} // namespace test

#endif
