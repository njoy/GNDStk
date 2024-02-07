
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_G3D_STARTS
#define GNDS_V2_0_G3D_STARTS

#include "GNDS/v2.0/key.hpp"

namespace GNDS {
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

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "g3d"; }
   static auto CLASS() { return "Starts"; }
   static auto NODENAME() { return "values"; }

   // Core Interface multi-query to transfer information to/from core Nodes
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

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "valueType",
         "label",
         "ints"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "value_type",
         "label",
         "ints"
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

   // metadata
   Field<std::string>
      valueType{this};
   Field<std::string>
      label{this};

   // data
   std::vector<int> &ints = *this;

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->valueType, \
      this->label, \
      static_cast<DataNode &>(*this) \
   )

   // default
   Starts() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
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
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      valueType(this,valueType),
      label(this,label)
   {
      Component::finish();
   }

   // from node
   explicit Starts(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // from vector<int>
   explicit Starts(const std::vector<int> &vector) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      DataNode(vector)
   {
      Component::finish(vector);
   }

   // copy
   Starts(const Starts &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      DataNode(other),
      comment(this,other.comment),
      valueType(this,other.valueType),
      label(this,other.label)
   {
      Component::finish(other);
   }

   // move
   Starts(Starts &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
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

   #include "GNDS/v2.0/g3d/Starts/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class Starts

} // namespace g3d
} // namespace v2_0
} // namespace GNDS

#endif
