#ifndef NJOY_GNDSTK_V1_9_GPDC_GRID
#define NJOY_GNDSTK_V1_9_GPDC_GRID

// system includes

// other includes
#include "GNDStk.hpp"
#include "GNDStk/v1.9/gpdc/Values.hpp"

namespace njoy {
namespace GNDStk {

using namespace njoy::GNDStk::core;

namespace v1_9 {
namespace gpdc {

class Grid : public Component<Grid> {

   // ------------------------
   // for Component
   // ------------------------

   friend class Component<Grid>;

   static auto className() { return "Grid"; }
   static auto GNDSField() { return "grid"; }
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
         std::optional<UTF8Text>{}
            / Meta<>("style") |
         std::optional<XMLName>{}
            / Meta<>("unit") |
         // children
         std::optional<gpdc::Values>{}
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
      std::optional<UTF8Text> style;
      std::optional<XMLName> unit;

      // children
      std::optional<gpdc::Values> values;
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
   const auto &style() const
    { return content.style; }
   const auto &unit() const
    { return content.unit; }

   // children
   const auto &values() const
    { return content.values; }

   // ------------------------
   // constructors
   // ------------------------

   // default
   Grid() :
      Component{
         content.index,
         content.interpolation,
         content.label,
         content.style,
         content.unit,
         content.values
      }
   {
      Component::construct();
   }

   // copy
   Grid(const Grid &other) :
      Component{
         content.index,
         content.interpolation,
         content.label,
         content.style,
         content.unit,
         content.values
      },
      content{other.content}
   {
      Component::construct();
   }

   // node
   Grid(const Node &node) :
      Grid{}
   {
      Component::query(node);
      Component::construct();
   }

   // fields
   explicit Grid(
      const std::optional<Integer32> &index,
      const Defaulted<interpolation_t> &interpolation,
      const std::optional<XMLName> &label,
      const std::optional<UTF8Text> &style,
      const std::optional<XMLName> &unit,
      const std::optional<gpdc::Values> &values
   ) :
      Component{
         content.index,
         content.interpolation,
         content.label,
         content.style,
         content.unit,
         content.values
      },
      content{
         index,
         interpolation,
         label,
         style,
         unit,
         values
      }
   {
      Component::construct();
   }

   // ------------------------
   // assignment: copy, move
   // ------------------------

   Grid &operator=(const Grid &) = default;
   Grid &operator=(Grid &&) = default;

   // ------------------------
   // custom functionality
   // ------------------------

   #include "GNDStk/v1.9/gpdc/Grid/src/custom.hpp"

}; // class Grid

} // gpdc namespace
} // v1_9 namespace
} // GNDStk namespace
} // njoy namespace

#endif
