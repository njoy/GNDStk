
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

   using XYS1D_REGIONS1D = std::variant<
      containers::XYs1d,
      containers::Regions1d
   >;

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "transport"; }
   static auto className() { return "CrossSection"; }
   static auto GNDSName() { return "crossSection"; }

   // Core Interface object to extract metadata and child nodes
   static auto keys()
   {
      return
         // children
         XYS1D_REGIONS1D{}
            / ++(Child<>("XYs1d") || Child<>("regions1d"))
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
      // children
      std::vector<XYS1D_REGIONS1D> XYs1d_regions1d;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // XYs1d_regions1d
   const std::vector<XYS1D_REGIONS1D> &XYs1d_regions1d() const
    { return content.XYs1d_regions1d; }
   std::vector<XYS1D_REGIONS1D> &XYs1d_regions1d()
    { return content.XYs1d_regions1d; }

   // XYs1d_regions1d(index)
   const XYS1D_REGIONS1D &XYs1d_regions1d(const std::size_t index) const
    { return getter(XYs1d_regions1d(), index, "XYs1d_regions1d"); }
   XYS1D_REGIONS1D &XYs1d_regions1d(const std::size_t index)
    { return getter(XYs1d_regions1d(), index, "XYs1d_regions1d"); }

   // XYs1d_regions1d(label)
   const XYS1D_REGIONS1D &XYs1d_regions1d(const std::string &label) const
    { return getter(XYs1d_regions1d(), label, "XYs1d_regions1d"); }
   XYS1D_REGIONS1D &XYs1d_regions1d(const std::string &label)
    { return getter(XYs1d_regions1d(), label, "XYs1d_regions1d"); }

   // XYs1d(index)
   const containers::XYs1d *XYs1d(const std::size_t index) const
    { return getter<containers::XYs1d>(XYs1d_regions1d(), index, "XYs1d"); }
   containers::XYs1d *XYs1d(const std::size_t index)
    { return getter<containers::XYs1d>(XYs1d_regions1d(), index, "XYs1d"); }

   // XYs1d(label)
   const containers::XYs1d *XYs1d(const std::string &label) const
    { return getter<containers::XYs1d>(XYs1d_regions1d(), label, "XYs1d"); }
   containers::XYs1d *XYs1d(const std::string &label)
    { return getter<containers::XYs1d>(XYs1d_regions1d(), label, "XYs1d"); }

   // regions1d(index)
   const containers::Regions1d *regions1d(const std::size_t index) const
    { return getter<containers::Regions1d>(XYs1d_regions1d(), index, "regions1d"); }
   containers::Regions1d *regions1d(const std::size_t index)
    { return getter<containers::Regions1d>(XYs1d_regions1d(), index, "regions1d"); }

   // regions1d(label)
   const containers::Regions1d *regions1d(const std::string &label) const
    { return getter<containers::Regions1d>(XYs1d_regions1d(), label, "regions1d"); }
   containers::Regions1d *regions1d(const std::string &label)
    { return getter<containers::Regions1d>(XYs1d_regions1d(), label, "regions1d"); }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // XYs1d_regions1d(value)
   CrossSection &XYs1d_regions1d(const std::vector<XYS1D_REGIONS1D> &obj)
    { XYs1d_regions1d() = obj; return *this; }

   // XYs1d_regions1d(index,value)
   CrossSection &XYs1d_regions1d(
      const std::size_t index,
      const XYS1D_REGIONS1D &obj
   ) {
      XYs1d_regions1d(index) = obj; return *this;
   }

   // XYs1d_regions1d(label,value)
   CrossSection &XYs1d_regions1d(
      const std::string &label,
      const XYS1D_REGIONS1D &obj
   ) {
      XYs1d_regions1d(label) = obj; return *this;
   }

   // XYs1d(index,value)
   CrossSection &XYs1d(
      const std::size_t index,
      const std::optional<containers::XYs1d> &obj
   ) {
      if (obj) XYs1d_regions1d(index,obj.value());
      return *this;
   }

   // XYs1d(label,value)
   CrossSection &XYs1d(
      const std::string &label,
      const std::optional<containers::XYs1d> &obj
   ) {
      if (obj) XYs1d_regions1d(label,obj.value());
      return *this;
   }

   // regions1d(index,value)
   CrossSection &regions1d(
      const std::size_t index,
      const std::optional<containers::Regions1d> &obj
   ) {
      if (obj) XYs1d_regions1d(index,obj.value());
      return *this;
   }

   // regions1d(label,value)
   CrossSection &regions1d(
      const std::string &label,
      const std::optional<containers::Regions1d> &obj
   ) {
      if (obj) XYs1d_regions1d(label,obj.value());
      return *this;
   }

   // ------------------------
   // Construction
   // ------------------------

   // default
   CrossSection() :
      Component{
         BodyText{},
         content.XYs1d_regions1d
      }
   {
      Component::finish();
   }

   // copy
   CrossSection(const CrossSection &other) :
      Component{
         other,
         content.XYs1d_regions1d
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   CrossSection(CrossSection &&other) :
      Component{
         other,
         content.XYs1d_regions1d
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   CrossSection(const Node &node) :
      Component{
         BodyText{},
         content.XYs1d_regions1d
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit CrossSection(
      const std::vector<XYS1D_REGIONS1D> &XYs1d_regions1d
   ) :
      Component{
         BodyText{},
         content.XYs1d_regions1d
      },
      content{
         XYs1d_regions1d
      }
   {
      Component::finish();
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
