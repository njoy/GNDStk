
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

   friend class Component<Values,true>;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "containers"; }
   static auto className() { return "Values"; }
   static auto GNDSName() { return "values"; }

   // Core Interface construct to extract metadata and child nodes
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
   // Re: base classes
   // ------------------------

   using BaseComponent = Component<Values,true>;
   using BaseBodyText = BodyText<true>;
   using BaseComponent::construct;

   // ------------------------
   // Relevant defaults;
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
      std::optional<Integer32> length;
      Defaulted<Integer32> start{0};
      Defaulted<UTF8Text> valueType{"Float64"};
   } content;

   // ------------------------
   // Getters
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
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // length
   auto &length(const std::optional<Integer32> &obj)
    { BaseBodyText::length(content.length = obj); return *this; }

   // start
   auto &start(const Defaulted<Integer32> &obj)
    { BaseBodyText::start(content.start = obj); return *this; }
   auto &start(const Integer32 &obj)
    { BaseBodyText::start(content.start = obj); return *this; }

   // valueType
   auto &valueType(const Defaulted<UTF8Text> &obj)
    { BaseBodyText::valueType(content.valueType = obj); return *this; }
   auto &valueType(const UTF8Text &obj)
    { BaseBodyText::valueType(content.valueType = obj); return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Values() :
      Component{
         BaseBodyText{},
         content.length,
         content.start,
         content.valueType
      }
   {
      bodyTextUpdate(content);
      construct();
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
      bodyTextUpdate(content);
      construct(other);
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
      bodyTextUpdate(content);
      construct(other);
   }

   // from node
   Values(const Node &node) :
      Component{
         BaseBodyText{},
         content.length,
         content.start,
         content.valueType
      }
   {
      fromNode(node);
      bodyTextUpdate(content);
      construct(node);
   }

   // from fields
   explicit Values(
      const std::optional<Integer32> &length,
      const Defaulted<Integer32> &start,
      const Defaulted<UTF8Text> &valueType
   ) :
      Component{
         BaseBodyText{},
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
      bodyTextUpdate(content);
      construct();
   }

   // from fields, with T replacing Defaulted<T>
   explicit Values(
      const std::optional<Integer32> &length,
      const Integer32 &start,
      const UTF8Text &valueType
   ) :
      Component{
         BaseBodyText{},
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
      bodyTextUpdate(content);
      construct();
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
