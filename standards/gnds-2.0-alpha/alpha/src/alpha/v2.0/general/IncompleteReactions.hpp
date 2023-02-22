
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

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "IncompleteReactions"; }
   static auto NODENAME() { return "incompleteReactions"; }

   // Core Interface multi-query to transfer information to/from core Nodes
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

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "reaction"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "reaction"
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