
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_ORPHANPRODUCT
#define ALPHA_V2_0_GENERAL_ORPHANPRODUCT

#include "alpha/v2.0/general/CrossSection.hpp"
#include "alpha/v2.0/general/OutputChannel.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class OrphanProduct
// -----------------------------------------------------------------------------

class OrphanProduct :
   public Component<general::OrphanProduct>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "OrphanProduct"; }
   static auto FIELD() { return "orphanProduct"; }

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

         // children
         --Child<general::CrossSection>
            ("crossSection") |
         --Child<general::OutputChannel>
            ("outputChannel")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string> label{this};
   Field<int> ENDF_MT{this};

   // children
   Field<general::CrossSection>
      crossSection{this};
   Field<general::OutputChannel>
      outputChannel{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->label, \
      this->ENDF_MT, \
      this->crossSection, \
      this->outputChannel)

   // default
   OrphanProduct() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit OrphanProduct(
      const wrapper<std::string>
         &label,
      const wrapper<int>
         &ENDF_MT = {},
      const wrapper<general::CrossSection>
         &crossSection = {},
      const wrapper<general::OutputChannel>
         &outputChannel = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      ENDF_MT(this,ENDF_MT),
      crossSection(this,crossSection),
      outputChannel(this,outputChannel)
   {
      Component::finish();
   }

   // from node
   explicit OrphanProduct(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   OrphanProduct(const OrphanProduct &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      ENDF_MT(this,other.ENDF_MT),
      crossSection(this,other.crossSection),
      outputChannel(this,other.outputChannel)
   {
      Component::finish(other);
   }

   // move
   OrphanProduct(OrphanProduct &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      ENDF_MT(this,std::move(other.ENDF_MT)),
      crossSection(this,std::move(other.crossSection)),
      outputChannel(this,std::move(other.outputChannel))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   OrphanProduct &operator=(const OrphanProduct &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         ENDF_MT = other.ENDF_MT;
         crossSection = other.crossSection;
         outputChannel = other.outputChannel;
      }
      return *this;
   }

   // move
   OrphanProduct &operator=(OrphanProduct &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         ENDF_MT = std::move(other.ENDF_MT);
         crossSection = std::move(other.crossSection);
         outputChannel = std::move(other.outputChannel);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/OrphanProduct/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class OrphanProduct

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
