
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_FISSIONCOMPONENT
#define ALPHA_V2_0_GENERAL_FISSIONCOMPONENT

#include "alpha/v2.0/general/CrossSection.hpp"
#include "alpha/v2.0/general/OutputChannel.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class FissionComponent
// -----------------------------------------------------------------------------

class FissionComponent :
   public Component<general::FissionComponent>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "FissionComponent"; }
   static auto FIELD() { return "fissionComponent"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("label") |
         int{}
            / Meta<>("ENDF_MT") |
         std::string{}
            / Meta<>("fissionGenre") |

         // children
         --Child<general::CrossSection>
            ("crossSection") |
         --Child<general::OutputChannel>
            ("outputChannel")
      ;
   }

public:
   using component_t = Component;
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string>
      label{this};
   Field<int>
      ENDF_MT{this};
   Field<std::string>
      fissionGenre{this};

   // children
   Field<general::CrossSection>
      crossSection{this};
   Field<general::OutputChannel>
      outputChannel{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->ENDF_MT, \
      this->fissionGenre, \
      this->crossSection, \
      this->outputChannel \
   )

   // default
   FissionComponent() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit FissionComponent(
      const wrapper<std::string>
         &label,
      const wrapper<int>
         &ENDF_MT = {},
      const wrapper<std::string>
         &fissionGenre = {},
      const wrapper<general::CrossSection>
         &crossSection = {},
      const wrapper<general::OutputChannel>
         &outputChannel = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      ENDF_MT(this,ENDF_MT),
      fissionGenre(this,fissionGenre),
      crossSection(this,crossSection),
      outputChannel(this,outputChannel)
   {
      Component::finish();
   }

   // from node
   explicit FissionComponent(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   FissionComponent(const FissionComponent &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      ENDF_MT(this,other.ENDF_MT),
      fissionGenre(this,other.fissionGenre),
      crossSection(this,other.crossSection),
      outputChannel(this,other.outputChannel)
   {
      Component::finish(other);
   }

   // move
   FissionComponent(FissionComponent &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      ENDF_MT(this,std::move(other.ENDF_MT)),
      fissionGenre(this,std::move(other.fissionGenre)),
      crossSection(this,std::move(other.crossSection)),
      outputChannel(this,std::move(other.outputChannel))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   FissionComponent &operator=(const FissionComponent &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         ENDF_MT = other.ENDF_MT;
         fissionGenre = other.fissionGenre;
         crossSection = other.crossSection;
         outputChannel = other.outputChannel;
      }
      return *this;
   }

   // move
   FissionComponent &operator=(FissionComponent &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         ENDF_MT = std::move(other.ENDF_MT);
         fissionGenre = std::move(other.fissionGenre);
         crossSection = std::move(other.crossSection);
         outputChannel = std::move(other.outputChannel);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/FissionComponent/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class FissionComponent

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
