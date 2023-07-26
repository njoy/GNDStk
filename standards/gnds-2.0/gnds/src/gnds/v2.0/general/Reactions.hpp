
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_REACTIONS
#define GNDS_V2_0_GENERAL_REACTIONS

#include "gnds/v2.0/general/Reaction.hpp"

namespace gnds {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Reactions
// -----------------------------------------------------------------------------

class Reactions :
   public Component<general::Reactions>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Reactions"; }
   static auto NODENAME() { return "reactions"; }

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

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->reaction \
   )

   // default
   Reactions() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Reactions(
      const wrapper<std::vector<general::Reaction>>
         &reaction
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      reaction(this,reaction)
   {
      Component::finish();
   }

   // from node
   explicit Reactions(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Reactions(const Reactions &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      reaction(this,other.reaction)
   {
      Component::finish(other);
   }

   // move
   Reactions(Reactions &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      reaction(this,std::move(other.reaction))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Reactions &operator=(const Reactions &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         reaction = other.reaction;
      }
      return *this;
   }

   // move
   Reactions &operator=(Reactions &&other)
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

   #include "gnds/v2.0/general/Reactions/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class Reactions

} // namespace general
} // namespace v2_0
} // namespace gnds

#endif
