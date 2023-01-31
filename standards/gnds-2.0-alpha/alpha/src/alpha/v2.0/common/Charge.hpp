
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_COMMON_CHARGE
#define ALPHA_V2_0_COMMON_CHARGE

#include "alpha/v2.0/common/Integer.hpp"

namespace alpha {
namespace v2_0 {
namespace common {

// -----------------------------------------------------------------------------
// common::
// class Charge
// -----------------------------------------------------------------------------

class Charge :
   public Component<common::Charge>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "common"; }
   static auto CLASS() { return "Charge"; }
   static auto FIELD() { return "charge"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<common::Integer>("integer")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<common::Integer> integer{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->integer)

   // default
   Charge() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Charge(
      const wrapper<common::Integer> &integer
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      integer(this,integer)
   {
      Component::finish();
   }

   // from node
   explicit Charge(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Charge(const Charge &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      integer(this,other.integer)
   {
      Component::finish(other);
   }

   // move
   Charge(Charge &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      integer(this,std::move(other.integer))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Charge &operator=(const Charge &) = default;
   Charge &operator=(Charge &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/common/Charge/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Charge

} // namespace common
} // namespace v2_0
} // namespace alpha

#endif
