
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_R
#define GNDS_V2_0_GENERAL_R

#include "GNDS/v2.0/general/XYs2d.hpp"

namespace GNDS {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class R
// -----------------------------------------------------------------------------

class R :
   public Component<general::R>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "R"; }
   static auto NODENAME() { return "r"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<general::XYs2d>
            ("XYs2d")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "XYs2d"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "xys2d"
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
   Field<general::XYs2d>
      XYs2d{this};

   // shortcuts
   #define NJOY_GNDSTK_SHORTCUT(to,name) decltype(to.name) &name = to.name
   NJOY_GNDSTK_SHORTCUT(XYs2d().function1ds(),Legendre);
   NJOY_GNDSTK_SHORTCUT(XYs2d().function1ds(),XYs1d);
   NJOY_GNDSTK_SHORTCUT(XYs2d(),axes);
   NJOY_GNDSTK_SHORTCUT(XYs2d(),function1ds);
   NJOY_GNDSTK_SHORTCUT(XYs2d().function1ds(),regions1d);
   NJOY_GNDSTK_SHORTCUT(XYs2d(),uncertainty);
   #undef NJOY_GNDSTK_SHORTCUT

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->XYs2d \
   )

   // default
   R() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit R(
      const wrapper<general::XYs2d>
         &XYs2d
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      XYs2d(this,XYs2d)
   {
      Component::finish();
   }

   // from node
   explicit R(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   R(const R &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      XYs2d(this,other.XYs2d)
   {
      Component::finish(other);
   }

   // move
   R(R &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      XYs2d(this,std::move(other.XYs2d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   R &operator=(const R &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         XYs2d = other.XYs2d;
      }
      return *this;
   }

   // move
   R &operator=(R &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         XYs2d = std::move(other.XYs2d);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDS/v2.0/general/R/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class R

} // namespace general
} // namespace v2_0
} // namespace GNDS

#endif