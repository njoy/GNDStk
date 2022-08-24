
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_TRANSPORT_PRODUCTION
#define NJOY_GNDSTK_V2_0_TRANSPORT_PRODUCTION

// core interface
#include "GNDStk.hpp"

// v2.0 dependencies
#include "GNDStk/v2.0/transport/CrossSection.hpp"
#include "GNDStk/v2.0/transport/OutputChannel.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// transport::
// class Production
// -----------------------------------------------------------------------------

namespace transport {

class Production : public Component<Production> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "transport"; }
   static auto className() { return "Production"; }
   static auto GNDSName() { return "production"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         std::optional<Integer32>{}
            / Meta<>("ENDF_MT") |
         std::optional<XMLName>{}
            / Meta<>("label") |
         // children
         std::optional<transport::CrossSection>{}
            / --Child<>("crossSection") |
         std::optional<transport::OutputChannel>{}
            / --Child<>("outputChannel")
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
      std::optional<Integer32> ENDF_MT;
      std::optional<XMLName> label;
      // children
      std::optional<transport::CrossSection> crossSection;
      std::optional<transport::OutputChannel> outputChannel;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // ENDF_MT
   const std::optional<Integer32> &ENDF_MT() const
      { return content.ENDF_MT; }
   std::optional<Integer32> &ENDF_MT()
      { return content.ENDF_MT; }

   // label
   const std::optional<XMLName> &label() const
      { return content.label; }
   std::optional<XMLName> &label()
      { return content.label; }

   // crossSection
   const std::optional<transport::CrossSection> &crossSection() const
      { return content.crossSection; }
   std::optional<transport::CrossSection> &crossSection()
      { return content.crossSection; }

   // outputChannel
   const std::optional<transport::OutputChannel> &outputChannel() const
      { return content.outputChannel; }
   std::optional<transport::OutputChannel> &outputChannel()
      { return content.outputChannel; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // ENDF_MT(value)
   Production &ENDF_MT(const std::optional<Integer32> &obj)
      { ENDF_MT() = obj; return *this; }

   // label(value)
   Production &label(const std::optional<XMLName> &obj)
      { label() = obj; return *this; }

   // crossSection(value)
   Production &crossSection(const std::optional<transport::CrossSection> &obj)
      { crossSection() = obj; return *this; }

   // outputChannel(value)
   Production &outputChannel(const std::optional<transport::OutputChannel> &obj)
      { outputChannel() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Production() :
      Component{
         BodyText{},
         content.ENDF_MT,
         content.label,
         content.crossSection,
         content.outputChannel
      }
   {
      Component::finish();
   }

   // copy
   Production(const Production &other) :
      Component{
         other,
         content.ENDF_MT,
         content.label,
         content.crossSection,
         content.outputChannel
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Production(Production &&other) :
      Component{
         other,
         content.ENDF_MT,
         content.label,
         content.crossSection,
         content.outputChannel
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Production(const Node &node) :
      Component{
         BodyText{},
         content.ENDF_MT,
         content.label,
         content.crossSection,
         content.outputChannel
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Production(
      const std::optional<Integer32> &ENDF_MT,
      const std::optional<XMLName> &label,
      const std::optional<transport::CrossSection> &crossSection,
      const std::optional<transport::OutputChannel> &outputChannel
   ) :
      Component{
         BodyText{},
         content.ENDF_MT,
         content.label,
         content.crossSection,
         content.outputChannel
      },
      content{
         ENDF_MT,
         label,
         crossSection,
         outputChannel
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Production &operator=(const Production &) = default;

   // move
   Production &operator=(Production &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/transport/Production/src/custom.hpp"

}; // class Production

} // namespace transport
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif