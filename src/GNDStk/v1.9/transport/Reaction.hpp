#ifndef NJOY_GNDSTK_V1_9_TRANSPORT_REACTION
#define NJOY_GNDSTK_V1_9_TRANSPORT_REACTION

// system includes

// other includes
#include "GNDStk.hpp"
#include "GNDStk/v1.9/transport/CrossSection.hpp"

namespace njoy {
namespace GNDStk {

using namespace njoy::GNDStk::core;

namespace v1_9 {
namespace transport {

class Reaction : public Component<Reaction> {

   // ------------------------
   // for Component
   // ------------------------

   friend class Component<Reaction>;

   static auto className() { return "Reaction"; }
   static auto GNDSField() { return "reaction"; }
   static auto keys()
   {
      return
         // metadata
         Integer32{}
            / Meta<>("ENDF_MT") |
         std::optional<XMLName>{}
            / Meta<>("fissionGenre") |
         XMLName{}
            / Meta<>("label") |
         // children
         transport::CrossSection{}
            / --Child<>("crossSection")
      ;
   }

public:

   // ------------------------
   // raw GNDS content
   // ------------------------

   struct {
      // metadata
      Integer32 ENDF_MT;
      std::optional<XMLName> fissionGenre;
      XMLName label;

      // children
      transport::CrossSection crossSection;
   } content;

   // ------------------------
   // getters
   // ------------------------

   // metadata
   const auto &ENDF_MT() const
    { return content.ENDF_MT; }
   const auto &fissionGenre() const
    { return content.fissionGenre; }
   const auto &label() const
    { return content.label; }

   // children
   const auto &crossSection() const
    { return content.crossSection; }

   // ------------------------
   // constructors
   // ------------------------

   // default
   Reaction() :
      Component{
         content.ENDF_MT,
         content.fissionGenre,
         content.label,
         content.crossSection
      }
   {
      Component::construct();
   }

   // copy
   Reaction(const Reaction &other) :
      Component{
         content.ENDF_MT,
         content.fissionGenre,
         content.label,
         content.crossSection
      },
      content{other.content}
   {
      Component::construct();
   }

   // node
   Reaction(const Node &node) :
      Reaction{}
   {
      Component::query(node);
      Component::construct();
   }

   // fields
   explicit Reaction(
      const Integer32 &ENDF_MT,
      const std::optional<XMLName> &fissionGenre,
      const XMLName &label,
      const transport::CrossSection &crossSection
   ) :
      Component{
         content.ENDF_MT,
         content.fissionGenre,
         content.label,
         content.crossSection
      },
      content{
         ENDF_MT,
         fissionGenre,
         label,
         crossSection
      }
   {
      Component::construct();
   }

   // ------------------------
   // assignment: copy, move
   // ------------------------

   Reaction &operator=(const Reaction &) = default;
   Reaction &operator=(Reaction &&) = default;

   // ------------------------
   // custom functionality
   // ------------------------

   #include "GNDStk/v1.9/transport/Reaction/src/custom.hpp"

}; // class Reaction

} // transport namespace
} // v1_9 namespace
} // GNDStk namespace
} // njoy namespace

#endif
