
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_LS
#define GNDS_V2_0_GENERAL_LS

#include "gnds/v2.0/general/L.hpp"

namespace gnds {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Ls
// -----------------------------------------------------------------------------

class Ls :
   public Component<general::Ls>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Ls"; }
   static auto NODENAME() { return "Ls"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<general::L>
            ("L")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "L"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "l"
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
   Field<std::vector<general::L>>
      L{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->L \
   )

   // default
   Ls() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Ls(
      const wrapper<std::vector<general::L>>
         &L
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      L(this,L)
   {
      Component::finish();
   }

   // from node
   explicit Ls(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Ls(const Ls &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      L(this,other.L)
   {
      Component::finish(other);
   }

   // move
   Ls(Ls &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      L(this,std::move(other.L))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Ls &operator=(const Ls &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         L = other.L;
      }
      return *this;
   }

   // move
   Ls &operator=(Ls &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         L = std::move(other.L);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "gnds/v2.0/general/Ls/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Ls

} // namespace general
} // namespace v2_0
} // namespace gnds

#endif
