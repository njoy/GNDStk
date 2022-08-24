
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_POPS_ALIASES
#define NJOY_GNDSTK_V2_0_POPS_ALIASES

// core interface
#include "GNDStk.hpp"

// v2.0 dependencies
#include "GNDStk/v2.0/pops/Alias.hpp"
#include "GNDStk/v2.0/pops/MetaStable.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// pops::
// class Aliases
// -----------------------------------------------------------------------------

namespace pops {

class Aliases : public Component<Aliases> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "pops"; }
   static auto className() { return "Aliases"; }
   static auto GNDSName() { return "aliases"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // children
         std::optional<pops::Alias>{}
            / ++Child<>("alias") |
         std::optional<pops::MetaStable>{}
            / ++Child<>("metaStable")
      ;
   }

public:

   using Component::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static inline const struct Defaults {
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // children
      std::optional<std::vector<pops::Alias>> alias;
      std::optional<std::vector<pops::MetaStable>> metaStable;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // alias
   const std::optional<std::vector<pops::Alias>> &alias() const
      { return content.alias; }
   std::optional<std::vector<pops::Alias>> &alias()
      { return content.alias; }

   // alias(index)
   const pops::Alias &alias(const std::size_t index) const
      { return getter(alias(), index, "alias"); }
   pops::Alias &alias(const std::size_t index)
      { return getter(alias(), index, "alias"); }

   // alias(label)
   const pops::Alias &alias(const std::string &label) const
      { return getter(alias(), label, "alias"); }
   pops::Alias &alias(const std::string &label)
      { return getter(alias(), label, "alias"); }

   // metaStable
   const std::optional<std::vector<pops::MetaStable>> &metaStable() const
      { return content.metaStable; }
   std::optional<std::vector<pops::MetaStable>> &metaStable()
      { return content.metaStable; }

   // metaStable(index)
   const pops::MetaStable &metaStable(const std::size_t index) const
      { return getter(metaStable(), index, "metaStable"); }
   pops::MetaStable &metaStable(const std::size_t index)
      { return getter(metaStable(), index, "metaStable"); }

   // metaStable(label)
   const pops::MetaStable &metaStable(const std::string &label) const
      { return getter(metaStable(), label, "metaStable"); }
   pops::MetaStable &metaStable(const std::string &label)
      { return getter(metaStable(), label, "metaStable"); }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // alias(value)
   Aliases &alias(const std::optional<std::vector<pops::Alias>> &obj)
      { alias() = obj; return *this; }

   // alias(index,value)
   Aliases &alias(
      const std::size_t index,
      const pops::Alias &obj
   ) {
      alias(index) = obj; return *this;
   }

   // alias(label,value)
   Aliases &alias(
      const std::string &label,
      const pops::Alias &obj
   ) {
      alias(label) = obj; return *this;
   }

   // metaStable(value)
   Aliases &metaStable(const std::optional<std::vector<pops::MetaStable>> &obj)
      { metaStable() = obj; return *this; }

   // metaStable(index,value)
   Aliases &metaStable(
      const std::size_t index,
      const pops::MetaStable &obj
   ) {
      metaStable(index) = obj; return *this;
   }

   // metaStable(label,value)
   Aliases &metaStable(
      const std::string &label,
      const pops::MetaStable &obj
   ) {
      metaStable(label) = obj; return *this;
   }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Aliases() :
      Component{
         BodyText{},
         content.alias,
         content.metaStable
      }
   {
      Component::finish();
   }

   // copy
   Aliases(const Aliases &other) :
      Component{
         other,
         content.alias,
         content.metaStable
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Aliases(Aliases &&other) :
      Component{
         other,
         content.alias,
         content.metaStable
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Aliases(const Node &node) :
      Component{
         BodyText{},
         content.alias,
         content.metaStable
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Aliases(
      const std::optional<std::vector<pops::Alias>> &alias,
      const std::optional<std::vector<pops::MetaStable>> &metaStable
   ) :
      Component{
         BodyText{},
         content.alias,
         content.metaStable
      },
      content{
         alias,
         metaStable
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Aliases &operator=(const Aliases &) = default;

   // move
   Aliases &operator=(Aliases &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/pops/Aliases/src/custom.hpp"

}; // class Aliases

} // namespace pops
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif