
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
   // for Component
   // ------------------------

   friend class Component<Link>;

   static auto className() { return "Link"; }
   static auto GNDSField() { return "link"; }

   static auto keys()
   {
      return
         // metadata
         std::optional<bodyText>{}
            / Meta<>("href")
      ;
   }

public:

   // ------------------------
   // relevant defaults
   // FYI for users
   // ------------------------

   static const struct {
   } defaults;

   // ------------------------
   // raw GNDS content
   // ------------------------

   struct {
      // metadata
      std::optional<bodyText> href;
   } content;

   // ------------------------
   // getters
   // const and non-const
   // ------------------------

   // href
   const auto &href() const
    { return content.href; }
   auto &href()
    { return content.href; }

   // ------------------------
   // setters
   // non-const only
   // ------------------------

   // href
   auto &href(const std::optional<bodyText> &obj)
    { content.href = obj; return *this; }

   // ------------------------
   // construction
   // ------------------------

   // default
   Link() :
      Component{
         content.href
      }
   {
      construct();
   }

   // copy
   Link(const Link &other) :
      Component{
         content.href
      },
      content{other.content}
   {
      construct();
   }

   // move
   Link(Link &&other) :
      Component{
         content.href
      },
      content{std::move(other.content)}
   {
      construct();
   }

   // from node
   Link(const Node &node) :
      Component{
         content.href
      }
   {
      query(node);
      construct();
   }

   // from fields
   explicit Link(
      const std::optional<bodyText> &href
   ) :
      Component{
         content.href
      },
      content{
         href
      }
   {
      construct();
   }

   // ------------------------
   // assignment
   // ------------------------

   // copy
   Link &operator=(const Link &) = default;

   // move
   Link &operator=(Link &&) = default;

   // ------------------------
   // custom functionality
   // ------------------------

   #include "GNDStk/v1.9/containers/Link/src/custom.hpp"

}; // class Link

} // namespace containers

} // namespace v1_9
} // namespace GNDStk
} // namespace njoy

#endif
