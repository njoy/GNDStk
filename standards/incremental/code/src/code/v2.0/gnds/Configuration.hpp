
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

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "gnds"; }
   static auto CLASS() { return "Configuration"; }
   static auto FIELD() { return "configuration"; }

   // Core Interface multi-query to transfer information to/from Nodes
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
         --Child<gnds::BindingEnergy>("bindingEnergy")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string> subshell{this};
   Field<std::string> electronNumber{this};

   // children
   Field<gnds::BindingEnergy> bindingEnergy{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->subshell, \
      this->electronNumber, \
      this->bindingEnergy)

   // default
   Configuration() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Configuration(
      const wrapper<std::string> &subshell,
      const wrapper<std::string> &electronNumber = {},
      const wrapper<gnds::BindingEnergy> &bindingEnergy = {}
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

   Configuration &operator=(const Configuration &) = default;
   Configuration &operator=(Configuration &&) = default;

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
