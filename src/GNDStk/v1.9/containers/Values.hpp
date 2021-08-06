
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

class Values : public Component<Values,true> {

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "containers"; }
   static auto className() { return "Values"; }
   static auto GNDSName() { return "values"; }

   // Core Interface object to extract metadata and child nodes
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

   using Component::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static const struct {
      const Integer32 start{0};
      const UTF8Text valueType{"Float64"};
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      mutable std::optional<Integer32> length;
      mutable Defaulted<Integer32> start{0};
      mutable Defaulted<UTF8Text> valueType{"Float64"};
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // length
   const std::optional<Integer32> &
   length() const
    { return content.length; }
   std::optional<Integer32> &
   length()
    { return content.length; }

   // start
   Integer32
   start() const
    { return content.start.value(); }
   Integer32
   start()
    { return content.start.value(); }

   // valueType
   const UTF8Text
   valueType() const
    { return content.valueType.value(); }
   UTF8Text
   valueType()
    { return content.valueType.value(); }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // length(value)
   auto &length(const std::optional<Integer32> &obj)
    { BodyText::length(length() = obj); return *this; }

   // start(value)
   auto &start(const Defaulted<Integer32> &obj)
    { BodyText::start(content.start = obj); return *this; }
   auto &start(const Integer32 &obj)
    { BodyText::start(content.start = obj); return *this; }

   // valueType(value)
   auto &valueType(const Defaulted<UTF8Text> &obj)
    { BodyText::valueType(content.valueType = obj); return *this; }
   auto &valueType(const UTF8Text &obj)
    { BodyText::valueType(content.valueType = obj); return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Values() :
      Component{
         BodyText{},
         content.length,
         content.start,
         content.valueType
      }
   {
      Component::finish();
   }

   // copy
   Values(const Values &other) :
      Component{
         other,
         content.length,
         content.start,
         content.valueType
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Values(Values &&other) :
      Component{
         other,
         content.length,
         content.start,
         content.valueType
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Values(const Node &node) :
      Component{
         BodyText{},
         content.length,
         content.start,
         content.valueType
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Values(
      const std::optional<Integer32> &length,
      const Defaulted<Integer32> &start,
      const Defaulted<UTF8Text> &valueType
   ) :
      Component{
         BodyText{},
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
      Component::finish();
   }

   // from fields, with T replacing Defaulted<T>
   explicit Values(
      const std::optional<Integer32> &length,
      const Integer32 &start,
      const UTF8Text &valueType
   ) :
      Component{
         BodyText{},
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
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Values &operator=(const Values &) = default;

   // move
   Values &operator=(Values &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v1.9/containers/Values/src/custom.hpp"

}; // class Values

} // namespace containers

} // namespace v1_9
} // namespace GNDStk
} // namespace njoy

#endif
