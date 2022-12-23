
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_TRANSPORT_RESONANCESWITHBACKGROUND
#define TEST_V2_0_TRANSPORT_RESONANCESWITHBACKGROUND

#include "test/v2.0/transport/ResonancesLink.hpp"
#include "test/v2.0/transport/Background.hpp"
#include "test/v2.0/containers/Uncertainty.hpp"

namespace test {
namespace v2_0 {
namespace transport {

// -----------------------------------------------------------------------------
// transport::
// class ResonancesWithBackground
// -----------------------------------------------------------------------------

class ResonancesWithBackground : public Component<transport::ResonancesWithBackground> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "transport"; }
   static auto CLASS() { return "ResonancesWithBackground"; }
   static auto FIELD() { return "resonancesWithBackground"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("label") |
         // children
         --Child<transport::ResonancesLink>("resonances") |
         --Child<transport::Background>("background") |
         --Child<std::optional<containers::Uncertainty>>("uncertainty")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<XMLName> label{this};

   // children
   Field<transport::ResonancesLink> resonances{this};
   Field<transport::Background> background{this};
   Field<std::optional<containers::Uncertainty>> uncertainty{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->resonances, \
      this->background, \
      this->uncertainty)

   // default
   ResonancesWithBackground() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields
   explicit ResonancesWithBackground(
      const wrapper<XMLName> &label,
      const wrapper<transport::ResonancesLink> &resonances = {},
      const wrapper<transport::Background> &background = {},
      const wrapper<std::optional<containers::Uncertainty>> &uncertainty = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      resonances(this,resonances),
      background(this,background),
      uncertainty(this,uncertainty)
   {
      Component::finish();
   }

   // from node
   explicit ResonancesWithBackground(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ResonancesWithBackground(const ResonancesWithBackground &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      label(this,other.label),
      resonances(this,other.resonances),
      background(this,other.background),
      uncertainty(this,other.uncertainty)
   {
      Component::finish(other);
   }

   // move
   ResonancesWithBackground(ResonancesWithBackground &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      label(this,std::move(other.label)),
      resonances(this,std::move(other.resonances)),
      background(this,std::move(other.background)),
      uncertainty(this,std::move(other.uncertainty))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   ResonancesWithBackground &operator=(const ResonancesWithBackground &) = default;
   ResonancesWithBackground &operator=(ResonancesWithBackground &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/transport/ResonancesWithBackground/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ResonancesWithBackground

} // namespace transport
} // namespace v2_0
} // namespace test

#endif
