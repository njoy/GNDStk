
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V1_9_CONTAINERS_GRID
#define NJOY_GNDSTK_V1_9_CONTAINERS_GRID

// core interface
#include "GNDStk.hpp"

// v1.9 dependencies
#include "GNDStk/v1.9/containers/Link.hpp"
#include "GNDStk/v1.9/containers/Values.hpp"

namespace njoy {
namespace GNDStk {
namespace v1_9 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// containers::
// class Grid
// -----------------------------------------------------------------------------

namespace containers {

class Grid : public Component<Grid> {

   using LINK_VALUES = std::variant<
      containers::Link,
      containers::Values
   >;

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "containers"; }
   static auto className() { return "Grid"; }
   static auto GNDSName() { return "grid"; }

   // Core Interface object to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         std::optional<Integer32>{}
            / Meta<>("index") |
         Defaulted<enums::Interpolation>{enums::Interpolation::linlin}
            / Meta<>("interpolation") |
         std::optional<XMLName>{}
            / Meta<>("label") |
         std::optional<enums::GridStyle>{}
            / Meta<>("style") |
         std::optional<XMLName>{}
            / Meta<>("unit") |
         // children
         LINK_VALUES{}
            / --(Child<>("link") || Child<>("values"))
      ;
   }

public:

   using Component::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static struct {
      static enums::Interpolation interpolation()
      {
         return enums::Interpolation::linlin;
      }
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      std::optional<Integer32> index;
      Defaulted<enums::Interpolation> interpolation{enums::Interpolation::linlin};
      std::optional<XMLName> label;
      std::optional<enums::GridStyle> style;
      std::optional<XMLName> unit;

      // children
      LINK_VALUES link_values;
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

   // interpolation
   const Defaulted<enums::Interpolation> &interpolation() const
    { return content.interpolation; }
   Defaulted<enums::Interpolation> &interpolation()
    { return content.interpolation; }

   // label
   const std::optional<XMLName> &label() const
    { return content.label; }
   std::optional<XMLName> &label()
    { return content.label; }

   // style
   const std::optional<enums::GridStyle> &style() const
    { return content.style; }
   std::optional<enums::GridStyle> &style()
    { return content.style; }

   // unit
   const std::optional<XMLName> &unit() const
    { return content.unit; }
   std::optional<XMLName> &unit()
    { return content.unit; }

   // link_values
   const LINK_VALUES &link_values() const
    { return content.link_values; }
   LINK_VALUES &link_values()
    { return content.link_values; }

   // link
   const containers::Link *link() const
    { return getter<containers::Link>(link_values(), "link"); }
   containers::Link *link()
    { return getter<containers::Link>(link_values(), "link"); }

   // values
   const containers::Values *values() const
    { return getter<containers::Values>(link_values(), "values"); }
   containers::Values *values()
    { return getter<containers::Values>(link_values(), "values"); }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // index(value)
   Grid &index(const std::optional<Integer32> &obj)
    { index() = obj; return *this; }

   // interpolation(value)
   Grid &interpolation(const Defaulted<enums::Interpolation> &obj)
    { content.interpolation = obj; return *this; }
   Grid &interpolation(const std::optional<enums::Interpolation> &obj)
    { content.interpolation = obj; return *this; }

   // label(value)
   Grid &label(const std::optional<XMLName> &obj)
    { label() = obj; return *this; }

   // style(value)
   Grid &style(const std::optional<enums::GridStyle> &obj)
    { style() = obj; return *this; }

   // unit(value)
   Grid &unit(const std::optional<XMLName> &obj)
    { unit() = obj; return *this; }

   // link_values(value)
   Grid &link_values(const LINK_VALUES &obj)
    { link_values() = obj; return *this; }

   // link(value)
   Grid &link(const std::optional<containers::Link> &obj)
    { if (obj) link_values(obj.value()); return *this; }

   // values(value)
   Grid &values(const std::optional<containers::Values> &obj)
    { if (obj) link_values(obj.value()); return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Grid() :
      Component{
         BodyText{},
         content.index,
         content.interpolation,
         content.label,
         content.style,
         content.unit,
         content.link_values
      }
   {
      Component::finish();
   }

   // copy
   Grid(const Grid &other) :
      Component{
         other,
         content.index,
         content.interpolation,
         content.label,
         content.style,
         content.unit,
         content.link_values
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Grid(Grid &&other) :
      Component{
         other,
         content.index,
         content.interpolation,
         content.label,
         content.style,
         content.unit,
         content.link_values
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Grid(const Node &node) :
      Component{
         BodyText{},
         content.index,
         content.interpolation,
         content.label,
         content.style,
         content.unit,
         content.link_values
      }
   {
      Component::finish(node);
   }

   // from fields
   // std::optional replaces Defaulted; this class knows the default(s)
   explicit Grid(
      const std::optional<Integer32> &index,
      const std::optional<enums::Interpolation> &interpolation,
      const std::optional<XMLName> &label,
      const std::optional<enums::GridStyle> &style,
      const std::optional<XMLName> &unit,
      const LINK_VALUES &link_values
   ) :
      Component{
         BodyText{},
         content.index,
         content.interpolation,
         content.label,
         content.style,
         content.unit,
         content.link_values
      },
      content{
         index,
         Defaulted<enums::Interpolation>(defaults.interpolation(),interpolation),
         label,
         style,
         unit,
         link_values
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Grid &operator=(const Grid &) = default;

   // move
   Grid &operator=(Grid &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v1.9/containers/Grid/src/custom.hpp"

}; // class Grid

} // namespace containers
} // namespace v1_9
} // namespace GNDStk
} // namespace njoy

#endif
