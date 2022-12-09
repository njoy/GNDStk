
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_CONTAINERS_LEGENDRE
#define TEST_V2_0_CONTAINERS_LEGENDRE

#include "test/v2.0/containers/Values.hpp"

namespace test {
namespace v2_0 {
namespace containers {

// -----------------------------------------------------------------------------
// containers::
// class Legendre
// -----------------------------------------------------------------------------

class Legendre : public Component<containers::Legendre> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "containers"; }
   static auto CLASS() { return "Legendre"; }
   static auto FIELD() { return "Legendre"; }

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
         Defaulted<Float64>{-1.0}
            / Meta<>("domainMin") |
         Defaulted<Float64>{1.0}
            / Meta<>("domainMax") |
         // children
         --Child<containers::Values>("values")
      ;
   }

public:
   using Component::construct;

   // defaults
   static inline const struct Defaults {
      static inline const Integer32 lowerIndex = 0;
      static inline const Float64 domainMin = -1.0;
      static inline const Float64 domainMax = 1.0;
   } defaults;

   // metadata
   Field<std::optional<XMLName>> label{this};
   Field<std::optional<Float64>> outerDomainValue{this};
   Field<Defaulted<Integer32>> lowerIndex{this,defaults.lowerIndex};
   Field<Defaulted<Float64>> domainMin{this,defaults.domainMin};
   Field<Defaulted<Float64>> domainMax{this,defaults.domainMax};

   // children
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
      this->values)

   // default
   Legendre() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields
   // std::optional replaces Defaulted; this class knows the default(s)
   explicit Legendre(
      const wrapper<std::optional<XMLName>> &label,
      const wrapper<std::optional<Float64>> &outerDomainValue = {},
      const wrapper<std::optional<Integer32>> &lowerIndex = {},
      const wrapper<std::optional<Float64>> &domainMin = {},
      const wrapper<std::optional<Float64>> &domainMax = {},
      const wrapper<containers::Values> &values = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      outerDomainValue(this,outerDomainValue),
      lowerIndex(this,defaults.lowerIndex,lowerIndex),
      domainMin(this,defaults.domainMin,domainMin),
      domainMax(this,defaults.domainMax,domainMax),
      values(this,values)
   {
      Component::finish();
   }

   // from node
   explicit Legendre(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Legendre(const Legendre &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      label(this,other.label),
      outerDomainValue(this,other.outerDomainValue),
      lowerIndex(this,other.lowerIndex),
      domainMin(this,other.domainMin),
      domainMax(this,other.domainMax),
      values(this,other.values)
   {
      Component::finish(other);
   }

   // move
   Legendre(Legendre &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      label(this,std::move(other.label)),
      outerDomainValue(this,std::move(other.outerDomainValue)),
      lowerIndex(this,std::move(other.lowerIndex)),
      domainMin(this,std::move(other.domainMin)),
      domainMax(this,std::move(other.domainMax)),
      values(this,std::move(other.values))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Legendre &operator=(const Legendre &) = default;
   Legendre &operator=(Legendre &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/containers/Legendre/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Legendre

} // namespace containers
} // namespace v2_0
} // namespace test

#endif
