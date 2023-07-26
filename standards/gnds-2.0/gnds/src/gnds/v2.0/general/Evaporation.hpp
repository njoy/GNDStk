
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_EVAPORATION
#define GNDS_V2_0_GENERAL_EVAPORATION

#include "gnds/v2.0/general/U.hpp"
#include "gnds/v2.0/general/Theta.hpp"

namespace gnds {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Evaporation
// -----------------------------------------------------------------------------

class Evaporation :
   public Component<general::Evaporation>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Evaporation"; }
   static auto NODENAME() { return "evaporation"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<general::U>
            ("U") |
         --Child<general::Theta>
            ("theta")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "U",
         "theta"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "u",
         "theta"
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
   Field<general::U>
      U{this};
   Field<general::Theta>
      theta{this};

   // shortcuts
   #define NJOY_GNDSTK_SHORTCUT(to,name) decltype(to.name) &name = to.name
   NJOY_GNDSTK_SHORTCUT(theta(),XYs1d);
   NJOY_GNDSTK_SHORTCUT(theta(),regions1d);
   #undef NJOY_GNDSTK_SHORTCUT

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->U, \
      this->theta \
   )

   // default
   Evaporation() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Evaporation(
      const wrapper<general::U>
         &U,
      const wrapper<general::Theta>
         &theta = {}
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      U(this,U),
      theta(this,theta)
   {
      Component::finish();
   }

   // from node
   explicit Evaporation(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Evaporation(const Evaporation &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      U(this,other.U),
      theta(this,other.theta)
   {
      Component::finish(other);
   }

   // move
   Evaporation(Evaporation &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      U(this,std::move(other.U)),
      theta(this,std::move(other.theta))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Evaporation &operator=(const Evaporation &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         U = other.U;
         theta = other.theta;
      }
      return *this;
   }

   // move
   Evaporation &operator=(Evaporation &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         U = std::move(other.U);
         theta = std::move(other.theta);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "gnds/v2.0/general/Evaporation/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class Evaporation

} // namespace general
} // namespace v2_0
} // namespace gnds

#endif
