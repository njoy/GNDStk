
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V1_9_TRANSPORT_REACTION
#define NJOY_GNDSTK_V1_9_TRANSPORT_REACTION

// core interface
#include "GNDStk.hpp"

// v1.9 dependencies
#include "GNDStk/v1.9/transport/CrossSection.hpp"

namespace njoy {
namespace GNDStk {
namespace v1_9 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// transport::
// class Reaction
// -----------------------------------------------------------------------------

namespace transport {

class Reaction : public Component<Reaction> {

   // ------------------------
   // For Component
   // ------------------------

   friend class Component<Reaction>;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "transport"; }
   static auto className() { return "Reaction"; }
   static auto GNDSName() { return "reaction"; }

   // Core Interface construct to extract metadata and child nodes
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

   // Base classes
   using BaseComponent = Component<Reaction>;
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
      // metadata
      Integer32 ENDF_MT;
      std::optional<XMLName> fissionGenre;
      XMLName label;

      // children
      transport::CrossSection crossSection;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // ENDF_MT
   const auto &ENDF_MT() const
    { return content.ENDF_MT; }
   auto &ENDF_MT()
    { return content.ENDF_MT; }

   // fissionGenre
   const auto &fissionGenre() const
    { return content.fissionGenre; }
   auto &fissionGenre()
    { return content.fissionGenre; }

   // label
   const auto &label() const
    { return content.label; }
   auto &label()
    { return content.label; }

   // crossSection
   const auto &crossSection() const
    { return content.crossSection; }
   auto &crossSection()
    { return content.crossSection; }

   // ------------------------
   // Setters
   // non-const
   // ------------------------

   // ENDF_MT
   auto &ENDF_MT(const Integer32 &obj)
    { content.ENDF_MT = obj; return *this; }

   // fissionGenre
   auto &fissionGenre(const std::optional<XMLName> &obj)
    { content.fissionGenre = obj; return *this; }

   // label
   auto &label(const XMLName &obj)
    { content.label = obj; return *this; }

   // crossSection
   auto &crossSection(const transport::CrossSection &obj)
    { content.crossSection = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Reaction() :
      Component{
         BaseBodyText{},
         content.ENDF_MT,
         content.fissionGenre,
         content.label,
         content.crossSection
      }
   {
      bodyTextUpdate(content);
      construct();
   }

   // copy
   Reaction(const Reaction &other) :
      Component{
         other,
         content.ENDF_MT,
         content.fissionGenre,
         content.label,
         content.crossSection
      },
      content{other.content}
   {
      bodyTextUpdate(content);
      construct(other);
   }

   // move
   Reaction(Reaction &&other) :
      Component{
         other,
         content.ENDF_MT,
         content.fissionGenre,
         content.label,
         content.crossSection
      },
      content{std::move(other.content)}
   {
      bodyTextUpdate(content);
      construct(other);
   }

   // from node
   Reaction(const Node &node) :
      Component{
         BaseBodyText{},
         content.ENDF_MT,
         content.fissionGenre,
         content.label,
         content.crossSection
      }
   {
      fromNode(node);
      bodyTextUpdate(content);
      construct(node);
   }

   // from fields
   explicit Reaction(
      const Integer32 &ENDF_MT,
      const std::optional<XMLName> &fissionGenre,
      const XMLName &label,
      const transport::CrossSection &crossSection
   ) :
      Component{
         BaseBodyText{},
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
      bodyTextUpdate(content);
      construct();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Reaction &operator=(const Reaction &) = default;

   // move
   Reaction &operator=(Reaction &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v1.9/transport/Reaction/src/custom.hpp"

}; // class Reaction

} // namespace transport

} // namespace v1_9
} // namespace GNDStk
} // namespace njoy

#endif
