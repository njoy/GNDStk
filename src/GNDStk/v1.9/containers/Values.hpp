
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

   static struct {
      static Integer32 start()
      {
         return 0;
      }
      static UTF8Text valueType()
      {
         return "Float64";
      }
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
   const std::optional<Integer32> &length() const
    { return content.length; }
   std::optional<Integer32> &length()
    { return content.length; }

   // start
   const Defaulted<Integer32> &start() const
    { return content.start; }
   Defaulted<Integer32> &start()
    { return content.start; }

   // valueType
   const Defaulted<UTF8Text> &valueType() const
    { return content.valueType; }
   Defaulted<UTF8Text> &valueType()
    { return content.valueType; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // length(value)
   Values &length(const std::optional<Integer32> &obj)
    { BodyText::length(length() = obj); return *this; }

   // start(value)
   Values &start(const Defaulted<Integer32> &obj)
    { BodyText::start(content.start = obj); return *this; }
   Values &start(const std::optional<Integer32> &obj)
    { BodyText::start(content.start = obj); return *this; }

   // valueType(value)
   Values &valueType(const Defaulted<UTF8Text> &obj)
    { BodyText::valueType(content.valueType = obj); return *this; }
   Values &valueType(const std::optional<UTF8Text> &obj)
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
   // std::optional replaces Defaulted; this class knows the default(s)
   explicit Values(
      const std::optional<Integer32> &length,
      const std::optional<Integer32> &start,
      const std::optional<UTF8Text> &valueType
   ) :
      Component{
         BodyText{},
         content.length,
         content.start,
         content.valueType
      },
      content{
         length,
         Defaulted<Integer32>(defaults.start(),start),
         Defaulted<UTF8Text>(defaults.valueType(),valueType)
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
