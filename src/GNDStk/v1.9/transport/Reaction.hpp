
// THIS FILE WAS AUTOGENERATED!
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

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "transport"; }
   static auto className() { return "Reaction"; }
   static auto GNDSName() { return "reaction"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         int{}
            / Meta<>("ENDF_MT") |
         std::optional<std::string>{}
            / Meta<>("fissionGenre") |
         std::string{}
            / Meta<>("label") |
         // children
         transport::CrossSection{}
            / --Child<>("crossSection")
      ;
   }

public:

   using Component::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static inline const struct Defaults {
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      int ENDF_MT;
      std::optional<std::string> fissionGenre;
      std::string label;
      // children
      transport::CrossSection crossSection;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // ENDF_MT
   const int &ENDF_MT() const
      { return content.ENDF_MT; }
   int &ENDF_MT()
      { return content.ENDF_MT; }

   // fissionGenre
   const std::optional<std::string> &fissionGenre() const
      { return content.fissionGenre; }
   std::optional<std::string> &fissionGenre()
      { return content.fissionGenre; }

   // label
   const std::string &label() const
      { return content.label; }
   std::string &label()
      { return content.label; }

   // crossSection
   const transport::CrossSection &crossSection() const
      { return content.crossSection; }
   transport::CrossSection &crossSection()
      { return content.crossSection; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // ENDF_MT(value)
   Reaction &ENDF_MT(const int &obj)
      { ENDF_MT() = obj; return *this; }

   // fissionGenre(value)
   Reaction &fissionGenre(const std::optional<std::string> &obj)
      { fissionGenre() = obj; return *this; }

   // label(value)
   Reaction &label(const std::string &obj)
      { label() = obj; return *this; }

   // crossSection(value)
   Reaction &crossSection(const transport::CrossSection &obj)
      { crossSection() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Reaction() :
      Component{
         BodyText{},
         content.ENDF_MT,
         content.fissionGenre,
         content.label,
         content.crossSection
      }
   {
      Component::finish();
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
      Component::finish(other);
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
      Component::finish(other);
   }

   // from node
   Reaction(const Node &node) :
      Component{
         BodyText{},
         content.ENDF_MT,
         content.fissionGenre,
         content.label,
         content.crossSection
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Reaction(
      const int &ENDF_MT,
      const std::optional<std::string> &fissionGenre,
      const std::string &label,
      const transport::CrossSection &crossSection
   ) :
      Component{
         BodyText{},
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
      Component::finish();
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
