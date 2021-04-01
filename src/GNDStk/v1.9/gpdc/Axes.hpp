#ifndef NJOY_GNDSTK_V1_9_GPDC_AXES
#define NJOY_GNDSTK_V1_9_GPDC_AXES

// system includes

// other includes
#include "GNDStk.hpp"
#include "GNDStk/v1.9/gpdc/Axis.hpp"
#include "GNDStk/v1.9/gpdc/Grid.hpp"

namespace njoy {
namespace GNDStk {

using namespace njoy::GNDStk::core;

namespace v1_9 {
namespace gpdc {

class Axes : public Component<Axes> {

   // ------------------------
   // for Component
   // ------------------------

   friend class Component<Axes>;

   static auto className() { return "Axes"; }
   static auto GNDSField() { return "axes"; }
   static auto keys()
   {
      return
         // metadata
         std::optional<UTF8Text>{}
            / Meta<>("href") |
         // children
         std::optional<gpdc::Axis>{}
            / ++Child<>("axis") |
         std::optional<gpdc::Grid>{}
            / ++Child<>("grid")
      ;
   }

public:

   // ------------------------
   // raw GNDS content
   // ------------------------

   struct {
      // metadata
      std::optional<UTF8Text> href;

      // children
      std::optional<std::vector<gpdc::Axis>> axis;
      std::optional<std::vector<gpdc::Grid>> grid;
   } content;

   // ------------------------
   // getters
   // ------------------------

   // metadata
   const auto &href() const
    { return content.href; }

   // children
   const auto &axis() const
    { return content.axis; }
   const auto &grid() const
    { return content.grid; }

   // ------------------------
   // constructors
   // ------------------------

   // default
   Axes() :
      Component{
         content.href,
         content.axis,
         content.grid
      }
   {
      Component::construct();
   }

   // copy
   Axes(const Axes &other) :
      Component{
         content.href,
         content.axis,
         content.grid
      },
      content{other.content}
   {
      Component::construct();
   }

   // node
   Axes(const Node &node) :
      Axes{}
   {
      Component::query(node);
      Component::construct();
   }

   // fields
   explicit Axes(
      const std::optional<UTF8Text> &href,
      const std::optional<std::vector<gpdc::Axis>> &axis,
      const std::optional<std::vector<gpdc::Grid>> &grid
   ) :
      Component{
         content.href,
         content.axis,
         content.grid
      },
      content{
         href,
         axis,
         grid
      }
   {
      Component::construct();
   }

   // ------------------------
   // assignment: copy, move
   // ------------------------

   Axes &operator=(const Axes &) = default;
   Axes &operator=(Axes &&) = default;

   // ------------------------
   // custom functionality
   // ------------------------

   #include "GNDStk/v1.9/gpdc/Axes/src/custom.hpp"

}; // class Axes

} // gpdc namespace
} // v1_9 namespace
} // GNDStk namespace
} // njoy namespace

#endif
