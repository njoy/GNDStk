
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V1_9_TRANSPORT_CROSSSECTION
#define NJOY_GNDSTK_V1_9_TRANSPORT_CROSSSECTION

// core interface
#include "GNDStk.hpp"

// v1.9 dependencies
#include "GNDStk/v1.9/containers/XYs1d.hpp"
#include "GNDStk/v1.9/containers/Regions1d.hpp"

namespace njoy {
namespace GNDStk {
namespace v1_9 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// transport::
// class CrossSection
// -----------------------------------------------------------------------------

namespace transport {

class CrossSection : public Component<CrossSection> {

   using VARIANT = std::variant<
      containers::XYs1d,
      containers::Regions1d
   >;

   // ------------------------
   // For Component
   // ------------------------

   friend class Component<CrossSection>;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "transport"; }
   static auto className() { return "CrossSection"; }
   static auto GNDSName() { return "crossSection"; }

   // Core Interface construct to extract metadata and child nodes
   static auto keys()
   {
      return
         // children
         VARIANT{}
            / ++Child<>("XYs1d regions1d")
      ;
   }

public:

   // Base classes
   using BaseComponent = Component<CrossSection>;
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
      std::vector<VARIANT> choice;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // choice
   const auto &choice() const
    { return content.choice; }
   auto &choice()
    { return content.choice; }

   // choice(n)
   const auto &choice(const std::size_t n) const
    { return getter(choice(),n,"choice"); }
   auto &choice(const std::size_t n)
    { return getter(choice(),n,"choice"); }

   // choice(label)
   const auto &choice(const std::string &label) const
    { return getter(choice(),label,"choice"); }
   auto &choice(const std::string &label)
    { return getter(choice(),label,"choice"); }

   // optional XYs1d(n)
   auto XYs1d(const std::size_t n) const
   {
      return getter<containers::XYs1d>(choice(),n,"XYs1d");
   }

   // optional XYs1d(label)
   auto XYs1d(const std::string &label) const
   {
      return getter<containers::XYs1d>(choice(),label,"XYs1d");
   }

   // optional regions1d(n)
   auto regions1d(const std::size_t n) const
   {
      return getter<containers::Regions1d>(choice(),n,"regions1d");
   }

   // optional regions1d(label)
   auto regions1d(const std::string &label) const
   {
      return getter<containers::Regions1d>(choice(),label,"regions1d");
   }

   // ------------------------
   // Setters
   // non-const
   // ------------------------

   // choice
   auto &choice(const std::vector<VARIANT> &obj)
    { content.choice = obj; return *this; }

   // XYs1d
   auto &XYs1d(
      const std::size_t n,
      const std::optional<containers::XYs1d> &obj
   ) {
      detail::setter(choice(),n,obj,namespaceName(),className(),"XYs1d");
      return *this;
   }

   // regions1d
   auto &regions1d(
      const std::size_t n,
      const std::optional<containers::Regions1d> &obj
   ) {
      detail::setter(choice(),n,obj,namespaceName(),className(),"regions1d");
      return *this;
   }

   // ------------------------
   // Construction
   // ------------------------

   // default
   CrossSection() :
      Component{
         BaseBodyText{},
         content.choice
      }
   {
      bodyTextUpdate(content);
      construct();
   }

   // copy
   CrossSection(const CrossSection &other) :
      Component{
         other,
         content.choice
      },
      content{other.content}
   {
      bodyTextUpdate(content);
      construct(other);
   }

   // move
   CrossSection(CrossSection &&other) :
      Component{
         other,
         content.choice
      },
      content{std::move(other.content)}
   {
      bodyTextUpdate(content);
      construct(other);
   }

   // from node
   CrossSection(const Node &node) :
      Component{
         BaseBodyText{},
         content.choice
      }
   {
      fromNode(node);
      bodyTextUpdate(content);
      construct(node);
   }

   // from fields
   explicit CrossSection(
      const std::vector<VARIANT> &choice
   ) :
      Component{
         BaseBodyText{},
         content.choice
      },
      content{
         choice
      }
   {
      bodyTextUpdate(content);
      construct();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   CrossSection &operator=(const CrossSection &) = default;

   // move
   CrossSection &operator=(CrossSection &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v1.9/transport/CrossSection/src/custom.hpp"

}; // class CrossSection

} // namespace transport

} // namespace v1_9
} // namespace GNDStk
} // namespace njoy

#endif
