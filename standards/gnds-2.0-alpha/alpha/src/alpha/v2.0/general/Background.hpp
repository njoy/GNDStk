
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_BACKGROUND
#define ALPHA_V2_0_GENERAL_BACKGROUND

#include "alpha/v2.0/general/ResolvedRegion.hpp"
#include "alpha/v2.0/general/FastRegion.hpp"
#include "alpha/v2.0/general/UnresolvedRegion.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Background
// -----------------------------------------------------------------------------

class Background :
   public Component<general::Background>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Background"; }
   static auto NODENAME() { return "background"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<std::optional<general::ResolvedRegion>>
            ("resolvedRegion") |
         --Child<general::FastRegion>
            ("fastRegion") |
         --Child<std::optional<general::UnresolvedRegion>>
            ("unresolvedRegion")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "resolvedRegion",
         "fastRegion",
         "unresolvedRegion"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "resolved_region",
         "fast_region",
         "unresolved_region"
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
   Field<std::optional<general::ResolvedRegion>>
      resolvedRegion{this};
   Field<general::FastRegion>
      fastRegion{this};
   Field<std::optional<general::UnresolvedRegion>>
      unresolvedRegion{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->resolvedRegion, \
      this->fastRegion, \
      this->unresolvedRegion \
   )

   // default
   Background() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Background(
      const wrapper<std::optional<general::ResolvedRegion>>
         &resolvedRegion,
      const wrapper<general::FastRegion>
         &fastRegion = {},
      const wrapper<std::optional<general::UnresolvedRegion>>
         &unresolvedRegion = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      resolvedRegion(this,resolvedRegion),
      fastRegion(this,fastRegion),
      unresolvedRegion(this,unresolvedRegion)
   {
      Component::finish();
   }

   // from node
   explicit Background(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Background(const Background &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      resolvedRegion(this,other.resolvedRegion),
      fastRegion(this,other.fastRegion),
      unresolvedRegion(this,other.unresolvedRegion)
   {
      Component::finish(other);
   }

   // move
   Background(Background &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      resolvedRegion(this,std::move(other.resolvedRegion)),
      fastRegion(this,std::move(other.fastRegion)),
      unresolvedRegion(this,std::move(other.unresolvedRegion))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Background &operator=(const Background &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         resolvedRegion = other.resolvedRegion;
         fastRegion = other.fastRegion;
         unresolvedRegion = other.unresolvedRegion;
      }
      return *this;
   }

   // move
   Background &operator=(Background &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         resolvedRegion = std::move(other.resolvedRegion);
         fastRegion = std::move(other.fastRegion);
         unresolvedRegion = std::move(other.unresolvedRegion);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/Background/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Background

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
