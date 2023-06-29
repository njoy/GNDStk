
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_POPS_ALIAS
#define TEST_V2_0_POPS_ALIAS

#include "test/v2.0/key.hpp"

namespace test {
namespace v2_0 {
namespace pops {

// -----------------------------------------------------------------------------
// pops::
// class Alias
// -----------------------------------------------------------------------------

class Alias :
   public Component<pops::Alias>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "pops"; }
   static auto CLASS() { return "Alias"; }
   static auto NODENAME() { return "alias"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         XMLName{}
            / Meta<>("id") |
         XMLName{}
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

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
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
   Field<XMLName>
      id{this};
   Field<XMLName>
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
      const wrapper<XMLName>
         &id,
      const wrapper<XMLName>
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

   #include "test/v2.0/pops/Alias/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Alias

} // namespace pops
} // namespace v2_0
} // namespace test

#endif
