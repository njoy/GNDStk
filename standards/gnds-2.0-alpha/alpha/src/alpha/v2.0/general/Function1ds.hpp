
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_FUNCTION1DS
#define ALPHA_V2_0_GENERAL_FUNCTION1DS

#include "alpha/v2.0/general/Legendre.hpp"
#include "alpha/v2.0/general/XYs1d.hpp"
#include "alpha/v2.0/general/Regions1d.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Function1ds
// -----------------------------------------------------------------------------

class Function1ds :
   public Component<general::Function1ds>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Function1ds"; }
   static auto NODENAME() { return "function1ds"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<general::Legendre>
            ("Legendre") |
         ++Child<std::optional<general::XYs1d>>
            ("XYs1d") |
         ++Child<std::optional<general::Regions1d>>
            ("regions1d")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "Legendre",
         "XYs1d",
         "regions1d"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "legendre",
         "xys1d",
         "regions1d"
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
   Field<std::vector<general::Legendre>>
      Legendre{this};
   Field<std::optional<std::vector<general::XYs1d>>>
      XYs1d{this};
   Field<std::optional<std::vector<general::Regions1d>>>
      regions1d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->Legendre, \
      this->XYs1d, \
      this->regions1d \
   )

   // default
   Function1ds() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Function1ds(
      const wrapper<std::vector<general::Legendre>>
         &Legendre,
      const wrapper<std::optional<std::vector<general::XYs1d>>>
         &XYs1d = {},
      const wrapper<std::optional<std::vector<general::Regions1d>>>
         &regions1d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      Legendre(this,Legendre),
      XYs1d(this,XYs1d),
      regions1d(this,regions1d)
   {
      Component::finish();
   }

   // from node
   explicit Function1ds(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Function1ds(const Function1ds &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      Legendre(this,other.Legendre),
      XYs1d(this,other.XYs1d),
      regions1d(this,other.regions1d)
   {
      Component::finish(other);
   }

   // move
   Function1ds(Function1ds &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      Legendre(this,std::move(other.Legendre)),
      XYs1d(this,std::move(other.XYs1d)),
      regions1d(this,std::move(other.regions1d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Function1ds &operator=(const Function1ds &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         Legendre = other.Legendre;
         XYs1d = other.XYs1d;
         regions1d = other.regions1d;
      }
      return *this;
   }

   // move
   Function1ds &operator=(Function1ds &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         Legendre = std::move(other.Legendre);
         XYs1d = std::move(other.XYs1d);
         regions1d = std::move(other.regions1d);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/Function1ds/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Function1ds

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif