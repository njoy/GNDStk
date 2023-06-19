
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_COVARIANCE_SUM
#define TEST_V2_0_COVARIANCE_SUM

#include "test/v2.0/covariance/Summand.hpp"

namespace test {
namespace v2_0 {
namespace covariance {

// -----------------------------------------------------------------------------
// covariance::
// class Sum
// -----------------------------------------------------------------------------

class Sum :
   public Component<covariance::Sum>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "covariance"; }
   static auto CLASS() { return "Sum"; }
   static auto NODENAME() { return "sum"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         Float64{}
            / Meta<>("domainMin") |
         Float64{}
            / Meta<>("domainMax") |
         XMLName{}
            / Meta<>("domainUnit") |
         std::optional<XMLName>{}
            / Meta<>("label") |

         // children
         ++Child<std::optional<covariance::Summand>>
            ("summand")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "domainMin",
         "domainMax",
         "domainUnit",
         "label",
         "summand"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "domain_min",
         "domain_max",
         "domain_unit",
         "label",
         "summand"
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
   Field<Float64>
      domainMin{this};
   Field<Float64>
      domainMax{this};
   Field<XMLName>
      domainUnit{this};
   Field<std::optional<XMLName>>
      label{this};

   // children
   Field<std::optional<std::vector<covariance::Summand>>>
      summand{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->domainMin, \
      this->domainMax, \
      this->domainUnit, \
      this->label, \
      this->summand \
   )

   // default
   Sum() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Sum(
      const wrapper<Float64>
         &domainMin,
      const wrapper<Float64>
         &domainMax = {},
      const wrapper<XMLName>
         &domainUnit = {},
      const wrapper<std::optional<XMLName>>
         &label = {},
      const wrapper<std::optional<std::vector<covariance::Summand>>>
         &summand = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      domainMin(this,domainMin),
      domainMax(this,domainMax),
      domainUnit(this,domainUnit),
      label(this,label),
      summand(this,summand)
   {
      Component::finish();
   }

   // from node
   explicit Sum(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Sum(const Sum &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      domainMin(this,other.domainMin),
      domainMax(this,other.domainMax),
      domainUnit(this,other.domainUnit),
      label(this,other.label),
      summand(this,other.summand)
   {
      Component::finish(other);
   }

   // move
   Sum(Sum &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      domainMin(this,std::move(other.domainMin)),
      domainMax(this,std::move(other.domainMax)),
      domainUnit(this,std::move(other.domainUnit)),
      label(this,std::move(other.label)),
      summand(this,std::move(other.summand))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Sum &operator=(const Sum &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         domainMin = other.domainMin;
         domainMax = other.domainMax;
         domainUnit = other.domainUnit;
         label = other.label;
         summand = other.summand;
      }
      return *this;
   }

   // move
   Sum &operator=(Sum &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         domainMin = std::move(other.domainMin);
         domainMax = std::move(other.domainMax);
         domainUnit = std::move(other.domainUnit);
         label = std::move(other.label);
         summand = std::move(other.summand);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/covariance/Sum/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Sum

} // namespace covariance
} // namespace v2_0
} // namespace test

#endif
