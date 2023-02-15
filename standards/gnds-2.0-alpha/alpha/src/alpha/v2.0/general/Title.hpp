
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_TITLE
#define ALPHA_V2_0_GENERAL_TITLE

#include "alpha/v2.0/key.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Title
// -----------------------------------------------------------------------------

class Title :
   public Component<general::Title>,
   public DataNode<std::string,true>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Title"; }
   static auto FIELD() { return "title"; }

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

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "string"
      };
      return names;
   }

   // ------------------------
   // Public interface
   // ------------------------

public:

   using component_t = Component;
   using Component::construct;
   using DataNode::operator=;

   // ------------------------
   // Data members
   // ------------------------

   // comment
   Field<std::vector<std::string>> comment{this};

   // data
   std::string &string = *this;

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
   Title() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from node
   explicit Title(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Title(const Title &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      DataNode(other),
      comment(this,other.comment)
   {
      Component::finish(other);
   }

   // move
   Title(Title &&other) :
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
   Title &operator=(const Title &other)
   {
      if (this != &other) {
         Component::operator=(other);
         DataNode::operator=(other);
         comment = other.comment;
      }
      return *this;
   }

   // move
   Title &operator=(Title &&other)
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

   #include "alpha/v2.0/general/Title/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Title

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
