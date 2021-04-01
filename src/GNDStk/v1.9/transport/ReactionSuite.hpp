#ifndef NJOY_GNDSTK_V1_9_TRANSPORT_REACTIONSUITE
#define NJOY_GNDSTK_V1_9_TRANSPORT_REACTIONSUITE

// system includes

// other includes
#include "GNDStk.hpp"
#include "GNDStk/v1.9/transport/Reactions.hpp"

namespace njoy {
namespace GNDStk {

using namespace njoy::GNDStk::core;

namespace v1_9 {
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
         interaction_t{}
            / Meta<>("interaction") |
         XMLName{}
            / Meta<>("projectile") |
         frame_t{}
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
   // raw GNDS content
   // ------------------------

   struct {
      // metadata
      XMLName evaluation;
      XMLName format;
      interaction_t interaction;
      XMLName projectile;
      frame_t projectileFrame;
      XMLName target;

      // children
      std::optional<transport::Reactions> reactions;
   } content;

   // ------------------------
   // getters
   // ------------------------

   // metadata
   const auto &evaluation() const
    { return content.evaluation; }
   const auto &format() const
    { return content.format; }
   const auto &interaction() const
    { return content.interaction; }
   const auto &projectile() const
    { return content.projectile; }
   const auto &projectileFrame() const
    { return content.projectileFrame; }
   const auto &target() const
    { return content.target; }

   // children
   const auto &reactions() const
    { return content.reactions; }

   // ------------------------
   // constructors
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
      Component::construct();
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
      Component::construct();
   }

   // node
   ReactionSuite(const Node &node) :
      ReactionSuite{}
   {
      Component::query(node);
      Component::construct();
   }

   // fields
   explicit ReactionSuite(
      const XMLName &evaluation,
      const XMLName &format,
      const interaction_t &interaction,
      const XMLName &projectile,
      const frame_t &projectileFrame,
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
      Component::construct();
   }

   // ------------------------
   // assignment: copy, move
   // ------------------------

   ReactionSuite &operator=(const ReactionSuite &) = default;
   ReactionSuite &operator=(ReactionSuite &&) = default;

   // ------------------------
   // custom functionality
   // ------------------------

   #include "GNDStk/v1.9/transport/ReactionSuite/src/custom.hpp"

}; // class ReactionSuite

} // transport namespace
} // v1_9 namespace
} // GNDStk namespace
} // njoy namespace

#endif
