
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_CONFIGURATION
#define GNDS_V2_0_GENERAL_CONFIGURATION

#include "gnds/v2.0/general/BindingEnergy.hpp"
#include "gnds/v2.0/general/DecayData.hpp"

namespace gnds {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Configuration
// -----------------------------------------------------------------------------

class Configuration :
   public Component<general::Configuration>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Configuration"; }
   static auto NODENAME() { return "configuration"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("subshell") |
         double{}
            / Meta<>("electronNumber") |

         // children
         --Child<general::BindingEnergy>
            ("bindingEnergy") |
         ++Child<general::DecayData>
            ("decayData")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "subshell",
         "electronNumber",
         "bindingEnergy",
         "decayData"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "subshell",
         "electron_number",
         "binding_energy",
         "decay_data"
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
      subshell{this};
   Field<double>
      electronNumber{this};

   // children
   Field<general::BindingEnergy>
      bindingEnergy{this};
   Field<std::vector<general::DecayData>>
      decayData{this};

   // shortcuts
   #define NJOY_GNDSTK_SHORTCUT(to,name) decltype(to.name) &name = to.name
   NJOY_GNDSTK_SHORTCUT(bindingEnergy(),Double);
   NJOY_GNDSTK_SHORTCUT(bindingEnergy().Double(),uncertainty);
   #undef NJOY_GNDSTK_SHORTCUT

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->subshell, \
      this->electronNumber, \
      this->bindingEnergy, \
      this->decayData \
   )

   // default
   Configuration() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Configuration(
      const wrapper<std::string>
         &subshell,
      const wrapper<double>
         &electronNumber = {},
      const wrapper<general::BindingEnergy>
         &bindingEnergy = {},
      const wrapper<std::vector<general::DecayData>>
         &decayData = {}
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      subshell(this,subshell),
      electronNumber(this,electronNumber),
      bindingEnergy(this,bindingEnergy),
      decayData(this,decayData)
   {
      Component::finish();
   }

   // from node
   explicit Configuration(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Configuration(const Configuration &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      subshell(this,other.subshell),
      electronNumber(this,other.electronNumber),
      bindingEnergy(this,other.bindingEnergy),
      decayData(this,other.decayData)
   {
      Component::finish(other);
   }

   // move
   Configuration(Configuration &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      subshell(this,std::move(other.subshell)),
      electronNumber(this,std::move(other.electronNumber)),
      bindingEnergy(this,std::move(other.bindingEnergy)),
      decayData(this,std::move(other.decayData))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Configuration &operator=(const Configuration &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         subshell = other.subshell;
         electronNumber = other.electronNumber;
         bindingEnergy = other.bindingEnergy;
         decayData = other.decayData;
      }
      return *this;
   }

   // move
   Configuration &operator=(Configuration &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         subshell = std::move(other.subshell);
         electronNumber = std::move(other.electronNumber);
         bindingEnergy = std::move(other.bindingEnergy);
         decayData = std::move(other.decayData);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "gnds/v2.0/general/Configuration/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class Configuration

} // namespace general
} // namespace v2_0
} // namespace gnds

#endif
