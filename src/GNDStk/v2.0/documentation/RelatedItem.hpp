
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_DOCUMENTATION_RELATEDITEM
#define NJOY_GNDSTK_V2_0_DOCUMENTATION_RELATEDITEM

// core interface
#include "GNDStk.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// documentation::
// class RelatedItem
// -----------------------------------------------------------------------------

namespace documentation {

class RelatedItem : public Component<RelatedItem> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "documentation"; }
   static auto className() { return "RelatedItem"; }
   static auto GNDSName() { return "relatedItem"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         std::optional<UTF8Text>{}
            / Meta<>("href") |
         UTF8Text{}
            / Meta<>("name") |
         std::optional<enums::RelationType>{}
            / Meta<>("relationType")
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
      // metadata
      std::optional<UTF8Text> href;
      UTF8Text name;
      std::optional<enums::RelationType> relationType;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // href
   const std::optional<UTF8Text> &href() const
      { return content.href; }
   std::optional<UTF8Text> &href()
      { return content.href; }

   // name
   const UTF8Text &name() const
      { return content.name; }
   UTF8Text &name()
      { return content.name; }

   // relationType
   const std::optional<enums::RelationType> &relationType() const
      { return content.relationType; }
   std::optional<enums::RelationType> &relationType()
      { return content.relationType; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // href(value)
   RelatedItem &href(const std::optional<UTF8Text> &obj)
      { href() = obj; return *this; }

   // name(value)
   RelatedItem &name(const UTF8Text &obj)
      { name() = obj; return *this; }

   // relationType(value)
   RelatedItem &relationType(const std::optional<enums::RelationType> &obj)
      { relationType() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   RelatedItem() :
      Component{
         BodyText{},
         content.href,
         content.name,
         content.relationType
      }
   {
      Component::finish();
   }

   // copy
   RelatedItem(const RelatedItem &other) :
      Component{
         other,
         content.href,
         content.name,
         content.relationType
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   RelatedItem(RelatedItem &&other) :
      Component{
         other,
         content.href,
         content.name,
         content.relationType
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   RelatedItem(const Node &node) :
      Component{
         BodyText{},
         content.href,
         content.name,
         content.relationType
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit RelatedItem(
      const std::optional<UTF8Text> &href,
      const UTF8Text &name,
      const std::optional<enums::RelationType> &relationType
   ) :
      Component{
         BodyText{},
         content.href,
         content.name,
         content.relationType
      },
      content{
         href,
         name,
         relationType
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   RelatedItem &operator=(const RelatedItem &) = default;

   // move
   RelatedItem &operator=(RelatedItem &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/documentation/RelatedItem/src/custom.hpp"

}; // class RelatedItem

} // namespace documentation
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif