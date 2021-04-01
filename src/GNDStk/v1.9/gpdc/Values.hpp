#ifndef NJOY_GNDSTK_V1_9_GPDC_VALUES
#define NJOY_GNDSTK_V1_9_GPDC_VALUES

// system includes

// other includes
#include "GNDStk.hpp"

namespace njoy {
namespace GNDStk {

using namespace njoy::GNDStk::core;

namespace v1_9 {
namespace gpdc {

class Values : public Component<Values> {

   // ------------------------
   // for Component
   // ------------------------

   friend class Component<Values>;

   static auto className() { return "Values"; }
   static auto GNDSField() { return "values"; }
   static auto keys()
   {
      return
         // metadata
         std::optional<Integer32>{}
            / Meta<>("length") |
         Defaulted<Integer32>{0}
            / Meta<>("start") |
         Defaulted<UTF8Text>{"Float64"}
            / Meta<>("valueType")
      ;
   }

public:

   // ------------------------
   // raw GNDS content
   // ------------------------

   struct {
      // metadata
      std::optional<Integer32> length;
      Defaulted<Integer32> start{0};
      Defaulted<UTF8Text> valueType{"Float64"};
   } content;

   // ------------------------
   // getters
   // ------------------------

   // metadata
   const auto &length() const
    { return content.length; }
   const auto &start() const
    { return content.start; }
   const auto &valueType() const
    { return content.valueType; }

   // ------------------------
   // constructors
   // ------------------------

   // default
   Values() :
      Component{
         content.length,
         content.start,
         content.valueType
      }
   {
      Component::construct();
   }

   // copy
   Values(const Values &other) :
      Component{
         content.length,
         content.start,
         content.valueType
      },
      content{other.content}
   {
      Component::construct();
   }

   // node
   Values(const Node &node) :
      Values{}
   {
      Component::query(node);
      Component::construct();
   }

   // fields
   explicit Values(
      const std::optional<Integer32> &length,
      const Defaulted<Integer32> &start,
      const Defaulted<UTF8Text> &valueType
   ) :
      Component{
         content.length,
         content.start,
         content.valueType
      },
      content{
         length,
         start,
         valueType
      }
   {
      Component::construct();
   }

   // ------------------------
   // assignment: copy, move
   // ------------------------

   Values &operator=(const Values &) = default;
   Values &operator=(Values &&) = default;

   // ------------------------
   // custom functionality
   // ------------------------

   #include "GNDStk/v1.9/gpdc/Values/src/custom.hpp"

}; // class Values

} // gpdc namespace
} // v1_9 namespace
} // GNDStk namespace
} // njoy namespace

#endif
