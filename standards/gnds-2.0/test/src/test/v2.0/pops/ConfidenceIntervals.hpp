
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_POPS_CONFIDENCEINTERVALS
#define TEST_V2_0_POPS_CONFIDENCEINTERVALS

#include "test/v2.0/pops/Interval.hpp"

namespace test {
namespace v2_0 {
namespace pops {

// -----------------------------------------------------------------------------
// pops::
// class ConfidenceIntervals
// -----------------------------------------------------------------------------

class ConfidenceIntervals : public Component<pops::ConfidenceIntervals> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "pops"; }
   static auto CLASS() { return "ConfidenceIntervals"; }
   static auto FIELD() { return "confidenceIntervals"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         pops::Interval{}
            / ++Child<>("interval")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::vector<pops::Interval>> interval{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->interval)

   // default, and from fields
   explicit ConfidenceIntervals(
      const wrapper<std::vector<pops::Interval>> &interval = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      interval(this,interval)
   {
      Component::finish();
   }

   // from node
   explicit ConfidenceIntervals(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ConfidenceIntervals(const ConfidenceIntervals &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   ConfidenceIntervals(ConfidenceIntervals &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   ConfidenceIntervals &operator=(const ConfidenceIntervals &) = default;
   ConfidenceIntervals &operator=(ConfidenceIntervals &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/pops/ConfidenceIntervals/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ConfidenceIntervals

} // namespace pops
} // namespace v2_0
} // namespace test

#endif
