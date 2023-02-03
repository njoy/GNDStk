
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_DECAYMODES
#define ALPHA_V2_0_GENERAL_DECAYMODES

#include "alpha/v2.0/general/DecayMode.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class DecayModes
// -----------------------------------------------------------------------------

class DecayModes :
   public Component<general::DecayModes>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "DecayModes"; }
   static auto FIELD() { return "decayModes"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<general::DecayMode>
            ("decayMode")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<std::vector<general::DecayMode>>
      decayMode{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->decayMode)

   // default
   DecayModes() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit DecayModes(
      const wrapper<std::vector<general::DecayMode>>
         &decayMode
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      decayMode(this,decayMode)
   {
      Component::finish();
   }

   // from node
   explicit DecayModes(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   DecayModes(const DecayModes &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      decayMode(this,other.decayMode)
   {
      Component::finish(other);
   }

   // move
   DecayModes(DecayModes &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      decayMode(this,std::move(other.decayMode))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   DecayModes &operator=(const DecayModes &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         decayMode = other.decayMode;
      }
      return *this;
   }

   // move
   DecayModes &operator=(DecayModes &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         decayMode = std::move(other.decayMode);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/DecayModes/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class DecayModes

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
