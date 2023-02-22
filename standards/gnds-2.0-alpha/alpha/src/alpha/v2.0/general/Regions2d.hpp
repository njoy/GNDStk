
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_REGIONS2D
#define ALPHA_V2_0_GENERAL_REGIONS2D

#include "alpha/v2.0/general/Axes.hpp"
#include "alpha/v2.0/general/Function2ds.hpp"
#include "alpha/v2.0/general/Uncertainty.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Regions2d
// -----------------------------------------------------------------------------

class Regions2d :
   public Component<general::Regions2d>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Regions2d"; }
   static auto NODENAME() { return "regions2d"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<general::Axes>
            ("axes") |
         --Child<general::Function2ds>
            ("function2ds") |
         --Child<std::optional<general::Uncertainty>>
            ("uncertainty")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "axes",
         "function2ds",
         "uncertainty"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "axes",
         "function2ds",
         "uncertainty"
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
   Field<general::Function2ds>
      function2ds{this};
   Field<std::optional<general::Uncertainty>>
      uncertainty{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->axes, \
      this->function2ds, \
      this->uncertainty \
   )

   // default
   Regions2d() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Regions2d(
      const wrapper<general::Axes>
         &axes,
      const wrapper<general::Function2ds>
         &function2ds = {},
      const wrapper<std::optional<general::Uncertainty>>
         &uncertainty = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      axes(this,axes),
      function2ds(this,function2ds),
      uncertainty(this,uncertainty)
   {
      Component::finish();
   }

   // from node
   explicit Regions2d(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Regions2d(const Regions2d &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      axes(this,other.axes),
      function2ds(this,other.function2ds),
      uncertainty(this,other.uncertainty)
   {
      Component::finish(other);
   }

   // move
   Regions2d(Regions2d &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      axes(this,std::move(other.axes)),
      function2ds(this,std::move(other.function2ds)),
      uncertainty(this,std::move(other.uncertainty))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Regions2d &operator=(const Regions2d &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         axes = other.axes;
         function2ds = other.function2ds;
         uncertainty = other.uncertainty;
      }
      return *this;
   }

   // move
   Regions2d &operator=(Regions2d &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         axes = std::move(other.axes);
         function2ds = std::move(other.function2ds);
         uncertainty = std::move(other.uncertainty);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/Regions2d/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Regions2d

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif