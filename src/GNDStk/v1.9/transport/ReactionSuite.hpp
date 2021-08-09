
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V1_9_TRANSPORT_REACTIONSUITE
#define NJOY_GNDSTK_V1_9_TRANSPORT_REACTIONSUITE

// core interface
#include "GNDStk.hpp"

// v1.9 dependencies
#include "GNDStk/v1.9/transport/Reactions.hpp"

namespace njoy {
namespace GNDStk {
namespace v1_9 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// transport::
// class ReactionSuite
// -----------------------------------------------------------------------------

namespace transport {

class ReactionSuite : public Component<ReactionSuite> {

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "transport"; }
   static auto className() { return "ReactionSuite"; }
   static auto GNDSName() { return "reactionSuite"; }

   // Core Interface object to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("evaluation") |
         XMLName{}
            / Meta<>("format") |
         std::optional<enums::Interaction>{}
            / Meta<>("interaction") |
         XMLName{}
            / Meta<>("projectile") |
         enums::Frame{}
            / Meta<>("projectileFrame") |
         XMLName{}
            / Meta<>("target") |
         // children
         std::optional<transport::Reactions>{}
            / --Child<>("reactions")
      ;
   }

public:

   using Component::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static const struct {
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      XMLName evaluation;
      XMLName format;
      std::optional<enums::Interaction> interaction;
      XMLName projectile;
      enums::Frame projectileFrame;
      XMLName target;

      // children
      std::optional<transport::Reactions> reactions;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // evaluation
   const XMLName &
   evaluation() const
    { return content.evaluation; }
   XMLName &
   evaluation()
    { return content.evaluation; }

   // format
   const XMLName &
   format() const
    { return content.format; }
   XMLName &
   format()
    { return content.format; }

   // interaction
   const std::optional<enums::Interaction> &
   interaction() const
    { return content.interaction; }
   std::optional<enums::Interaction> &
   interaction()
    { return content.interaction; }

   // projectile
   const XMLName &
   projectile() const
    { return content.projectile; }
   XMLName &
   projectile()
    { return content.projectile; }

   // projectileFrame
   const enums::Frame &
   projectileFrame() const
    { return content.projectileFrame; }
   enums::Frame &
   projectileFrame()
    { return content.projectileFrame; }

   // target
   const XMLName &
   target() const
    { return content.target; }
   XMLName &
   target()
    { return content.target; }

   // reactions
   const std::optional<transport::Reactions> &
   reactions() const
    { return content.reactions; }
   std::optional<transport::Reactions> &
   reactions()
    { return content.reactions; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // evaluation(value)
   auto &evaluation(const XMLName &obj)
    { evaluation() = obj; return *this; }

   // format(value)
   auto &format(const XMLName &obj)
    { format() = obj; return *this; }

   // interaction(value)
   auto &interaction(const std::optional<enums::Interaction> &obj)
    { interaction() = obj; return *this; }

   // projectile(value)
   auto &projectile(const XMLName &obj)
    { projectile() = obj; return *this; }

   // projectileFrame(value)
   auto &projectileFrame(const enums::Frame &obj)
    { projectileFrame() = obj; return *this; }

   // target(value)
   auto &target(const XMLName &obj)
    { target() = obj; return *this; }

   // reactions(value)
   auto &reactions(const std::optional<transport::Reactions> &obj)
    { reactions() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   ReactionSuite() :
      Component{
         BodyText{},
         content.evaluation,
         content.format,
         content.interaction,
         content.projectile,
         content.projectileFrame,
         content.target,
         content.reactions
      }
   {
      Component::finish();
   }

   // copy
   ReactionSuite(const ReactionSuite &other) :
      Component{
         other,
         content.evaluation,
         content.format,
         content.interaction,
         content.projectile,
         content.projectileFrame,
         content.target,
         content.reactions
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   ReactionSuite(ReactionSuite &&other) :
      Component{
         other,
         content.evaluation,
         content.format,
         content.interaction,
         content.projectile,
         content.projectileFrame,
         content.target,
         content.reactions
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   ReactionSuite(const Node &node) :
      Component{
         BodyText{},
         content.evaluation,
         content.format,
         content.interaction,
         content.projectile,
         content.projectileFrame,
         content.target,
         content.reactions
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit ReactionSuite(
      const XMLName &evaluation,
      const XMLName &format,
      const std::optional<enums::Interaction> &interaction,
      const XMLName &projectile,
      const enums::Frame &projectileFrame,
      const XMLName &target,
      const std::optional<transport::Reactions> &reactions
   ) :
      Component{
         BodyText{},
         content.evaluation,
         content.format,
         content.interaction,
         content.projectile,
         content.projectileFrame,
         content.target,
         content.reactions
      },
      content{
         evaluation,
         format,
         interaction,
         projectile,
         projectileFrame,
         target,
         reactions
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   ReactionSuite &operator=(const ReactionSuite &) = default;

   // move
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
