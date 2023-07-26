
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_FASTREGION
#define GNDS_V2_0_GENERAL_FASTREGION

#include "gnds/v2.0/general/XYs1d.hpp"
#include "gnds/v2.0/general/Regions1d.hpp"

namespace gnds {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class FastRegion
// -----------------------------------------------------------------------------

class FastRegion :
   public Component<general::FastRegion>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "FastRegion"; }
   static auto NODENAME() { return "fastRegion"; }

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

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->XYs1d, \
      this->regions1d \
   )

   // default
   FastRegion() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit FastRegion(
      const wrapper<std::optional<general::XYs1d>>
         &XYs1d,
      const wrapper<std::optional<general::Regions1d>>
         &regions1d = {}
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      XYs1d(this,XYs1d),
      regions1d(this,regions1d)
   {
      Component::finish();
   }

   // from node
   explicit FastRegion(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   FastRegion(const FastRegion &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      XYs1d(this,other.XYs1d),
      regions1d(this,other.regions1d)
   {
      Component::finish(other);
   }

   // move
   FastRegion(FastRegion &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
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
   FastRegion &operator=(const FastRegion &other)
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
   FastRegion &operator=(FastRegion &&other)
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

   #include "gnds/v2.0/general/FastRegion/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class FastRegion

} // namespace general
} // namespace v2_0
} // namespace gnds

#endif
