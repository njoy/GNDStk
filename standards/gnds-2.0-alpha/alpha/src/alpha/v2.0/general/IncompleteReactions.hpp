
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_INCOMPLETEREACTIONS
#define ALPHA_V2_0_GENERAL_INCOMPLETEREACTIONS

#include "alpha/v2.0/general/Reaction.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class IncompleteReactions
// -----------------------------------------------------------------------------

class IncompleteReactions :
   public Component<general::IncompleteReactions>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "IncompleteReactions"; }
   static auto FIELD() { return "incompleteReactions"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<general::Reaction>
            ("reaction")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<std::vector<general::Reaction>>
      reaction{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->reaction \
   )

   // default
   IncompleteReactions() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit IncompleteReactions(
      const wrapper<std::vector<general::Reaction>>
         &reaction
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      reaction(this,reaction)
   {
      Component::finish();
   }

   // from node
   explicit IncompleteReactions(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   IncompleteReactions(const IncompleteReactions &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      reaction(this,other.reaction)
   {
      Component::finish(other);
   }

   // move
   IncompleteReactions(IncompleteReactions &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      reaction(this,std::move(other.reaction))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   IncompleteReactions &operator=(const IncompleteReactions &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         reaction = other.reaction;
      }
      return *this;
   }

   // move
   IncompleteReactions &operator=(IncompleteReactions &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         reaction = std::move(other.reaction);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/IncompleteReactions/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class IncompleteReactions

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
