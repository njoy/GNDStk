
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

   // ------------------------
   // for Component
   // ------------------------

   friend class Component<Axes>;

   static auto className() { return "Axes"; }
   static auto GNDSField() { return "axes"; }

   static auto keys()
   {
      return
         // metadata
         std::optional<UTF8Text>{}
            / Meta<>("href") |
         // children
         std::optional<containers::Axis>{}
            / ++Child<>("axis") |
         std::optional<containers::Grid>{}
            / ++Child<>("grid")
      ;
   }

public:

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
      std::optional<UTF8Text> href;

      // children
      std::optional<std::vector<containers::Axis>> axis;
      std::optional<std::vector<containers::Grid>> grid;
   } content;

   // ------------------------
   // getters
   // const and non-const
   // ------------------------

   // href
   const auto &href() const
    { return content.href; }
   auto &href()
    { return content.href; }

   // axis
   const auto &axis() const
    { return content.axis; }
   auto &axis()
    { return content.axis; }

   // axis(n)
   const auto &axis(const std::size_t n) const
    { return detail::getter(axis(),n,"containers",className(),"axis"); }
   auto &axis(const std::size_t n)
    { return detail::getter(axis(),n,"containers",className(),"axis"); }

   // grid
   const auto &grid() const
    { return content.grid; }
   auto &grid()
    { return content.grid; }

   // grid(n)
   const auto &grid(const std::size_t n) const
    { return detail::getter(grid(),n,"containers",className(),"grid"); }
   auto &grid(const std::size_t n)
    { return detail::getter(grid(),n,"containers",className(),"grid"); }

   // ------------------------
   // setters
   // non-const only
   // ------------------------

   // href
   auto &href(const std::optional<UTF8Text> &obj)
    { content.href = obj; return *this; }

   // axis
   auto &axis(const std::optional<std::vector<containers::Axis>> &obj)
    { content.axis = obj; return *this; }

   // grid
   auto &grid(const std::optional<std::vector<containers::Grid>> &obj)
    { content.grid = obj; return *this; }

   // ------------------------
   // construction
   // ------------------------

   // default
   Axes() :
      Component{
         content.href,
         content.axis,
         content.grid
      }
   {
      construct();
   }

   // copy
   Axes(const Axes &other) :
      Component{
         content.href,
         content.axis,
         content.grid
      },
      content{other.content}
   {
      construct();
   }

   // move
   Axes(Axes &&other) :
      Component{
         content.href,
         content.axis,
         content.grid
      },
      content{std::move(other.content)}
   {
      construct();
   }

   // from node
   Axes(const Node &node) :
      Component{
         content.href,
         content.axis,
         content.grid
      }
   {
      query(node);
      construct();
   }

   // from fields
   explicit Axes(
      const std::optional<UTF8Text> &href,
      const std::optional<std::vector<containers::Axis>> &axis,
      const std::optional<std::vector<containers::Grid>> &grid
   ) :
      Component{
         content.href,
         content.axis,
         content.grid
      },
      content{
         href,
         axis,
         grid
      }
   {
      construct();
   }

   // ------------------------
   // assignment
   // ------------------------

   // copy
   Axes &operator=(const Axes &) = default;

   // move
   Axes &operator=(Axes &&) = default;

   // ------------------------
   // custom functionality
   // ------------------------

   #include "GNDStk/v1.9/containers/Axes/src/custom.hpp"

}; // class Axes

} // namespace containers

} // namespace v1_9
} // namespace GNDStk
} // namespace njoy

#endif
