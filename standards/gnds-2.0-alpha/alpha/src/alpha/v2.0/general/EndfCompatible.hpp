
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_ENDFCOMPATIBLE
#define ALPHA_V2_0_GENERAL_ENDFCOMPATIBLE

#include "alpha/v2.0/key.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class EndfCompatible
// -----------------------------------------------------------------------------

class EndfCompatible :
   public Component<general::EndfCompatible>,
   public DataNode<std::string,true>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "EndfCompatible"; }
   static auto FIELD() { return "endfCompatible"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // data
         --Child<DataNode>(special::self) / DataConverter{}
      ;
   }

public:
   using component_t = Component;
   using Component::construct;
   using DataNode::operator=;

   // comment
   Field<std::vector<std::string>> comment{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      static_cast<DataNode &>(*this) \
   )

   // default
   EndfCompatible() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from node
   explicit EndfCompatible(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   EndfCompatible(const EndfCompatible &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      DataNode(other),
      comment(this,other.comment)
   {
      Component::finish(other);
   }

   // move
   EndfCompatible(EndfCompatible &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      DataNode(std::move(other)),
      comment(this,std::move(other.comment))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   EndfCompatible &operator=(const EndfCompatible &other)
   {
      if (this != &other) {
         Component::operator=(other);
         DataNode::operator=(other);
         comment = other.comment;
      }
      return *this;
   }

   // move
   EndfCompatible &operator=(EndfCompatible &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         DataNode::operator=(std::move(other));
         comment = std::move(other.comment);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/EndfCompatible/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class EndfCompatible

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
