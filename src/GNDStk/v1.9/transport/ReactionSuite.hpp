
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
   // for Component
   // ------------------------

   friend class Component<ReactionSuite>;

   static auto className() { return "ReactionSuite"; }
   static auto GNDSField() { return "reactionSuite"; }

   static auto keys()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("evaluation") |
         XMLName{}
            / Meta<>("format") |
         enums::Interaction{}
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

   // ------------------------
   // relevant defaults
   // FYI for users
   // ------------------------

   static const struct {
   } defaults;

   // ------------------------
   // raw GNDS content
   // ------------------------

   struct {
      // metadata
      XMLName evaluation;
      XMLName format;
      enums::Interaction interaction;
      XMLName projectile;
      enums::Frame projectileFrame;
      XMLName target;

      // children
      std::optional<transport::Reactions> reactions;
   } content;

   // ------------------------
   // getters
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
   // setters
   // non-const only
   // ------------------------

   // evaluation
   auto &evaluation(const XMLName &obj)
    { content.evaluation = obj; return *this; }

   // format
   auto &format(const XMLName &obj)
    { content.format = obj; return *this; }

   // interaction
   auto &interaction(const enums::Interaction &obj)
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
   // construction
   // ------------------------

   // default
   ReactionSuite() :
      Component{
         content.evaluation,
         content.format,
         content.interaction,
         content.projectile,
         content.projectileFrame,
         content.target,
         content.reactions
      }
   {
      construct();
   }

   // copy
   ReactionSuite(const ReactionSuite &other) :
      Component{
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
      construct();
   }

   // move
   ReactionSuite(ReactionSuite &&other) :
      Component{
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
      construct();
   }

   // from node
   ReactionSuite(const Node &node) :
      Component{
         content.evaluation,
         content.format,
         content.interaction,
         content.projectile,
         content.projectileFrame,
         content.target,
         content.reactions
      }
   {
      query(node);
      construct();
   }

   // from fields
   explicit ReactionSuite(
      const XMLName &evaluation,
      const XMLName &format,
      const enums::Interaction &interaction,
      const XMLName &projectile,
      const enums::Frame &projectileFrame,
      const XMLName &target,
      const std::optional<transport::Reactions> &reactions
   ) :
      Component{
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
      construct();
   }

   // ------------------------
   // assignment
   // ------------------------

   // copy
   ReactionSuite &operator=(const ReactionSuite &) = default;

   // move
   ReactionSuite &operator=(ReactionSuite &&) = default;

   // ------------------------
   // custom functionality
   // ------------------------

   #include "GNDStk/v1.9/transport/ReactionSuite/src/custom.hpp"

}; // class ReactionSuite

} // namespace transport

} // namespace v1_9
} // namespace GNDStk
} // namespace njoy

#endif
