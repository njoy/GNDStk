
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_PRODUCTS
#define ALPHA_V2_0_GENERAL_PRODUCTS

#include "alpha/v2.0/general/Product.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Products
// -----------------------------------------------------------------------------

class Products :
   public Component<general::Products>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Products"; }
   static auto NODENAME() { return "products"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<std::optional<general::Product>>
            ("product")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "product"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "product"
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

   // children
   Field<std::optional<std::vector<general::Product>>>
      product{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->product \
   )

   // default
   Products() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Products(
      const wrapper<std::optional<std::vector<general::Product>>>
         &product
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

   // copy
   Products &operator=(const Products &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         product = other.product;
      }
      return *this;
   }

   // move
   Products &operator=(Products &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         product = std::move(other.product);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/Products/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Products

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif