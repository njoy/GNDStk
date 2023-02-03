
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_MASS
#define ALPHA_V2_0_GENERAL_MASS

#include "alpha/v2.0/general/Double.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Mass
// -----------------------------------------------------------------------------

class Mass :
   public Component<general::Mass>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Mass"; }
   static auto FIELD() { return "mass"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::optional<double>{}
            / Meta<>("value") |
         std::optional<std::string>{}
            / Meta<>("unit") |

         // children
         --Child<std::optional<general::Double>>
            ("double")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::optional<double>>
      value{this};
   Field<std::optional<std::string>>
      unit{this};

   // children
   Field<std::optional<general::Double>>
      Double{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->value, \
      this->unit, \
      this->Double)

   // default
   Mass() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Mass(
      const wrapper<std::optional<double>>
         &value,
      const wrapper<std::optional<std::string>>
         &unit = {},
      const wrapper<std::optional<general::Double>>
         &Double = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      value(this,value),
      unit(this,unit),
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
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      value(this,other.value),
      unit(this,other.unit),
      Double(this,other.Double)
   {
      Component::finish(other);
   }

   // move
   Mass(Mass &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      value(this,std::move(other.value)),
      unit(this,std::move(other.unit)),
      Double(this,std::move(other.Double))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Mass &operator=(const Mass &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         value = other.value;
         unit = other.unit;
         Double = other.Double;
      }
      return *this;
   }

   // move
   Mass &operator=(Mass &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         value = std::move(other.value);
         unit = std::move(other.unit);
         Double = std::move(other.Double);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/Mass/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Mass

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
