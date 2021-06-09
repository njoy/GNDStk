
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
   // For Component
   // ------------------------

   friend class Component<Axes>;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "containers"; }
   static auto className() { return "Axes"; }
   static auto GNDSName() { return "axes"; }

   // Core Interface construct to extract metadata and child nodes
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

   // Base classes
   using BaseComponent = Component<Axes>;
   using BaseBodyText = BodyText<false>;
   using BaseComponent::construct;

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
      std::optional<UTF8Text> href;

      // children
      std::optional<std::vector<containers::Axis>> axis;
      std::optional<std::vector<containers::Grid>> grid;
   } content;

   // ------------------------
   // Getters
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
    { return getter(axis(),n,"axis"); }
   auto &axis(const std::size_t n)
    { return getter(axis(),n,"axis"); }

   // axis(label)
   const auto &axis(const std::string &label) const
    { return getter(axis(),label,"axis"); }
   auto &axis(const std::string &label)
    { return getter(axis(),label,"axis"); }

   // grid
   const auto &grid() const
    { return content.grid; }
   auto &grid()
    { return content.grid; }

   // grid(n)
   const auto &grid(const std::size_t n) const
    { return getter(grid(),n,"grid"); }
   auto &grid(const std::size_t n)
    { return getter(grid(),n,"grid"); }

   // grid(label)
   const auto &grid(const std::string &label) const
    { return getter(grid(),label,"grid"); }
   auto &grid(const std::string &label)
    { return getter(grid(),label,"grid"); }

   // ------------------------
   // Setters
   // non-const
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
   // Construction
   // ------------------------

   // default
   Axes() :
      Component{
         BaseBodyText{},
         content.href,
         content.axis,
         content.grid
      }
   {
      bodyTextUpdate(content);
      construct();
   }

   // copy
   Axes(const Axes &other) :
      Component{
         other,
         content.href,
         content.axis,
         content.grid
      },
      content{other.content}
   {
      bodyTextUpdate(content);
      construct(other);
   }

   // move
   Axes(Axes &&other) :
      Component{
         other,
         content.href,
         content.axis,
         content.grid
      },
      content{std::move(other.content)}
   {
      bodyTextUpdate(content);
      construct(other);
   }

   // from node
   Axes(const Node &node) :
      Component{
         BaseBodyText{},
         content.href,
         content.axis,
         content.grid
      }
   {
      fromNode(node);
      bodyTextUpdate(content);
      construct(node);
   }

   // from fields
   explicit Axes(
      const std::optional<UTF8Text> &href,
      const std::optional<std::vector<containers::Axis>> &axis,
      const std::optional<std::vector<containers::Grid>> &grid
   ) :
      Component{
         BaseBodyText{},
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
      bodyTextUpdate(content);
      construct();
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
