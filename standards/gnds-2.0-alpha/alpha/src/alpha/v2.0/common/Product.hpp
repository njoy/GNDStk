
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_COMMON_PRODUCT
#define ALPHA_V2_0_COMMON_PRODUCT

#include "alpha/v2.0/common/Multiplicity.hpp"
#include "alpha/v2.0/common/Distribution.hpp"
#include "alpha/v2.0/reduced/OutputChannel.hpp"
#include "alpha/v2.0/mean/AverageProductEnergy.hpp"

namespace alpha {
namespace v2_0 {
namespace common {

// -----------------------------------------------------------------------------
// common::
// class Product
// -----------------------------------------------------------------------------

class Product :
   public Component<common::Product>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "common"; }
   static auto CLASS() { return "Product"; }
   static auto FIELD() { return "product"; }

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
            / Meta<>("pid") |

         // children
         --Child<std::optional<common::Multiplicity>>("multiplicity") |
         --Child<std::optional<common::Distribution>>("distribution") |
         --Child<std::optional<reduced::OutputChannel>>("outputChannel") |
         --Child<std::optional<mean::AverageProductEnergy>>("averageProductEnergy")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string> label{this};
   Field<std::string> pid{this};

   // children
   Field<std::optional<common::Multiplicity>> multiplicity{this};
   Field<std::optional<common::Distribution>> distribution{this};
   Field<std::optional<reduced::OutputChannel>> outputChannel{this};
   Field<std::optional<mean::AverageProductEnergy>> averageProductEnergy{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->label, \
      this->pid, \
      this->multiplicity, \
      this->distribution, \
      this->outputChannel, \
      this->averageProductEnergy)

   // default
   Product() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Product(
      const wrapper<std::string> &label,
      const wrapper<std::string> &pid = {},
      const wrapper<std::optional<common::Multiplicity>> &multiplicity = {},
      const wrapper<std::optional<common::Distribution>> &distribution = {},
      const wrapper<std::optional<reduced::OutputChannel>> &outputChannel = {},
      const wrapper<std::optional<mean::AverageProductEnergy>> &averageProductEnergy = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      pid(this,pid),
      multiplicity(this,multiplicity),
      distribution(this,distribution),
      outputChannel(this,outputChannel),
      averageProductEnergy(this,averageProductEnergy)
   {
      Component::finish();
   }

   // from node
   explicit Product(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Product(const Product &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      pid(this,other.pid),
      multiplicity(this,other.multiplicity),
      distribution(this,other.distribution),
      outputChannel(this,other.outputChannel),
      averageProductEnergy(this,other.averageProductEnergy)
   {
      Component::finish(other);
   }

   // move
   Product(Product &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      pid(this,std::move(other.pid)),
      multiplicity(this,std::move(other.multiplicity)),
      distribution(this,std::move(other.distribution)),
      outputChannel(this,std::move(other.outputChannel)),
      averageProductEnergy(this,std::move(other.averageProductEnergy))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Product &operator=(const Product &) = default;
   Product &operator=(Product &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/common/Product/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Product

} // namespace common
} // namespace v2_0
} // namespace alpha

#endif
