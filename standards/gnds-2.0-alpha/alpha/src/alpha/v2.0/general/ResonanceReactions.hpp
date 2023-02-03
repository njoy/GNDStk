
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_RESONANCEREACTIONS
#define ALPHA_V2_0_GENERAL_RESONANCEREACTIONS

#include "alpha/v2.0/general/ResonanceReaction.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class ResonanceReactions
// -----------------------------------------------------------------------------

class ResonanceReactions :
   public Component<general::ResonanceReactions>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "ResonanceReactions"; }
   static auto FIELD() { return "resonanceReactions"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<general::ResonanceReaction>
            ("resonanceReaction")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<std::vector<general::ResonanceReaction>>
      resonanceReaction{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->resonanceReaction)

   // default
   ResonanceReactions() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ResonanceReactions(
      const wrapper<std::vector<general::ResonanceReaction>>
         &resonanceReaction
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      resonanceReaction(this,resonanceReaction)
   {
      Component::finish();
   }

   // from node
   explicit ResonanceReactions(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ResonanceReactions(const ResonanceReactions &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      resonanceReaction(this,other.resonanceReaction)
   {
      Component::finish(other);
   }

   // move
   ResonanceReactions(ResonanceReactions &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      resonanceReaction(this,std::move(other.resonanceReaction))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   ResonanceReactions &operator=(const ResonanceReactions &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         resonanceReaction = other.resonanceReaction;
      }
      return *this;
   }

   // move
   ResonanceReactions &operator=(ResonanceReactions &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         resonanceReaction = std::move(other.resonanceReaction);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/ResonanceReactions/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ResonanceReactions

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
