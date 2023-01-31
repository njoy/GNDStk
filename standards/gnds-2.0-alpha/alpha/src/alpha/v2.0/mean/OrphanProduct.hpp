
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_MEAN_ORPHANPRODUCT
#define ALPHA_V2_0_MEAN_ORPHANPRODUCT

#include "alpha/v2.0/common/CrossSection.hpp"
#include "alpha/v2.0/common/OutputChannel.hpp"

namespace alpha {
namespace v2_0 {
namespace mean {

// -----------------------------------------------------------------------------
// mean::
// class OrphanProduct
// -----------------------------------------------------------------------------

class OrphanProduct :
   public Component<mean::OrphanProduct>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "mean"; }
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
         --Child<common::CrossSection>("crossSection") |
         --Child<common::OutputChannel>("outputChannel")
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
   Field<common::CrossSection> crossSection{this};
   Field<common::OutputChannel> outputChannel{this};

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
      const wrapper<std::string> &label,
      const wrapper<int> &ENDF_MT = {},
      const wrapper<common::CrossSection> &crossSection = {},
      const wrapper<common::OutputChannel> &outputChannel = {}
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

   OrphanProduct &operator=(const OrphanProduct &) = default;
   OrphanProduct &operator=(OrphanProduct &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/mean/OrphanProduct/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class OrphanProduct

} // namespace mean
} // namespace v2_0
} // namespace alpha

#endif
