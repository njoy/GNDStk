
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_AXES
#define GNDS_V2_0_GENERAL_AXES

#include "GNDS/v2.0/general/Axis.hpp"
#include "GNDS/v2.0/general/Grid.hpp"

namespace GNDS {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Axes
// -----------------------------------------------------------------------------

class Axes :
   public Component<general::Axes>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Axes"; }
   static auto NODENAME() { return "axes"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<general::Axis>
            ("axis") |
         ++Child<std::optional<general::Grid>>
            ("grid")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "axis",
         "grid"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "axis",
         "grid"
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
   Field<std::vector<general::Axis>>
      axis{this};
   Field<std::optional<std::vector<general::Grid>>>
      grid{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->axis, \
      this->grid \
   )

   // default
   Axes() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Axes(
      const wrapper<std::vector<general::Axis>>
         &axis,
      const wrapper<std::optional<std::vector<general::Grid>>>
         &grid = {}
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      axis(this,axis),
      grid(this,grid)
   {
      Component::finish();
   }

   // from node
   explicit Axes(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Axes(const Axes &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      axis(this,other.axis),
      grid(this,other.grid)
   {
      Component::finish(other);
   }

   // move
   Axes(Axes &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      axis(this,std::move(other.axis)),
      grid(this,std::move(other.grid))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Axes &operator=(const Axes &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         axis = other.axis;
         grid = other.grid;
      }
      return *this;
   }

   // move
   Axes &operator=(Axes &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         axis = std::move(other.axis);
         grid = std::move(other.grid);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDS/v2.0/general/Axes/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class Axes

} // namespace general
} // namespace v2_0
} // namespace GNDS

#endif
