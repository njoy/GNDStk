
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V1_9_CONTAINERS_VALUES
#define NJOY_GNDSTK_V1_9_CONTAINERS_VALUES

// core interface
#include "GNDStk.hpp"

namespace njoy {
namespace GNDStk {
namespace v1_9 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// containers::
// class Values
// -----------------------------------------------------------------------------

namespace containers {

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
   // relevant defaults
   // FYI for users
   // ------------------------

   static const struct {
      const Integer32 start{0};
      const UTF8Text valueType{"Float64"};
   } defaults;

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
   // const and non-const
   // ------------------------

   // length
   const auto &length() const
    { return content.length; }
   auto &length()
    { return content.length; }

   // start
   const auto &start() const
    { return content.start.value(); }
   auto &start()
    { return content.start.value(); }

   // valueType
   const auto &valueType() const
    { return content.valueType.value(); }
   auto &valueType()
    { return content.valueType.value(); }

   // ------------------------
   // setters
   // non-const only
   // ------------------------

   // length
   auto &length(const std::optional<Integer32> &obj)
    { content.length = obj; return *this; }

   // start
   auto &start(const Defaulted<Integer32> &obj)
    { content.start = obj; return *this; }
   auto &start(const Integer32 &obj)
    { content.start = obj; return *this; }

   // valueType
   auto &valueType(const Defaulted<UTF8Text> &obj)
    { content.valueType = obj; return *this; }
   auto &valueType(const UTF8Text &obj)
    { content.valueType = obj; return *this; }

   // ------------------------
   // construction
   // ------------------------

   // default
   Values() :
      Component{
         content.length,
         content.start,
         content.valueType
      }
   {
      construct();
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
      construct();
   }

   // move
   Values(Values &&other) :
      Component{
         content.length,
         content.start,
         content.valueType
      },
      content{std::move(other.content)}
   {
      construct();
   }

   // from node
   Values(const Node &node) :
      Component{
         content.length,
         content.start,
         content.valueType
      }
   {
      query(node);
      construct();
   }

   // from fields
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
      construct();
   }

   // from fields, with T replacing Defaulted<T>
   explicit Values(
      const std::optional<Integer32> &length,
      const Integer32 &start,
      const UTF8Text &valueType
   ) :
      Component{
         content.length,
         content.start,
         content.valueType
      },
      content{
         length,
         start == 0
            ? Defaulted<Integer32>{0}
            : Defaulted<Integer32>{0,start},
         valueType == "Float64"
            ? Defaulted<UTF8Text>{"Float64"}
            : Defaulted<UTF8Text>{"Float64",valueType}
      }
   {
      construct();
   }

   // ------------------------
   // assignment
   // ------------------------

   // copy
   Values &operator=(const Values &) = default;

   // move
   Values &operator=(Values &&) = default;

   // ------------------------
   // custom functionality
   // ------------------------

   #include "GNDStk/v1.9/containers/Values/src/custom.hpp"

}; // class Values

} // namespace containers

} // namespace v1_9
} // namespace GNDStk
} // namespace njoy

#endif
