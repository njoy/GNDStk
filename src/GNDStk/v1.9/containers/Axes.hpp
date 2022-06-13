
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDSTK_V1_9_CONTAINERS_AXES
#define GNDSTK_V1_9_CONTAINERS_AXES

#include "GNDStk/v1.9/containers/Axis.hpp"
#include "GNDStk/v1.9/containers/Grid.hpp"

namespace njoy {
namespace GNDStk {
namespace v1_9 {


// -----------------------------------------------------------------------------
// containers::
// class Axes
// -----------------------------------------------------------------------------

namespace containers {

class Axes : public Component<containers::Axes> {
   friend class Component;

   using axis_grid_t = std::variant<
      containers::Axis,
      containers::Grid
   >;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field / node of this type
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

   ///// but deal with [name]!

   // metadata
   Field<Axes,std::optional<std::string>> href{this};
   // children - variant
   Field<Axes,std::vector<axis_grid_t>> axis_grid{this};
   FieldPart<decltype(axis_grid),containers::Axis> axis{axis_grid};
   FieldPart<decltype(axis_grid),containers::Grid> grid{axis_grid};

   // ------------------------
   // Constructors
   // ------------------------

   // default, and from fields
   explicit Axes(
      const wrapper<std::optional<std::string>> &href = {},
      const wrapper<std::vector<axis_grid_t>> &axis_grid = {}
   ) :
      Component{
         BlockData{},
         this->href,
         this->axis_grid
      },
      href(this,href,"href"),
      axis_grid(this,axis_grid,"axis_grid"),
      axis(this->axis_grid,"axis"),
      grid(this->axis_grid,"grid")
   {
      Component::finish();
   }

   // from node
   Axes(const Node &node) :
      Component{
         BlockData{},
         href,
         axis_grid
      },
      href(this,{},"href"),
      axis_grid(this,{},"axis_grid"),
      axis(axis_grid,"axis"),
      grid(axis_grid,"grid")
   {
      Component::finish(node);
   }

   // copy
   Axes(const Axes &other) :
      Component{
         other.baseBlockData(),
         href,
         axis_grid
      }
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Axes(Axes &&other) :
      Component{
         other.baseBlockData(),
         href,
         axis_grid
      }
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment
   // ------------------------

   Axes &operator=(const Axes &) = default;
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
