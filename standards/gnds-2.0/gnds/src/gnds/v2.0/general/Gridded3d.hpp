
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_GRIDDED3D
#define GNDS_V2_0_GENERAL_GRIDDED3D

#include "gnds/v2.0/general/Axes.hpp"
#include "gnds/v2.0/g3d/Array.hpp"

namespace gnds {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Gridded3d
// -----------------------------------------------------------------------------

class Gridded3d :
   public Component<general::Gridded3d>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Gridded3d"; }
   static auto NODENAME() { return "gridded3d"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<general::Axes>
            ("axes") |
         --Child<g3d::Array>
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
   Field<g3d::Array>
      array{this};

   // shortcuts
   #define NJOY_GNDSTK_SHORTCUT(to,name) decltype(to.name) &name = to.name
   NJOY_GNDSTK_SHORTCUT(axes(),axis);
   NJOY_GNDSTK_SHORTCUT(axes(),grid);
   NJOY_GNDSTK_SHORTCUT(array(),lengths);
   NJOY_GNDSTK_SHORTCUT(array(),starts);
   #undef NJOY_GNDSTK_SHORTCUT

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->axes, \
      this->array \
   )

   // default
   Gridded3d() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Gridded3d(
      const wrapper<general::Axes>
         &axes,
      const wrapper<g3d::Array>
         &array = {}
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      axes(this,axes),
      array(this,array)
   {
      Component::finish();
   }

   // from node
   explicit Gridded3d(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Gridded3d(const Gridded3d &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      axes(this,other.axes),
      array(this,other.array)
   {
      Component::finish(other);
   }

   // move
   Gridded3d(Gridded3d &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
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
   Gridded3d &operator=(const Gridded3d &other)
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
   Gridded3d &operator=(Gridded3d &&other)
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

   #include "gnds/v2.0/general/Gridded3d/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class Gridded3d

} // namespace general
} // namespace v2_0
} // namespace gnds

#endif
