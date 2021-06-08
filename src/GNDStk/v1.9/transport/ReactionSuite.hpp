
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

   friend class Component<ReactionSuite>;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "transport"; }
   static auto className() { return "ReactionSuite"; }
   static auto GNDSName() { return "reactionSuite"; }

   // Core Interface construct to extract metadata and child nodes
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

   // Base classes
   using BaseComponent = Component<ReactionSuite>;
   using BaseBodyText = BodyText<false>;

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
   const auto &evaluation() const
    { return content.evaluation; }
   auto &evaluation()
    { return content.evaluation; }

   // format
   const auto &format() const
    { return content.format; }
   auto &format()
    { return content.format; }

   // interaction
   const auto &interaction() const
    { return content.interaction; }
   auto &interaction()
    { return content.interaction; }

   // projectile
   const auto &projectile() const
    { return content.projectile; }
   auto &projectile()
    { return content.projectile; }

   // projectileFrame
   const auto &projectileFrame() const
    { return content.projectileFrame; }
   auto &projectileFrame()
    { return content.projectileFrame; }

   // target
   const auto &target() const
    { return content.target; }
   auto &target()
    { return content.target; }

   // reactions
   const auto &reactions() const
    { return content.reactions; }
   auto &reactions()
    { return content.reactions; }

   // ------------------------
   // Setters
   // non-const
   // ------------------------

   // evaluation
   auto &evaluation(const XMLName &obj)
    { content.evaluation = obj; return *this; }

   // format
   auto &format(const XMLName &obj)
    { content.format = obj; return *this; }

   // interaction
   auto &interaction(const std::optional<enums::Interaction> &obj)
    { content.interaction = obj; return *this; }

   // projectile
   auto &projectile(const XMLName &obj)
    { content.projectile = obj; return *this; }

   // projectileFrame
   auto &projectileFrame(const enums::Frame &obj)
    { content.projectileFrame = obj; return *this; }

   // target
   auto &target(const XMLName &obj)
    { content.target = obj; return *this; }

   // reactions
   auto &reactions(const std::optional<transport::Reactions> &obj)
    { content.reactions = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   ReactionSuite() :
      Component{
         BaseBodyText{},
         content.evaluation,
         content.format,
         content.interaction,
         content.projectile,
         content.projectileFrame,
         content.target,
         content.reactions
      }
   {
      bodyTextUpdate(content);
      construct();
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
      bodyTextUpdate(content);
      construct(other);
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
      bodyTextUpdate(content);
      construct(other);
   }

   // from node
   ReactionSuite(const Node &node) :
      Component{
         BaseBodyText{},
         content.evaluation,
         content.format,
         content.interaction,
         content.projectile,
         content.projectileFrame,
         content.target,
         content.reactions
      }
   {
      fromNode(node);
      bodyTextUpdate(content);
      construct(node);
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
         BaseBodyText{},
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
      bodyTextUpdate(content);
      construct();
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
