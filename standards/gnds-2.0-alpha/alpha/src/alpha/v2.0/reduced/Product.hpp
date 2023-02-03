
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_REDUCED_PRODUCT
#define ALPHA_V2_0_REDUCED_PRODUCT

#include "alpha/v2.0/general/Multiplicity.hpp"
#include "alpha/v2.0/reduced/Distribution.hpp"

namespace alpha {
namespace v2_0 {
namespace reduced {

// -----------------------------------------------------------------------------
// reduced::
// class Product
// -----------------------------------------------------------------------------

class Product :
   public Component<reduced::Product>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "reduced"; }
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
         --Child<general::Multiplicity>
            ("multiplicity") |
         --Child<reduced::Distribution>
            ("distribution")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string>
      label{this};
   Field<std::string>
      pid{this};

   // children
   Field<general::Multiplicity>
      multiplicity{this};
   Field<reduced::Distribution>
      distribution{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->label, \
      this->pid, \
      this->multiplicity, \
      this->distribution)

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
      const wrapper<general::Multiplicity>
         &multiplicity = {},
      const wrapper<reduced::Distribution>
         &distribution = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      pid(this,pid),
      multiplicity(this,multiplicity),
      distribution(this,distribution)
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
      distribution(this,other.distribution)
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
      distribution(this,std::move(other.distribution))
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
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/reduced/Product/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Product

} // namespace reduced
} // namespace v2_0
} // namespace alpha

#endif
