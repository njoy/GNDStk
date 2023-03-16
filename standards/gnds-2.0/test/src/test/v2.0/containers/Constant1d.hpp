
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_CONTAINERS_CONSTANT1D
#define TEST_V2_0_CONTAINERS_CONSTANT1D

#include "test/v2.0/containers/Axes.hpp"

namespace test {
namespace v2_0 {
namespace containers {

// -----------------------------------------------------------------------------
// containers::
// class Constant1d
// -----------------------------------------------------------------------------

class Constant1d :
   public Component<containers::Constant1d>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "containers"; }
   static auto CLASS() { return "Constant1d"; }
   static auto NODENAME() { return "constant1d"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::optional<Float64>{}
            / Meta<>("value") |
         std::optional<XMLName>{}
            / Meta<>("label") |
         std::optional<Float64>{}
            / Meta<>("outerDomainValue") |
         Float64{}
            / Meta<>("domainMin") |
         Float64{}
            / Meta<>("domainMax") |

         // children
         --Child<containers::Axes>
            ("axes")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "value",
         "label",
         "outerDomainValue",
         "domainMin",
         "domainMax",
         "axes"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "value",
         "label",
         "outer_domain_value",
         "domain_min",
         "domain_max",
         "axes"
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
   Field<std::optional<Float64>>
      value{this};
   Field<std::optional<XMLName>>
      label{this};
   Field<std::optional<Float64>>
      outerDomainValue{this};
   Field<Float64>
      domainMin{this};
   Field<Float64>
      domainMax{this};

   // children
   Field<containers::Axes>
      axes{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->value, \
      this->label, \
      this->outerDomainValue, \
      this->domainMin, \
      this->domainMax, \
      this->axes \
   )

   // default
   Constant1d() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Constant1d(
      const wrapper<std::optional<Float64>>
         &value,
      const wrapper<std::optional<XMLName>>
         &label = {},
      const wrapper<std::optional<Float64>>
         &outerDomainValue = {},
      const wrapper<Float64>
         &domainMin = {},
      const wrapper<Float64>
         &domainMax = {},
      const wrapper<containers::Axes>
         &axes = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      value(this,value),
      label(this,label),
      outerDomainValue(this,outerDomainValue),
      domainMin(this,domainMin),
      domainMax(this,domainMax),
      axes(this,axes)
   {
      Component::finish();
   }

   // from node
   explicit Constant1d(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Constant1d(const Constant1d &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      value(this,other.value),
      label(this,other.label),
      outerDomainValue(this,other.outerDomainValue),
      domainMin(this,other.domainMin),
      domainMax(this,other.domainMax),
      axes(this,other.axes)
   {
      Component::finish(other);
   }

   // move
   Constant1d(Constant1d &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      value(this,std::move(other.value)),
      label(this,std::move(other.label)),
      outerDomainValue(this,std::move(other.outerDomainValue)),
      domainMin(this,std::move(other.domainMin)),
      domainMax(this,std::move(other.domainMax)),
      axes(this,std::move(other.axes))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Constant1d &operator=(const Constant1d &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         value = other.value;
         label = other.label;
         outerDomainValue = other.outerDomainValue;
         domainMin = other.domainMin;
         domainMax = other.domainMax;
         axes = other.axes;
      }
      return *this;
   }

   // move
   Constant1d &operator=(Constant1d &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         value = std::move(other.value);
         label = std::move(other.label);
         outerDomainValue = std::move(other.outerDomainValue);
         domainMin = std::move(other.domainMin);
         domainMax = std::move(other.domainMax);
         axes = std::move(other.axes);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/containers/Constant1d/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Constant1d

} // namespace containers
} // namespace v2_0
} // namespace test

#endif
