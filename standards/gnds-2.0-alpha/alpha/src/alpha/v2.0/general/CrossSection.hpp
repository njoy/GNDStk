
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_CROSSSECTION
#define ALPHA_V2_0_GENERAL_CROSSSECTION

#include "alpha/v2.0/general/XYs1d.hpp"
#include "alpha/v2.0/general/Regions1d.hpp"
#include "alpha/v2.0/general/Reference.hpp"
#include "alpha/v2.0/general/ResonancesWithBackground.hpp"
#include "alpha/v2.0/general/CoulombPlusNuclearElastic.hpp"
#include "alpha/v2.0/general/ThermalNeutronScatteringLaw1d.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class CrossSection
// -----------------------------------------------------------------------------

class CrossSection :
   public Component<general::CrossSection>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "CrossSection"; }
   static auto FIELD() { return "crossSection"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<std::optional<general::XYs1d>>
            ("XYs1d") |
         --Child<std::optional<general::Regions1d>>
            ("regions1d") |
         --Child<std::optional<general::Reference>>
            ("reference") |
         --Child<std::optional<general::ResonancesWithBackground>>
            ("resonancesWithBackground") |
         --Child<std::optional<general::CoulombPlusNuclearElastic>>
            ("CoulombPlusNuclearElastic") |
         --Child<std::optional<general::ThermalNeutronScatteringLaw1d>>
            ("thermalNeutronScatteringLaw1d")
      ;
   }

public:
   using component_t = Component;
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<std::optional<general::XYs1d>>
      XYs1d{this};
   Field<std::optional<general::Regions1d>>
      regions1d{this};
   Field<std::optional<general::Reference>>
      reference{this};
   Field<std::optional<general::ResonancesWithBackground>>
      resonancesWithBackground{this};
   Field<std::optional<general::CoulombPlusNuclearElastic>>
      CoulombPlusNuclearElastic{this};
   Field<std::optional<general::ThermalNeutronScatteringLaw1d>>
      thermalNeutronScatteringLaw1d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->XYs1d, \
      this->regions1d, \
      this->reference, \
      this->resonancesWithBackground, \
      this->CoulombPlusNuclearElastic, \
      this->thermalNeutronScatteringLaw1d \
   )

   // default
   CrossSection() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit CrossSection(
      const wrapper<std::optional<general::XYs1d>>
         &XYs1d,
      const wrapper<std::optional<general::Regions1d>>
         &regions1d = {},
      const wrapper<std::optional<general::Reference>>
         &reference = {},
      const wrapper<std::optional<general::ResonancesWithBackground>>
         &resonancesWithBackground = {},
      const wrapper<std::optional<general::CoulombPlusNuclearElastic>>
         &CoulombPlusNuclearElastic = {},
      const wrapper<std::optional<general::ThermalNeutronScatteringLaw1d>>
         &thermalNeutronScatteringLaw1d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      XYs1d(this,XYs1d),
      regions1d(this,regions1d),
      reference(this,reference),
      resonancesWithBackground(this,resonancesWithBackground),
      CoulombPlusNuclearElastic(this,CoulombPlusNuclearElastic),
      thermalNeutronScatteringLaw1d(this,thermalNeutronScatteringLaw1d)
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
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      XYs1d(this,other.XYs1d),
      regions1d(this,other.regions1d),
      reference(this,other.reference),
      resonancesWithBackground(this,other.resonancesWithBackground),
      CoulombPlusNuclearElastic(this,other.CoulombPlusNuclearElastic),
      thermalNeutronScatteringLaw1d(this,other.thermalNeutronScatteringLaw1d)
   {
      Component::finish(other);
   }

   // move
   CrossSection(CrossSection &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      XYs1d(this,std::move(other.XYs1d)),
      regions1d(this,std::move(other.regions1d)),
      reference(this,std::move(other.reference)),
      resonancesWithBackground(this,std::move(other.resonancesWithBackground)),
      CoulombPlusNuclearElastic(this,std::move(other.CoulombPlusNuclearElastic)),
      thermalNeutronScatteringLaw1d(this,std::move(other.thermalNeutronScatteringLaw1d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   CrossSection &operator=(const CrossSection &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         XYs1d = other.XYs1d;
         regions1d = other.regions1d;
         reference = other.reference;
         resonancesWithBackground = other.resonancesWithBackground;
         CoulombPlusNuclearElastic = other.CoulombPlusNuclearElastic;
         thermalNeutronScatteringLaw1d = other.thermalNeutronScatteringLaw1d;
      }
      return *this;
   }

   // move
   CrossSection &operator=(CrossSection &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         XYs1d = std::move(other.XYs1d);
         regions1d = std::move(other.regions1d);
         reference = std::move(other.reference);
         resonancesWithBackground = std::move(other.resonancesWithBackground);
         CoulombPlusNuclearElastic = std::move(other.CoulombPlusNuclearElastic);
         thermalNeutronScatteringLaw1d = std::move(other.thermalNeutronScatteringLaw1d);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/CrossSection/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class CrossSection

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
