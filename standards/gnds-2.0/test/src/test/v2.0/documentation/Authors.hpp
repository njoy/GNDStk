
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_DOCUMENTATION_AUTHORS
#define TEST_V2_0_DOCUMENTATION_AUTHORS

#include "test/v2.0/documentation/Author.hpp"

namespace test {
namespace v2_0 {
namespace documentation {

// -----------------------------------------------------------------------------
// documentation::
// class Authors
// -----------------------------------------------------------------------------

class Authors : public Component<documentation::Authors> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "documentation"; }
   static auto CLASS() { return "Authors"; }
   static auto FIELD() { return "authors"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         documentation::Author{}
            / ++Child<>("author")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::vector<documentation::Author>> author{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->author)

   // default, and from fields
   explicit Authors(
      const wrapper<std::vector<documentation::Author>> &author = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      author(this,author)
   {
      Component::finish();
   }

   // from node
   explicit Authors(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Authors(const Authors &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Authors(Authors &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Authors &operator=(const Authors &) = default;
   Authors &operator=(Authors &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/documentation/Authors/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Authors

} // namespace documentation
} // namespace v2_0
} // namespace test

#endif
