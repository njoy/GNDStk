
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_CONTAINERS_POLYNOMIAL1D
#define TEST_V2_0_CONTAINERS_POLYNOMIAL1D

#include "test/v2.0/containers/Axes.hpp"
#include "test/v2.0/extra/Uncertainty.hpp"
#include "test/v2.0/containers/Values.hpp"

namespace test {
namespace v2_0 {
namespace containers {

// -----------------------------------------------------------------------------
// containers::
// class Polynomial1d
// -----------------------------------------------------------------------------

class Polynomial1d : public Component<containers::Polynomial1d> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "containers"; }
   static auto CLASS() { return "Polynomial1d"; }
   static auto FIELD() { return "polynomial1d"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::optional<XMLName>{}
            / Meta<>("label") |
         std::optional<Float64>{}
            / Meta<>("outerDomainValue") |
         Defaulted<Integer32>{0}
            / Meta<>("lowerIndex") |
         Float64{}
            / Meta<>("domainMin") |
         Float64{}
            / Meta<>("domainMax") |
         // children
         --Child<containers::Axes>("axes") |
         --Child<std::optional<extra::Uncertainty>>("uncertainty") |
         --Child<containers::Values>("values")
      ;
   }

public:
   using Component::construct;

   // defaults
   static inline const struct Defaults {
      static inline const Integer32 lowerIndex = 0;
   } defaults;

   // metadata
   Field<std::optional<XMLName>> label{this};
   Field<std::optional<Float64>> outerDomainValue{this};
   Field<Defaulted<Integer32>> lowerIndex{this,defaults.lowerIndex};
   Field<Float64> domainMin{this};
   Field<Float64> domainMax{this};

   // children
   Field<containers::Axes> axes{this};
   Field<std::optional<extra::Uncertainty>> uncertainty{this};
   Field<containers::Values> values{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->outerDomainValue, \
      this->lowerIndex, \
      this->domainMin, \
      this->domainMax, \
      this->axes, \
      this->uncertainty, \
      this->values)

   // default
   Polynomial1d() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields
   // std::optional replaces Defaulted; this class knows the default(s)
   explicit Polynomial1d(
      const wrapper<std::optional<XMLName>> &label,
      const wrapper<std::optional<Float64>> &outerDomainValue = {},
      const wrapper<std::optional<Integer32>> &lowerIndex = {},
      const wrapper<Float64> &domainMin = {},
      const wrapper<Float64> &domainMax = {},
      const wrapper<containers::Axes> &axes = {},
      const wrapper<std::optional<extra::Uncertainty>> &uncertainty = {},
      const wrapper<containers::Values> &values = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      outerDomainValue(this,outerDomainValue),
      lowerIndex(this,defaults.lowerIndex,lowerIndex),
      domainMin(this,domainMin),
      domainMax(this,domainMax),
      axes(this,axes),
      uncertainty(this,uncertainty),
      values(this,values)
   {
      Component::finish();
   }

   // from node
   explicit Polynomial1d(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Polynomial1d(const Polynomial1d &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      label(this,other.label),
      outerDomainValue(this,other.outerDomainValue),
      lowerIndex(this,other.lowerIndex),
      domainMin(this,other.domainMin),
      domainMax(this,other.domainMax),
      axes(this,other.axes),
      uncertainty(this,other.uncertainty),
      values(this,other.values)
   {
      Component::finish(other);
   }

   // move
   Polynomial1d(Polynomial1d &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      label(this,std::move(other.label)),
      outerDomainValue(this,std::move(other.outerDomainValue)),
      lowerIndex(this,std::move(other.lowerIndex)),
      domainMin(this,std::move(other.domainMin)),
      domainMax(this,std::move(other.domainMax)),
      axes(this,std::move(other.axes)),
      uncertainty(this,std::move(other.uncertainty)),
      values(this,std::move(other.values))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Polynomial1d &operator=(const Polynomial1d &) = default;
   Polynomial1d &operator=(Polynomial1d &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/containers/Polynomial1d/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Polynomial1d

} // namespace containers
} // namespace v2_0
} // namespace test

#endif
