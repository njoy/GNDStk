
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V1_9_CONTAINERS_AXIS
#define NJOY_GNDSTK_V1_9_CONTAINERS_AXIS

// core interface
#include "GNDStk.hpp"

namespace njoy {
namespace GNDStk {
namespace v1_9 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// containers::
// class Axis
// -----------------------------------------------------------------------------

namespace containers {

class Axis : public Component<Axis> {

   // ------------------------
   // for Component
   // ------------------------

   friend class Component<Axis>;

   static auto namespaceName() { return "containers"; }
   static auto className() { return "Axis"; }
   static auto GNDSName() { return "axis"; }

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

   using Base = Component<Axis>;

   // ------------------------
   // relevant defaults
   // FYI for users
   // ------------------------

   static const struct {
   } defaults;

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
   // const and non-const
   // ------------------------

   // index
   const auto &index() const
    { return content.index; }
   auto &index()
    { return content.index; }

   // label
   const auto &label() const
    { return content.label; }
   auto &label()
    { return content.label; }

   // unit
   const auto &unit() const
    { return content.unit; }
   auto &unit()
    { return content.unit; }

   // ------------------------
   // setters
   // non-const only
   // ------------------------

   // index
   auto &index(const std::optional<Integer32> &obj)
    { content.index = obj; return *this; }

   // label
   auto &label(const std::optional<XMLName> &obj)
    { content.label = obj; return *this; }

   // unit
   auto &unit(const std::optional<XMLName> &obj)
    { content.unit = obj; return *this; }

   // ------------------------
   // construction
   // ------------------------

   // default
   Axis() :
      Component{
         content.index,
         content.label,
         content.unit
      }
   {
      construct();
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
      construct(other);
   }

   // move
   Axis(Axis &&other) :
      Component{
         content.index,
         content.label,
         content.unit
      },
      content{std::move(other.content)}
   {
      construct(other);
   }

   // from node
   Axis(const Node &node) :
      Component{
         content.index,
         content.label,
         content.unit
      }
   {
      query(node);
      construct(node);
   }

   // from fields
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
      construct();
   }

   // ------------------------
   // assignment
   // ------------------------

   // copy
   Axis &operator=(const Axis &) = default;

   // move
   Axis &operator=(Axis &&) = default;

   // ------------------------
   // custom functionality
   // ------------------------

   #include "GNDStk/v1.9/containers/Axis/src/custom.hpp"

}; // class Axis

} // namespace containers

} // namespace v1_9
} // namespace GNDStk
} // namespace njoy

#endif
