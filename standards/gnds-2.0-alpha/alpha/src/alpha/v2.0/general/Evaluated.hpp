
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_EVALUATED
#define ALPHA_V2_0_GENERAL_EVALUATED

#include "alpha/v2.0/general/Documentation.hpp"
#include "alpha/v2.0/general/Temperature.hpp"
#include "alpha/v2.0/general/ProjectileEnergyDomain.hpp"

namespace alpha {
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

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Evaluated"; }
   static auto FIELD() { return "evaluated"; }

   // Core Interface multi-query to transfer information to/from Nodes
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

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string> label{this};
   Field<std::string> date{this};
   Field<std::string> library{this};
   Field<std::string> version{this};

   // children
   Field<general::Documentation>
      documentation{this};
   Field<std::optional<general::Temperature>>
      temperature{this};
   Field<std::optional<general::ProjectileEnergyDomain>>
      projectileEnergyDomain{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->label, \
      this->date, \
      this->library, \
      this->version, \
      this->documentation, \
      this->temperature, \
      this->projectileEnergyDomain)

   // default
   Evaluated() :
      GNDSTK_COMPONENT(BlockData{})
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
      GNDSTK_COMPONENT(BlockData{}),
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
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Evaluated(const Evaluated &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
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
      GNDSTK_COMPONENT(other.baseBlockData()),
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

   #include "alpha/v2.0/general/Evaluated/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Evaluated

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
