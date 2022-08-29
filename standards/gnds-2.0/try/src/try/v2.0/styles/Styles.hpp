
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_STYLES_STYLES
#define TRY_V2_0_STYLES_STYLES

#include "try/v2.0/styles/Evaluated.hpp"
#include "try/v2.0/styles/CrossSectionReconstructed.hpp"
#include "try/v2.0/styles/AngularDistributionReconstructed.hpp"
#include "try/v2.0/styles/CoulombPlusNuclearElasticMuCutoff.hpp"
#include "try/v2.0/styles/Heated.hpp"
#include "try/v2.0/styles/AverageProductData.hpp"
#include "try/v2.0/styles/MonteCarlo_cdf.hpp"
#include "try/v2.0/styles/GriddedCrossSection.hpp"
#include "try/v2.0/styles/URR_probabilityTables.hpp"
#include "try/v2.0/styles/HeatedMultiGroup.hpp"
#include "try/v2.0/styles/SnElasticUpScatter.hpp"

namespace try {
namespace v2_0 {
namespace styles {

// -----------------------------------------------------------------------------
// styles::
// class Styles
// -----------------------------------------------------------------------------

class Styles : public Component<styles::Styles> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "styles"; }
   static auto CLASS() { return "Styles"; }
   static auto FIELD() { return "styles"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         std::optional<styles::Evaluated>{}
            / ++Child<>("evaluated") |
         std::optional<styles::CrossSectionReconstructed>{}
            / ++Child<>("crossSectionReconstructed") |
         std::optional<styles::AngularDistributionReconstructed>{}
            / ++Child<>("angularDistributionReconstructed") |
         std::optional<styles::CoulombPlusNuclearElasticMuCutoff>{}
            / ++Child<>("CoulombPlusNuclearElasticMuCutoff") |
         std::optional<styles::Heated>{}
            / ++Child<>("heated") |
         std::optional<styles::AverageProductData>{}
            / ++Child<>("averageProductData") |
         std::optional<styles::MonteCarlo_cdf>{}
            / ++Child<>("MonteCarlo_cdf") |
         std::optional<styles::GriddedCrossSection>{}
            / ++Child<>("griddedCrossSection") |
         std::optional<styles::URR_probabilityTables>{}
            / ++Child<>("URR_probabilityTables") |
         std::optional<styles::HeatedMultiGroup>{}
            / ++Child<>("heatedMultiGroup") |
         std::optional<styles::SnElasticUpScatter>{}
            / ++Child<>("SnElasticUpScatter")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::optional<std::vector<styles::Evaluated>>> evaluated{this};
   Field<std::optional<std::vector<styles::CrossSectionReconstructed>>> crossSectionReconstructed{this};
   Field<std::optional<std::vector<styles::AngularDistributionReconstructed>>> angularDistributionReconstructed{this};
   Field<std::optional<std::vector<styles::CoulombPlusNuclearElasticMuCutoff>>> CoulombPlusNuclearElasticMuCutoff{this};
   Field<std::optional<std::vector<styles::Heated>>> heated{this};
   Field<std::optional<std::vector<styles::AverageProductData>>> averageProductData{this};
   Field<std::optional<std::vector<styles::MonteCarlo_cdf>>> MonteCarlo_cdf{this};
   Field<std::optional<std::vector<styles::GriddedCrossSection>>> griddedCrossSection{this};
   Field<std::optional<std::vector<styles::URR_probabilityTables>>> URR_probabilityTables{this};
   Field<std::optional<std::vector<styles::HeatedMultiGroup>>> heatedMultiGroup{this};
   Field<std::optional<std::vector<styles::SnElasticUpScatter>>> SnElasticUpScatter{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->evaluated, \
      this->crossSectionReconstructed, \
      this->angularDistributionReconstructed, \
      this->CoulombPlusNuclearElasticMuCutoff, \
      this->heated, \
      this->averageProductData, \
      this->MonteCarlo_cdf, \
      this->griddedCrossSection, \
      this->URR_probabilityTables, \
      this->heatedMultiGroup, \
      this->SnElasticUpScatter)

   // default, and from fields
   explicit Styles(
      const wrapper<std::optional<std::vector<styles::Evaluated>>> &evaluated = {},
      const wrapper<std::optional<std::vector<styles::CrossSectionReconstructed>>> &crossSectionReconstructed = {},
      const wrapper<std::optional<std::vector<styles::AngularDistributionReconstructed>>> &angularDistributionReconstructed = {},
      const wrapper<std::optional<std::vector<styles::CoulombPlusNuclearElasticMuCutoff>>> &CoulombPlusNuclearElasticMuCutoff = {},
      const wrapper<std::optional<std::vector<styles::Heated>>> &heated = {},
      const wrapper<std::optional<std::vector<styles::AverageProductData>>> &averageProductData = {},
      const wrapper<std::optional<std::vector<styles::MonteCarlo_cdf>>> &MonteCarlo_cdf = {},
      const wrapper<std::optional<std::vector<styles::GriddedCrossSection>>> &griddedCrossSection = {},
      const wrapper<std::optional<std::vector<styles::URR_probabilityTables>>> &URR_probabilityTables = {},
      const wrapper<std::optional<std::vector<styles::HeatedMultiGroup>>> &heatedMultiGroup = {},
      const wrapper<std::optional<std::vector<styles::SnElasticUpScatter>>> &SnElasticUpScatter = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      evaluated(this,evaluated),
      crossSectionReconstructed(this,crossSectionReconstructed),
      angularDistributionReconstructed(this,angularDistributionReconstructed),
      CoulombPlusNuclearElasticMuCutoff(this,CoulombPlusNuclearElasticMuCutoff),
      heated(this,heated),
      averageProductData(this,averageProductData),
      MonteCarlo_cdf(this,MonteCarlo_cdf),
      griddedCrossSection(this,griddedCrossSection),
      URR_probabilityTables(this,URR_probabilityTables),
      heatedMultiGroup(this,heatedMultiGroup),
      SnElasticUpScatter(this,SnElasticUpScatter)
   {
      Component::finish();
   }

   // from node
   explicit Styles(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Styles(const Styles &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Styles(Styles &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Styles &operator=(const Styles &) = default;
   Styles &operator=(Styles &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/styles/Styles/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Styles

} // namespace styles
} // namespace v2_0
} // namespace try

#endif
