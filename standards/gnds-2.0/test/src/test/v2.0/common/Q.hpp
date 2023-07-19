
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_COMMON_Q
#define TEST_V2_0_COMMON_Q

#include "test/v2.0/documentation/Documentation.hpp"
#include "test/v2.0/containers/Uncertainty.hpp"
#include "test/v2.0/containers/Constant1d.hpp"
#include "test/v2.0/containers/XYs1d.hpp"
#include "test/v2.0/containers/Regions1d.hpp"
#include "test/v2.0/containers/Polynomial1d.hpp"
#include "test/v2.0/containers/Gridded1d.hpp"

namespace test {
namespace v2_0 {
namespace common {

// -----------------------------------------------------------------------------
// common::
// class Q
// -----------------------------------------------------------------------------

class Q :
   public Component<common::Q>
{
   friend class Component;

   using _t = std::variant<
      containers::Constant1d,
      containers::XYs1d,
      containers::Regions1d,
      containers::Polynomial1d,
      containers::Gridded1d
   >;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "common"; }
   static auto CLASS() { return "Q"; }
   static auto NODENAME() { return "Q"; }

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
         XMLName{}
            / Meta<>("value") |

         // children
         --Child<std::optional<documentation::Documentation>>
            ("documentation") |
         --Child<std::optional<containers::Uncertainty>>
            ("uncertainty") |
         _t{}
            / --(Child<>("constant1d") || Child<>("XYs1d") || Child<>("regions1d") || Child<>("polynomial1d") || Child<>("gridded1d"))
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
         "uncertainty",
         "_constant1dXYs1dregions1dpolynomial1dgridded1d"
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
         "uncertainty",
         "_constant1d_xys1dregions1dpolynomial1dgridded1d"
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
   Field<XMLName>
      value{this};

   // children
   Field<std::optional<documentation::Documentation>>
      documentation{this};
   Field<std::optional<containers::Uncertainty>>
      uncertainty{this};

   // children - variant
   Field<_t>
      _constant1dXYs1dregions1dpolynomial1dgridded1d{this};
   FieldPart<decltype(_constant1dXYs1dregions1dpolynomial1dgridded1d),containers::Constant1d> constant1d{_constant1dXYs1dregions1dpolynomial1dgridded1d};
   FieldPart<decltype(_constant1dXYs1dregions1dpolynomial1dgridded1d),containers::XYs1d> XYs1d{_constant1dXYs1dregions1dpolynomial1dgridded1d};
   FieldPart<decltype(_constant1dXYs1dregions1dpolynomial1dgridded1d),containers::Regions1d> regions1d{_constant1dXYs1dregions1dpolynomial1dgridded1d};
   FieldPart<decltype(_constant1dXYs1dregions1dpolynomial1dgridded1d),containers::Polynomial1d> polynomial1d{_constant1dXYs1dregions1dpolynomial1dgridded1d};
   FieldPart<decltype(_constant1dXYs1dregions1dpolynomial1dgridded1d),containers::Gridded1d> gridded1d{_constant1dXYs1dregions1dpolynomial1dgridded1d};

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
      this->uncertainty, \
      this->_constant1dXYs1dregions1dpolynomial1dgridded1d \
   )

   // default
   Q() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Q(
      const wrapper<std::optional<XMLName>>
         &label,
      const wrapper<std::optional<XMLName>>
         &unit = {},
      const wrapper<XMLName>
         &value = {},
      const wrapper<std::optional<documentation::Documentation>>
         &documentation = {},
      const wrapper<std::optional<containers::Uncertainty>>
         &uncertainty = {},
      const wrapper<_t>
         &_constant1dXYs1dregions1dpolynomial1dgridded1d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      unit(this,unit),
      value(this,value),
      documentation(this,documentation),
      uncertainty(this,uncertainty),
      _constant1dXYs1dregions1dpolynomial1dgridded1d(this,_constant1dXYs1dregions1dpolynomial1dgridded1d)
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
      _constant1dXYs1dregions1dpolynomial1dgridded1d(this,other._constant1dXYs1dregions1dpolynomial1dgridded1d)
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
      _constant1dXYs1dregions1dpolynomial1dgridded1d(this,std::move(other._constant1dXYs1dregions1dpolynomial1dgridded1d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Q &operator=(const Q &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         unit = other.unit;
         value = other.value;
         documentation = other.documentation;
         uncertainty = other.uncertainty;
         _constant1dXYs1dregions1dpolynomial1dgridded1d = other._constant1dXYs1dregions1dpolynomial1dgridded1d;
      }
      return *this;
   }

   // move
   Q &operator=(Q &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         unit = std::move(other.unit);
         value = std::move(other.value);
         documentation = std::move(other.documentation);
         uncertainty = std::move(other.uncertainty);
         _constant1dXYs1dregions1dpolynomial1dgridded1d = std::move(other._constant1dXYs1dregions1dpolynomial1dgridded1d);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/common/Q/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Q

} // namespace common
} // namespace v2_0
} // namespace test

#endif
