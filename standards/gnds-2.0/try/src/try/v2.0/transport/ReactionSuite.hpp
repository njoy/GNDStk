
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_TRANSPORT_REACTIONSUITE
#define TRY_V2_0_TRANSPORT_REACTIONSUITE

#include "try/v2.0/common/ExternalFiles.hpp"
#include "try/v2.0/styles/Styles.hpp"
#include "try/v2.0/unknownNamespace/PoPs.hpp"
#include "try/v2.0/resonances/Resonances.hpp"
#include "try/v2.0/transport/Reactions.hpp"
#include "try/v2.0/transport/OrphanProducts.hpp"
#include "try/v2.0/transport/Sums.hpp"
#include "try/v2.0/fissionTransport/FissionComponents.hpp"
#include "try/v2.0/transport/Productions.hpp"
#include "try/v2.0/transport/IncompleteReactions.hpp"
#include "try/v2.0/appData/ApplicationData.hpp"

namespace try {
namespace v2_0 {
namespace transport {

// -----------------------------------------------------------------------------
// transport::
// class ReactionSuite
// -----------------------------------------------------------------------------

class ReactionSuite : public Component<transport::ReactionSuite> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "transport"; }
   static auto CLASS() { return "ReactionSuite"; }
   static auto FIELD() { return "reactionSuite"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("evaluation") |
         XMLName{}
            / Meta<>("format") |
         XMLName{}
            / Meta<>("projectile") |
         enums::Frame{}
            / Meta<>("projectileFrame") |
         XMLName{}
            / Meta<>("target") |
         enums::Interaction{}
            / Meta<>("interaction") |
         // children
         std::optional<common::ExternalFiles>{}
            / --Child<>("externalFiles") |
         styles::Styles{}
            / --Child<>("styles") |
         unknownNamespace::PoPs{}
            / --Child<>("PoPs") |
         std::optional<resonances::Resonances>{}
            / --Child<>("resonances") |
         std::optional<transport::Reactions>{}
            / --Child<>("reactions") |
         std::optional<transport::OrphanProducts>{}
            / --Child<>("orphanProducts") |
         std::optional<transport::Sums>{}
            / --Child<>("sums") |
         std::optional<fissionTransport::FissionComponents>{}
            / --Child<>("fissionComponents") |
         std::optional<transport::Productions>{}
            / --Child<>("productions") |
         std::optional<transport::IncompleteReactions>{}
            / --Child<>("incompleteReactions") |
         std::optional<appData::ApplicationData>{}
            / --Child<>("applicationData")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<XMLName> evaluation{this};
   Field<XMLName> format{this};
   Field<XMLName> projectile{this};
   Field<enums::Frame> projectileFrame{this};
   Field<XMLName> target{this};
   Field<enums::Interaction> interaction{this};

   // children
   Field<std::optional<common::ExternalFiles>> externalFiles{this};
   Field<styles::Styles> styles{this};
   Field<unknownNamespace::PoPs> PoPs{this};
   Field<std::optional<resonances::Resonances>> resonances{this};
   Field<std::optional<transport::Reactions>> reactions{this};
   Field<std::optional<transport::OrphanProducts>> orphanProducts{this};
   Field<std::optional<transport::Sums>> sums{this};
   Field<std::optional<fissionTransport::FissionComponents>> fissionComponents{this};
   Field<std::optional<transport::Productions>> productions{this};
   Field<std::optional<transport::IncompleteReactions>> incompleteReactions{this};
   Field<std::optional<appData::ApplicationData>> applicationData{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->evaluation, \
      this->format, \
      this->projectile, \
      this->projectileFrame, \
      this->target, \
      this->interaction, \
      this->externalFiles, \
      this->styles, \
      this->PoPs, \
      this->resonances, \
      this->reactions, \
      this->orphanProducts, \
      this->sums, \
      this->fissionComponents, \
      this->productions, \
      this->incompleteReactions, \
      this->applicationData)

   // default, and from fields
   explicit ReactionSuite(
      const wrapper<XMLName> &evaluation = {},
      const wrapper<XMLName> &format = {},
      const wrapper<XMLName> &projectile = {},
      const wrapper<enums::Frame> &projectileFrame = {},
      const wrapper<XMLName> &target = {},
      const wrapper<enums::Interaction> &interaction = {},
      const wrapper<std::optional<common::ExternalFiles>> &externalFiles = {},
      const wrapper<styles::Styles> &styles = {},
      const wrapper<unknownNamespace::PoPs> &PoPs = {},
      const wrapper<std::optional<resonances::Resonances>> &resonances = {},
      const wrapper<std::optional<transport::Reactions>> &reactions = {},
      const wrapper<std::optional<transport::OrphanProducts>> &orphanProducts = {},
      const wrapper<std::optional<transport::Sums>> &sums = {},
      const wrapper<std::optional<fissionTransport::FissionComponents>> &fissionComponents = {},
      const wrapper<std::optional<transport::Productions>> &productions = {},
      const wrapper<std::optional<transport::IncompleteReactions>> &incompleteReactions = {},
      const wrapper<std::optional<appData::ApplicationData>> &applicationData = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      evaluation(this,evaluation),
      format(this,format),
      projectile(this,projectile),
      projectileFrame(this,projectileFrame),
      target(this,target),
      interaction(this,interaction),
      externalFiles(this,externalFiles),
      styles(this,styles),
      PoPs(this,PoPs),
      resonances(this,resonances),
      reactions(this,reactions),
      orphanProducts(this,orphanProducts),
      sums(this,sums),
      fissionComponents(this,fissionComponents),
      productions(this,productions),
      incompleteReactions(this,incompleteReactions),
      applicationData(this,applicationData)
   {
      Component::finish();
   }

   // from node
   explicit ReactionSuite(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ReactionSuite(const ReactionSuite &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   ReactionSuite(ReactionSuite &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   ReactionSuite &operator=(const ReactionSuite &) = default;
   ReactionSuite &operator=(ReactionSuite &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/transport/ReactionSuite/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ReactionSuite

} // namespace transport
} // namespace v2_0
} // namespace try

#endif
