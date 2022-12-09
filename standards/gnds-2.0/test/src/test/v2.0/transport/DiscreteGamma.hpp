
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_TRANSPORT_DISCRETEGAMMA
#define TEST_V2_0_TRANSPORT_DISCRETEGAMMA

#include "test/v2.0/containers/Axes.hpp"

namespace test {
namespace v2_0 {
namespace transport {

// -----------------------------------------------------------------------------
// transport::
// class DiscreteGamma
// -----------------------------------------------------------------------------

class DiscreteGamma : public Component<transport::DiscreteGamma> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "transport"; }
   static auto CLASS() { return "DiscreteGamma"; }
   static auto FIELD() { return "discreteGamma"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::optional<Float64>{}
            / Meta<>("domainMax") |
         std::optional<Float64>{}
            / Meta<>("domainMin") |
         std::optional<Float64>{}
            / Meta<>("value") |
         // children
         std::optional<containers::Axes>{}
            / --Child<>("axes")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::optional<Float64>> domainMax{this};
   Field<std::optional<Float64>> domainMin{this};
   Field<std::optional<Float64>> value{this};

   // children
   Field<std::optional<containers::Axes>> axes{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->domainMax, \
      this->domainMin, \
      this->value, \
      this->axes)

   // default, and from fields
   explicit DiscreteGamma(
      const wrapper<std::optional<Float64>> &domainMax = {},
      const wrapper<std::optional<Float64>> &domainMin = {},
      const wrapper<std::optional<Float64>> &value = {},
      const wrapper<std::optional<containers::Axes>> &axes = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      domainMax(this,domainMax),
      domainMin(this,domainMin),
      value(this,value),
      axes(this,axes)
   {
      Component::finish();
   }

   // from node
   explicit DiscreteGamma(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   DiscreteGamma(const DiscreteGamma &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   DiscreteGamma(DiscreteGamma &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   DiscreteGamma &operator=(const DiscreteGamma &) = default;
   DiscreteGamma &operator=(DiscreteGamma &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/transport/DiscreteGamma/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class DiscreteGamma

} // namespace transport
} // namespace v2_0
} // namespace test

#endif
