
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef CODE_V2_0_GNDS_CONFIGURATION
#define CODE_V2_0_GNDS_CONFIGURATION

#include "code/v2.0/gnds/BindingEnergy.hpp"

namespace code {
namespace v2_0 {
namespace gnds {

// -----------------------------------------------------------------------------
// gnds::
// class Configuration
// -----------------------------------------------------------------------------

class Configuration :
   public Component<gnds::Configuration>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "gnds"; }
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
         std::string{}
            / Meta<>("electronNumber") |

         // children
         --Child<gnds::BindingEnergy>
            ("bindingEnergy")
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
         "bindingEnergy"
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
         "binding_energy"
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
   Field<std::string>
      electronNumber{this};

   // children
   Field<gnds::BindingEnergy>
      bindingEnergy{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->subshell, \
      this->electronNumber, \
      this->bindingEnergy \
   )

   // default
   Configuration() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Configuration(
      const wrapper<std::string>
         &subshell,
      const wrapper<std::string>
         &electronNumber = {},
      const wrapper<gnds::BindingEnergy>
         &bindingEnergy = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      subshell(this,subshell),
      electronNumber(this,electronNumber),
      bindingEnergy(this,bindingEnergy)
   {
      Component::finish();
   }

   // from node
   explicit Configuration(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Configuration(const Configuration &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      subshell(this,other.subshell),
      electronNumber(this,other.electronNumber),
      bindingEnergy(this,other.bindingEnergy)
   {
      Component::finish(other);
   }

   // move
   Configuration(Configuration &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      subshell(this,std::move(other.subshell)),
      electronNumber(this,std::move(other.electronNumber)),
      bindingEnergy(this,std::move(other.bindingEnergy))
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
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "code/v2.0/gnds/Configuration/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Configuration

} // namespace gnds
} // namespace v2_0
} // namespace code

#endif
