
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_COMMON_PRODUCTS
#define ALPHA_V2_0_COMMON_PRODUCTS

#include "alpha/v2.0/common/Product.hpp"

namespace alpha {
namespace v2_0 {
namespace common {

// -----------------------------------------------------------------------------
// common::
// class Products
// -----------------------------------------------------------------------------

class Products :
   public Component<common::Products>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "common"; }
   static auto CLASS() { return "Products"; }
   static auto FIELD() { return "products"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<std::optional<common::Product>>("product")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<std::optional<std::vector<common::Product>>> product{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->product)

   // default
   Products() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Products(
      const wrapper<std::optional<std::vector<common::Product>>> &product
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      product(this,product)
   {
      Component::finish();
   }

   // from node
   explicit Products(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Products(const Products &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      product(this,other.product)
   {
      Component::finish(other);
   }

   // move
   Products(Products &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      product(this,std::move(other.product))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Products &operator=(const Products &) = default;
   Products &operator=(Products &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/common/Products/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Products

} // namespace common
} // namespace v2_0
} // namespace alpha

#endif
