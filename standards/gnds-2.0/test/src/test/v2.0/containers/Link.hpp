
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_CONTAINERS_LINK
#define TEST_V2_0_CONTAINERS_LINK

#include "test/v2.0/key.hpp"

namespace test {
namespace v2_0 {
namespace containers {

// -----------------------------------------------------------------------------
// containers::
// class Link
// -----------------------------------------------------------------------------

class Link : public Component<containers::Link> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "containers"; }
   static auto CLASS() { return "Link"; }
   static auto FIELD() { return "link"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::string{}
            / Meta<>("href")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::string> href{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->href)

   // default
   Link() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields
   explicit Link(
      const wrapper<std::string> &href
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      href(this,href)
   {
      Component::finish();
   }

   // from node
   explicit Link(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Link(const Link &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      href(this,other.href)
   {
      Component::finish(other);
   }

   // move
   Link(Link &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      href(this,std::move(other.href))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Link &operator=(const Link &) = default;
   Link &operator=(Link &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/containers/Link/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Link

} // namespace containers
} // namespace v2_0
} // namespace test

#endif
