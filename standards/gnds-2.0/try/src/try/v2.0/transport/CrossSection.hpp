
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_TRANSPORT_CROSSSECTION
#define TRY_V2_0_TRANSPORT_CROSSSECTION

#include "try/v2.0/unknownNamespace/XYs1d.hpp"
#include "try/v2.0/unknownNamespace/Regions1d.hpp"
#include "try/v2.0/transport/ResonancesWithBackground.hpp"
#include "try/v2.0/cpTransport/CoulombPlusNuclearElastic.hpp"
#include "try/v2.0/tsl/ThermalNeutronScatteringLaw1d.hpp"
#include "try/v2.0/transport/Reference.hpp"
#include "try/v2.0/unknownNamespace/Gridded1d.hpp"
#include "try/v2.0/unknownNamespace/Ys1d.hpp"
#include "try/v2.0/transport/URR_probabilityTables1d.hpp"

namespace try {
namespace v2_0 {
namespace transport {

// -----------------------------------------------------------------------------
// transport::
// class CrossSection
// -----------------------------------------------------------------------------

class CrossSection : public Component<transport::CrossSection> {
   friend class Component;

   using _t = std::variant<
      unknownNamespace::XYs1d,
      unknownNamespace::Regions1d,
      transport::ResonancesWithBackground,
      cpTransport::CoulombPlusNuclearElastic,
      tsl::ThermalNeutronScatteringLaw1d,
      transport::Reference,
      unknownNamespace::Gridded1d,
      unknownNamespace::Ys1d,
      transport::URR_probabilityTables1d
   >;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "transport"; }
   static auto CLASS() { return "CrossSection"; }
   static auto FIELD() { return "crossSection"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::optional<XMLName>{}
            / Meta<>("label") |
         // children
         _t{}
            / --(Child<>("XYs1d") || Child<>("regions1d") || Child<>("resonancesWithBackground") || Child<>("CoulombPlusNuclearElastic") || Child<>("thermalNeutronScatteringLaw1d") || Child<>("reference") || Child<>("gridded1d") || Child<>("Ys1d") || Child<>("URR_probabilityTables1d"))
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::optional<XMLName>> label{this};

   // children - variant
   Field<_t> _XYs1dregions1dresonancesWithBackgroundCoulombPlusNuclearElasticthermalNeutronScatteringLaw1dreferencegridded1dYs1dURR_probabilityTables1d{this};
   FieldPart<decltype(_XYs1dregions1dresonancesWithBackgroundCoulombPlusNuclearElasticthermalNeutronScatteringLaw1dreferencegridded1dYs1dURR_probabilityTables1d),unknownNamespace::XYs1d> XYs1d{_XYs1dregions1dresonancesWithBackgroundCoulombPlusNuclearElasticthermalNeutronScatteringLaw1dreferencegridded1dYs1dURR_probabilityTables1d};
   FieldPart<decltype(_XYs1dregions1dresonancesWithBackgroundCoulombPlusNuclearElasticthermalNeutronScatteringLaw1dreferencegridded1dYs1dURR_probabilityTables1d),unknownNamespace::Regions1d> regions1d{_XYs1dregions1dresonancesWithBackgroundCoulombPlusNuclearElasticthermalNeutronScatteringLaw1dreferencegridded1dYs1dURR_probabilityTables1d};
   FieldPart<decltype(_XYs1dregions1dresonancesWithBackgroundCoulombPlusNuclearElasticthermalNeutronScatteringLaw1dreferencegridded1dYs1dURR_probabilityTables1d),transport::ResonancesWithBackground> resonancesWithBackground{_XYs1dregions1dresonancesWithBackgroundCoulombPlusNuclearElasticthermalNeutronScatteringLaw1dreferencegridded1dYs1dURR_probabilityTables1d};
   FieldPart<decltype(_XYs1dregions1dresonancesWithBackgroundCoulombPlusNuclearElasticthermalNeutronScatteringLaw1dreferencegridded1dYs1dURR_probabilityTables1d),cpTransport::CoulombPlusNuclearElastic> CoulombPlusNuclearElastic{_XYs1dregions1dresonancesWithBackgroundCoulombPlusNuclearElasticthermalNeutronScatteringLaw1dreferencegridded1dYs1dURR_probabilityTables1d};
   FieldPart<decltype(_XYs1dregions1dresonancesWithBackgroundCoulombPlusNuclearElasticthermalNeutronScatteringLaw1dreferencegridded1dYs1dURR_probabilityTables1d),tsl::ThermalNeutronScatteringLaw1d> thermalNeutronScatteringLaw1d{_XYs1dregions1dresonancesWithBackgroundCoulombPlusNuclearElasticthermalNeutronScatteringLaw1dreferencegridded1dYs1dURR_probabilityTables1d};
   FieldPart<decltype(_XYs1dregions1dresonancesWithBackgroundCoulombPlusNuclearElasticthermalNeutronScatteringLaw1dreferencegridded1dYs1dURR_probabilityTables1d),transport::Reference> reference{_XYs1dregions1dresonancesWithBackgroundCoulombPlusNuclearElasticthermalNeutronScatteringLaw1dreferencegridded1dYs1dURR_probabilityTables1d};
   FieldPart<decltype(_XYs1dregions1dresonancesWithBackgroundCoulombPlusNuclearElasticthermalNeutronScatteringLaw1dreferencegridded1dYs1dURR_probabilityTables1d),unknownNamespace::Gridded1d> gridded1d{_XYs1dregions1dresonancesWithBackgroundCoulombPlusNuclearElasticthermalNeutronScatteringLaw1dreferencegridded1dYs1dURR_probabilityTables1d};
   FieldPart<decltype(_XYs1dregions1dresonancesWithBackgroundCoulombPlusNuclearElasticthermalNeutronScatteringLaw1dreferencegridded1dYs1dURR_probabilityTables1d),unknownNamespace::Ys1d> Ys1d{_XYs1dregions1dresonancesWithBackgroundCoulombPlusNuclearElasticthermalNeutronScatteringLaw1dreferencegridded1dYs1dURR_probabilityTables1d};
   FieldPart<decltype(_XYs1dregions1dresonancesWithBackgroundCoulombPlusNuclearElasticthermalNeutronScatteringLaw1dreferencegridded1dYs1dURR_probabilityTables1d),transport::URR_probabilityTables1d> URR_probabilityTables1d{_XYs1dregions1dresonancesWithBackgroundCoulombPlusNuclearElasticthermalNeutronScatteringLaw1dreferencegridded1dYs1dURR_probabilityTables1d};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->_XYs1dregions1dresonancesWithBackgroundCoulombPlusNuclearElasticthermalNeutronScatteringLaw1dreferencegridded1dYs1dURR_probabilityTables1d)

   // default, and from fields
   explicit CrossSection(
      const wrapper<std::optional<XMLName>> &label = {},
      const wrapper<_t> &_XYs1dregions1dresonancesWithBackgroundCoulombPlusNuclearElasticthermalNeutronScatteringLaw1dreferencegridded1dYs1dURR_probabilityTables1d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      _XYs1dregions1dresonancesWithBackgroundCoulombPlusNuclearElasticthermalNeutronScatteringLaw1dreferencegridded1dYs1dURR_probabilityTables1d(this,_XYs1dregions1dresonancesWithBackgroundCoulombPlusNuclearElasticthermalNeutronScatteringLaw1dreferencegridded1dYs1dURR_probabilityTables1d)
   {
      Component::finish();
   }

   // from node
   explicit CrossSection(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   CrossSection(const CrossSection &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   CrossSection(CrossSection &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   CrossSection &operator=(const CrossSection &) = default;
   CrossSection &operator=(CrossSection &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/transport/CrossSection/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class CrossSection

} // namespace transport
} // namespace v2_0
} // namespace try

#endif
