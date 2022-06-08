
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDSTK_V1_9_TRANSPORT_REACTIONSUITE
#define GNDSTK_V1_9_TRANSPORT_REACTIONSUITE

#include "GNDStk/v1.9/key.hpp"
#include "GNDStk/v1.9/transport/Reactions.hpp"

namespace njoy {
namespace GNDStk {
namespace v1_9 {


// -----------------------------------------------------------------------------
// transport::
// class ReactionSuite
// -----------------------------------------------------------------------------

namespace transport {

class ReactionSuite : public Component<transport::ReactionSuite> {

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Names: this namespace, this class, a field / node of this type
   static auto NAMESPACE() { return "transport"; }
   static auto CLASS() { return "ReactionSuite"; }
   static auto FIELD() { return "reactionSuite"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::string{}
            / Meta<>("evaluation") |
         std::string{}
            / Meta<>("format") |
         std::string{}
            / Meta<>("projectile") |
         enums::Frame{}
            / Meta<>("projectileFrame") |
         std::string{}
            / Meta<>("target") |
         std::optional<enums::Interaction>{}
            / Meta<>("interaction") |
         // children
         std::optional<transport::Reactions>{}
            / --Child<>("reactions")
      ;
   }

public:

   using Component::construct;

   // metadata
   Field<ReactionSuite,std::string> evaluation;
   Field<ReactionSuite,std::string> format;
   Field<ReactionSuite,std::string> projectile;
   Field<ReactionSuite,enums::Frame> projectileFrame;
   Field<ReactionSuite,std::string> target;
   Field<ReactionSuite,std::optional<enums::Interaction>> interaction;
   // children
   Field<ReactionSuite,std::optional<transport::Reactions>> reactions;

   // ------------------------
   // Constructors
   // ------------------------

   // default, and from fields
   explicit ReactionSuite(
      const std::string &evaluation = {},
      const std::string &format = {},
      const std::string &projectile = {},
      const enums::Frame &projectileFrame = {},
      const std::string &target = {},
      const std::optional<enums::Interaction> &interaction = {},
      const std::optional<transport::Reactions> &reactions = {}
   ) :
      Component{
         BlockData{},
         this->evaluation,
         this->format,
         this->projectile,
         this->projectileFrame,
         this->target,
         this->interaction,
         this->reactions
      },
      evaluation(this,evaluation,"evaluation"),
      format(this,format,"format"),
      projectile(this,projectile,"projectile"),
      projectileFrame(this,projectileFrame,"projectileFrame"),
      target(this,target,"target"),
      interaction(this,interaction,"interaction"),
      reactions(this,reactions,"reactions")
   {
      Component::finish();
   }

   // copy
   ReactionSuite(const ReactionSuite &other) :
      Component{
         other.baseBlockData(),
         this->evaluation,
         this->format,
         this->projectile,
         this->projectileFrame,
         this->target,
         this->interaction,
         this->reactions
      },
      evaluation(this,other.evaluation),
      format(this,other.format),
      projectile(this,other.projectile),
      projectileFrame(this,other.projectileFrame),
      target(this,other.target),
      interaction(this,other.interaction),
      reactions(this,other.reactions)
   {
      Component::finish(other);
   }

   // move
   ReactionSuite(ReactionSuite &&other) :
      Component{
         other.baseBlockData(),
         this->evaluation,
         this->format,
         this->projectile,
         this->projectileFrame,
         this->target,
         this->interaction,
         this->reactions
      },
      evaluation(this,std::move(other.evaluation)),
      format(this,std::move(other.format)),
      projectile(this,std::move(other.projectile)),
      projectileFrame(this,std::move(other.projectileFrame)),
      target(this,std::move(other.target)),
      interaction(this,std::move(other.interaction)),
      reactions(this,std::move(other.reactions))
   {
      Component::finish(other);
   }

   // from node
   ReactionSuite(const Node &node) :
      Component{
         BlockData{},
         this->evaluation,
         this->format,
         this->projectile,
         this->projectileFrame,
         this->target,
         this->interaction,
         this->reactions
      },
      evaluation(this,{},"evaluation"),
      format(this,{},"format"),
      projectile(this,{},"projectile"),
      projectileFrame(this,{},"projectileFrame"),
      target(this,{},"target"),
      interaction(this,{},"interaction"),
      reactions(this,{},"reactions")
   {
      Component::finish(node);
   }

   // ------------------------
   // Assignment
   // ------------------------

   ReactionSuite &operator=(const ReactionSuite &) = default;
   ReactionSuite &operator=(ReactionSuite &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v1.9/transport/ReactionSuite/src/custom.hpp"

}; // class ReactionSuite

} // namespace transport
} // namespace v1_9
} // namespace GNDStk
} // namespace njoy

#endif
