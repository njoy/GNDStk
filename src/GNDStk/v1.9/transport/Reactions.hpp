
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
   // for Component
   // ------------------------

   friend class Component<Reactions>;

   static auto namespaceName() { return "transport"; }
   static auto className() { return "Reactions"; }
   static auto GNDSName() { return "reactions"; }

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
   // relevant defaults
   // FYI for users
   // ------------------------

   static const struct {
   } defaults;

   // ------------------------
   // raw GNDS content
   // ------------------------

   struct {
      // children
      std::vector<transport::Reaction> reaction;
   } content;

   // ------------------------
   // getters
   // const and non-const
   // ------------------------

   // reaction
   const auto &reaction() const
    { return content.reaction; }
   auto &reaction()
    { return content.reaction; }

   // reaction(n)
   const auto &reaction(const std::size_t n) const
    { return detail::getter(reaction(),n,namespaceName(),className(),"reaction"); }
   auto &reaction(const std::size_t n)
    { return detail::getter(reaction(),n,namespaceName(),className(),"reaction"); }

   // reaction(label)
   const auto &reaction(const std::string &label) const
    { return detail::getter(reaction(),label,namespaceName(),className(),"reaction"); }
   auto &reaction(const std::string &label)
    { return detail::getter(reaction(),label,namespaceName(),className(),"reaction"); }

   // ------------------------
   // setters
   // non-const only
   // ------------------------

   // reaction
   auto &reaction(const std::vector<transport::Reaction> &obj)
    { content.reaction = obj; return *this; }

   // ------------------------
   // construction
   // ------------------------

   // default
   Reactions() :
      Component{
         content.reaction
      }
   {
      construct();
   }

   // copy
   Reactions(const Reactions &other) :
      Component{
         content.reaction
      },
      content{other.content}
   {
      construct(other);
   }

   // move
   Reactions(Reactions &&other) :
      Component{
         content.reaction
      },
      content{std::move(other.content)}
   {
      construct(other);
   }

   // from node
   Reactions(const Node &node) :
      Component{
         content.reaction
      }
   {
      query(node);
      construct(node);
   }

   // from fields
   explicit Reactions(
      const std::vector<transport::Reaction> &reaction
   ) :
      Component{
         content.reaction
      },
      content{
         reaction
      }
   {
      construct();
   }

   // ------------------------
   // assignment
   // ------------------------

   // copy
   Reactions &operator=(const Reactions &) = default;

   // move
   Reactions &operator=(Reactions &&) = default;

   // ------------------------
   // custom functionality
   // ------------------------

   #include "GNDStk/v1.9/transport/Reactions/src/custom.hpp"

}; // class Reactions

} // namespace transport

} // namespace v1_9
} // namespace GNDStk
} // namespace njoy

#endif
