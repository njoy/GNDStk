
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_ALIAS
#define ALPHA_V2_0_GENERAL_ALIAS

#include "alpha/v2.0/key.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Alias
// -----------------------------------------------------------------------------

class Alias :
   public Component<general::Alias>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
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

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "id",
         "pid"
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

   // metadata
   Field<std::optional<std::string>>
      id{this};
   Field<std::optional<std::string>>
      pid{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->id, \
      this->pid \
   )

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

   #include "alpha/v2.0/general/Alias/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Alias

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
