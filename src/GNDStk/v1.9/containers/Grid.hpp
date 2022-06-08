
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDSTK_V1_9_CONTAINERS_GRID
#define GNDSTK_V1_9_CONTAINERS_GRID

#include "GNDStk/v1.9/key.hpp"
#include "GNDStk/v1.9/containers/Values.hpp"
#include "GNDStk/v1.9/containers/Link.hpp"

namespace njoy {
namespace GNDStk {
namespace v1_9 {


// -----------------------------------------------------------------------------
// containers::
// class Grid
// -----------------------------------------------------------------------------

namespace containers {

class Grid : public Component<containers::Grid> {

   using link_values_t = std::variant<
      containers::Values,
      containers::Link
   >;

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Names: this namespace, this class, a field / node of this type
   static auto NAMESPACE() { return "containers"; }
   static auto CLASS() { return "Grid"; }
   static auto FIELD() { return "grid"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
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

   // defaults
   static inline const struct Defaults {
      static inline const enums::Interpolation interpolation = enums::Interpolation::linlin;
   } defaults;

   // metadata
   Field<Grid,std::optional<int>> index;
   Field<Grid,Defaulted<enums::Interpolation>> interpolation;
   Field<Grid,std::optional<std::string>> label;
   Field<Grid,std::optional<enums::GridStyle>> style;
   Field<Grid,std::optional<std::string>> unit;
   // children - variant
   Field<Grid,link_values_t> link_values;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

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
      const std::optional<int> &index = {},
      const std::optional<enums::Interpolation> &interpolation = {},
      const std::optional<std::string> &label = {},
      const std::optional<enums::GridStyle> &style = {},
      const std::optional<std::string> &unit = {},
      const link_values_t &link_values = {}
   ) :
      Component{
         BlockData{},
         this->index,
         this->interpolation,
         this->label,
         this->style,
         this->unit,
         this->link_values
      },
      index(this,index,"index"),
      interpolation(this,defaults.interpolation,interpolation,"interpolation"),
      label(this,label,"label"),
      style(this,style,"style"),
      unit(this,unit,"unit"),
      link_values(this,link_values,"link_values")
   {
      Component::finish();
   }

   // copy
   Grid(const Grid &other) :
      Component{
         other.baseBlockData(),
         this->index,
         this->interpolation,
         this->label,
         this->style,
         this->unit,
         this->link_values
      },
      index(this,other.index),
      interpolation(this,other.interpolation),
      label(this,other.label),
      style(this,other.style),
      unit(this,other.unit),
      link_values(this,other.link_values)
   {
      Component::finish(other);
   }

   // move
   Grid(Grid &&other) :
      Component{
         other.baseBlockData(),
         this->index,
         this->interpolation,
         this->label,
         this->style,
         this->unit,
         this->link_values
      },
      index(this,std::move(other.index)),
      interpolation(this,std::move(other.interpolation)),
      label(this,std::move(other.label)),
      style(this,std::move(other.style)),
      unit(this,std::move(other.unit)),
      link_values(this,std::move(other.link_values))
   {
      Component::finish(other);
   }

   // from node
   Grid(const Node &node) :
      Component{
         BlockData{},
         this->index,
         this->interpolation,
         this->label,
         this->style,
         this->unit,
         this->link_values
      },
      index(this,{},"index"),
      interpolation(this,defaults.interpolation,{},"interpolation"),
      label(this,{},"label"),
      style(this,{},"style"),
      unit(this,{},"unit"),
      link_values(this,{},"link_values")
   {
      Component::finish(node);
   }

   // ------------------------
   // Assignment
   // ------------------------

   Grid &operator=(const Grid &) = default;
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
