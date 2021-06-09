
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V1_9_CONTAINERS_LINK
#define NJOY_GNDSTK_V1_9_CONTAINERS_LINK

// core interface
#include "GNDStk.hpp"

namespace njoy {
namespace GNDStk {
namespace v1_9 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// containers::
// class Link
// -----------------------------------------------------------------------------

namespace containers {

class Link : public Component<Link> {

   // ------------------------
   // For Component
   // ------------------------

   friend class Component<Link>;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "containers"; }
   static auto className() { return "Link"; }
   static auto GNDSName() { return "link"; }

   // Core Interface construct to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         std::optional<UTF8Text>{}
            / Meta<>("href")
      ;
   }

public:

   // Base classes
   using BaseComponent = Component<Link>;
   using BaseBodyText = BodyText<false>;
   using BaseComponent::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static const struct {
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      std::optional<UTF8Text> href;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // href
   const auto &href() const
    { return content.href; }
   auto &href()
    { return content.href; }

   // ------------------------
   // Setters
   // non-const
   // ------------------------

   // href
   auto &href(const std::optional<UTF8Text> &obj)
    { content.href = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Link() :
      Component{
         BaseBodyText{},
         content.href
      }
   {
      bodyTextUpdate(content);
      construct();
   }

   // copy
   Link(const Link &other) :
      Component{
         other,
         content.href
      },
      content{other.content}
   {
      bodyTextUpdate(content);
      construct(other);
   }

   // move
   Link(Link &&other) :
      Component{
         other,
         content.href
      },
      content{std::move(other.content)}
   {
      bodyTextUpdate(content);
      construct(other);
   }

   // from node
   Link(const Node &node) :
      Component{
         BaseBodyText{},
         content.href
      }
   {
      fromNode(node);
      bodyTextUpdate(content);
      construct(node);
   }

   // from fields
   explicit Link(
      const std::optional<UTF8Text> &href
   ) :
      Component{
         BaseBodyText{},
         content.href
      },
      content{
         href
      }
   {
      bodyTextUpdate(content);
      construct();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Link &operator=(const Link &) = default;

   // move
   Link &operator=(Link &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v1.9/containers/Link/src/custom.hpp"

}; // class Link

} // namespace containers

} // namespace v1_9
} // namespace GNDStk
} // namespace njoy

#endif
