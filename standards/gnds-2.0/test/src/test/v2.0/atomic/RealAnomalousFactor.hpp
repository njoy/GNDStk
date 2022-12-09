
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_ATOMIC_REALANOMALOUSFACTOR
#define TEST_V2_0_ATOMIC_REALANOMALOUSFACTOR

#include "test/v2.0/containers/XYs1d.hpp"
#include "test/v2.0/containers/Regions1d.hpp"

namespace test {
namespace v2_0 {
namespace atomic {

// -----------------------------------------------------------------------------
// atomic::
// class RealAnomalousFactor
// -----------------------------------------------------------------------------

class RealAnomalousFactor : public Component<atomic::RealAnomalousFactor> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "atomic"; }
   static auto CLASS() { return "RealAnomalousFactor"; }
   static auto FIELD() { return "realAnomalousFactor"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         std::optional<containers::XYs1d>{}
            / --Child<>("XYs1d") |
         std::optional<containers::Regions1d>{}
            / --Child<>("regions1d")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::optional<containers::XYs1d>> XYs1d{this};
   Field<std::optional<containers::Regions1d>> regions1d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->XYs1d, \
      this->regions1d)

   // default, and from fields
   explicit RealAnomalousFactor(
      const wrapper<std::optional<containers::XYs1d>> &XYs1d = {},
      const wrapper<std::optional<containers::Regions1d>> &regions1d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      XYs1d(this,XYs1d),
      regions1d(this,regions1d)
   {
      Component::finish();
   }

   // from node
   explicit RealAnomalousFactor(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   RealAnomalousFactor(const RealAnomalousFactor &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   RealAnomalousFactor(RealAnomalousFactor &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   RealAnomalousFactor &operator=(const RealAnomalousFactor &) = default;
   RealAnomalousFactor &operator=(RealAnomalousFactor &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/atomic/RealAnomalousFactor/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class RealAnomalousFactor

} // namespace atomic
} // namespace v2_0
} // namespace test

#endif
