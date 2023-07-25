
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_GRIDDED2D
#define GNDS_V2_0_GENERAL_GRIDDED2D

#include "gnds/v2.0/general/Axes.hpp"
#include "gnds/v2.0/g2d/Array.hpp"

namespace gnds {
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

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Gridded2d"; }
   static auto NODENAME() { return "gridded2d"; }

   // Core Interface multi-query to transfer information to/from core Nodes
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

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "axes",
         "array"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "axes",
         "array"
      };
      return names;
   }

   // ------------------------
   // Public interface
   // ------------------------

public:

   using component_t = Component;
   using Component::construct;

   // ------------------------
   // Data members
   // ------------------------

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<general::Axes>
      axes{this};
   Field<g2d::Array>
      array{this};

   // shortcuts
   #define GNDSTK_SHORTCUT(to,name) decltype(to.name) &name = to.name
   GNDSTK_SHORTCUT(axes(),axis);
   GNDSTK_SHORTCUT(axes(),grid);
   #undef GNDSTK_SHORTCUT

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

   #include "gnds/v2.0/general/Gridded2d/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Gridded2d

} // namespace general
} // namespace v2_0
} // namespace gnds

#endif
