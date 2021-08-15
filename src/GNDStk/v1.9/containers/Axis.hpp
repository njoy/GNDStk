
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
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "containers"; }
   static auto className() { return "Axis"; }
   static auto GNDSName() { return "axis"; }

   // Core Interface object to extract metadata and child nodes
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

   using Component::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static const struct {
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      std::optional<Integer32> index;
      std::optional<XMLName> label;
      std::optional<XMLName> unit;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // index
   const std::optional<Integer32> &index() const
    { return content.index; }
   std::optional<Integer32> &index()
    { return content.index; }

   // label
   const std::optional<XMLName> &label() const
    { return content.label; }
   std::optional<XMLName> &label()
    { return content.label; }

   // unit
   const std::optional<XMLName> &unit() const
    { return content.unit; }
   std::optional<XMLName> &unit()
    { return content.unit; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // index(value)
   Axis &index(const std::optional<Integer32> &obj)
    { index() = obj; return *this; }

   // label(value)
   Axis &label(const std::optional<XMLName> &obj)
    { label() = obj; return *this; }

   // unit(value)
   Axis &unit(const std::optional<XMLName> &obj)
    { unit() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Axis() :
      Component{
         BodyText{},
         content.index,
         content.label,
         content.unit
      }
   {
      Component::finish();
   }

   // copy
   Axis(const Axis &other) :
      Component{
         other,
         content.index,
         content.label,
         content.unit
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Axis(Axis &&other) :
      Component{
         other,
         content.index,
         content.label,
         content.unit
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Axis(const Node &node) :
      Component{
         BodyText{},
         content.index,
         content.label,
         content.unit
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Axis(
      const std::optional<Integer32> &index,
      const std::optional<XMLName> &label,
      const std::optional<XMLName> &unit
   ) :
      Component{
         BodyText{},
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
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Axis &operator=(const Axis &) = default;

   // move
   Axis &operator=(Axis &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v1.9/containers/Axis/src/custom.hpp"

}; // class Axis

} // namespace containers
} // namespace v1_9
} // namespace GNDStk
} // namespace njoy

#endif
