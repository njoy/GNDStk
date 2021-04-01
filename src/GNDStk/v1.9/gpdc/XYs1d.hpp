#ifndef NJOY_GNDSTK_V1_9_GPDC_XYS1D
#define NJOY_GNDSTK_V1_9_GPDC_XYS1D

// system includes

// other includes
#include "GNDStk.hpp"
#include "GNDStk/v1.9/gpdc/Axes.hpp"
#include "GNDStk/v1.9/gpdc/Values.hpp"

namespace njoy {
namespace GNDStk {

using namespace njoy::GNDStk::core;

namespace v1_9 {
namespace gpdc {

class XYs1d : public Component<XYs1d> {

   // ------------------------
   // for Component
   // ------------------------

   friend class Component<XYs1d>;

   static auto className() { return "XYs1d"; }
   static auto GNDSField() { return "XYs1d"; }
   static auto keys()
   {
      return
         // metadata
         std::optional<Integer32>{}
            / Meta<>("index") |
         Defaulted<interpolation_t>{interpolation_t::lin_lin}
            / Meta<>("interpolation") |
         std::optional<XMLName>{}
            / Meta<>("label") |
         std::optional<Float64>{}
            / Meta<>("outerDomainValue") |
         // children
         std::optional<gpdc::Axes>{}
            / --Child<>("axes") |
         gpdc::Values{}
            / --Child<>("values")
      ;
   }

public:

   // ------------------------
   // raw GNDS content
   // ------------------------

   struct {
      // metadata
      std::optional<Integer32> index;
      Defaulted<interpolation_t> interpolation{interpolation_t::lin_lin};
      std::optional<XMLName> label;
      std::optional<Float64> outerDomainValue;

      // children
      std::optional<gpdc::Axes> axes;
      gpdc::Values values;
   } content;

   // ------------------------
   // getters
   // ------------------------

   // metadata
   const auto &index() const
    { return content.index; }
   const auto &interpolation() const
    { return content.interpolation; }
   const auto &label() const
    { return content.label; }
   const auto &outerDomainValue() const
    { return content.outerDomainValue; }

   // children
   const auto &axes() const
    { return content.axes; }
   const auto &values() const
    { return content.values; }

   // ------------------------
   // constructors
   // ------------------------

   // default
   XYs1d() :
      Component{
         content.index,
         content.interpolation,
         content.label,
         content.outerDomainValue,
         content.axes,
         content.values
      }
   {
      Component::construct();
   }

   // copy
   XYs1d(const XYs1d &other) :
      Component{
         content.index,
         content.interpolation,
         content.label,
         content.outerDomainValue,
         content.axes,
         content.values
      },
      content{other.content}
   {
      Component::construct();
   }

   // node
   XYs1d(const Node &node) :
      XYs1d{}
   {
      Component::query(node);
      Component::construct();
   }

   // fields
   explicit XYs1d(
      const std::optional<Integer32> &index,
      const Defaulted<interpolation_t> &interpolation,
      const std::optional<XMLName> &label,
      const std::optional<Float64> &outerDomainValue,
      const std::optional<gpdc::Axes> &axes,
      const gpdc::Values &values
   ) :
      Component{
         content.index,
         content.interpolation,
         content.label,
         content.outerDomainValue,
         content.axes,
         content.values
      },
      content{
         index,
         interpolation,
         label,
         outerDomainValue,
         axes,
         values
      }
   {
      Component::construct();
   }

   // ------------------------
   // assignment: copy, move
   // ------------------------

   XYs1d &operator=(const XYs1d &) = default;
   XYs1d &operator=(XYs1d &&) = default;

   // ------------------------
   // custom functionality
   // ------------------------

   #include "GNDStk/v1.9/gpdc/XYs1d/src/custom.hpp"

}; // class XYs1d

} // gpdc namespace
} // v1_9 namespace
} // GNDStk namespace
} // njoy namespace

#endif
