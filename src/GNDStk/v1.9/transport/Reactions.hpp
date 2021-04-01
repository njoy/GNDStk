#ifndef NJOY_GNDSTK_V1_9_TRANSPORT_REACTIONS
#define NJOY_GNDSTK_V1_9_TRANSPORT_REACTIONS

// system includes

// other includes
#include "GNDStk.hpp"
#include "GNDStk/v1.9/transport/Reaction.hpp"

namespace njoy {
namespace GNDStk {

using namespace njoy::GNDStk::core;

namespace v1_9 {
namespace transport {

class Reactions : public Component<Reactions> {

   // ------------------------
   // for Component
   // ------------------------

   friend class Component<Reactions>;

   static auto className() { return "Reactions"; }
   static auto GNDSField() { return "reactions"; }
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
   // raw GNDS content
   // ------------------------

   struct {
      // children
      std::vector<transport::Reaction> reaction;
   } content;

   // ------------------------
   // getters
   // ------------------------

   // children
   const auto &reaction() const
    { return content.reaction; }

   // ------------------------
   // constructors
   // ------------------------

   // default
   Reactions() :
      Component{
         content.reaction
      }
   {
      Component::construct();
   }

   // copy
   Reactions(const Reactions &other) :
      Component{
         content.reaction
      },
      content{other.content}
   {
      Component::construct();
   }

   // node
   Reactions(const Node &node) :
      Reactions{}
   {
      Component::query(node);
      Component::construct();
   }

   // fields
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
      Component::construct();
   }

   // ------------------------
   // assignment: copy, move
   // ------------------------

   Reactions &operator=(const Reactions &) = default;
   Reactions &operator=(Reactions &&) = default;

   // ------------------------
   // custom functionality
   // ------------------------

   #include "GNDStk/v1.9/transport/Reactions/src/custom.hpp"

}; // class Reactions

} // transport namespace
} // v1_9 namespace
} // GNDStk namespace
} // njoy namespace

#endif
