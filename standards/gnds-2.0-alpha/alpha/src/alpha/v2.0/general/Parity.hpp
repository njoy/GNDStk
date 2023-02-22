
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_PARITY
#define ALPHA_V2_0_GENERAL_PARITY

#include "alpha/v2.0/general/Integer.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Parity
// -----------------------------------------------------------------------------

class Parity :
   public Component<general::Parity>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Parity"; }
   static auto NODENAME() { return "parity"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<general::Integer>
            ("integer")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "integer"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "integer"
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
   Field<general::Integer>
      integer{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->integer \
   )

   // default
   Parity() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Parity(
      const wrapper<general::Integer>
         &integer
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      integer(this,integer)
   {
      Component::finish();
   }

   // from node
   explicit Parity(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Parity(const Parity &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      integer(this,other.integer)
   {
      Component::finish(other);
   }

   // move
   Parity(Parity &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      integer(this,std::move(other.integer))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Parity &operator=(const Parity &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         integer = other.integer;
      }
      return *this;
   }

   // move
   Parity &operator=(Parity &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         integer = std::move(other.integer);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/Parity/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Parity

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif