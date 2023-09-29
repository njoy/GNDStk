
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_FISSIONENERGYRELEASE
#define GNDS_V2_0_GENERAL_FISSIONENERGYRELEASE

#include "GNDS/v2.0/general/PromptProductKE.hpp"
#include "GNDS/v2.0/general/PromptNeutronKE.hpp"
#include "GNDS/v2.0/general/DelayedNeutronKE.hpp"
#include "GNDS/v2.0/general/PromptGammaEnergy.hpp"
#include "GNDS/v2.0/general/DelayedGammaEnergy.hpp"
#include "GNDS/v2.0/general/DelayedBetaEnergy.hpp"
#include "GNDS/v2.0/general/NeutrinoEnergy.hpp"
#include "GNDS/v2.0/general/NonNeutrinoEnergy.hpp"
#include "GNDS/v2.0/general/TotalEnergy.hpp"

namespace GNDS {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class FissionEnergyRelease
// -----------------------------------------------------------------------------

class FissionEnergyRelease :
   public Component<general::FissionEnergyRelease>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "FissionEnergyRelease"; }
   static auto NODENAME() { return "fissionEnergyRelease"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("label") |

         // children
         --Child<general::PromptProductKE>
            ("promptProductKE") |
         --Child<general::PromptNeutronKE>
            ("promptNeutronKE") |
         --Child<general::DelayedNeutronKE>
            ("delayedNeutronKE") |
         --Child<general::PromptGammaEnergy>
            ("promptGammaEnergy") |
         --Child<general::DelayedGammaEnergy>
            ("delayedGammaEnergy") |
         --Child<general::DelayedBetaEnergy>
            ("delayedBetaEnergy") |
         --Child<general::NeutrinoEnergy>
            ("neutrinoEnergy") |
         --Child<general::NonNeutrinoEnergy>
            ("nonNeutrinoEnergy") |
         --Child<general::TotalEnergy>
            ("totalEnergy")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "promptProductKE",
         "promptNeutronKE",
         "delayedNeutronKE",
         "promptGammaEnergy",
         "delayedGammaEnergy",
         "delayedBetaEnergy",
         "neutrinoEnergy",
         "nonNeutrinoEnergy",
         "totalEnergy"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "prompt_product_ke",
         "prompt_neutron_ke",
         "delayed_neutron_ke",
         "prompt_gamma_energy",
         "delayed_gamma_energy",
         "delayed_beta_energy",
         "neutrino_energy",
         "non_neutrino_energy",
         "total_energy"
      };
      return names;
   }

   // ------------------------
   // Public interface
   // ------------------------

