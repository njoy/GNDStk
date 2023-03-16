
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_FISSIONTRANSPORT_FISSIONENERGYRELEASED
#define NJOY_GNDSTK_V2_0_FISSIONTRANSPORT_FISSIONENERGYRELEASED

// core interface
#include "GNDStk.hpp"

// v2.0 dependencies
#include "GNDStk/v2.0/fissionTransport/DelayedBetaEnergy.hpp"
#include "GNDStk/v2.0/fissionTransport/DelayedGammaEnergy.hpp"
#include "GNDStk/v2.0/fissionTransport/DelayedNeutronKE.hpp"
#include "GNDStk/v2.0/fissionTransport/NeutrinoEnergy.hpp"
#include "GNDStk/v2.0/fissionTransport/NonNeutrinoEnergy.hpp"
#include "GNDStk/v2.0/fissionTransport/PromptGammaEnergy.hpp"
#include "GNDStk/v2.0/fissionTransport/PromptNeutronKE.hpp"
#include "GNDStk/v2.0/fissionTransport/PromptProductKE.hpp"
#include "GNDStk/v2.0/fissionTransport/TotalEnergy.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// fissionTransport::
// class FissionEnergyReleased
// -----------------------------------------------------------------------------

namespace fissionTransport {

class FissionEnergyReleased : public Component<FissionEnergyReleased> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "fissionTransport"; }
   static auto className() { return "FissionEnergyReleased"; }
   static auto GNDSName() { return "fissionEnergyReleased"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         std::optional<XMLName>{}
            / Meta<>("label") |
         // children
         std::optional<fissionTransport::DelayedBetaEnergy>{}
            / --Child<>("delayedBetaEnergy") |
         std::optional<fissionTransport::DelayedGammaEnergy>{}
            / --Child<>("delayedGammaEnergy") |
         std::optional<fissionTransport::DelayedNeutronKE>{}
            / --Child<>("delayedNeutronKE") |
         std::optional<fissionTransport::NeutrinoEnergy>{}
            / --Child<>("neutrinoEnergy") |
         std::optional<fissionTransport::NonNeutrinoEnergy>{}
            / --Child<>("nonNeutrinoEnergy") |
         std::optional<fissionTransport::PromptGammaEnergy>{}
            / --Child<>("promptGammaEnergy") |
         std::optional<fissionTransport::PromptNeutronKE>{}
            / --Child<>("promptNeutronKE") |
         std::optional<fissionTransport::PromptProductKE>{}
            / --Child<>("promptProductKE") |
         std::optional<fissionTransport::TotalEnergy>{}
            / --Child<>("totalEnergy")
      ;
   }

