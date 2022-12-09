
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_DOCUMENTATION_CODEREPO
#define TEST_V2_0_DOCUMENTATION_CODEREPO

#include "test/v2.0/key.hpp"

namespace test {
namespace v2_0 {
namespace documentation {

// -----------------------------------------------------------------------------
// documentation::
// class CodeRepo
// -----------------------------------------------------------------------------

class CodeRepo : public Component<documentation::CodeRepo> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "documentation"; }
   static auto CLASS() { return "CodeRepo"; }
   static auto FIELD() { return "codeRepo"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::optional<XMLName>{}
            / Meta<>("label") |
         XMLName{}
            / Meta<>("revisionSystem") |
         XMLName{}
            / Meta<>("href") |
         XMLName{}
            / Meta<>("revisionID")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::optional<XMLName>> label{this};
   Field<XMLName> revisionSystem{this};
   Field<XMLName> href{this};
   Field<XMLName> revisionID{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->revisionSystem, \
      this->href, \
      this->revisionID)

   // default
   CodeRepo() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields
   explicit CodeRepo(
      const wrapper<std::optional<XMLName>> &label,
      const wrapper<XMLName> &revisionSystem = {},
      const wrapper<XMLName> &href = {},
      const wrapper<XMLName> &revisionID = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      revisionSystem(this,revisionSystem),
      href(this,href),
      revisionID(this,revisionID)
   {
      Component::finish();
   }

   // from node
   explicit CodeRepo(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   CodeRepo(const CodeRepo &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      label(this,other.label),
      revisionSystem(this,other.revisionSystem),
      href(this,other.href),
      revisionID(this,other.revisionID)
   {
      Component::finish(other);
   }

   // move
   CodeRepo(CodeRepo &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      label(this,std::move(other.label)),
      revisionSystem(this,std::move(other.revisionSystem)),
      href(this,std::move(other.href)),
      revisionID(this,std::move(other.revisionID))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   CodeRepo &operator=(const CodeRepo &) = default;
   CodeRepo &operator=(CodeRepo &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/documentation/CodeRepo/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class CodeRepo

} // namespace documentation
} // namespace v2_0
} // namespace test

#endif
