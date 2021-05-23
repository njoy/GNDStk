
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

   using VARIANT = std::variant<
      containers::Link,
      containers::Values
   >;

   // ------------------------
   // for Component
   // ------------------------

   friend class Component<Grid>;

   static auto namespaceName() { return "containers"; }
   static auto className() { return "Grid"; }
   static auto GNDSName() { return "grid"; }

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
         std::optional<UTF8Text>{}
            / Meta<>("style") |
         std::optional<XMLName>{}
            / Meta<>("unit") |
         // children
         VARIANT{}
            / --Child<>("link values")
      ;
   }

public:

   // ------------------------
   // relevant defaults
   // FYI for users
   // ------------------------

   static const struct {
      const enums::Interpolation interpolation{enums::Interpolation::linlin};
   } defaults;

   // ------------------------
   // raw GNDS content
   // ------------------------

   struct {
      // metadata
      std::optional<Integer32> index;
      Defaulted<enums::Interpolation> interpolation{enums::Interpolation::linlin};
      std::optional<XMLName> label;
      std::optional<UTF8Text> style;
      std::optional<XMLName> unit;

      // children
      VARIANT choice;
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

   // interpolation
   const auto &interpolation() const
    { return content.interpolation.value(); }
   auto &interpolation()
    { return content.interpolation.value(); }

   // label
   const auto &label() const
    { return content.label; }
   auto &label()
    { return content.label; }

   // style
   const auto &style() const
    { return content.style; }
   auto &style()
    { return content.style; }

   // unit
   const auto &unit() const
    { return content.unit; }
   auto &unit()
    { return content.unit; }

   // choice
   const auto &choice() const
    { return content.choice; }
   auto &choice()
    { return content.choice; }

   // optional link
   auto link() const
   {
      return detail::getter<containers::Link>
         (choice(),namespaceName(),className(),"link");
   }

   // optional values
   auto values() const
   {
      return detail::getter<containers::Values>
         (choice(),namespaceName(),className(),"values");
   }

   // ------------------------
   // setters
   // non-const only
   // ------------------------

   // index
   auto &index(const std::optional<Integer32> &obj)
    { content.index = obj; return *this; }

   // interpolation
   auto &interpolation(const Defaulted<enums::Interpolation> &obj)
    { content.interpolation = obj; return *this; }
   auto &interpolation(const enums::Interpolation &obj)
    { content.interpolation = obj; return *this; }

   // label
   auto &label(const std::optional<XMLName> &obj)
    { content.label = obj; return *this; }

   // style
   auto &style(const std::optional<UTF8Text> &obj)
    { content.style = obj; return *this; }

   // unit
   auto &unit(const std::optional<XMLName> &obj)
    { content.unit = obj; return *this; }

   // choice
   auto &choice(const VARIANT &obj)
    { content.choice = obj; return *this; }

   // link
   auto &link(const std::optional<containers::Link> &obj)
    { if (obj) choice(*obj); return *this; }

   // values
   auto &values(const std::optional<containers::Values> &obj)
    { if (obj) choice(*obj); return *this; }

   // ------------------------
   // construction
   // ------------------------

   // default
   Grid() :
      Component{
         content.index,
         content.interpolation,
         content.label,
         content.style,
         content.unit,
         content.choice
      }
   {
      construct();
   }

   // copy
   Grid(const Grid &other) :
      Component{
         content.index,
         content.interpolation,
         content.label,
         content.style,
         content.unit,
         content.choice
      },
      content{other.content}
   {
      construct(other);
   }

   // move
   Grid(Grid &&other) :
      Component{
         content.index,
         content.interpolation,
         content.label,
         content.style,
         content.unit,
         content.choice
      },
      content{std::move(other.content)}
   {
      construct(other);
   }

   // from node
   Grid(const Node &node) :
      Component{
         content.index,
         content.interpolation,
         content.label,
         content.style,
         content.unit,
         content.choice
      }
   {
      query(node);
      construct(node);
   }

   // from fields
   explicit Grid(
      const std::optional<Integer32> &index,
      const Defaulted<enums::Interpolation> &interpolation,
      const std::optional<XMLName> &label,
      const std::optional<UTF8Text> &style,
      const std::optional<XMLName> &unit,
      const VARIANT &choice
   ) :
      Component{
         content.index,
         content.interpolation,
         content.label,
         content.style,
         content.unit,
         content.choice
      },
      content{
         index,
         interpolation,
         label,
         style,
         unit,
         choice
      }
   {
      construct();
   }

   // from fields, with T replacing Defaulted<T>
   explicit Grid(
      const std::optional<Integer32> &index,
      const enums::Interpolation &interpolation,
      const std::optional<XMLName> &label,
      const std::optional<UTF8Text> &style,
      const std::optional<XMLName> &unit,
      const VARIANT &choice
   ) :
      Component{
         content.index,
         content.interpolation,
         content.label,
         content.style,
         content.unit,
         content.choice
      },
      content{
         index,
         interpolation == enums::Interpolation::linlin
            ? Defaulted<enums::Interpolation>{enums::Interpolation::linlin}
            : Defaulted<enums::Interpolation>{enums::Interpolation::linlin,interpolation},
         label,
         style,
         unit,
         choice
      }
   {
      construct();
   }

   // ------------------------
   // assignment
   // ------------------------

   // copy
   Grid &operator=(const Grid &) = default;

   // move
   Grid &operator=(Grid &&) = default;

   // ------------------------
   // custom functionality
   // ------------------------

   #include "GNDStk/v1.9/containers/Grid/src/custom.hpp"

}; // class Grid

} // namespace containers

} // namespace v1_9
} // namespace GNDStk
} // namespace njoy

#endif
