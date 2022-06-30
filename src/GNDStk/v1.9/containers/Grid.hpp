
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDSTK_V1_9_CONTAINERS_GRID
#define GNDSTK_V1_9_CONTAINERS_GRID

// GNDStk Core Interface
#include "GNDStk.hpp"

// Dependencies
#include "GNDStk/v1.9/containers/Values.hpp"
#include "GNDStk/v1.9/containers/Link.hpp"

namespace njoy {
namespace GNDStk {
namespace v1_9 {

using namespace njoy::GNDStk;



// -----------------------------------------------------------------------------
// containers::
// class Grid
// -----------------------------------------------------------------------------

namespace containers {

class Grid : public Component<Grid> {

   using link_values_t = std::variant<
      containers::Values,
      containers::Link
   >;

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "containers"; }
   static auto className() { return "Grid"; }
   static auto GNDSName() { return "grid"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         std::optional<int>{}
            / Meta<>("index") |
         Defaulted<enums::Interpolation>{enums::Interpolation::linlin}
            / Meta<>("interpolation") |
         std::optional<std::string>{}
            / Meta<>("label") |
         std::optional<enums::GridStyle>{}
            / Meta<>("style") |
         std::optional<std::string>{}
            / Meta<>("unit") |
         // children
         link_values_t{}
            / --(Child<>("values") || Child<>("link"))
      ;
   }

public:

   using Component::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static inline const struct Defaults {
      static inline const enums::Interpolation interpolation = enums::Interpolation::linlin;
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      std::optional<int> index;
      Defaulted<enums::Interpolation> interpolation{enums::Interpolation::linlin};
      std::optional<std::string> label;
      std::optional<enums::GridStyle> style;
      std::optional<std::string> unit;
      // children - variant
      link_values_t link_values;
   } Content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // index
   const std::optional<int> &index() const
      { return Content.index; }
   std::optional<int> &index()
      { return Content.index; }

   // interpolation
   const Defaulted<enums::Interpolation> &interpolation() const
      { return Content.interpolation; }
   Defaulted<enums::Interpolation> &interpolation()
      { return Content.interpolation; }

   // label
   const std::optional<std::string> &label() const
      { return Content.label; }
   std::optional<std::string> &label()
      { return Content.label; }

   // style
   const std::optional<enums::GridStyle> &style() const
      { return Content.style; }
   std::optional<enums::GridStyle> &style()
      { return Content.style; }

   // unit
   const std::optional<std::string> &unit() const
      { return Content.unit; }
   std::optional<std::string> &unit()
      { return Content.unit; }

   // link_values
   const link_values_t &link_values() const
      { return Content.link_values; }
   link_values_t &link_values()
      { return Content.link_values; }

   // values
   const containers::Values *values() const
      { return getter<containers::Values>(link_values(), "values"); }
   containers::Values *values()
      { return getter<containers::Values>(link_values(), "values"); }

   // link
   const containers::Link *link() const
      { return getter<containers::Link>(link_values(), "link"); }
   containers::Link *link()
      { return getter<containers::Link>(link_values(), "link"); }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // index(value)
   Grid &index(const std::optional<int> &obj)
      { index() = obj; return *this; }

   // interpolation(value)
   Grid &interpolation(const Defaulted<enums::Interpolation> &obj)
      { interpolation() = obj; return *this; }
   Grid &interpolation(const std::optional<enums::Interpolation> &obj)
      { interpolation() = obj; return *this; }

   // label(value)
   Grid &label(const std::optional<std::string> &obj)
      { label() = obj; return *this; }

   // style(value)
   Grid &style(const std::optional<enums::GridStyle> &obj)
      { style() = obj; return *this; }

   // unit(value)
   Grid &unit(const std::optional<std::string> &obj)
      { unit() = obj; return *this; }

   // link_values(value)
   Grid &link_values(const link_values_t &obj)
      { link_values() = obj; return *this; }

   // values(value)
   Grid &values(const std::optional<containers::Values> &obj)
      { if (obj) link_values(obj.value()); return *this; }

   // link(value)
   Grid &link(const std::optional<containers::Link> &obj)
      { if (obj) link_values(obj.value()); return *this; }

   // ------------------------
   // Constructors
   // ------------------------

   // default, and from fields
   // std::optional replaces Defaulted; this class knows the default(s)
   explicit Grid(
      const std::optional<int> &index =
         std::optional<int>{},
      const std::optional<enums::Interpolation> &interpolation =
         std::optional<enums::Interpolation>{},
      const std::optional<std::string> &label =
         std::optional<std::string>{},
      const std::optional<enums::GridStyle> &style =
         std::optional<enums::GridStyle>{},
      const std::optional<std::string> &unit =
         std::optional<std::string>{},
      const link_values_t &link_values =
         link_values_t{}
   ) :
      Component{
         BlockData{},
         this->index(),
         this->interpolation(),
         this->label(),
         this->style(),
         this->unit(),
         this->link_values()
      },
      Content{
         index,
         Defaulted<enums::Interpolation>(defaults.interpolation,interpolation),
         label,
         style,
         unit,
         link_values
      }
   {
      Component::finish();
   }

   // copy
   Grid(const Grid &other) :
      Component{
         other.baseBlockData(),
         this->index(),
         this->interpolation(),
         this->label(),
         this->style(),
         this->unit(),
         this->link_values()
      },
      Content{other.Content}
   {
      Component::finish(other);
   }

   // move
   Grid(Grid &&other) :
      Component{
         other.baseBlockData(),
         this->index(),
         this->interpolation(),
         this->label(),
         this->style(),
         this->unit(),
         this->link_values()
      },
      Content{std::move(other.Content)}
   {
      Component::finish(other);
   }

   // from node
   Grid(const Node &node) :
      Component{
         BlockData{},
         this->index(),
         this->interpolation(),
         this->label(),
         this->style(),
         this->unit(),
         this->link_values()
      }
   {
      Component::finish(node);
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
