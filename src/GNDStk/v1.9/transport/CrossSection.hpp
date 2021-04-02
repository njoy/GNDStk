#ifndef NJOY_GNDSTK_V1_9_TRANSPORT_CROSSSECTION
#define NJOY_GNDSTK_V1_9_TRANSPORT_CROSSSECTION

// system includes

// other includes
#include "GNDStk.hpp"
#include "GNDStk/v1.9/gpdc/Regions1d.hpp"
#include "GNDStk/v1.9/gpdc/XYs1d.hpp"

namespace njoy {
namespace GNDStk {

using namespace njoy::GNDStk::core;

namespace v1_9 {
namespace transport {

class CrossSection : public Component<CrossSection> {

   // ------------------------
   // for Component
   // ------------------------

   friend class Component<CrossSection>;

   static auto className() { return "CrossSection"; }
   static auto GNDSField() { return "crossSection"; }
   static auto keys()
   {
      return
         // children
         std::optional<gpdc::XYs1d>{}
            / ++Child<>("XYs1d") |
         std::optional<gpdc::Regions1d>{}
            / ++Child<>("regions1d")
      ;
   }

public:

   // ------------------------
   // raw GNDS content
   // ------------------------

   struct {
      // children
      std::optional<std::vector<gpdc::XYs1d>> XYs1d;
      std::optional<std::vector<gpdc::Regions1d>> regions1d;
   } content;

   // ------------------------
   // getters
   // ------------------------

   // children
   const auto &XYs1d() const
    { return content.XYs1d; }
   const auto &regions1d() const
    { return content.regions1d; }

   // ------------------------
   // constructors
   // ------------------------

   // default
   CrossSection() :
      Component{
         content.XYs1d,
         content.regions1d
      }
   {
      Component::construct();
   }

   // copy
   CrossSection(const CrossSection &other) :
      Component{
         content.XYs1d,
         content.regions1d
      },
      content{other.content}
   {
      Component::construct();
   }

   // node
   CrossSection(const Node &node) :
      CrossSection{}
   {
      Component::query(node);
      Component::construct();
   }

   // fields
   explicit CrossSection(
      const std::optional<gpdc::XYs1d> &XYs1d,
      const std::optional<gpdc::Regions1d> &regions1d
   ) :
      Component{
         content.XYs1d,
         content.regions1d
      },
      content{
         XYs1d,
         regions1d
      }
   {
      Component::construct();
   }

   // ------------------------
   // assignment: copy, move
   // ------------------------

   CrossSection &operator=(const CrossSection &) = default;
   CrossSection &operator=(CrossSection &&) = default;

   // ------------------------
   // custom functionality
   // ------------------------

   #include "GNDStk/v1.9/transport/CrossSection/src/custom.hpp"

}; // class CrossSection

} // transport namespace
} // v1_9 namespace
} // GNDStk namespace
} // njoy namespace

#endif
