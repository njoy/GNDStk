
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_ORPHANPRODUCTS
#define GNDS_V2_0_GENERAL_ORPHANPRODUCTS

#include "GNDS/v2.0/general/OrphanProduct.hpp"

namespace GNDS {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class OrphanProducts
// -----------------------------------------------------------------------------

class OrphanProducts :
   public Component<general::OrphanProducts>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "OrphanProducts"; }
   static auto NODENAME() { return "orphanProducts"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<general::OrphanProduct>
            ("orphanProduct")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "orphanProduct"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "orphan_product"
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
   Field<std::vector<general::OrphanProduct>>
      orphanProduct{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->orphanProduct \
   )

   // default
   OrphanProducts() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit OrphanProducts(
      const wrapper<std::vector<general::OrphanProduct>>
         &orphanProduct
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      orphanProduct(this,orphanProduct)
   {
      Component::finish();
   }

   // from node
   explicit OrphanProducts(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   OrphanProducts(const OrphanProducts &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      orphanProduct(this,other.orphanProduct)
   {
      Component::finish(other);
   }

   // move
   OrphanProducts(OrphanProducts &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      orphanProduct(this,std::move(other.orphanProduct))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   OrphanProducts &operator=(const OrphanProducts &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         orphanProduct = other.orphanProduct;
      }
      return *this;
   }

   // move
   OrphanProducts &operator=(OrphanProducts &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         orphanProduct = std::move(other.orphanProduct);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDS/v2.0/general/OrphanProducts/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class OrphanProducts

} // namespace general
} // namespace v2_0
} // namespace GNDS

#endif
