
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_FISSIONTRANSPORT_B
#define TEST_V2_0_FISSIONTRANSPORT_B

#include "test/v2.0/key.hpp"

namespace test {
namespace v2_0 {
namespace fissionTransport {

// -----------------------------------------------------------------------------
// fissionTransport::
// class B
// -----------------------------------------------------------------------------

class B : public Component<fissionTransport::B> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "fissionTransport"; }
   static auto CLASS() { return "B"; }
   static auto FIELD() { return "b"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return std::tuple<>{};
   }

public:
   using Component::construct;

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata)

   // default
   B() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from node
   explicit B(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   B(const B &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   B(B &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   B &operator=(const B &) = default;
   B &operator=(B &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/fissionTransport/B/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class B

} // namespace fissionTransport
} // namespace v2_0
} // namespace test

#endif
