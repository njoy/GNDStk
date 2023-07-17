
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_ANGULAR
#define ALPHA_V2_0_GENERAL_ANGULAR

#include "alpha/v2.0/general/Isotropic2d.hpp"
#include "alpha/v2.0/general/XYs2d.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Angular
// -----------------------------------------------------------------------------

class Angular :
   public Component<general::Angular>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Angular"; }
   static auto NODENAME() { return "angular"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<std::optional<general::Isotropic2d>>
            ("isotropic2d") |
         --Child<std::optional<general::XYs2d>>
            ("XYs2d")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "isotropic2d",
         "XYs2d"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "isotropic2d",
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
   Field<std::optional<general::Isotropic2d>>
      isotropic2d{this};
   Field<std::optional<general::XYs2d>>
      XYs2d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->isotropic2d, \
      this->XYs2d \
   )

   // default
   Angular() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Angular(
      const wrapper<std::optional<general::Isotropic2d>>
         &isotropic2d,
      const wrapper<std::optional<general::XYs2d>>
         &XYs2d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      isotropic2d(this,isotropic2d),
      XYs2d(this,XYs2d)
   {
      Component::finish();
   }

   // from node
   explicit Angular(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Angular(const Angular &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      isotropic2d(this,other.isotropic2d),
      XYs2d(this,other.XYs2d)
   {
      Component::finish(other);
   }

   // move
   Angular(Angular &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      isotropic2d(this,std::move(other.isotropic2d)),
      XYs2d(this,std::move(other.XYs2d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Angular &operator=(const Angular &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         isotropic2d = other.isotropic2d;
         XYs2d = other.XYs2d;
      }
      return *this;
   }

   // move
   Angular &operator=(Angular &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         isotropic2d = std::move(other.isotropic2d);
         XYs2d = std::move(other.XYs2d);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/Angular/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Angular

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
