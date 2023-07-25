
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_GENERALEVAPORATION
#define GNDS_V2_0_GENERAL_GENERALEVAPORATION

#include "gnds/v2.0/general/U.hpp"
#include "gnds/v2.0/general/Theta.hpp"
#include "gnds/v2.0/general/G.hpp"

namespace gnds {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class GeneralEvaporation
// -----------------------------------------------------------------------------

class GeneralEvaporation :
   public Component<general::GeneralEvaporation>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "GeneralEvaporation"; }
   static auto NODENAME() { return "generalEvaporation"; }

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
            ("theta") |
         --Child<general::G>
            ("g")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "U",
         "theta",
         "g"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "u",
         "theta",
         "g"
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
   Field<general::G>
      g{this};

   // shortcuts
   #define GNDSTK_SHORTCUT(to,name) decltype(to.name) &name = to.name
   GNDSTK_SHORTCUT(theta(),regions1d);
   #undef GNDSTK_SHORTCUT

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->U, \
      this->theta, \
      this->g \
   )

   // default
   GeneralEvaporation() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit GeneralEvaporation(
      const wrapper<general::U>
         &U,
      const wrapper<general::Theta>
         &theta = {},
      const wrapper<general::G>
         &g = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      U(this,U),
      theta(this,theta),
      g(this,g)
   {
      Component::finish();
   }

   // from node
   explicit GeneralEvaporation(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   GeneralEvaporation(const GeneralEvaporation &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      U(this,other.U),
      theta(this,other.theta),
      g(this,other.g)
   {
      Component::finish(other);
   }

   // move
   GeneralEvaporation(GeneralEvaporation &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      U(this,std::move(other.U)),
      theta(this,std::move(other.theta)),
      g(this,std::move(other.g))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   GeneralEvaporation &operator=(const GeneralEvaporation &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         U = other.U;
         theta = other.theta;
         g = other.g;
      }
      return *this;
   }

   // move
   GeneralEvaporation &operator=(GeneralEvaporation &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         U = std::move(other.U);
         theta = std::move(other.theta);
         g = std::move(other.g);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "gnds/v2.0/general/GeneralEvaporation/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class GeneralEvaporation

} // namespace general
} // namespace v2_0
} // namespace gnds

#endif
