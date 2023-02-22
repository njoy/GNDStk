
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_SCATTERINGRADIUS
#define ALPHA_V2_0_GENERAL_SCATTERINGRADIUS

#include "alpha/v2.0/general/Constant1d.hpp"
#include "alpha/v2.0/general/XYs1d.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class ScatteringRadius
// -----------------------------------------------------------------------------

class ScatteringRadius :
   public Component<general::ScatteringRadius>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "ScatteringRadius"; }
   static auto NODENAME() { return "scatteringRadius"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<std::optional<general::Constant1d>>
            ("constant1d") |
         --Child<std::optional<general::XYs1d>>
            ("XYs1d")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "constant1d",
         "XYs1d"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "constant1d",
         "xys1d"
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
   Field<std::optional<general::Constant1d>>
      constant1d{this};
   Field<std::optional<general::XYs1d>>
      XYs1d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->constant1d, \
      this->XYs1d \
   )

   // default
   ScatteringRadius() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ScatteringRadius(
      const wrapper<std::optional<general::Constant1d>>
         &constant1d,
      const wrapper<std::optional<general::XYs1d>>
         &XYs1d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      constant1d(this,constant1d),
      XYs1d(this,XYs1d)
   {
      Component::finish();
   }

   // from node
   explicit ScatteringRadius(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ScatteringRadius(const ScatteringRadius &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      constant1d(this,other.constant1d),
      XYs1d(this,other.XYs1d)
   {
      Component::finish(other);
   }

   // move
   ScatteringRadius(ScatteringRadius &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      constant1d(this,std::move(other.constant1d)),
      XYs1d(this,std::move(other.XYs1d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   ScatteringRadius &operator=(const ScatteringRadius &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         constant1d = other.constant1d;
         XYs1d = other.XYs1d;
      }
      return *this;
   }

   // move
   ScatteringRadius &operator=(ScatteringRadius &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         constant1d = std::move(other.constant1d);
         XYs1d = std::move(other.XYs1d);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/ScatteringRadius/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ScatteringRadius

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif