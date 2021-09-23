
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V1_9_CONTAINERS_AXES
#define NJOY_GNDSTK_V1_9_CONTAINERS_AXES

// core interface
#include "GNDStk.hpp"

// v1.9 dependencies
#include "GNDStk/v1.9/containers/Axis.hpp"
#include "GNDStk/v1.9/containers/Grid.hpp"

namespace njoy {
namespace GNDStk {
namespace v1_9 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// containers::
// class Axes
// -----------------------------------------------------------------------------

namespace containers {

class Axes : public Component<Axes> {

   using AXIS_GRID = std::variant<
      containers::Axis,
      containers::Grid
   >;

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "containers"; }
   static auto className() { return "Axes"; }
   static auto GNDSName() { return "axes"; }

   // Core Interface object to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         std::optional<UTF8Text>{}
            / Meta<>("href") |
         // children
         AXIS_GRID{}
            / ++(Child<>("axis") || Child<>("grid"))
      ;
   }

public:

   using Component::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static inline const struct Defaults {
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      std::optional<UTF8Text> href;

      // children
      std::vector<AXIS_GRID> axis_grid;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // href
   const std::optional<UTF8Text> &href() const
    { return content.href; }
   std::optional<UTF8Text> &href()
    { return content.href; }

   // axis_grid
   const std::vector<AXIS_GRID> &axis_grid() const
    { return content.axis_grid; }
   std::vector<AXIS_GRID> &axis_grid()
    { return content.axis_grid; }

   // axis_grid(index)
   const AXIS_GRID &axis_grid(const std::size_t index) const
    { return getter(axis_grid(), index, "axis_grid"); }
   AXIS_GRID &axis_grid(const std::size_t index)
    { return getter(axis_grid(), index, "axis_grid"); }

   // axis_grid(label)
   const AXIS_GRID &axis_grid(const std::string &label) const
    { return getter(axis_grid(), label, "axis_grid"); }
   AXIS_GRID &axis_grid(const std::string &label)
    { return getter(axis_grid(), label, "axis_grid"); }

   // axis(index)
   const containers::Axis *axis(const std::size_t index) const
    { return getter<containers::Axis>(axis_grid(), index, "axis"); }
   containers::Axis *axis(const std::size_t index)
    { return getter<containers::Axis>(axis_grid(), index, "axis"); }

   // axis(label)
   const containers::Axis *axis(const std::string &label) const
    { return getter<containers::Axis>(axis_grid(), label, "axis"); }
   containers::Axis *axis(const std::string &label)
    { return getter<containers::Axis>(axis_grid(), label, "axis"); }

   // grid(index)
   const containers::Grid *grid(const std::size_t index) const
    { return getter<containers::Grid>(axis_grid(), index, "grid"); }
   containers::Grid *grid(const std::size_t index)
    { return getter<containers::Grid>(axis_grid(), index, "grid"); }

   // grid(label)
   const containers::Grid *grid(const std::string &label) const
    { return getter<containers::Grid>(axis_grid(), label, "grid"); }
   containers::Grid *grid(const std::string &label)
    { return getter<containers::Grid>(axis_grid(), label, "grid"); }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // href(value)
   Axes &href(const std::optional<UTF8Text> &obj)
    { href() = obj; return *this; }

   // axis_grid(value)
   Axes &axis_grid(const std::vector<AXIS_GRID> &obj)
    { axis_grid() = obj; return *this; }

   // axis_grid(index,value)
   Axes &axis_grid(
      const std::size_t index,
      const AXIS_GRID &obj
   ) {
      axis_grid(index) = obj; return *this;
   }

   // axis_grid(label,value)
   Axes &axis_grid(
      const std::string &label,
      const AXIS_GRID &obj
   ) {
      axis_grid(label) = obj; return *this;
   }

   // axis(index,value)
   Axes &axis(
      const std::size_t index,
      const std::optional<containers::Axis> &obj
   ) {
      if (obj) axis_grid(index,obj.value());
      return *this;
   }

   // axis(label,value)
   Axes &axis(
      const std::string &label,
      const std::optional<containers::Axis> &obj
   ) {
      if (obj) axis_grid(label,obj.value());
      return *this;
   }

   // grid(index,value)
   Axes &grid(
      const std::size_t index,
      const std::optional<containers::Grid> &obj
   ) {
      if (obj) axis_grid(index,obj.value());
      return *this;
   }

   // grid(label,value)
   Axes &grid(
      const std::string &label,
      const std::optional<containers::Grid> &obj
   ) {
      if (obj) axis_grid(label,obj.value());
      return *this;
   }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Axes() :
      Component{
         BodyText{},
         content.href,
         content.axis_grid
      }
   {
      Component::finish();
   }

   // copy
   Axes(const Axes &other) :
      Component{
         other,
         content.href,
         content.axis_grid
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Axes(Axes &&other) :
      Component{
         other,
         content.href,
         content.axis_grid
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Axes(const Node &node) :
      Component{
         BodyText{},
         content.href,
         content.axis_grid
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Axes(
      const std::optional<UTF8Text> &href,
      const std::vector<AXIS_GRID> &axis_grid
   ) :
      Component{
         BodyText{},
         content.href,
         content.axis_grid
      },
      content{
         href,
         axis_grid
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Axes &operator=(const Axes &) = default;

   // move
   Axes &operator=(Axes &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v1.9/containers/Axes/src/custom.hpp"

}; // class Axes

} // namespace containers
} // namespace v1_9
} // namespace GNDStk
} // namespace njoy

#endif
