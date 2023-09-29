
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_ALIASES
#define GNDS_V2_0_GENERAL_ALIASES

#include "GNDS/v2.0/general/Alias.hpp"
#include "GNDS/v2.0/general/MetaStable.hpp"

namespace GNDS {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Aliases
// -----------------------------------------------------------------------------

class Aliases :
   public Component<general::Aliases>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Aliases"; }
   static auto NODENAME() { return "aliases"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<std::optional<general::Alias>>
            ("alias") |
         ++Child<std::optional<general::MetaStable>>
            ("metaStable")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "alias",
         "metaStable"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "alias",
         "meta_stable"
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
   Field<std::optional<std::vector<general::Alias>>>
      alias{this};
   Field<std::optional<std::vector<general::MetaStable>>>
      metaStable{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->alias, \
      this->metaStable \
   )

   // default
   Aliases() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Aliases(
      const wrapper<std::optional<std::vector<general::Alias>>>
         &alias,
      const wrapper<std::optional<std::vector<general::MetaStable>>>
         &metaStable = {}
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      alias(this,alias),
      metaStable(this,metaStable)
   {
      Component::finish();
   }

   // from node
   explicit Aliases(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Aliases(const Aliases &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      alias(this,other.alias),
      metaStable(this,other.metaStable)
   {
      Component::finish(other);
   }

   // move
   Aliases(Aliases &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      alias(this,std::move(other.alias)),
      metaStable(this,std::move(other.metaStable))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Aliases &operator=(const Aliases &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         alias = other.alias;
         metaStable = other.metaStable;
      }
      return *this;
   }

   // move
   Aliases &operator=(Aliases &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         alias = std::move(other.alias);
         metaStable = std::move(other.metaStable);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDS/v2.0/general/Aliases/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class Aliases

} // namespace general
} // namespace v2_0
} // namespace GNDS

#endif
