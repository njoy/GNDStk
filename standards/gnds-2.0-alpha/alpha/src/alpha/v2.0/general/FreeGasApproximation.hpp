
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_FREEGASAPPROXIMATION
#define ALPHA_V2_0_GENERAL_FREEGASAPPROXIMATION

#include "alpha/v2.0/key.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class FreeGasApproximation
// -----------------------------------------------------------------------------

class FreeGasApproximation :
   public Component<general::FreeGasApproximation>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "FreeGasApproximation"; }
   static auto FIELD() { return "freeGasApproximation"; }

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
   FreeGasApproximation() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from node
   explicit FreeGasApproximation(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   FreeGasApproximation(const FreeGasApproximation &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment)
   {
      Component::finish(other);
   }

   // move
   FreeGasApproximation(FreeGasApproximation &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   FreeGasApproximation &operator=(const FreeGasApproximation &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
      }
      return *this;
   }

   // move
   FreeGasApproximation &operator=(FreeGasApproximation &&other)
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

   #include "alpha/v2.0/general/FreeGasApproximation/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class FreeGasApproximation

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
