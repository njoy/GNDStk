
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_DOCUMENTATION_COLLABORATION
#define TEST_V2_0_DOCUMENTATION_COLLABORATION

#include "test/v2.0/key.hpp"

namespace test {
namespace v2_0 {
namespace documentation {

// -----------------------------------------------------------------------------
// documentation::
// class Collaboration
// -----------------------------------------------------------------------------

class Collaboration : public Component<documentation::Collaboration> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "documentation"; }
   static auto CLASS() { return "Collaboration"; }
   static auto FIELD() { return "collaboration"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         UTF8Text{}
            / Meta<>("name") |
         std::optional<UTF8Text>{}
            / Meta<>("href")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<UTF8Text> name{this};
   Field<std::optional<UTF8Text>> href{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->name, \
      this->href)

   // default, and from fields
   explicit Collaboration(
      const wrapper<UTF8Text> &name = {},
      const wrapper<std::optional<UTF8Text>> &href = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      name(this,name),
      href(this,href)
   {
      Component::finish();
   }

   // from node
   explicit Collaboration(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Collaboration(const Collaboration &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Collaboration(Collaboration &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Collaboration &operator=(const Collaboration &) = default;
   Collaboration &operator=(Collaboration &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/documentation/Collaboration/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Collaboration

} // namespace documentation
} // namespace v2_0
} // namespace test

#endif
