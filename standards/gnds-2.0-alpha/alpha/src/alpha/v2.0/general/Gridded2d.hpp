
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_GRIDDED2D
#define ALPHA_V2_0_GENERAL_GRIDDED2D

#include "alpha/v2.0/general/Axes.hpp"
#include "alpha/v2.0/g2d/Array.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Gridded2d
// -----------------------------------------------------------------------------

class Gridded2d :
   public Component<general::Gridded2d>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Gridded2d"; }
   static auto FIELD() { return "gridded2d"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<general::Axes>
            ("axes") |
         --Child<g2d::Array>
            ("array")
      ;
   }

public:
   using component_t = Component;
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<general::Axes>
      axes{this};
   Field<g2d::Array>
      array{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->axes, \
      this->array \
   )

   // default
   Gridded2d() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Gridded2d(
      const wrapper<general::Axes>
         &axes,
      const wrapper<g2d::Array>
         &array = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      axes(this,axes),
      array(this,array)
   {
      Component::finish();
   }

   // from node
   explicit Gridded2d(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Gridded2d(const Gridded2d &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      axes(this,other.axes),
      array(this,other.array)
   {
      Component::finish(other);
   }

   // move
   Gridded2d(Gridded2d &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      axes(this,std::move(other.axes)),
      array(this,std::move(other.array))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Gridded2d &operator=(const Gridded2d &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         axes = other.axes;
         array = other.array;
      }
      return *this;
   }

   // move
   Gridded2d &operator=(Gridded2d &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         axes = std::move(other.axes);
         array = std::move(other.array);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/Gridded2d/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Gridded2d

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
