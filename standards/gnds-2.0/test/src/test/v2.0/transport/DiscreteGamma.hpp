
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_TRANSPORT_DISCRETEGAMMA
#define TEST_V2_0_TRANSPORT_DISCRETEGAMMA

#include "test/v2.0/containers/Axes.hpp"

namespace test {
namespace v2_0 {
namespace transport {

// -----------------------------------------------------------------------------
// transport::
// class DiscreteGamma
// -----------------------------------------------------------------------------

class DiscreteGamma :
   public Component<transport::DiscreteGamma>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "transport"; }
   static auto CLASS() { return "DiscreteGamma"; }
   static auto NODENAME() { return "discreteGamma"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::optional<Float64>{}
            / Meta<>("domainMax") |
         std::optional<Float64>{}
            / Meta<>("domainMin") |
         std::optional<Float64>{}
            / Meta<>("value") |

         // children
         --Child<std::optional<containers::Axes>>
            ("axes")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "domainMax",
         "domainMin",
         "value",
         "axes"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "domain_max",
         "domain_min",
         "value",
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
      domainMax{this};
   Field<std::optional<Float64>>
      domainMin{this};
   Field<std::optional<Float64>>
      value{this};

   // children
   Field<std::optional<containers::Axes>>
      axes{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->domainMax, \
      this->domainMin, \
      this->value, \
      this->axes \
   )

   // default
   DiscreteGamma() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit DiscreteGamma(
      const wrapper<std::optional<Float64>>
         &domainMax,
      const wrapper<std::optional<Float64>>
         &domainMin = {},
      const wrapper<std::optional<Float64>>
         &value = {},
      const wrapper<std::optional<containers::Axes>>
         &axes = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      domainMax(this,domainMax),
      domainMin(this,domainMin),
      value(this,value),
      axes(this,axes)
   {
      Component::finish();
   }

   // from node
   explicit DiscreteGamma(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   DiscreteGamma(const DiscreteGamma &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      domainMax(this,other.domainMax),
      domainMin(this,other.domainMin),
      value(this,other.value),
      axes(this,other.axes)
   {
      Component::finish(other);
   }

   // move
   DiscreteGamma(DiscreteGamma &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      domainMax(this,std::move(other.domainMax)),
      domainMin(this,std::move(other.domainMin)),
      value(this,std::move(other.value)),
      axes(this,std::move(other.axes))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   DiscreteGamma &operator=(const DiscreteGamma &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         domainMax = other.domainMax;
         domainMin = other.domainMin;
         value = other.value;
         axes = other.axes;
      }
      return *this;
   }

   // move
   DiscreteGamma &operator=(DiscreteGamma &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         domainMax = std::move(other.domainMax);
         domainMin = std::move(other.domainMin);
         value = std::move(other.value);
         axes = std::move(other.axes);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/transport/DiscreteGamma/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class DiscreteGamma

} // namespace transport
} // namespace v2_0
} // namespace test

#endif
