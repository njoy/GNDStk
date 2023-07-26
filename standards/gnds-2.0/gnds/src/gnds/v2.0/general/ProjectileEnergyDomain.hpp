
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_PROJECTILEENERGYDOMAIN
#define GNDS_V2_0_GENERAL_PROJECTILEENERGYDOMAIN

#include "gnds/v2.0/key.hpp"

namespace gnds {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class ProjectileEnergyDomain
// -----------------------------------------------------------------------------

class ProjectileEnergyDomain :
   public Component<general::ProjectileEnergyDomain>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "ProjectileEnergyDomain"; }
   static auto NODENAME() { return "projectileEnergyDomain"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         double{}
            / Meta<>("min") |
         double{}
            / Meta<>("max") |
         std::string{}
            / Meta<>("unit")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "min",
         "max",
         "unit"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "min",
         "max",
         "unit"
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

   // metadata
   Field<double>
      min{this};
   Field<double>
      max{this};
   Field<std::string>
      unit{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->min, \
      this->max, \
      this->unit \
   )

   // default
   ProjectileEnergyDomain() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ProjectileEnergyDomain(
      const wrapper<double>
         &min,
      const wrapper<double>
         &max = {},
      const wrapper<std::string>
         &unit = {}
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      min(this,min),
      max(this,max),
      unit(this,unit)
   {
      Component::finish();
   }

   // from node
   explicit ProjectileEnergyDomain(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ProjectileEnergyDomain(const ProjectileEnergyDomain &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      min(this,other.min),
      max(this,other.max),
      unit(this,other.unit)
   {
      Component::finish(other);
   }

   // move
   ProjectileEnergyDomain(ProjectileEnergyDomain &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      min(this,std::move(other.min)),
      max(this,std::move(other.max)),
      unit(this,std::move(other.unit))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   ProjectileEnergyDomain &operator=(const ProjectileEnergyDomain &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         min = other.min;
         max = other.max;
         unit = other.unit;
      }
      return *this;
   }

   // move
   ProjectileEnergyDomain &operator=(ProjectileEnergyDomain &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         min = std::move(other.min);
         max = std::move(other.max);
         unit = std::move(other.unit);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "gnds/v2.0/general/ProjectileEnergyDomain/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class ProjectileEnergyDomain

} // namespace general
} // namespace v2_0
} // namespace gnds

#endif
