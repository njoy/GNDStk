
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_G3D_STARTS
#define ALPHA_V2_0_G3D_STARTS

#include "alpha/v2.0/key.hpp"

namespace alpha {
namespace v2_0 {
namespace g3d {

// -----------------------------------------------------------------------------
// g3d::
// class Starts
// -----------------------------------------------------------------------------

class Starts :
   public Component<g3d::Starts>,
   public DataNode<std::vector<int>,false>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "g3d"; }
   static auto CLASS() { return "Starts"; }
   static auto FIELD() { return "values"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("valueType") |
         std::string{}
            / Meta<>("label") |

         // data
         --Child<DataNode>(special::self) / DataConverter{}
      ;
   }

public:
   using Component::construct;
   using DataNode::operator=;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string>
      valueType{this};
   Field<std::string>
      label{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->valueType, \
      this->label, \
      static_cast<DataNode &>(*this))

   // default
   Starts() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Starts(
      const wrapper<std::string>
         &valueType,
      const wrapper<std::string>
         &label = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      valueType(this,valueType),
      label(this,label)
   {
      Component::finish();
   }

   // from node
   explicit Starts(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // from vector<int>
   Starts(const std::vector<int> &vector) :
      GNDSTK_COMPONENT(BlockData{}),
      DataNode(vector)
   {
      Component::finish(vector);
   }

   // copy
   Starts(const Starts &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      DataNode(other),
      comment(this,other.comment),
      valueType(this,other.valueType),
      label(this,other.label)
   {
      Component::finish(other);
   }

   // move
   Starts(Starts &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      DataNode(std::move(other)),
      comment(this,std::move(other.comment)),
      valueType(this,std::move(other.valueType)),
      label(this,std::move(other.label))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Starts &operator=(const Starts &other)
   {
      if (this != &other) {
         Component::operator=(other);
         DataNode::operator=(other);
         comment = other.comment;
         valueType = other.valueType;
         label = other.label;
      }
      return *this;
   }

   // move
   Starts &operator=(Starts &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         DataNode::operator=(std::move(other));
         comment = std::move(other.comment);
         valueType = std::move(other.valueType);
         label = std::move(other.label);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/g3d/Starts/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Starts

} // namespace g3d
} // namespace v2_0
} // namespace alpha

#endif
