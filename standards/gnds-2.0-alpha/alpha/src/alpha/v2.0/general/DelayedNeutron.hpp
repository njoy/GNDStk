
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_DELAYEDNEUTRON
#define ALPHA_V2_0_GENERAL_DELAYEDNEUTRON

#include "alpha/v2.0/general/Rate.hpp"
#include "alpha/v2.0/reduced/Product.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class DelayedNeutron
// -----------------------------------------------------------------------------

class DelayedNeutron :
   public Component<general::DelayedNeutron>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "DelayedNeutron"; }
   static auto FIELD() { return "delayedNeutron"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("label") |

         // children
         --Child<general::Rate>
            ("rate") |
         --Child<reduced::Product>
            ("product")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string> label{this};

   // children
   Field<general::Rate>
      rate{this};
   Field<reduced::Product>
      product{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->rate, \
      this->product \
   )

   // default
   DelayedNeutron() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit DelayedNeutron(
      const wrapper<std::string>
         &label,
      const wrapper<general::Rate>
         &rate = {},
      const wrapper<reduced::Product>
         &product = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      rate(this,rate),
      product(this,product)
   {
      Component::finish();
   }

   // from node
   explicit DelayedNeutron(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   DelayedNeutron(const DelayedNeutron &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      rate(this,other.rate),
      product(this,other.product)
   {
      Component::finish(other);
   }

   // move
   DelayedNeutron(DelayedNeutron &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      rate(this,std::move(other.rate)),
      product(this,std::move(other.product))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   DelayedNeutron &operator=(const DelayedNeutron &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         rate = other.rate;
         product = other.product;
      }
      return *this;
   }

   // move
   DelayedNeutron &operator=(DelayedNeutron &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         rate = std::move(other.rate);
         product = std::move(other.product);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/DelayedNeutron/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class DelayedNeutron

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
