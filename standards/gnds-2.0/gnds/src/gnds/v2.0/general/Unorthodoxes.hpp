
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_UNORTHODOXES
#define GNDS_V2_0_GENERAL_UNORTHODOXES

#include "gnds/v2.0/general/Unorthodox.hpp"

namespace gnds {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Unorthodoxes
// -----------------------------------------------------------------------------

class Unorthodoxes :
   public Component<general::Unorthodoxes>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Unorthodoxes"; }
   static auto NODENAME() { return "unorthodoxes"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<general::Unorthodox>
            ("unorthodox")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "unorthodox"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "unorthodox"
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
   Field<std::vector<general::Unorthodox>>
      unorthodox{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->unorthodox \
   )

   // default
   Unorthodoxes() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Unorthodoxes(
      const wrapper<std::vector<general::Unorthodox>>
         &unorthodox
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      unorthodox(this,unorthodox)
   {
      Component::finish();
   }

   // from node
   explicit Unorthodoxes(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Unorthodoxes(const Unorthodoxes &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      unorthodox(this,other.unorthodox)
   {
      Component::finish(other);
   }

   // move
   Unorthodoxes(Unorthodoxes &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      unorthodox(this,std::move(other.unorthodox))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Unorthodoxes &operator=(const Unorthodoxes &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         unorthodox = other.unorthodox;
      }
      return *this;
   }

   // move
   Unorthodoxes &operator=(Unorthodoxes &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         unorthodox = std::move(other.unorthodox);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "gnds/v2.0/general/Unorthodoxes/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class Unorthodoxes

} // namespace general
} // namespace v2_0
} // namespace gnds

#endif
