
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_DOCUMENTATION_CONTRIBUTOR
#define TEST_V2_0_DOCUMENTATION_CONTRIBUTOR

#include "test/v2.0/documentation/Affiliations.hpp"
#include "test/v2.0/documentation/Note.hpp"

namespace test {
namespace v2_0 {
namespace documentation {

// -----------------------------------------------------------------------------
// documentation::
// class Contributor
// -----------------------------------------------------------------------------

class Contributor : public Component<documentation::Contributor> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "documentation"; }
   static auto CLASS() { return "Contributor"; }
   static auto FIELD() { return "contributor"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         UTF8Text{}
            / Meta<>("name") |
         enums::ContributorType{}
            / Meta<>("contributorType") |
         std::optional<UTF8Text>{}
            / Meta<>("orcid") |
         std::optional<UTF8Text>{}
            / Meta<>("email") |
         // children
         std::optional<documentation::Affiliations>{}
            / --Child<>("affiliations") |
         std::optional<documentation::Note>{}
            / --Child<>("note")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<UTF8Text> name{this};
   Field<enums::ContributorType> contributorType{this};
   Field<std::optional<UTF8Text>> orcid{this};
   Field<std::optional<UTF8Text>> email{this};

   // children
   Field<std::optional<documentation::Affiliations>> affiliations{this};
   Field<std::optional<documentation::Note>> note{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->name, \
      this->contributorType, \
      this->orcid, \
      this->email, \
      this->affiliations, \
      this->note)

   // default, and from fields
   explicit Contributor(
      const wrapper<UTF8Text> &name = {},
      const wrapper<enums::ContributorType> &contributorType = {},
      const wrapper<std::optional<UTF8Text>> &orcid = {},
      const wrapper<std::optional<UTF8Text>> &email = {},
      const wrapper<std::optional<documentation::Affiliations>> &affiliations = {},
      const wrapper<std::optional<documentation::Note>> &note = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      name(this,name),
      contributorType(this,contributorType),
      orcid(this,orcid),
      email(this,email),
      affiliations(this,affiliations),
      note(this,note)
   {
      Component::finish();
   }

   // from node
   explicit Contributor(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Contributor(const Contributor &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Contributor(Contributor &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Contributor &operator=(const Contributor &) = default;
   Contributor &operator=(Contributor &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/documentation/Contributor/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Contributor

} // namespace documentation
} // namespace v2_0
} // namespace test

#endif