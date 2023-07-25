
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_PRODUCT
#define GNDS_V2_0_GENERAL_PRODUCT

#include "gnds/v2.0/general/Multiplicity.hpp"
#include "gnds/v2.0/general/Distribution.hpp"
#include "gnds/v2.0/reduced/OutputChannel.hpp"
#include "gnds/v2.0/general/AverageProductEnergy.hpp"

namespace gnds {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Product
// -----------------------------------------------------------------------------

class Product :
   public Component<general::Product>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Product"; }
   static auto NODENAME() { return "product"; }

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
            / Meta<>("pid") |

         // children
         --Child<std::optional<general::Multiplicity>>
            ("multiplicity") |
         --Child<std::optional<general::Distribution>>
            ("distribution") |
         --Child<std::optional<reduced::OutputChannel>>
            ("outputChannel") |
         --Child<std::optional<general::AverageProductEnergy>>
            ("averageProductEnergy")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "pid",
         "multiplicity",
         "distribution",
         "outputChannel",
         "averageProductEnergy"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "pid",
         "multiplicity",
         "distribution",
         "output_channel",
         "average_product_energy"
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
      pid{this};

   // children
   Field<std::optional<general::Multiplicity>>
      multiplicity{this};
   Field<std::optional<general::Distribution>>
      distribution{this};
   Field<std::optional<reduced::OutputChannel>>
      outputChannel{this};
   Field<std::optional<general::AverageProductEnergy>>
      averageProductEnergy{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->pid, \
      this->multiplicity, \
      this->distribution, \
      this->outputChannel, \
      this->averageProductEnergy \
   )

   // default
   Product() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Product(
      const wrapper<std::string>
         &label,
      const wrapper<std::string>
         &pid = {},
      const wrapper<std::optional<general::Multiplicity>>
         &multiplicity = {},
      const wrapper<std::optional<general::Distribution>>
         &distribution = {},
      const wrapper<std::optional<reduced::OutputChannel>>
         &outputChannel = {},
      const wrapper<std::optional<general::AverageProductEnergy>>
         &averageProductEnergy = {}
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

   // copy
   Product &operator=(const Product &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         pid = other.pid;
         multiplicity = other.multiplicity;
         distribution = other.distribution;
         outputChannel = other.outputChannel;
         averageProductEnergy = other.averageProductEnergy;
      }
      return *this;
   }

   // move
   Product &operator=(Product &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         pid = std::move(other.pid);
         multiplicity = std::move(other.multiplicity);
         distribution = std::move(other.distribution);
         outputChannel = std::move(other.outputChannel);
         averageProductEnergy = std::move(other.averageProductEnergy);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "gnds/v2.0/general/Product/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Product

} // namespace general
} // namespace v2_0
} // namespace gnds

#endif
