
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_DOCUMENTATION_AUTHOR
#define NJOY_GNDSTK_V2_0_DOCUMENTATION_AUTHOR

// core interface
#include "GNDStk.hpp"

// v2.0 dependencies
#include "GNDStk/v2.0/documentation/Affiliations.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// documentation::
// class Author
// -----------------------------------------------------------------------------

namespace documentation {

class Author : public Component<Author> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "documentation"; }
   static auto className() { return "Author"; }
   static auto GNDSName() { return "author"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         std::optional<UTF8Text>{}
            / Meta<>("email") |
         UTF8Text{}
            / Meta<>("name") |
         std::optional<UTF8Text>{}
            / Meta<>("orcid_id") |
         // children
         std::optional<documentation::Affiliations>{}
            / --Child<>("affiliations")
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
      std::optional<UTF8Text> email;
      UTF8Text name;
      std::optional<UTF8Text> orcid_id;
      // children
      std::optional<documentation::Affiliations> affiliations;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // email
   const std::optional<UTF8Text> &email() const
      { return content.email; }
   std::optional<UTF8Text> &email()
      { return content.email; }

   // name
   const UTF8Text &name() const
      { return content.name; }
   UTF8Text &name()
      { return content.name; }

   // orcid_id
   const std::optional<UTF8Text> &orcid_id() const
      { return content.orcid_id; }
   std::optional<UTF8Text> &orcid_id()
      { return content.orcid_id; }

   // affiliations
   const std::optional<documentation::Affiliations> &affiliations() const
      { return content.affiliations; }
   std::optional<documentation::Affiliations> &affiliations()
      { return content.affiliations; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // email(value)
   Author &email(const std::optional<UTF8Text> &obj)
      { email() = obj; return *this; }

   // name(value)
   Author &name(const UTF8Text &obj)
      { name() = obj; return *this; }

   // orcid_id(value)
   Author &orcid_id(const std::optional<UTF8Text> &obj)
      { orcid_id() = obj; return *this; }

   // affiliations(value)
   Author &affiliations(const std::optional<documentation::Affiliations> &obj)
      { affiliations() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Author() :
      Component{
         BodyText{},
         content.email,
         content.name,
         content.orcid_id,
         content.affiliations
      }
   {
      Component::finish();
   }

   // copy
   Author(const Author &other) :
      Component{
         other,
         content.email,
         content.name,
         content.orcid_id,
         content.affiliations
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Author(Author &&other) :
      Component{
         other,
         content.email,
         content.name,
         content.orcid_id,
         content.affiliations
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Author(const Node &node) :
      Component{
         BodyText{},
         content.email,
         content.name,
         content.orcid_id,
         content.affiliations
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Author(
      const std::optional<UTF8Text> &email,
      const UTF8Text &name,
      const std::optional<UTF8Text> &orcid_id,
      const std::optional<documentation::Affiliations> &affiliations
   ) :
      Component{
         BodyText{},
         content.email,
         content.name,
         content.orcid_id,
         content.affiliations
      },
      content{
         email,
         name,
         orcid_id,
         affiliations
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Author &operator=(const Author &) = default;

   // move
   Author &operator=(Author &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/documentation/Author/src/custom.hpp"

}; // class Author

} // namespace documentation
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif