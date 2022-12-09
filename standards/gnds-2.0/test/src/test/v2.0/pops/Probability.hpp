
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_POPS_PROBABILITY
#define TEST_V2_0_POPS_PROBABILITY

#include "test/v2.0/containers/Double.hpp"

namespace test {
namespace v2_0 {
namespace pops {

// -----------------------------------------------------------------------------
// pops::
// class Probability
// -----------------------------------------------------------------------------

class Probability : public Component<pops::Probability> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "pops"; }
   static auto CLASS() { return "Probability"; }
   static auto FIELD() { return "probability"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         containers::Double{}
            / ++Child<>("Double")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::vector<containers::Double>> Double{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->Double)

   // default, and from fields
   explicit Probability(
      const wrapper<std::vector<containers::Double>> &Double = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      Double(this,Double)
   {
      Component::finish();
   }

   // from node
   explicit Probability(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Probability(const Probability &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Probability(Probability &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Probability &operator=(const Probability &) = default;
   Probability &operator=(Probability &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/pops/Probability/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Probability

} // namespace pops
} // namespace v2_0
} // namespace test

#endif
