
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_CONTAINERS_GRID
#define TEST_V2_0_CONTAINERS_GRID

#include "test/v2.0/containers/Values.hpp"
#include "test/v2.0/containers/Link.hpp"

namespace test {
namespace v2_0 {
namespace containers {

// -----------------------------------------------------------------------------
// containers::
// class Grid
// -----------------------------------------------------------------------------

class Grid : public Component<containers::Grid> {
   friend class Component;

   using _t = std::variant<
      containers::Values,
      containers::Link
   >;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "containers"; }
   static auto CLASS() { return "Grid"; }
   static auto FIELD() { return "grid"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
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
         _t{}
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
   Field<std::optional<Integer32>> index{this};
   Field<Defaulted<enums::Interpolation>> interpolation{this,defaults.interpolation};
   Field<std::optional<XMLName>> label{this};
   Field<std::optional<UTF8Text>> style{this};
   Field<std::optional<XMLName>> unit{this};

   // children - variant
   Field<_t> _valueslink{this};
   FieldPart<decltype(_valueslink),containers::Values> values{_valueslink};
   FieldPart<decltype(_valueslink),containers::Link> link{_valueslink};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->index, \
      this->interpolation, \
      this->label, \
      this->style, \
      this->unit, \
      this->_valueslink)

   // default, and from fields
   // std::optional replaces Defaulted; this class knows the default(s)
   explicit Grid(
      const wrapper<std::optional<Integer32>> &index = {},
      const wrapper<std::optional<enums::Interpolation>> &interpolation = {},
      const wrapper<std::optional<XMLName>> &label = {},
      const wrapper<std::optional<UTF8Text>> &style = {},
      const wrapper<std::optional<XMLName>> &unit = {},
      const wrapper<_t> &_valueslink = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      index(this,index),
      interpolation(this,defaults.interpolation,interpolation),
      label(this,label),
      style(this,style),
      unit(this,unit),
      _valueslink(this,_valueslink)
   {
      Component::finish();
   }

   // from node
   explicit Grid(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Grid(const Grid &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Grid(Grid &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Grid &operator=(const Grid &) = default;
   Grid &operator=(Grid &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/containers/Grid/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Grid

} // namespace containers
} // namespace v2_0
} // namespace test

#endif
