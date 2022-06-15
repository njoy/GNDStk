
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDSTK_V1_9_CONTAINERS_AXES
#define GNDSTK_V1_9_CONTAINERS_AXES

#include "GNDStk/v1.9/containers/Axis.hpp"
#include "GNDStk/v1.9/containers/Grid.hpp"

namespace njoy {
namespace GNDStk {
namespace v1_9 {
namespace containers {

// -----------------------------------------------------------------------------
// containers::
// class Axes
// -----------------------------------------------------------------------------

class Axes : public Component<containers::Axes> {
   friend class Component;

   using axis_grid_t = std::variant<
      containers::Axis,
      containers::Grid
   >;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "containers"; }
   static auto CLASS() { return "Axes"; }
   static auto FIELD() { return "axes"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::optional<std::string>{}
            / Meta<>("href") |
         // children
         axis_grid_t{}
            / ++(Child<>("axis") || Child<>("grid"))
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::optional<std::string>> href{this};

   // children - variant
   Field<std::vector<axis_grid_t>> axis_grid{this};
   FieldPart<decltype(axis_grid),containers::Axis> axis{axis_grid};
   FieldPart<decltype(axis_grid),containers::Grid> grid{axis_grid};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->href, \
      this->axis_grid)

   // default, and from fields
   explicit Axes(
      const wrapper<std::optional<std::string>> &href = {},
      const wrapper<std::vector<axis_grid_t>> &axis_grid = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      href(this,href),
      axis_grid(this,axis_grid),
      axis(this->axis_grid),
      grid(this->axis_grid)
   {
      Component::finish();
   }

   // from node
   Axes(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Axes(const Axes &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Axes(Axes &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Axes &operator=(const Axes &) = default;
   Axes &operator=(Axes &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v1.9/containers/Axes/src/custom.hpp"
   #undef GNDSTK_COMPONENT

}; // class Axes

} // namespace containers
} // namespace v1_9
} // namespace GNDStk
} // namespace njoy

#endif
