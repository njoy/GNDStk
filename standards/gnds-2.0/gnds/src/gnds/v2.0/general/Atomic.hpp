
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_ATOMIC
#define GNDS_V2_0_GENERAL_ATOMIC

#include "gnds/v2.0/general/Configurations.hpp"

namespace gnds {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Atomic
// -----------------------------------------------------------------------------

class Atomic :
   public Component<general::Atomic>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Atomic"; }
   static auto NODENAME() { return "atomic"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<general::Configurations>
            ("configurations")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "configurations"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "configurations"
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

   // children
   Field<general::Configurations>
      configurations{this};

   // shortcuts
   #define NJOY_GNDSTK_SHORTCUT(to,name) decltype(to.name) &name = to.name
   NJOY_GNDSTK_SHORTCUT(configurations(),configuration);
   #undef NJOY_GNDSTK_SHORTCUT

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->configurations \
   )

   // default
   Atomic() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Atomic(
      const wrapper<general::Configurations>
         &configurations
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      configurations(this,configurations)
   {
      Component::finish();
   }

   // from node
   explicit Atomic(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Atomic(const Atomic &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      configurations(this,other.configurations)
   {
      Component::finish(other);
   }

   // move
   Atomic(Atomic &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      configurations(this,std::move(other.configurations))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Atomic &operator=(const Atomic &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         configurations = other.configurations;
      }
      return *this;
   }

   // move
   Atomic &operator=(Atomic &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         configurations = std::move(other.configurations);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "gnds/v2.0/general/Atomic/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class Atomic

} // namespace general
} // namespace v2_0
} // namespace gnds

#endif