public:

   using Component::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static inline const struct Defaults {
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      std::optional<XMLName> label;
      // children
      std::optional<fissionTransport::DelayedBetaEnergy> delayedBetaEnergy;
      std::optional<fissionTransport::DelayedGammaEnergy> delayedGammaEnergy;
      std::optional<fissionTransport::DelayedNeutronKE> delayedNeutronKE;
      std::optional<fissionTransport::NeutrinoEnergy> neutrinoEnergy;
      std::optional<fissionTransport::NonNeutrinoEnergy> nonNeutrinoEnergy;
      std::optional<fissionTransport::PromptGammaEnergy> promptGammaEnergy;
      std::optional<fissionTransport::PromptNeutronKE> promptNeutronKE;
      std::optional<fissionTransport::PromptProductKE> promptProductKE;
      std::optional<fissionTransport::TotalEnergy> totalEnergy;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // label
   const std::optional<XMLName> &label() const
      { return content.label; }
   std::optional<XMLName> &label()
      { return content.label; }

   // delayedBetaEnergy
   const std::optional<fissionTransport::DelayedBetaEnergy> &delayedBetaEnergy() const
      { return content.delayedBetaEnergy; }
   std::optional<fissionTransport::DelayedBetaEnergy> &delayedBetaEnergy()
      { return content.delayedBetaEnergy; }

   // delayedGammaEnergy
   const std::optional<fissionTransport::DelayedGammaEnergy> &delayedGammaEnergy() const
      { return content.delayedGammaEnergy; }
   std::optional<fissionTransport::DelayedGammaEnergy> &delayedGammaEnergy()
      { return content.delayedGammaEnergy; }

   // delayedNeutronKE
   const std::optional<fissionTransport::DelayedNeutronKE> &delayedNeutronKE() const
      { return content.delayedNeutronKE; }
   std::optional<fissionTransport::DelayedNeutronKE> &delayedNeutronKE()
      { return content.delayedNeutronKE; }

   // neutrinoEnergy
   const std::optional<fissionTransport::NeutrinoEnergy> &neutrinoEnergy() const
      { return content.neutrinoEnergy; }
   std::optional<fissionTransport::NeutrinoEnergy> &neutrinoEnergy()
      { return content.neutrinoEnergy; }

   // nonNeutrinoEnergy
   const std::optional<fissionTransport::NonNeutrinoEnergy> &nonNeutrinoEnergy() const
      { return content.nonNeutrinoEnergy; }
   std::optional<fissionTransport::NonNeutrinoEnergy> &nonNeutrinoEnergy()
      { return content.nonNeutrinoEnergy; }

   // promptGammaEnergy
   const std::optional<fissionTransport::PromptGammaEnergy> &promptGammaEnergy() const
      { return content.promptGammaEnergy; }
   std::optional<fissionTransport::PromptGammaEnergy> &promptGammaEnergy()
      { return content.promptGammaEnergy; }

   // promptNeutronKE
   const std::optional<fissionTransport::PromptNeutronKE> &promptNeutronKE() const
      { return content.promptNeutronKE; }
   std::optional<fissionTransport::PromptNeutronKE> &promptNeutronKE()
      { return content.promptNeutronKE; }

   // promptProductKE
   const std::optional<fissionTransport::PromptProductKE> &promptProductKE() const
      { return content.promptProductKE; }
   std::optional<fissionTransport::PromptProductKE> &promptProductKE()
      { return content.promptProductKE; }

   // totalEnergy
   const std::optional<fissionTransport::TotalEnergy> &totalEnergy() const
      { return content.totalEnergy; }
   std::optional<fissionTransport::TotalEnergy> &totalEnergy()
      { return content.totalEnergy; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // label(value)
   FissionEnergyReleased &label(const std::optional<XMLName> &obj)
      { label() = obj; return *this; }

   // delayedBetaEnergy(value)
   FissionEnergyReleased &delayedBetaEnergy(const std::optional<fissionTransport::DelayedBetaEnergy> &obj)
      { delayedBetaEnergy() = obj; return *this; }

   // delayedGammaEnergy(value)
   FissionEnergyReleased &delayedGammaEnergy(const std::optional<fissionTransport::DelayedGammaEnergy> &obj)
      { delayedGammaEnergy() = obj; return *this; }

   // delayedNeutronKE(value)
   FissionEnergyReleased &delayedNeutronKE(const std::optional<fissionTransport::DelayedNeutronKE> &obj)
      { delayedNeutronKE() = obj; return *this; }

   // neutrinoEnergy(value)
   FissionEnergyReleased &neutrinoEnergy(const std::optional<fissionTransport::NeutrinoEnergy> &obj)
      { neutrinoEnergy() = obj; return *this; }

   // nonNeutrinoEnergy(value)
   FissionEnergyReleased &nonNeutrinoEnergy(const std::optional<fissionTransport::NonNeutrinoEnergy> &obj)
      { nonNeutrinoEnergy() = obj; return *this; }

   // promptGammaEnergy(value)
   FissionEnergyReleased &promptGammaEnergy(const std::optional<fissionTransport::PromptGammaEnergy> &obj)
      { promptGammaEnergy() = obj; return *this; }

   // promptNeutronKE(value)
   FissionEnergyReleased &promptNeutronKE(const std::optional<fissionTransport::PromptNeutronKE> &obj)
      { promptNeutronKE() = obj; return *this; }

   // promptProductKE(value)
   FissionEnergyReleased &promptProductKE(const std::optional<fissionTransport::PromptProductKE> &obj)
      { promptProductKE() = obj; return *this; }

   // totalEnergy(value)
   FissionEnergyReleased &totalEnergy(const std::optional<fissionTransport::TotalEnergy> &obj)
      { totalEnergy() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   FissionEnergyReleased() :
      Component{
         BodyText{},
         content.label,
         content.delayedBetaEnergy,
         content.delayedGammaEnergy,
         content.delayedNeutronKE,
         content.neutrinoEnergy,
         content.nonNeutrinoEnergy,
         content.promptGammaEnergy,
         content.promptNeutronKE,
         content.promptProductKE,
         content.totalEnergy
      }
   {
      Component::finish();
   }

   // copy
   FissionEnergyReleased(const FissionEnergyReleased &other) :
      Component{
         other,
         content.label,
         content.delayedBetaEnergy,
         content.delayedGammaEnergy,
         content.delayedNeutronKE,
         content.neutrinoEnergy,
         content.nonNeutrinoEnergy,
         content.promptGammaEnergy,
         content.promptNeutronKE,
         content.promptProductKE,
         content.totalEnergy
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   FissionEnergyReleased(FissionEnergyReleased &&other) :
      Component{
         other,
         content.label,
         content.delayedBetaEnergy,
         content.delayedGammaEnergy,
         content.delayedNeutronKE,
         content.neutrinoEnergy,
         content.nonNeutrinoEnergy,
         content.promptGammaEnergy,
         content.promptNeutronKE,
         content.promptProductKE,
         content.totalEnergy
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   FissionEnergyReleased(const Node &node) :
      Component{
         BodyText{},
         content.label,
         content.delayedBetaEnergy,
         content.delayedGammaEnergy,
         content.delayedNeutronKE,
         content.neutrinoEnergy,
         content.nonNeutrinoEnergy,
         content.promptGammaEnergy,
         content.promptNeutronKE,
         content.promptProductKE,
         content.totalEnergy
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit FissionEnergyReleased(
      const std::optional<XMLName> &label,
      const std::optional<fissionTransport::DelayedBetaEnergy> &delayedBetaEnergy,
      const std::optional<fissionTransport::DelayedGammaEnergy> &delayedGammaEnergy,
      const std::optional<fissionTransport::DelayedNeutronKE> &delayedNeutronKE,
      const std::optional<fissionTransport::NeutrinoEnergy> &neutrinoEnergy,
      const std::optional<fissionTransport::NonNeutrinoEnergy> &nonNeutrinoEnergy,
      const std::optional<fissionTransport::PromptGammaEnergy> &promptGammaEnergy,
      const std::optional<fissionTransport::PromptNeutronKE> &promptNeutronKE,
      const std::optional<fissionTransport::PromptProductKE> &promptProductKE,
      const std::optional<fissionTransport::TotalEnergy> &totalEnergy
   ) :
      Component{
         BodyText{},
         content.label,
         content.delayedBetaEnergy,
         content.delayedGammaEnergy,
         content.delayedNeutronKE,
         content.neutrinoEnergy,
         content.nonNeutrinoEnergy,
         content.promptGammaEnergy,
         content.promptNeutronKE,
         content.promptProductKE,
         content.totalEnergy
      },
      content{
         label,
         delayedBetaEnergy,
         delayedGammaEnergy,
         delayedNeutronKE,
         neutrinoEnergy,
         nonNeutrinoEnergy,
         promptGammaEnergy,
         promptNeutronKE,
         promptProductKE,
         totalEnergy
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   FissionEnergyReleased &operator=(const FissionEnergyReleased &) = default;

   // move
   FissionEnergyReleased &operator=(FissionEnergyReleased &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/fissionTransport/FissionEnergyReleased/src/custom.hpp"

}; // class FissionEnergyReleased

} // namespace fissionTransport
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif
