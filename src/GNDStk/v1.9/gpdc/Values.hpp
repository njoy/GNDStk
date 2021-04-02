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
            / Meta<>("valueType") |
         std::vector< double >{} / GNDStk::basic::numeric< double >
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
      std::vector< double > values;
   } content;

   // ------------------------
   // getters
   // ------------------------

   // metadata
   std::size_t length() const
    { return content.length ?  content.length.value() : content.values.size(); }
   const auto &start() const
    { return content.start.value(); }
   const auto &valueType() const
    { return content.valueType.value(); }
   const auto &values() const
    { return content.values; }

   // ------------------------
   // constructors
   // ------------------------

   // default
   Values() :
      Component{
         content.length,
         content.start,
         content.valueType,
         content.values
      }
   {
      Component::construct();
   }

   // copy
   Values(const Values &other) :
      Component{
         content.length,
         content.start,
         content.valueType,
         content.values
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
      Integer32 start,
      UTF8Text valueType,
      const std::vector< double > &values
   ) :
      Component{
         content.length,
         content.start,
         content.valueType,
         content.values
      },
      content{
         length,
         start == 0 ? Defaulted<Integer32>{0} : Defaulted<Integer32>{ start },
         valueType == "Float64" ? Defaulted<UTF8Text>{"Float64"} :
                                  Defaulted<UTF8Text>{ valueType },
         values
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