public:

   using component_t = Component;
   using Component::construct;

   // ------------------------
   // Data members
   // ------------------------

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string>
      label{this};

   // children
   Field<general::PromptProductKE>
      promptProductKE{this};
   Field<general::PromptNeutronKE>
      promptNeutronKE{this};
   Field<general::DelayedNeutronKE>
      delayedNeutronKE{this};
   Field<general::PromptGammaEnergy>
      promptGammaEnergy{this};
   Field<general::DelayedGammaEnergy>
      delayedGammaEnergy{this};
   Field<general::DelayedBetaEnergy>
      delayedBetaEnergy{this};
   Field<general::NeutrinoEnergy>
      neutrinoEnergy{this};
   Field<general::NonNeutrinoEnergy>
      nonNeutrinoEnergy{this};
   Field<general::TotalEnergy>
      totalEnergy{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->promptProductKE, \
      this->promptNeutronKE, \
      this->delayedNeutronKE, \
      this->promptGammaEnergy, \
      this->delayedGammaEnergy, \
      this->delayedBetaEnergy, \
      this->neutrinoEnergy, \
      this->nonNeutrinoEnergy, \
      this->totalEnergy \
   )

   // default
   FissionEnergyRelease() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit FissionEnergyRelease(
      const wrapper<std::string>
         &label,
      const wrapper<general::PromptProductKE>
         &promptProductKE = {},
      const wrapper<general::PromptNeutronKE>
         &promptNeutronKE = {},
      const wrapper<general::DelayedNeutronKE>
         &delayedNeutronKE = {},
      const wrapper<general::PromptGammaEnergy>
         &promptGammaEnergy = {},
      const wrapper<general::DelayedGammaEnergy>
         &delayedGammaEnergy = {},
      const wrapper<general::DelayedBetaEnergy>
         &delayedBetaEnergy = {},
      const wrapper<general::NeutrinoEnergy>
         &neutrinoEnergy = {},
      const wrapper<general::NonNeutrinoEnergy>
         &nonNeutrinoEnergy = {},
      const wrapper<general::TotalEnergy>
         &totalEnergy = {}
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      promptProductKE(this,promptProductKE),
      promptNeutronKE(this,promptNeutronKE),
      delayedNeutronKE(this,delayedNeutronKE),
      promptGammaEnergy(this,promptGammaEnergy),
      delayedGammaEnergy(this,delayedGammaEnergy),
      delayedBetaEnergy(this,delayedBetaEnergy),
      neutrinoEnergy(this,neutrinoEnergy),
      nonNeutrinoEnergy(this,nonNeutrinoEnergy),
      totalEnergy(this,totalEnergy)
   {
      Component::finish();
   }

   // from node
   explicit FissionEnergyRelease(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   FissionEnergyRelease(const FissionEnergyRelease &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      promptProductKE(this,other.promptProductKE),
      promptNeutronKE(this,other.promptNeutronKE),
      delayedNeutronKE(this,other.delayedNeutronKE),
      promptGammaEnergy(this,other.promptGammaEnergy),
      delayedGammaEnergy(this,other.delayedGammaEnergy),
      delayedBetaEnergy(this,other.delayedBetaEnergy),
      neutrinoEnergy(this,other.neutrinoEnergy),
      nonNeutrinoEnergy(this,other.nonNeutrinoEnergy),
      totalEnergy(this,other.totalEnergy)
   {
      Component::finish(other);
   }

   // move
   FissionEnergyRelease(FissionEnergyRelease &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      promptProductKE(this,std::move(other.promptProductKE)),
      promptNeutronKE(this,std::move(other.promptNeutronKE)),
      delayedNeutronKE(this,std::move(other.delayedNeutronKE)),
      promptGammaEnergy(this,std::move(other.promptGammaEnergy)),
      delayedGammaEnergy(this,std::move(other.delayedGammaEnergy)),
      delayedBetaEnergy(this,std::move(other.delayedBetaEnergy)),
      neutrinoEnergy(this,std::move(other.neutrinoEnergy)),
      nonNeutrinoEnergy(this,std::move(other.nonNeutrinoEnergy)),
      totalEnergy(this,std::move(other.totalEnergy))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   FissionEnergyRelease &operator=(const FissionEnergyRelease &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         promptProductKE = other.promptProductKE;
         promptNeutronKE = other.promptNeutronKE;
         delayedNeutronKE = other.delayedNeutronKE;
         promptGammaEnergy = other.promptGammaEnergy;
         delayedGammaEnergy = other.delayedGammaEnergy;
         delayedBetaEnergy = other.delayedBetaEnergy;
         neutrinoEnergy = other.neutrinoEnergy;
         nonNeutrinoEnergy = other.nonNeutrinoEnergy;
         totalEnergy = other.totalEnergy;
      }
      return *this;
   }

   // move
   FissionEnergyRelease &operator=(FissionEnergyRelease &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         promptProductKE = std::move(other.promptProductKE);
         promptNeutronKE = std::move(other.promptNeutronKE);
         delayedNeutronKE = std::move(other.delayedNeutronKE);
         promptGammaEnergy = std::move(other.promptGammaEnergy);
         delayedGammaEnergy = std::move(other.delayedGammaEnergy);
         delayedBetaEnergy = std::move(other.delayedBetaEnergy);
         neutrinoEnergy = std::move(other.neutrinoEnergy);
         nonNeutrinoEnergy = std::move(other.nonNeutrinoEnergy);
         totalEnergy = std::move(other.totalEnergy);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDS/v2.0/general/FissionEnergyRelease/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class FissionEnergyRelease

} // namespace general
} // namespace v2_0
} // namespace GNDS

#endif
