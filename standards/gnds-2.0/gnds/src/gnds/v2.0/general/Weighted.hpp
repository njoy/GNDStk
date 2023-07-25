
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_WEIGHTED
#define GNDS_V2_0_GENERAL_WEIGHTED

#include "gnds/v2.0/general/XYs1d.hpp"
#include "gnds/v2.0/general/Evaporation.hpp"

namespace gnds {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Weighted
// -----------------------------------------------------------------------------

class Weighted :
   public Component<general::Weighted>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Weighted"; }
   static auto NODENAME() { return "weighted"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<general::XYs1d>
            ("XYs1d") |
         --Child<general::Evaporation>
            ("evaporation")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "XYs1d",
         "evaporation"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "xys1d",
         "evaporation"
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
   Field<general::XYs1d>
      XYs1d{this};
   Field<general::Evaporation>
      evaporation{this};

   // shortcuts
   #define GNDSTK_SHORTCUT(to,name) decltype(to.name) &name = to.name
   GNDSTK_SHORTCUT(evaporation(),U);
   GNDSTK_SHORTCUT(XYs1d(),axes);
   GNDSTK_SHORTCUT(evaporation().theta(),regions1d);
   GNDSTK_SHORTCUT(evaporation(),theta);
   GNDSTK_SHORTCUT(XYs1d(),uncertainty);
   GNDSTK_SHORTCUT(XYs1d(),values);
   #undef GNDSTK_SHORTCUT

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->XYs1d, \
      this->evaporation \
   )

   // default
   Weighted() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Weighted(
      const wrapper<general::XYs1d>
         &XYs1d,
      const wrapper<general::Evaporation>
         &evaporation = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      XYs1d(this,XYs1d),
      evaporation(this,evaporation)
   {
      Component::finish();
   }

   // from node
   explicit Weighted(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Weighted(const Weighted &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      XYs1d(this,other.XYs1d),
      evaporation(this,other.evaporation)
   {
      Component::finish(other);
   }

   // move
   Weighted(Weighted &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      XYs1d(this,std::move(other.XYs1d)),
      evaporation(this,std::move(other.evaporation))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Weighted &operator=(const Weighted &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         XYs1d = other.XYs1d;
         evaporation = other.evaporation;
      }
      return *this;
   }

   // move
   Weighted &operator=(Weighted &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         XYs1d = std::move(other.XYs1d);
         evaporation = std::move(other.evaporation);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "gnds/v2.0/general/Weighted/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Weighted

} // namespace general
} // namespace v2_0
} // namespace gnds

#endif
