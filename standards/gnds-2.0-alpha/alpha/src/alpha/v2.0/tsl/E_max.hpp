
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_TSL_E_MAX
#define ALPHA_V2_0_TSL_E_MAX

#include "alpha/v2.0/key.hpp"

namespace alpha {
namespace v2_0 {
namespace tsl {

// -----------------------------------------------------------------------------
// tsl::
// class E_max
// -----------------------------------------------------------------------------

class E_max :
   public Component<tsl::E_max>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "tsl"; }
   static auto CLASS() { return "E_max"; }
   static auto FIELD() { return "e_max"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         double{}
            / Meta<>("value") |
         std::string{}
            / Meta<>("unit")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<double> value{this};
   Field<std::string> unit{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->value, \
      this->unit)

   // default
   E_max() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit E_max(
      const wrapper<double>
         &value,
      const wrapper<std::string>
         &unit = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      value(this,value),
      unit(this,unit)
   {
      Component::finish();
   }

   // from node
   explicit E_max(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   E_max(const E_max &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      value(this,other.value),
      unit(this,other.unit)
   {
      Component::finish(other);
   }

   // move
   E_max(E_max &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      value(this,std::move(other.value)),
      unit(this,std::move(other.unit))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   E_max &operator=(const E_max &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         value = other.value;
         unit = other.unit;
      }
      return *this;
   }

   // move
   E_max &operator=(E_max &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         value = std::move(other.value);
         unit = std::move(other.unit);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/tsl/E_max/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class E_max

} // namespace tsl
} // namespace v2_0
} // namespace alpha

#endif
