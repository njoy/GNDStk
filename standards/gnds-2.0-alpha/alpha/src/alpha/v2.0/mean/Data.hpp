
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_MEAN_DATA
#define ALPHA_V2_0_MEAN_DATA

#include "alpha/v2.0/key.hpp"

namespace alpha {
namespace v2_0 {
namespace mean {

// -----------------------------------------------------------------------------
// mean::
// class Data
// -----------------------------------------------------------------------------

class Data :
   public Component<mean::Data>,
   public DataNode<std::vector<double>,false>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "mean"; }
   static auto CLASS() { return "Data"; }
   static auto FIELD() { return "data"; }

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
   using Component::construct;
   using DataNode::operator=;

   // comment
   Field<std::vector<std::string>> comment{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      static_cast<DataNode &>(*this))

   // default
   Data() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from node
   explicit Data(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // from vector<double>
   Data(const std::vector<double> &vector) :
      GNDSTK_COMPONENT(BlockData{}),
      DataNode(vector)
   {
      Component::finish(vector);
   }

   // copy
   Data(const Data &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      DataNode(other),
      comment(this,other.comment)
   {
      Component::finish(other);
   }

   // move
   Data(Data &&other) :
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
   Data &operator=(const Data &other)
   {
      if (this != &other) {
         Component::operator=(other);
         DataNode::operator=(other);
         comment = other.comment;
      }
      return *this;
   }

   // move
   Data &operator=(Data &&other)
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

   #include "alpha/v2.0/mean/Data/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Data

} // namespace mean
} // namespace v2_0
} // namespace alpha

#endif
