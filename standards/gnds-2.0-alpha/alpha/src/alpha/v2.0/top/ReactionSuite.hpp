
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_TOP_REACTIONSUITE
#define ALPHA_V2_0_TOP_REACTIONSUITE

#include "alpha/v2.0/general/Styles.hpp"
#include "alpha/v2.0/top/PoPs.hpp"
#include "alpha/v2.0/general/Reactions.hpp"
#include "alpha/v2.0/general/ApplicationData.hpp"
#include "alpha/v2.0/general/ExternalFiles.hpp"
#include "alpha/v2.0/general/Resonances.hpp"
#include "alpha/v2.0/general/Sums.hpp"
#include "alpha/v2.0/general/Productions.hpp"
#include "alpha/v2.0/general/FissionComponents.hpp"
#include "alpha/v2.0/general/OrphanProducts.hpp"
#include "alpha/v2.0/general/IncompleteReactions.hpp"

namespace alpha {
namespace v2_0 {
namespace top {

// -----------------------------------------------------------------------------
// top::
// class ReactionSuite
// -----------------------------------------------------------------------------

class ReactionSuite :
   public Component<top::ReactionSuite>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "top"; }
   static auto CLASS() { return "ReactionSuite"; }
   static auto NODENAME() { return "reactionSuite"; }

   // Core Interface multi-query to transfer information to/from core Nodes
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
         --Child<general::Styles>
            ("styles") |
         --Child<top::PoPs>
            ("PoPs") |
         --Child<general::Reactions>
            ("reactions") |
         --Child<std::optional<general::ApplicationData>>
            ("applicationData") |
         --Child<std::optional<general::ExternalFiles>>
            ("externalFiles") |
         --Child<std::optional<general::Resonances>>
            ("resonances") |
         --Child<std::optional<general::Sums>>
            ("sums") |
         --Child<std::optional<general::Productions>>
            ("productions") |
         --Child<std::optional<general::FissionComponents>>
            ("fissionComponents") |
         --Child<std::optional<general::OrphanProducts>>
            ("orphanProducts") |
         --Child<std::optional<general::IncompleteReactions>>
            ("incompleteReactions")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "projectile",
         "target",
         "evaluation",
         "format",
         "projectileFrame",
         "interaction",
         "styles",
         "PoPs",
         "reactions",
         "applicationData",
         "externalFiles",
         "resonances",
         "sums",
         "productions",
         "fissionComponents",
         "orphanProducts",
         "incompleteReactions"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "projectile",
         "target",
         "evaluation",
         "format",
         "projectile_frame",
         "interaction",
         "styles",
         "po_ps",
         "reactions",
         "application_data",
         "external_files",
         "resonances",
         "sums",
         "productions",
         "fission_components",
         "orphan_products",
         "incomplete_reactions"
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
      projectile{this};
   Field<std::string>
      target{this};
   Field<std::string>
      evaluation{this};
   Field<std::string>
      format{this};
   Field<std::string>
      projectileFrame{this};
   Field<std::string>
      interaction{this};

   // children
   Field<general::Styles>
      styles{this};
   Field<top::PoPs>
      PoPs{this};
   Field<general::Reactions>
      reactions{this};
   Field<std::optional<general::ApplicationData>>
      applicationData{this};
   Field<std::optional<general::ExternalFiles>>
      externalFiles{this};
   Field<std::optional<general::Resonances>>
      resonances{this};
   Field<std::optional<general::Sums>>
      sums{this};
   Field<std::optional<general::Productions>>
      productions{this};
   Field<std::optional<general::FissionComponents>>
      fissionComponents{this};
   Field<std::optional<general::OrphanProducts>>
      orphanProducts{this};
   Field<std::optional<general::IncompleteReactions>>
      incompleteReactions{this};

   // shortcuts
   #define GNDSTK_SHORTCUT(to,name) decltype(to.name) &name = to.name
   GNDSTK_SHORTCUT(PoPs(),aliases);
   GNDSTK_SHORTCUT(PoPs(),baryons);
   GNDSTK_SHORTCUT(PoPs(),chemicalElements);
   GNDSTK_SHORTCUT(styles().evaluated(),documentation);
   GNDSTK_SHORTCUT(PoPs(),gaugeBosons);
   GNDSTK_SHORTCUT(PoPs(),leptons);
   GNDSTK_SHORTCUT(styles().evaluated(),projectileEnergyDomain);
   GNDSTK_SHORTCUT(styles().evaluated(),temperature);
   GNDSTK_SHORTCUT(PoPs(),unorthodoxes);
   #undef GNDSTK_SHORTCUT

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
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
      this->incompleteReactions \
   )

   // default
   ReactionSuite() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ReactionSuite(
      const wrapper<std::string>
         &projectile,
      const wrapper<std::string>
         &target = {},
      const wrapper<std::string>
         &evaluation = {},
      const wrapper<std::string>
         &format = {},
      const wrapper<std::string>
         &projectileFrame = {},
      const wrapper<std::string>
         &interaction = {},
      const wrapper<general::Styles>
         &styles = {},
      const wrapper<top::PoPs>
         &PoPs = {},
      const wrapper<general::Reactions>
         &reactions = {},
      const wrapper<std::optional<general::ApplicationData>>
         &applicationData = {},
      const wrapper<std::optional<general::ExternalFiles>>
         &externalFiles = {},
      const wrapper<std::optional<general::Resonances>>
         &resonances = {},
      const wrapper<std::optional<general::Sums>>
         &sums = {},
      const wrapper<std::optional<general::Productions>>
         &productions = {},
      const wrapper<std::optional<general::FissionComponents>>
         &fissionComponents = {},
      const wrapper<std::optional<general::OrphanProducts>>
         &orphanProducts = {},
      const wrapper<std::optional<general::IncompleteReactions>>
         &incompleteReactions = {}
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

   // copy
   ReactionSuite &operator=(const ReactionSuite &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         projectile = other.projectile;
         target = other.target;
         evaluation = other.evaluation;
         format = other.format;
         projectileFrame = other.projectileFrame;
         interaction = other.interaction;
         styles = other.styles;
         PoPs = other.PoPs;
         reactions = other.reactions;
         applicationData = other.applicationData;
         externalFiles = other.externalFiles;
         resonances = other.resonances;
         sums = other.sums;
         productions = other.productions;
         fissionComponents = other.fissionComponents;
         orphanProducts = other.orphanProducts;
         incompleteReactions = other.incompleteReactions;
      }
      return *this;
   }

   // move
   ReactionSuite &operator=(ReactionSuite &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         projectile = std::move(other.projectile);
         target = std::move(other.target);
         evaluation = std::move(other.evaluation);
         format = std::move(other.format);
         projectileFrame = std::move(other.projectileFrame);
         interaction = std::move(other.interaction);
         styles = std::move(other.styles);
         PoPs = std::move(other.PoPs);
         reactions = std::move(other.reactions);
         applicationData = std::move(other.applicationData);
         externalFiles = std::move(other.externalFiles);
         resonances = std::move(other.resonances);
         sums = std::move(other.sums);
         productions = std::move(other.productions);
         fissionComponents = std::move(other.fissionComponents);
         orphanProducts = std::move(other.orphanProducts);
         incompleteReactions = std::move(other.incompleteReactions);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/top/ReactionSuite/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ReactionSuite

} // namespace top
} // namespace v2_0
} // namespace alpha

#endif
