
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

   // ------------------------
   // Re: base classes
   // ------------------------

   using BaseComponent = Component<CrossSection>;
   using BaseBodyText = BodyText<false>;
   using BaseComponent::construct;

   // ------------------------
   // Relevant defaults;
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

   // choice(index)
   const auto &choice(const std::size_t index) const
    { return getter(choice(), index, "choice"); }
   auto &choice(const std::size_t index)
    { return getter(choice(), index, "choice"); }

   // choice(label)
   const auto &choice(const std::string &label) const
    { return getter(choice(), label, "choice"); }
   auto &choice(const std::string &label)
    { return getter(choice(), label, "choice"); }

   // XYs1d(index)
   auto XYs1d(const std::size_t index) const
    { return getter<containers::XYs1d>(choice(), index, "XYs1d"); }
   auto XYs1d(const std::size_t index)
    { return getter<containers::XYs1d>(choice(), index, "XYs1d"); }

   // XYs1d(label)
   auto XYs1d(const std::string &label) const
    { return getter<containers::XYs1d>(choice(), label, "XYs1d"); }
   auto XYs1d(const std::string &label)
    { return getter<containers::XYs1d>(choice(), label, "XYs1d"); }

   // regions1d(index)
   auto regions1d(const std::size_t index) const
    { return getter<containers::Regions1d>(choice(), index, "regions1d"); }
   auto regions1d(const std::size_t index)
    { return getter<containers::Regions1d>(choice(), index, "regions1d"); }

   // regions1d(label)
   auto regions1d(const std::string &label) const
    { return getter<containers::Regions1d>(choice(), label, "regions1d"); }
   auto regions1d(const std::string &label)
    { return getter<containers::Regions1d>(choice(), label, "regions1d"); }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // choice(value)
   auto &choice(const std::vector<VARIANT> &obj)
    { choice() = obj; return *this; }

   // choice(index,value)
   auto &choice(
      const std::size_t index,
      const VARIANT &obj
   ) {
      choice(index) = obj; return *this;
   }

   // choice(label,value)
   auto &choice(
      const std::string &label,
      const VARIANT &obj
   ) {
      choice(label) = obj; return *this;
   }

   // XYs1d(index,value)
   auto &XYs1d(
      const std::size_t index,
      const std::optional<containers::XYs1d> &obj
   ) {
      if (obj) choice(index,obj.value());
      return *this;
   }

   // XYs1d(label,value)
   auto &XYs1d(
      const std::string &label,
      const std::optional<containers::XYs1d> &obj
   ) {
      if (obj) choice(label,obj.value());
      return *this;
   }

   // regions1d(index,value)
   auto &regions1d(
      const std::size_t index,
      const std::optional<containers::Regions1d> &obj
   ) {
      if (obj) choice(index,obj.value());
      return *this;
   }

   // regions1d(label,value)
   auto &regions1d(
      const std::string &label,
      const std::optional<containers::Regions1d> &obj
   ) {
      if (obj) choice(label,obj.value());
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
