
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
   // For Component
   // ------------------------

   friend class Component<Grid>;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "containers"; }
   static auto className() { return "Grid"; }
   static auto GNDSName() { return "grid"; }

   // Core Interface construct to extract metadata and child nodes
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
   // Re: base classes
   // ------------------------

   using BaseComponent = Component<Grid>;
   using BaseBodyText = BodyText<false>;
   using BaseComponent::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static const struct {
      const enums::Interpolation interpolation{enums::Interpolation::linlin};
   } defaults;

   // ------------------------
   // Raw GNDS content
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
   // Getters
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

   // link
   auto link() const
    { return getter<containers::Link>(choice(), "link"); }
   auto link()
    { return getter<containers::Link>(choice(), "link"); }

   // values
   auto values() const
    { return getter<containers::Values>(choice(), "values"); }
   auto values()
    { return getter<containers::Values>(choice(), "values"); }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // index(value)
   auto &index(const std::optional<Integer32> &obj)
    { index() = obj; return *this; }

   // interpolation(value)
   auto &interpolation(const Defaulted<enums::Interpolation> &obj)
    { content.interpolation = obj; return *this; }
   auto &interpolation(const enums::Interpolation &obj)
    { content.interpolation = obj; return *this; }

   // label(value)
   auto &label(const std::optional<XMLName> &obj)
    { label() = obj; return *this; }

   // style(value)
   auto &style(const std::optional<UTF8Text> &obj)
    { style() = obj; return *this; }

   // unit(value)
   auto &unit(const std::optional<XMLName> &obj)
    { unit() = obj; return *this; }

   // choice(value)
   auto &choice(const VARIANT &obj)
    { choice() = obj; return *this; }

   // link(value)
   auto &link(const std::optional<containers::Link> &obj)
    { if (obj) choice(obj.value()); return *this; }

   // values(value)
   auto &values(const std::optional<containers::Values> &obj)
    { if (obj) choice(obj.value()); return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Grid() :
      Component{
         BaseBodyText{},
         content.index,
         content.interpolation,
         content.label,
         content.style,
         content.unit,
         content.choice
      }
   {
      bodyTextUpdate(content);
      construct();
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
         content.choice
      },
      content{other.content}
   {
      bodyTextUpdate(content);
      construct(other);
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
         content.choice
      },
      content{std::move(other.content)}
   {
      bodyTextUpdate(content);
      construct(other);
   }

   // from node
   Grid(const Node &node) :
      Component{
         BaseBodyText{},
         content.index,
         content.interpolation,
         content.label,
         content.style,
         content.unit,
         content.choice
      }
   {
      fromNode(node);
      bodyTextUpdate(content);
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
         BaseBodyText{},
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
      bodyTextUpdate(content);
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
         BaseBodyText{},
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
      bodyTextUpdate(content);
      construct();
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
