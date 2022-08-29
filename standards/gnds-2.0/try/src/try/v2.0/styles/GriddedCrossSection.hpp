
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_STYLES_GRIDDEDCROSSSECTION
#define TRY_V2_0_STYLES_GRIDDEDCROSSSECTION

#include "try/v2.0/unknownNamespace/Grid.hpp"
#include "try/v2.0/documentation/Documentation.hpp"

namespace try {
namespace v2_0 {
namespace styles {

// -----------------------------------------------------------------------------
// styles::
// class GriddedCrossSection
// -----------------------------------------------------------------------------

class GriddedCrossSection : public Component<styles::GriddedCrossSection> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "styles"; }
   static auto CLASS() { return "GriddedCrossSection"; }
   static auto FIELD() { return "griddedCrossSection"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::string{}
            / Meta<>("date") |
         XMLName{}
            / Meta<>("derivedFrom") |
         XMLName{}
            / Meta<>("label") |
         // children
         unknownNamespace::Grid{}
            / --Child<>("grid") |
         std::optional<documentation::Documentation>{}
            / --Child<>("documentation")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::string> date{this};
   Field<XMLName> derivedFrom{this};
   Field<XMLName> label{this};

   // children
   Field<unknownNamespace::Grid> grid{this};
   Field<std::optional<documentation::Documentation>> documentation{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->date, \
      this->derivedFrom, \
      this->label, \
      this->grid, \
      this->documentation)

   // default, and from fields
   explicit GriddedCrossSection(
      const wrapper<std::string> &date = {},
      const wrapper<XMLName> &derivedFrom = {},
      const wrapper<XMLName> &label = {},
      const wrapper<unknownNamespace::Grid> &grid = {},
      const wrapper<std::optional<documentation::Documentation>> &documentation = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      date(this,date),
      derivedFrom(this,derivedFrom),
      label(this,label),
      grid(this,grid),
      documentation(this,documentation)
   {
      Component::finish();
   }

   // from node
   explicit GriddedCrossSection(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   GriddedCrossSection(const GriddedCrossSection &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   GriddedCrossSection(GriddedCrossSection &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   GriddedCrossSection &operator=(const GriddedCrossSection &) = default;
   GriddedCrossSection &operator=(GriddedCrossSection &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/styles/GriddedCrossSection/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class GriddedCrossSection

} // namespace styles
} // namespace v2_0
} // namespace try

#endif
