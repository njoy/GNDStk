
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_TRANSPORT_ADD
#define TEST_V2_0_TRANSPORT_ADD

#include "test/v2.0/key.hpp"

namespace test {
namespace v2_0 {
namespace transport {

// -----------------------------------------------------------------------------
// transport::
// class Add
// -----------------------------------------------------------------------------

class Add : public Component<transport::Add> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "transport"; }
   static auto CLASS() { return "Add"; }
   static auto FIELD() { return "add"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::optional<std::string>{}
            / Meta<>("href")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::optional<std::string>> href{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->href)

   // default
   Add() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields
   explicit Add(
      const wrapper<std::optional<std::string>> &href
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      href(this,href)
   {
      Component::finish();
   }

   // from node
   explicit Add(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Add(const Add &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      href(this,other.href)
   {
      Component::finish(other);
   }

   // move
   Add(Add &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      href(this,std::move(other.href))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Add &operator=(const Add &) = default;
   Add &operator=(Add &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/transport/Add/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Add

} // namespace transport
} // namespace v2_0
} // namespace test

#endif
