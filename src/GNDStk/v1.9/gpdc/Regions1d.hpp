#ifndef NJOY_GNDSTK_V1_9_GPDC_REGIONS1D
#define NJOY_GNDSTK_V1_9_GPDC_REGIONS1D

// system includes

// other includes
#include "GNDStk.hpp"
#include "GNDStk/v1.9/gpdc/Axes.hpp"
#include "GNDStk/v1.9/gpdc/XYs1d.hpp"

namespace njoy {
namespace GNDStk {

using namespace njoy::GNDStk::core;

namespace v1_9 {
namespace gpdc {

class Regions1d : public Component<Regions1d> {

   // ------------------------
   // for Component
   // ------------------------

   friend class Component<Regions1d>;

   static auto className() { return "Regions1d"; }
   static auto GNDSField() { return "regions1d"; }
   static auto keys()
   {
      return
         // metadata
         std::optional<XMLName>{}
            / Meta<>("label") |
         std::optional<Float64>{}
            / Meta<>("outerDomainValue") |
         // children
         gpdc::XYs1d{}
            / --Child<>("XYs1d") |
         std::optional<gpdc::Axes>{}
            / --Child<>("axes")
      ;
   }

public:

   // ------------------------
   // raw GNDS content
   // ------------------------

   struct {
      // metadata
      std::optional<XMLName> label;
      std::optional<Float64> outerDomainValue;

      // children
      gpdc::XYs1d XYs1d;
      std::optional<gpdc::Axes> axes;
   } content;

   // ------------------------
   // getters
   // ------------------------

   // metadata
   const auto &label() const
    { return content.label; }
   const auto &outerDomainValue() const
    { return content.outerDomainValue; }

   // children
   const auto &XYs1d() const
    { return content.XYs1d; }
   const auto &axes() const
    { return content.axes; }

   // ------------------------
   // constructors
   // ------------------------

   // default
   Regions1d() :
      Component{
         content.label,
         content.outerDomainValue,
         content.XYs1d,
         content.axes
      }
   {
      Component::construct();
   }

   // copy
   Regions1d(const Regions1d &other) :
      Component{
         content.label,
         content.outerDomainValue,
         content.XYs1d,
         content.axes
      },
      content{other.content}
   {
      Component::construct();
   }

   // node
   Regions1d(const Node &node) :
      Regions1d{}
   {
      Component::query(node);
      Component::construct();
   }

   // fields
   explicit Regions1d(
      const std::optional<XMLName> &label,
      const std::optional<Float64> &outerDomainValue,
      const gpdc::XYs1d &XYs1d,
      const std::optional<gpdc::Axes> &axes
   ) :
      Component{
         content.label,
         content.outerDomainValue,
         content.XYs1d,
         content.axes
      },
      content{
         label,
         outerDomainValue,
         XYs1d,
         axes
      }
   {
      Component::construct();
   }

   // ------------------------
   // assignment: copy, move
   // ------------------------

   Regions1d &operator=(const Regions1d &) = default;
   Regions1d &operator=(Regions1d &&) = default;

   // ------------------------
   // custom functionality
   // ------------------------

   #include "GNDStk/v1.9/gpdc/Regions1d/src/custom.hpp"

}; // class Regions1d

} // gpdc namespace
} // v1_9 namespace
} // GNDStk namespace
} // njoy namespace

#endif
