
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V1_9_TRANSPORT_REACTIONS
#define NJOY_GNDSTK_V1_9_TRANSPORT_REACTIONS

// core interface
#include "GNDStk.hpp"

// v1.9 dependencies
#include "GNDStk/v1.9/transport/Reaction.hpp"

namespace njoy {
namespace GNDStk {
namespace v1_9 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// transport::
// class Reactions
// -----------------------------------------------------------------------------

namespace transport {

class Reactions : public Component<Reactions> {

   // ------------------------
   // For Component
   // ------------------------

   friend class Component<Reactions>;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "transport"; }
   static auto className() { return "Reactions"; }
   static auto GNDSName() { return "reactions"; }

   // Core Interface construct to extract metadata and child nodes
   static auto keys()
   {
      return
         // children
         transport::Reaction{}
            / ++Child<>("reaction")
      ;
   }

public:

   // ------------------------
   // Re: base classes
   // ------------------------

   using BaseComponent = Component<Reactions>;
   using BaseBodyText = BodyText<false>;
   using BaseComponent::construct;

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
      // children
      std::vector<transport::Reaction> reaction;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // reaction
   const auto &reaction() const
    { return content.reaction; }
   auto &reaction()
    { return content.reaction; }

   // reaction(index)
   const auto &reaction(const std::size_t index) const
    { return getter(reaction(), index, "reaction"); }
   auto &reaction(const std::size_t index)
    { return getter(reaction(), index, "reaction"); }

   // reaction(label)
   const auto &reaction(const std::string &label) const
    { return getter(reaction(), label, "reaction"); }
   auto &reaction(const std::string &label)
    { return getter(reaction(), label, "reaction"); }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // reaction(value)
   auto &reaction(const std::vector<transport::Reaction> &obj)
    { reaction() = obj; return *this; }

   // reaction(index,value)
   auto &reaction(
      const std::size_t index,
      const transport::Reaction &obj
   ) {
      reaction(index) = obj; return *this;
   }

   // reaction(label,value)
   auto &reaction(
      const std::string &label,
      const transport::Reaction &obj
   ) {
      reaction(label) = obj; return *this;
   }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Reactions() :
      Component{
         BaseBodyText{},
         content.reaction
      }
   {
      bodyTextUpdate(content);
      construct();
   }

   // copy
   Reactions(const Reactions &other) :
      Component{
         other,
         content.reaction
      },
      content{other.content}
   {
      bodyTextUpdate(content);
      construct(other);
   }

   // move
   Reactions(Reactions &&other) :
      Component{
         other,
         content.reaction
      },
      content{std::move(other.content)}
   {
      bodyTextUpdate(content);
      construct(other);
   }

   // from node
   Reactions(const Node &node) :
      Component{
         BaseBodyText{},
         content.reaction
      }
   {
      fromNode(node);
      bodyTextUpdate(content);
      construct(node);
   }

   // from fields
   explicit Reactions(
      const std::vector<transport::Reaction> &reaction
   ) :
      Component{
         BaseBodyText{},
         content.reaction
      },
      content{
         reaction
      }
   {
      bodyTextUpdate(content);
      construct();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Reactions &operator=(const Reactions &) = default;

   // move
   Reactions &operator=(Reactions &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v1.9/transport/Reactions/src/custom.hpp"

}; // class Reactions

} // namespace transport

} // namespace v1_9
} // namespace GNDStk
} // namespace njoy

#endif
