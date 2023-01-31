
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_COMMON_REACTIONSUITE
#define ALPHA_V2_0_COMMON_REACTIONSUITE

#include "alpha/v2.0/common/Styles.hpp"
#include "alpha/v2.0/common/PoPs.hpp"
#include "alpha/v2.0/common/Reactions.hpp"
#include "alpha/v2.0/common/ApplicationData.hpp"
#include "alpha/v2.0/common/ExternalFiles.hpp"
#include "alpha/v2.0/mean/Resonances.hpp"
#include "alpha/v2.0/mean/Sums.hpp"
#include "alpha/v2.0/mean/Productions.hpp"
#include "alpha/v2.0/mean/FissionComponents.hpp"
#include "alpha/v2.0/mean/OrphanProducts.hpp"
#include "alpha/v2.0/mean/IncompleteReactions.hpp"

namespace alpha {
namespace v2_0 {
namespace common {

// -----------------------------------------------------------------------------
// common::
// class ReactionSuite
// -----------------------------------------------------------------------------

class ReactionSuite :
   public Component<common::ReactionSuite>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "common"; }
   static auto CLASS() { return "ReactionSuite"; }
   static auto FIELD() { return "reactionSuite"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("projectile") |
         std::string{}
            / Meta<>("target") |
         std::string{}
            / Meta<>("evaluation") |
         std::string{}
            / Meta<>("format") |
         std::string{}
            / Meta<>("projectileFrame") |
         std::string{}
            / Meta<>("interaction") |

         // children
         --Child<common::Styles>("styles") |
         --Child<common::PoPs>("PoPs") |
         --Child<common::Reactions>("reactions") |
         --Child<std::optional<common::ApplicationData>>("applicationData") |
         --Child<std::optional<common::ExternalFiles>>("externalFiles") |
         --Child<std::optional<mean::Resonances>>("resonances") |
         --Child<std::optional<mean::Sums>>("sums") |
         --Child<std::optional<mean::Productions>>("productions") |
         --Child<std::optional<mean::FissionComponents>>("fissionComponents") |
         --Child<std::optional<mean::OrphanProducts>>("orphanProducts") |
         --Child<std::optional<mean::IncompleteReactions>>("incompleteReactions")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string> projectile{this};
   Field<std::string> target{this};
   Field<std::string> evaluation{this};
   Field<std::string> format{this};
   Field<std::string> projectileFrame{this};
   Field<std::string> interaction{this};

   // children
   Field<common::Styles> styles{this};
   Field<common::PoPs> PoPs{this};
   Field<common::Reactions> reactions{this};
   Field<std::optional<common::ApplicationData>> applicationData{this};
   Field<std::optional<common::ExternalFiles>> externalFiles{this};
   Field<std::optional<mean::Resonances>> resonances{this};
   Field<std::optional<mean::Sums>> sums{this};
   Field<std::optional<mean::Productions>> productions{this};
   Field<std::optional<mean::FissionComponents>> fissionComponents{this};
   Field<std::optional<mean::OrphanProducts>> orphanProducts{this};
   Field<std::optional<mean::IncompleteReactions>> incompleteReactions{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->projectile, \
      this->target, \
      this->evaluation, \
      this->format, \
      this->projectileFrame, \
      this->interaction, \
      this->styles, \
      this->PoPs, \
      this->reactions, \
      this->applicationData, \
      this->externalFiles, \
      this->resonances, \
      this->sums, \
      this->productions, \
      this->fissionComponents, \
      this->orphanProducts, \
      this->incompleteReactions)

   // default
   ReactionSuite() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ReactionSuite(
      const wrapper<std::string> &projectile,
      const wrapper<std::string> &target = {},
      const wrapper<std::string> &evaluation = {},
      const wrapper<std::string> &format = {},
      const wrapper<std::string> &projectileFrame = {},
      const wrapper<std::string> &interaction = {},
      const wrapper<common::Styles> &styles = {},
      const wrapper<common::PoPs> &PoPs = {},
      const wrapper<common::Reactions> &reactions = {},
      const wrapper<std::optional<common::ApplicationData>> &applicationData = {},
      const wrapper<std::optional<common::ExternalFiles>> &externalFiles = {},
      const wrapper<std::optional<mean::Resonances>> &resonances = {},
      const wrapper<std::optional<mean::Sums>> &sums = {},
      const wrapper<std::optional<mean::Productions>> &productions = {},
      const wrapper<std::optional<mean::FissionComponents>> &fissionComponents = {},
      const wrapper<std::optional<mean::OrphanProducts>> &orphanProducts = {},
      const wrapper<std::optional<mean::IncompleteReactions>> &incompleteReactions = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      projectile(this,projectile),
      target(this,target),
      evaluation(this,evaluation),
      format(this,format),
      projectileFrame(this,projectileFrame),
      interaction(this,interaction),
      styles(this,styles),
      PoPs(this,PoPs),
      reactions(this,reactions),
      applicationData(this,applicationData),
      externalFiles(this,externalFiles),
      resonances(this,resonances),
      sums(this,sums),
      productions(this,productions),
      fissionComponents(this,fissionComponents),
      orphanProducts(this,orphanProducts),
      incompleteReactions(this,incompleteReactions)
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
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      projectile(this,other.projectile),
      target(this,other.target),
      evaluation(this,other.evaluation),
      format(this,other.format),
      projectileFrame(this,other.projectileFrame),
      interaction(this,other.interaction),
      styles(this,other.styles),
      PoPs(this,other.PoPs),
      reactions(this,other.reactions),
      applicationData(this,other.applicationData),
      externalFiles(this,other.externalFiles),
      resonances(this,other.resonances),
      sums(this,other.sums),
      productions(this,other.productions),
      fissionComponents(this,other.fissionComponents),
      orphanProducts(this,other.orphanProducts),
      incompleteReactions(this,other.incompleteReactions)
   {
      Component::finish(other);
   }

   // move
   ReactionSuite(ReactionSuite &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      projectile(this,std::move(other.projectile)),
      target(this,std::move(other.target)),
      evaluation(this,std::move(other.evaluation)),
      format(this,std::move(other.format)),
      projectileFrame(this,std::move(other.projectileFrame)),
      interaction(this,std::move(other.interaction)),
      styles(this,std::move(other.styles)),
      PoPs(this,std::move(other.PoPs)),
      reactions(this,std::move(other.reactions)),
      applicationData(this,std::move(other.applicationData)),
      externalFiles(this,std::move(other.externalFiles)),
      resonances(this,std::move(other.resonances)),
      sums(this,std::move(other.sums)),
      productions(this,std::move(other.productions)),
      fissionComponents(this,std::move(other.fissionComponents)),
      orphanProducts(this,std::move(other.orphanProducts)),
      incompleteReactions(this,std::move(other.incompleteReactions))
   {
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

   #include "alpha/v2.0/common/ReactionSuite/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ReactionSuite

} // namespace common
} // namespace v2_0
} // namespace alpha

#endif
