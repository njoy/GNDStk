
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_RESOLVEDREGION
#define ALPHA_V2_0_GENERAL_RESOLVEDREGION

#include "alpha/v2.0/general/XYs1d.hpp"
#include "alpha/v2.0/general/Regions1d.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class ResolvedRegion
// -----------------------------------------------------------------------------

class ResolvedRegion :
   public Component<general::ResolvedRegion>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "ResolvedRegion"; }
   static auto NODENAME() { return "resolvedRegion"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<std::optional<general::XYs1d>>
            ("XYs1d") |
         --Child<std::optional<general::Regions1d>>
            ("regions1d")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
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
   Field<std::optional<general::XYs1d>>
      XYs1d{this};
   Field<std::optional<general::Regions1d>>
      regions1d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->XYs1d, \
      this->regions1d \
   )

   // default
   ResolvedRegion() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ResolvedRegion(
      const wrapper<std::optional<general::XYs1d>>
         &XYs1d,
      const wrapper<std::optional<general::Regions1d>>
         &regions1d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      XYs1d(this,XYs1d),
      regions1d(this,regions1d)
   {
      Component::finish();
   }

   // from node
   explicit ResolvedRegion(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ResolvedRegion(const ResolvedRegion &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      XYs1d(this,other.XYs1d),
      regions1d(this,other.regions1d)
   {
      Component::finish(other);
   }

   // move
   ResolvedRegion(ResolvedRegion &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      XYs1d(this,std::move(other.XYs1d)),
      regions1d(this,std::move(other.regions1d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   ResolvedRegion &operator=(const ResolvedRegion &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         XYs1d = other.XYs1d;
         regions1d = other.regions1d;
      }
      return *this;
   }

   // move
   ResolvedRegion &operator=(ResolvedRegion &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         XYs1d = std::move(other.XYs1d);
         regions1d = std::move(other.regions1d);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/ResolvedRegion/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ResolvedRegion

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif