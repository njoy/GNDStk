
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

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      std::string evaluation;
      std::string format;
      std::string projectile;
      enums::Frame projectileFrame;
      std::string target;
      std::optional<enums::Interaction> interaction;
      // children
      std::optional<transport::Reactions> reactions;
   } Content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // evaluation
   const std::string &evaluation() const
      { return Content.evaluation; }
   std::string &evaluation()
      { return Content.evaluation; }

   // format
   const std::string &format() const
      { return Content.format; }
   std::string &format()
      { return Content.format; }

   // projectile
   const std::string &projectile() const
      { return Content.projectile; }
   std::string &projectile()
      { return Content.projectile; }

   // projectileFrame
   const enums::Frame &projectileFrame() const
      { return Content.projectileFrame; }
   enums::Frame &projectileFrame()
      { return Content.projectileFrame; }

   // target
   const std::string &target() const
      { return Content.target; }
   std::string &target()
      { return Content.target; }

   // interaction
   const std::optional<enums::Interaction> &interaction() const
      { return Content.interaction; }
   std::optional<enums::Interaction> &interaction()
      { return Content.interaction; }

   // reactions
   const std::optional<transport::Reactions> &reactions() const
      { return Content.reactions; }
   std::optional<transport::Reactions> &reactions()
      { return Content.reactions; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // evaluation(value)
   ReactionSuite &evaluation(const std::string &obj)
      { evaluation() = obj; return *this; }

   // format(value)
   ReactionSuite &format(const std::string &obj)
      { format() = obj; return *this; }

   // projectile(value)
   ReactionSuite &projectile(const std::string &obj)
      { projectile() = obj; return *this; }

   // projectileFrame(value)
   ReactionSuite &projectileFrame(const enums::Frame &obj)
      { projectileFrame() = obj; return *this; }

   // target(value)
   ReactionSuite &target(const std::string &obj)
      { target() = obj; return *this; }

   // interaction(value)
   ReactionSuite &interaction(const std::optional<enums::Interaction> &obj)
      { interaction() = obj; return *this; }

   // reactions(value)
   ReactionSuite &reactions(const std::optional<transport::Reactions> &obj)
      { reactions() = obj; return *this; }

   // ------------------------
   // Constructors
   // ------------------------

   // default, and from fields
   explicit ReactionSuite(
      const std::string &evaluation =
         std::string{},
      const std::string &format =
         std::string{},
      const std::string &projectile =
         std::string{},
      const enums::Frame &projectileFrame =
         enums::Frame{},
      const std::string &target =
         std::string{},
      const std::optional<enums::Interaction> &interaction =
         std::optional<enums::Interaction>{},
      const std::optional<transport::Reactions> &reactions =
         std::optional<transport::Reactions>{}
   ) :
      Component{
         BlockData{},
         this->evaluation(),
         this->format(),
         this->projectile(),
         this->projectileFrame(),
         this->target(),
         this->interaction(),
         this->reactions()
      },
      Content{
         evaluation,
         format,
         projectile,
         projectileFrame,
         target,
         interaction,
         reactions
      }
   {
      Component::finish();
   }

   // copy
   ReactionSuite(const ReactionSuite &other) :
      Component{
         other.baseBlockData(),
         this->evaluation(),
         this->format(),
         this->projectile(),
         this->projectileFrame(),
         this->target(),
         this->interaction(),
         this->reactions()
      },
      Content{other.Content}
   {
      Component::finish(other);
   }

   // move
   ReactionSuite(ReactionSuite &&other) :
      Component{
         other.baseBlockData(),
         this->evaluation(),
         this->format(),
         this->projectile(),
         this->projectileFrame(),
         this->target(),
         this->interaction(),
         this->reactions()
      },
      Content{std::move(other.Content)}
   {
      Component::finish(other);
   }

   // from node
   ReactionSuite(const Node &node) :
      Component{
         BlockData{},
         this->evaluation(),
         this->format(),
         this->projectile(),
         this->projectileFrame(),
         this->target(),
         this->interaction(),
         this->reactions()
      }
   {
      Component::finish(node);
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
