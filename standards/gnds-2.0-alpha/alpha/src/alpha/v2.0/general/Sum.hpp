
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_SUM
#define ALPHA_V2_0_GENERAL_SUM

#include "alpha/v2.0/general/Summand.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Sum
// -----------------------------------------------------------------------------

class Sum :
   public Component<general::Sum>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Sum"; }
   static auto FIELD() { return "sum"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::optional<std::string>{}
            / Meta<>("label") |
         std::optional<double>{}
            / Meta<>("domainMin") |
         std::optional<double>{}
            / Meta<>("domainMax") |
         std::optional<std::string>{}
            / Meta<>("domainUnit") |

         // children
         ++Child<general::Summand>
            ("summand")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::optional<std::string>>
      label{this};
   Field<std::optional<double>>
      domainMin{this};
   Field<std::optional<double>>
      domainMax{this};
   Field<std::optional<std::string>>
      domainUnit{this};

   // children
   Field<std::vector<general::Summand>>
      summand{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->label, \
      this->domainMin, \
      this->domainMax, \
      this->domainUnit, \
      this->summand)

   // default
   Sum() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Sum(
      const wrapper<std::optional<std::string>>
         &label,
      const wrapper<std::optional<double>>
         &domainMin = {},
      const wrapper<std::optional<double>>
         &domainMax = {},
      const wrapper<std::optional<std::string>>
         &domainUnit = {},
      const wrapper<std::vector<general::Summand>>
         &summand = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      domainMin(this,domainMin),
      domainMax(this,domainMax),
      domainUnit(this,domainUnit),
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
      label(this,other.label),
      domainMin(this,other.domainMin),
      domainMax(this,other.domainMax),
      domainUnit(this,other.domainUnit),
      summand(this,other.summand)
   {
      Component::finish(other);
   }

   // move
   Sum(Sum &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      domainMin(this,std::move(other.domainMin)),
      domainMax(this,std::move(other.domainMax)),
      domainUnit(this,std::move(other.domainUnit)),
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
         label = other.label;
         domainMin = other.domainMin;
         domainMax = other.domainMax;
         domainUnit = other.domainUnit;
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
         label = std::move(other.label);
         domainMin = std::move(other.domainMin);
         domainMax = std::move(other.domainMax);
         domainUnit = std::move(other.domainUnit);
         summand = std::move(other.summand);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/Sum/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Sum

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
