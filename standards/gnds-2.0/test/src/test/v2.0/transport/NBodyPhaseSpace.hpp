
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_TRANSPORT_NBODYPHASESPACE
#define TEST_V2_0_TRANSPORT_NBODYPHASESPACE

#include "test/v2.0/tsl/Mass.hpp"

namespace test {
namespace v2_0 {
namespace transport {

// -----------------------------------------------------------------------------
// transport::
// class NBodyPhaseSpace
// -----------------------------------------------------------------------------

class NBodyPhaseSpace : public Component<transport::NBodyPhaseSpace> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "transport"; }
   static auto CLASS() { return "NBodyPhaseSpace"; }
   static auto FIELD() { return "NBodyPhaseSpace"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::optional<Integer32>{}
            / Meta<>("numberOfProducts") |
         // children
         std::optional<tsl::Mass>{}
            / --Child<>("mass")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::optional<Integer32>> numberOfProducts{this};

   // children
   Field<std::optional<tsl::Mass>> mass{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->numberOfProducts, \
      this->mass)

   // default, and from fields
   explicit NBodyPhaseSpace(
      const wrapper<std::optional<Integer32>> &numberOfProducts = {},
      const wrapper<std::optional<tsl::Mass>> &mass = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      numberOfProducts(this,numberOfProducts),
      mass(this,mass)
   {
      Component::finish();
   }

   // from node
   explicit NBodyPhaseSpace(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   NBodyPhaseSpace(const NBodyPhaseSpace &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   NBodyPhaseSpace(NBodyPhaseSpace &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   NBodyPhaseSpace &operator=(const NBodyPhaseSpace &) = default;
   NBodyPhaseSpace &operator=(NBodyPhaseSpace &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/transport/NBodyPhaseSpace/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class NBodyPhaseSpace

} // namespace transport
} // namespace v2_0
} // namespace test

#endif
