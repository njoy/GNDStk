
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_SCTAPPROXIMATION
#define ALPHA_V2_0_GENERAL_SCTAPPROXIMATION

#include "alpha/v2.0/key.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class SCTApproximation
// -----------------------------------------------------------------------------

class SCTApproximation :
   public Component<general::SCTApproximation>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "SCTApproximation"; }
   static auto FIELD() { return "SCTApproximation"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{}
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment \
   )

   // default
   SCTApproximation() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from node
   explicit SCTApproximation(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   SCTApproximation(const SCTApproximation &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment)
   {
      Component::finish(other);
   }

   // move
   SCTApproximation(SCTApproximation &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   SCTApproximation &operator=(const SCTApproximation &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
      }
      return *this;
   }

   // move
   SCTApproximation &operator=(SCTApproximation &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/SCTApproximation/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class SCTApproximation

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
