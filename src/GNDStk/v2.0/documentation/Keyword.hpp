
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_DOCUMENTATION_KEYWORD
#define NJOY_GNDSTK_V2_0_DOCUMENTATION_KEYWORD

// core interface
#include "GNDStk.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// documentation::
// class Keyword
// -----------------------------------------------------------------------------

namespace documentation {

class Keyword : public Component<Keyword> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "documentation"; }
   static auto className() { return "Keyword"; }
   static auto GNDSName() { return "keyword"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("type")
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
      XMLName type;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // type
   const XMLName &type() const
      { return content.type; }
   XMLName &type()
      { return content.type; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // type(value)
   Keyword &type(const XMLName &obj)
      { type() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Keyword() :
      Component{
         BodyText{},
         content.type
      }
   {
      Component::finish();
   }

   // copy
   Keyword(const Keyword &other) :
      Component{
         other,
         content.type
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Keyword(Keyword &&other) :
      Component{
         other,
         content.type
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Keyword(const Node &node) :
      Component{
         BodyText{},
         content.type
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Keyword(
      const XMLName &type
   ) :
      Component{
         BodyText{},
         content.type
      },
      content{
         type
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Keyword &operator=(const Keyword &) = default;

   // move
   Keyword &operator=(Keyword &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/documentation/Keyword/src/custom.hpp"

}; // class Keyword

} // namespace documentation
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif
