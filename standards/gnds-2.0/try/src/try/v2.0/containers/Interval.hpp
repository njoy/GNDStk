
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_CONTAINERS_INTERVAL
#define TRY_V2_0_CONTAINERS_INTERVAL

#include "try/v2.0/key.hpp"

namespace try {
namespace v2_0 {
namespace containers {

// -----------------------------------------------------------------------------
// containers::
// class Interval
// -----------------------------------------------------------------------------

class Interval : public Component<containers::Interval> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "containers"; }
   static auto CLASS() { return "Interval"; }
   static auto FIELD() { return "interval"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         Float64{}
            / Meta<>("confidence") |
         Float64{}
            / Meta<>("lower") |
         Float64{}
            / Meta<>("upper")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<Float64> confidence{this};
   Field<Float64> lower{this};
   Field<Float64> upper{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->confidence, \
      this->lower, \
      this->upper)

   // default, and from fields
   explicit Interval(
      const wrapper<Float64> &confidence = {},
      const wrapper<Float64> &lower = {},
      const wrapper<Float64> &upper = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      confidence(this,confidence),
      lower(this,lower),
      upper(this,upper)
   {
      Component::finish();
   }

   // from node
   explicit Interval(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Interval(const Interval &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Interval(Interval &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Interval &operator=(const Interval &) = default;
   Interval &operator=(Interval &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/containers/Interval/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Interval

} // namespace containers
} // namespace v2_0
} // namespace try

#endif
