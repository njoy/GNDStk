
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_CONFIGURATION
#define ALPHA_V2_0_GENERAL_CONFIGURATION

#include "alpha/v2.0/general/BindingEnergy.hpp"
#include "alpha/v2.0/general/DecayData.hpp"

namespace alpha {
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

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
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
         double{}
            / Meta<>("electronNumber") |

         // children
         --Child<general::BindingEnergy>
            ("bindingEnergy") |
         ++Child<general::DecayData>
            ("decayData")
      ;
   }

public:
   using component_t = Component;
   using Component::construct;

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

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
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
      GNDSTK_COMPONENT(BlockData{})
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
      GNDSTK_COMPONENT(BlockData{}),
      subshell(this,subshell),
      electronNumber(this,electronNumber),
      bindingEnergy(this,bindingEnergy),
      decayData(this,decayData)
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
      bindingEnergy(this,other.bindingEnergy),
      decayData(this,other.decayData)
   {
      Component::finish(other);
   }

   // move
   Configuration(Configuration &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
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

   #include "alpha/v2.0/general/Configuration/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Configuration

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
