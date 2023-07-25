
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_PRODUCTYIELDS
#define GNDS_V2_0_GENERAL_PRODUCTYIELDS

#include "gnds/v2.0/general/ProductYield.hpp"

namespace gnds {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class ProductYields
// -----------------------------------------------------------------------------

class ProductYields :
   public Component<general::ProductYields>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "ProductYields"; }
   static auto NODENAME() { return "productYields"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<general::ProductYield>
            ("productYield")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "productYield"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "product_yield"
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
   Field<std::vector<general::ProductYield>>
      productYield{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->productYield \
   )

   // default
   ProductYields() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ProductYields(
      const wrapper<std::vector<general::ProductYield>>
         &productYield
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      productYield(this,productYield)
   {
      Component::finish();
   }

   // from node
   explicit ProductYields(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ProductYields(const ProductYields &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      productYield(this,other.productYield)
   {
      Component::finish(other);
   }

   // move
   ProductYields(ProductYields &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      productYield(this,std::move(other.productYield))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   ProductYields &operator=(const ProductYields &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         productYield = other.productYield;
      }
      return *this;
   }

   // move
   ProductYields &operator=(ProductYields &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         productYield = std::move(other.productYield);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "gnds/v2.0/general/ProductYields/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ProductYields

} // namespace general
} // namespace v2_0
} // namespace gnds

#endif
