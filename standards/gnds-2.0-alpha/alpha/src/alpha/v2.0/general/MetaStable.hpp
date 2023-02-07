
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_METASTABLE
#define ALPHA_V2_0_GENERAL_METASTABLE

#include "alpha/v2.0/key.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class MetaStable
// -----------------------------------------------------------------------------

class MetaStable :
   public Component<general::MetaStable>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "MetaStable"; }
   static auto FIELD() { return "metaStable"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("id") |
         std::string{}
            / Meta<>("pid") |
         int{}
            / Meta<>("metaStableIndex")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string> id{this};
   Field<std::string> pid{this};
   Field<int> metaStableIndex{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->id, \
      this->pid, \
      this->metaStableIndex \
   )

   // default
   MetaStable() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit MetaStable(
      const wrapper<std::string>
         &id,
      const wrapper<std::string>
         &pid = {},
      const wrapper<int>
         &metaStableIndex = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      id(this,id),
      pid(this,pid),
      metaStableIndex(this,metaStableIndex)
   {
      Component::finish();
   }

   // from node
   explicit MetaStable(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   MetaStable(const MetaStable &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      id(this,other.id),
      pid(this,other.pid),
      metaStableIndex(this,other.metaStableIndex)
   {
      Component::finish(other);
   }

   // move
   MetaStable(MetaStable &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      id(this,std::move(other.id)),
      pid(this,std::move(other.pid)),
      metaStableIndex(this,std::move(other.metaStableIndex))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   MetaStable &operator=(const MetaStable &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         id = other.id;
         pid = other.pid;
         metaStableIndex = other.metaStableIndex;
      }
      return *this;
   }

   // move
   MetaStable &operator=(MetaStable &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         id = std::move(other.id);
         pid = std::move(other.pid);
         metaStableIndex = std::move(other.metaStableIndex);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/MetaStable/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class MetaStable

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
