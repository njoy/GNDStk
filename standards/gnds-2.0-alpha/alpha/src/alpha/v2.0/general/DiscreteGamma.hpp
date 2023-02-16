
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_DISCRETEGAMMA
#define ALPHA_V2_0_GENERAL_DISCRETEGAMMA

#include "alpha/v2.0/general/Axes.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class DiscreteGamma
// -----------------------------------------------------------------------------

class DiscreteGamma :
   public Component<general::DiscreteGamma>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "DiscreteGamma"; }
   static auto NODENAME() { return "discreteGamma"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         double{}
            / Meta<>("value") |
         double{}
            / Meta<>("domainMin") |
         double{}
            / Meta<>("domainMax") |

         // children
         --Child<general::Axes>
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
   Field<double>
      value{this};
   Field<double>
      domainMin{this};
   Field<double>
      domainMax{this};

   // children
   Field<general::Axes>
      axes{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->value, \
      this->domainMin, \
      this->domainMax, \
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
      const wrapper<double>
         &value,
      const wrapper<double>
         &domainMin = {},
      const wrapper<double>
         &domainMax = {},
      const wrapper<general::Axes>
         &axes = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      value(this,value),
      domainMin(this,domainMin),
      domainMax(this,domainMax),
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
      value(this,other.value),
      domainMin(this,other.domainMin),
      domainMax(this,other.domainMax),
      axes(this,other.axes)
   {
      Component::finish(other);
   }

   // move
   DiscreteGamma(DiscreteGamma &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      value(this,std::move(other.value)),
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
   DiscreteGamma &operator=(const DiscreteGamma &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         value = other.value;
         domainMin = other.domainMin;
         domainMax = other.domainMax;
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
         value = std::move(other.value);
         domainMin = std::move(other.domainMin);
         domainMax = std::move(other.domainMax);
         axes = std::move(other.axes);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/DiscreteGamma/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class DiscreteGamma

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
