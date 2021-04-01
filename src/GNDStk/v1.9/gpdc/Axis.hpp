#ifndef NJOY_GNDSTK_V1_9_GPDC_AXIS
#define NJOY_GNDSTK_V1_9_GPDC_AXIS

// system includes

// other includes
#include "GNDStk.hpp"

namespace njoy {
namespace GNDStk {

using namespace njoy::GNDStk::core;

namespace v1_9 {
namespace gpdc {

class Axis : public Component<Axis> {

   // ------------------------
   // for Component
   // ------------------------

   friend class Component<Axis>;

   static auto className() { return "Axis"; }
   static auto GNDSField() { return "axis"; }
   static auto keys()
   {
      return
         // metadata
         std::optional<Integer32>{}
            / Meta<>("index") |
         std::optional<XMLName>{}
            / Meta<>("label") |
         std::optional<XMLName>{}
            / Meta<>("unit")
      ;
   }

public:

   // ------------------------
   // raw GNDS content
   // ------------------------

   struct {
      // metadata
      std::optional<Integer32> index;
      std::optional<XMLName> label;
      std::optional<XMLName> unit;
   } content;

   // ------------------------
   // getters
   // ------------------------

   // metadata
   const auto &index() const
    { return content.index; }
   const auto &label() const
    { return content.label; }
   const auto &unit() const
    { return content.unit; }

   // ------------------------
   // constructors
   // ------------------------

   // default
   Axis() :
      Component{
         content.index,
         content.label,
         content.unit
      }
   {
      Component::construct();
   }

   // copy
   Axis(const Axis &other) :
      Component{
         content.index,
         content.label,
         content.unit
      },
      content{other.content}
   {
      Component::construct();
   }

   // node
   Axis(const Node &node) :
      Axis{}
   {
      Component::query(node);
      Component::construct();
   }

   // fields
   explicit Axis(
      const std::optional<Integer32> &index,
      const std::optional<XMLName> &label,
      const std::optional<XMLName> &unit
   ) :
      Component{
         content.index,
         content.label,
         content.unit
      },
      content{
         index,
         label,
         unit
      }
   {
      Component::construct();
   }

   // ------------------------
   // assignment: copy, move
   // ------------------------

   Axis &operator=(const Axis &) = default;
   Axis &operator=(Axis &&) = default;

   // ------------------------
   // custom functionality
   // ------------------------

   #include "GNDStk/v1.9/gpdc/Axis/src/custom.hpp"

}; // class Axis

} // gpdc namespace
} // v1_9 namespace
} // GNDStk namespace
} // njoy namespace

#endif
