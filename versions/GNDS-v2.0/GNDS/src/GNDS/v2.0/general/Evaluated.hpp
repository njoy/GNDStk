
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_EVALUATED
#define GNDS_V2_0_GENERAL_EVALUATED

#include "GNDS/v2.0/general/Documentation.hpp"
#include "GNDS/v2.0/general/Temperature.hpp"
#include "GNDS/v2.0/general/ProjectileEnergyDomain.hpp"

namespace GNDS {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Evaluated
// -----------------------------------------------------------------------------

class Evaluated :
   public Component<general::Evaluated>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Evaluated"; }
   static auto NODENAME() { return "evaluated"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("label") |
         std::string{}
            / Meta<>("date") |
         std::string{}
            / Meta<>("library") |
         std::string{}
            / Meta<>("version") |

         // children
         --Child<general::Documentation>
            ("documentation") |
         --Child<std::optional<general::Temperature>>
            ("temperature") |
         --Child<std::optional<general::ProjectileEnergyDomain>>
            ("projectileEnergyDomain")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "date",
         "library",
         "version",
         "documentation",
         "temperature",
         "projectileEnergyDomain"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "date",
         "library",
         "version",
         "documentation",
         "temperature",
         "projectile_energy_domain"
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
   Field<std::string>
      label{this};
   Field<std::string>
      date{this};
   Field<std::string>
      library{this};
   Field<std::string>
      version{this};

   // children
   Field<general::Documentation>
      documentation{this};
   Field<std::optional<general::Temperature>>
      temperature{this};
   Field<std::optional<general::ProjectileEnergyDomain>>
      projectileEnergyDomain{this};

   // shortcuts
   #define NJOY_GNDSTK_SHORTCUT(to,name) decltype(to.name) &name = to.name
   NJOY_GNDSTK_SHORTCUT(documentation().authors(),author);
   NJOY_GNDSTK_SHORTCUT(documentation(),authors);
   NJOY_GNDSTK_SHORTCUT(documentation(),body);
   NJOY_GNDSTK_SHORTCUT(documentation(),dates);
   NJOY_GNDSTK_SHORTCUT(documentation(),endfCompatible);
   NJOY_GNDSTK_SHORTCUT(documentation(),title);
   #undef NJOY_GNDSTK_SHORTCUT

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->date, \
      this->library, \
      this->version, \
      this->documentation, \
      this->temperature, \
      this->projectileEnergyDomain \
   )

   // default
   Evaluated() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Evaluated(
      const wrapper<std::string>
         &label,
      const wrapper<std::string>
         &date = {},
      const wrapper<std::string>
         &library = {},
      const wrapper<std::string>
         &version = {},
      const wrapper<general::Documentation>
         &documentation = {},
      const wrapper<std::optional<general::Temperature>>
         &temperature = {},
      const wrapper<std::optional<general::ProjectileEnergyDomain>>
         &projectileEnergyDomain = {}
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      date(this,date),
      library(this,library),
      version(this,version),
      documentation(this,documentation),
      temperature(this,temperature),
      projectileEnergyDomain(this,projectileEnergyDomain)
   {
      Component::finish();
   }

   // from node
   explicit Evaluated(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Evaluated(const Evaluated &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      date(this,other.date),
      library(this,other.library),
      version(this,other.version),
      documentation(this,other.documentation),
      temperature(this,other.temperature),
      projectileEnergyDomain(this,other.projectileEnergyDomain)
   {
      Component::finish(other);
   }

   // move
   Evaluated(Evaluated &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      date(this,std::move(other.date)),
      library(this,std::move(other.library)),
      version(this,std::move(other.version)),
      documentation(this,std::move(other.documentation)),
      temperature(this,std::move(other.temperature)),
      projectileEnergyDomain(this,std::move(other.projectileEnergyDomain))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Evaluated &operator=(const Evaluated &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         date = other.date;
         library = other.library;
         version = other.version;
         documentation = other.documentation;
         temperature = other.temperature;
         projectileEnergyDomain = other.projectileEnergyDomain;
      }
      return *this;
   }

   // move
   Evaluated &operator=(Evaluated &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         date = std::move(other.date);
         library = std::move(other.library);
         version = std::move(other.version);
         documentation = std::move(other.documentation);
         temperature = std::move(other.temperature);
         projectileEnergyDomain = std::move(other.projectileEnergyDomain);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDS/v2.0/general/Evaluated/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class Evaluated

} // namespace general
} // namespace v2_0
} // namespace GNDS

#endif
