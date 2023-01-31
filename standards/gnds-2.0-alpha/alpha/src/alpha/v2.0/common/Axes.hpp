
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_COMMON_AXES
#define ALPHA_V2_0_COMMON_AXES

#include "alpha/v2.0/common/Axis.hpp"
#include "alpha/v2.0/common/Grid.hpp"

namespace alpha {
namespace v2_0 {
namespace common {

// -----------------------------------------------------------------------------
// common::
// class Axes
// -----------------------------------------------------------------------------

class Axes :
   public Component<common::Axes>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "common"; }
   static auto CLASS() { return "Axes"; }
   static auto FIELD() { return "axes"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<common::Axis>("axis") |
         ++Child<std::optional<common::Grid>>("grid")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<std::vector<common::Axis>> axis{this};
   Field<std::optional<std::vector<common::Grid>>> grid{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->axis, \
      this->grid)

   // default
   Axes() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Axes(
      const wrapper<std::vector<common::Axis>> &axis,
      const wrapper<std::optional<std::vector<common::Grid>>> &grid = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      axis(this,axis),
      grid(this,grid)
   {
      Component::finish();
   }

   // from node
   explicit Axes(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Axes(const Axes &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      axis(this,other.axis),
      grid(this,other.grid)
   {
      Component::finish(other);
   }

   // move
   Axes(Axes &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      axis(this,std::move(other.axis)),
      grid(this,std::move(other.grid))
   {
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

   #include "alpha/v2.0/common/Axes/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Axes

} // namespace common
} // namespace v2_0
} // namespace alpha

#endif
