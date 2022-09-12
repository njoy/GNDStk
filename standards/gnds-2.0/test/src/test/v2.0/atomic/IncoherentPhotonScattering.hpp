
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_ATOMIC_INCOHERENTPHOTONSCATTERING
#define TEST_V2_0_ATOMIC_INCOHERENTPHOTONSCATTERING

#include "test/v2.0/atomic/ScatteringFactor.hpp"

namespace test {
namespace v2_0 {
namespace atomic {

// -----------------------------------------------------------------------------
// atomic::
// class IncoherentPhotonScattering
// -----------------------------------------------------------------------------

class IncoherentPhotonScattering : public Component<atomic::IncoherentPhotonScattering> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "atomic"; }
   static auto CLASS() { return "IncoherentPhotonScattering"; }
   static auto FIELD() { return "incoherentPhotonScattering"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::optional<std::string>{}
            / Meta<>("href") |
         std::optional<XMLName>{}
            / Meta<>("label") |
         std::optional<XMLName>{}
            / Meta<>("pid") |
         enums::Frame{}
            / Meta<>("productFrame") |
         // children
         std::optional<atomic::ScatteringFactor>{}
            / --Child<>("scatteringFactor")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::optional<std::string>> href{this};
   Field<std::optional<XMLName>> label{this};
   Field<std::optional<XMLName>> pid{this};
   Field<enums::Frame> productFrame{this};

   // children
   Field<std::optional<atomic::ScatteringFactor>> scatteringFactor{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->href, \
      this->label, \
      this->pid, \
      this->productFrame, \
      this->scatteringFactor)

   // default, and from fields
   explicit IncoherentPhotonScattering(
      const wrapper<std::optional<std::string>> &href = {},
      const wrapper<std::optional<XMLName>> &label = {},
      const wrapper<std::optional<XMLName>> &pid = {},
      const wrapper<enums::Frame> &productFrame = {},
      const wrapper<std::optional<atomic::ScatteringFactor>> &scatteringFactor = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      href(this,href),
      label(this,label),
      pid(this,pid),
      productFrame(this,productFrame),
      scatteringFactor(this,scatteringFactor)
   {
      Component::finish();
   }

   // from node
   explicit IncoherentPhotonScattering(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   IncoherentPhotonScattering(const IncoherentPhotonScattering &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   IncoherentPhotonScattering(IncoherentPhotonScattering &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   IncoherentPhotonScattering &operator=(const IncoherentPhotonScattering &) = default;
   IncoherentPhotonScattering &operator=(IncoherentPhotonScattering &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/atomic/IncoherentPhotonScattering/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class IncoherentPhotonScattering

} // namespace atomic
} // namespace v2_0
} // namespace test

#endif