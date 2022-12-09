
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_POPS_STANDARD
#define TEST_V2_0_POPS_STANDARD

#include "test/v2.0/extra/Double.hpp"

namespace test {
namespace v2_0 {
namespace pops {

// -----------------------------------------------------------------------------
// pops::
// class Standard
// -----------------------------------------------------------------------------

class Standard : public Component<pops::Standard> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "pops"; }
   static auto CLASS() { return "Standard"; }
   static auto FIELD() { return "standard"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         extra::Double{}
            / --Child<>("Double")
      ;
   }

public:
   using Component::construct;

   // children
   Field<extra::Double> Double{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->Double)

   // default, and from fields
   explicit Standard(
      const wrapper<extra::Double> &Double = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      Double(this,Double)
   {
      Component::finish();
   }

   // from node
   explicit Standard(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Standard(const Standard &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Standard(Standard &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Standard &operator=(const Standard &) = default;
   Standard &operator=(Standard &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/pops/Standard/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Standard

} // namespace pops
} // namespace v2_0
} // namespace test

#endif
