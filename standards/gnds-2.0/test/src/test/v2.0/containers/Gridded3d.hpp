
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_CONTAINERS_GRIDDED3D
#define TEST_V2_0_CONTAINERS_GRIDDED3D

#include "test/v2.0/containers/Array.hpp"
#include "test/v2.0/containers/Axes.hpp"

namespace test {
namespace v2_0 {
namespace containers {

// -----------------------------------------------------------------------------
// containers::
// class Gridded3d
// -----------------------------------------------------------------------------

class Gridded3d :
   public Component<containers::Gridded3d>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "containers"; }
   static auto CLASS() { return "Gridded3d"; }
   static auto FIELD() { return "gridded3d"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::optional<XMLName>{}
            / Meta<>("label") |

         // children
         --Child<containers::Array>("array") |
         --Child<containers::Axes>("axes")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::optional<XMLName>> label{this};

   // children
   Field<containers::Array> array{this};
   Field<containers::Axes> axes{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->label, \
      this->array, \
      this->axes)

   // default
   Gridded3d() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Gridded3d(
      const wrapper<std::optional<XMLName>> &label,
      const wrapper<containers::Array> &array = {},
      const wrapper<containers::Axes> &axes = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      array(this,array),
      axes(this,axes)
   {
      Component::finish();
   }

   // from node
   explicit Gridded3d(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Gridded3d(const Gridded3d &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      array(this,other.array),
      axes(this,other.axes)
   {
      Component::finish(other);
   }

   // move
   Gridded3d(Gridded3d &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      array(this,std::move(other.array)),
      axes(this,std::move(other.axes))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Gridded3d &operator=(const Gridded3d &) = default;
   Gridded3d &operator=(Gridded3d &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/containers/Gridded3d/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Gridded3d

} // namespace containers
} // namespace v2_0
} // namespace test

#endif
