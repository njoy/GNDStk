
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDSTK_V1_9_TRANSPORT_CROSSSECTION
#define GNDSTK_V1_9_TRANSPORT_CROSSSECTION

// GNDStk Core Interface
#include "GNDStk.hpp"

// Dependencies
#include "GNDStk/v1.9/containers/XYs1d.hpp"
#include "GNDStk/v1.9/containers/Regions1d.hpp"

namespace njoy {
namespace GNDStk {
namespace v1_9 {

using namespace njoy::GNDStk;



// -----------------------------------------------------------------------------
// transport::
// class CrossSection
// -----------------------------------------------------------------------------

namespace transport {

class CrossSection : public Component<CrossSection> {

   using XYs1d_regions1d_t = std::variant<
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

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // children
         XYs1d_regions1d_t{}
            / ++(Child<>("XYs1d") || Child<>("regions1d"))
      ;
   }

public:

   using Component::construct;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // children - variant
      std::vector<XYs1d_regions1d_t> XYs1d_regions1d;
   } Content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // XYs1d_regions1d
   const std::vector<XYs1d_regions1d_t> &XYs1d_regions1d() const
      { return Content.XYs1d_regions1d; }
   std::vector<XYs1d_regions1d_t> &XYs1d_regions1d()
      { return Content.XYs1d_regions1d; }

   // XYs1d_regions1d(index/label/Lookup)
   template<class KEY, class = detail::isSearchKey<KEY>>
   decltype(auto) XYs1d_regions1d(const KEY &key) const
      { return getter(XYs1d_regions1d(), key, "XYs1d_regions1d"); }
   template<class KEY, class = detail::isSearchKey<KEY>>
   decltype(auto) XYs1d_regions1d(const KEY &key)
      { return getter(XYs1d_regions1d(), key, "XYs1d_regions1d"); }

   // XYs1d(index/label/Lookup)
   template<class KEY, class = detail::isSearchKey<KEY>>
   decltype(auto) XYs1d(const KEY &key) const
      { return getter<containers::XYs1d>(XYs1d_regions1d(), key, "XYs1d"); }
   template<class KEY, class = detail::isSearchKey<KEY>>
   decltype(auto) XYs1d(const KEY &key)
      { return getter<containers::XYs1d>(XYs1d_regions1d(), key, "XYs1d"); }

   // regions1d(index/label/Lookup)
   template<class KEY, class = detail::isSearchKey<KEY>>
   decltype(auto) regions1d(const KEY &key) const
      { return getter<containers::Regions1d>(XYs1d_regions1d(), key, "regions1d"); }
   template<class KEY, class = detail::isSearchKey<KEY>>
   decltype(auto) regions1d(const KEY &key)
      { return getter<containers::Regions1d>(XYs1d_regions1d(), key, "regions1d"); }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // XYs1d_regions1d(vector): replace vector
   CrossSection &XYs1d_regions1d(const std::vector<XYs1d_regions1d_t> &obj)
      { XYs1d_regions1d() = obj; return *this; }

   // XYs1d_regions1d(scalar): vector push_back
   CrossSection &XYs1d_regions1d(const XYs1d_regions1d_t &obj)
      { setter(XYs1d_regions1d(), obj); return *this; }

   // XYs1d_regions1d(index/label/Lookup, value): replace vector entry
   template<class KEY, class = detail::isSearchKeyRefReturn<KEY>>
   CrossSection &XYs1d_regions1d(const KEY &key, const XYs1d_regions1d_t &obj)
   {
      XYs1d_regions1d(key) = obj; return *this;
   }

   // XYs1d(index/label/Lookup, value): replace vector entry
   template<class KEY, class = detail::isSearchKeyRefReturn<KEY>>
   CrossSection &XYs1d(
      const KEY &key,
      const std::optional<containers::XYs1d> &obj
   ) {
      if (obj) XYs1d_regions1d(key,obj.value());
      return *this;
   }

   // regions1d(index/label/Lookup, value): replace vector entry
   template<class KEY, class = detail::isSearchKeyRefReturn<KEY>>
   CrossSection &regions1d(
      const KEY &key,
      const std::optional<containers::Regions1d> &obj
   ) {
      if (obj) XYs1d_regions1d(key,obj.value());
      return *this;
   }

   // ------------------------
   // Constructors
   // ------------------------

   // default, and from fields
   explicit CrossSection(
      const std::vector<XYs1d_regions1d_t> &XYs1d_regions1d =
         std::vector<XYs1d_regions1d_t>{}
   ) :
      Component{
         BlockData{},
         this->XYs1d_regions1d()
      },
      Content{
         XYs1d_regions1d
      }
   {
      Component::finish();
   }

   // copy
   CrossSection(const CrossSection &other) :
      Component{
         other.baseBlockData(),
         this->XYs1d_regions1d()
      },
      Content{other.Content}
   {
      Component::finish(other);
   }

   // move
   CrossSection(CrossSection &&other) :
      Component{
         other.baseBlockData(),
         this->XYs1d_regions1d()
      },
      Content{std::move(other.Content)}
   {
      Component::finish(other);
   }

   // from node
   CrossSection(const Node &node) :
      Component{
         BlockData{},
         this->XYs1d_regions1d()
      }
   {
      Component::finish(node);
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
