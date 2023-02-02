
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_COMMON_ALIAS
#define ALPHA_V2_0_COMMON_ALIAS

#include "alpha/v2.0/key.hpp"

namespace alpha {
namespace v2_0 {
namespace common {

// -----------------------------------------------------------------------------
// common::
// class Alias
// -----------------------------------------------------------------------------

class Alias :
   public Component<common::Alias>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "common"; }
   static auto CLASS() { return "Alias"; }
   static auto FIELD() { return "alias"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::optional<std::string>{}
            / Meta<>("id") |
         std::optional<std::string>{}
            / Meta<>("pid")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::optional<std::string>> id{this};
   Field<std::optional<std::string>> pid{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->id, \
      this->pid)

   // default
   Alias() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Alias(
      const wrapper<std::optional<std::string>>
         &id,
      const wrapper<std::optional<std::string>>
         &pid = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      id(this,id),
      pid(this,pid)
   {
      Component::finish();
   }

   // from node
   explicit Alias(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Alias(const Alias &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      id(this,other.id),
      pid(this,other.pid)
   {
      Component::finish(other);
   }

   // move
   Alias(Alias &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      id(this,std::move(other.id)),
      pid(this,std::move(other.pid))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Alias &operator=(const Alias &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         id = other.id;
         pid = other.pid;
      }
      return *this;
   }

   // move
   Alias &operator=(Alias &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         id = std::move(other.id);
         pid = std::move(other.pid);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/common/Alias/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Alias

} // namespace common
} // namespace v2_0
} // namespace alpha

#endif
