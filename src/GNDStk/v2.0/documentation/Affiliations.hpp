
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_DOCUMENTATION_AFFILIATIONS
#define NJOY_GNDSTK_V2_0_DOCUMENTATION_AFFILIATIONS

// core interface
#include "GNDStk.hpp"

// v2.0 dependencies
#include "GNDStk/v2.0/documentation/Affiliation.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// documentation::
// class Affiliations
// -----------------------------------------------------------------------------

namespace documentation {

class Affiliations : public Component<Affiliations> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "documentation"; }
   static auto className() { return "Affiliations"; }
   static auto GNDSName() { return "affiliations"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // children
         documentation::Affiliation{}
            / ++Child<>("affiliation")
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
      std::vector<documentation::Affiliation> affiliation;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // affiliation
   const std::vector<documentation::Affiliation> &affiliation() const
      { return content.affiliation; }
   std::vector<documentation::Affiliation> &affiliation()
      { return content.affiliation; }

   // affiliation(index)
   const documentation::Affiliation &affiliation(const std::size_t index) const
      { return getter(affiliation(), index, "affiliation"); }
   documentation::Affiliation &affiliation(const std::size_t index)
      { return getter(affiliation(), index, "affiliation"); }

   // affiliation(label)
   const documentation::Affiliation &affiliation(const std::string &label) const
      { return getter(affiliation(), label, "affiliation"); }
   documentation::Affiliation &affiliation(const std::string &label)
      { return getter(affiliation(), label, "affiliation"); }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // affiliation(value)
   Affiliations &affiliation(const std::vector<documentation::Affiliation> &obj)
      { affiliation() = obj; return *this; }

   // affiliation(index,value)
   Affiliations &affiliation(
      const std::size_t index,
      const documentation::Affiliation &obj
   ) {
      affiliation(index) = obj; return *this;
   }

   // affiliation(label,value)
   Affiliations &affiliation(
      const std::string &label,
      const documentation::Affiliation &obj
   ) {
      affiliation(label) = obj; return *this;
   }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Affiliations() :
      Component{
         BodyText{},
         content.affiliation
      }
   {
      Component::finish();
   }

   // copy
   Affiliations(const Affiliations &other) :
      Component{
         other,
         content.affiliation
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Affiliations(Affiliations &&other) :
      Component{
         other,
         content.affiliation
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Affiliations(const Node &node) :
      Component{
         BodyText{},
         content.affiliation
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Affiliations(
      const std::vector<documentation::Affiliation> &affiliation
   ) :
      Component{
         BodyText{},
         content.affiliation
      },
      content{
         affiliation
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Affiliations &operator=(const Affiliations &) = default;

   // move
   Affiliations &operator=(Affiliations &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/documentation/Affiliations/src/custom.hpp"

}; // class Affiliations

} // namespace documentation
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif
