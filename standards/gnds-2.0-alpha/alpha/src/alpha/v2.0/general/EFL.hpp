
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_EFL
#define ALPHA_V2_0_GENERAL_EFL

#include "alpha/v2.0/key.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class EFL
// -----------------------------------------------------------------------------

class EFL :
   public Component<general::EFL>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "EFL"; }
   static auto FIELD() { return "EFL"; }

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
   EFL() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit EFL(
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
   explicit EFL(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   EFL(const EFL &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      value(this,other.value),
      unit(this,other.unit)
   {
      Component::finish(other);
   }

   // move
   EFL(EFL &&other) :
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
   EFL &operator=(const EFL &other)
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
   EFL &operator=(EFL &&other)
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

   #include "alpha/v2.0/general/EFL/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class EFL

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
