
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_TRANSPORT_ORPHANPRODUCTS
#define NJOY_GNDSTK_V2_0_TRANSPORT_ORPHANPRODUCTS

// core interface
#include "GNDStk.hpp"

// v2.0 dependencies
#include "GNDStk/v2.0/transport/OrphanProduct.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// transport::
// class OrphanProducts
// -----------------------------------------------------------------------------

namespace transport {

class OrphanProducts : public Component<OrphanProducts> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "transport"; }
   static auto className() { return "OrphanProducts"; }
   static auto GNDSName() { return "orphanProducts"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // children
         transport::OrphanProduct{}
            / ++Child<>("orphanProduct")
      ;
   }

public:

   using Component::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static inline const struct Defaults {
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // children
      std::vector<transport::OrphanProduct> orphanProduct;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // orphanProduct
   const std::vector<transport::OrphanProduct> &orphanProduct() const
      { return content.orphanProduct; }
   std::vector<transport::OrphanProduct> &orphanProduct()
      { return content.orphanProduct; }

   // orphanProduct(index)
   const transport::OrphanProduct &orphanProduct(const std::size_t index) const
      { return getter(orphanProduct(), index, "orphanProduct"); }
   transport::OrphanProduct &orphanProduct(const std::size_t index)
      { return getter(orphanProduct(), index, "orphanProduct"); }

   // orphanProduct(label)
   const transport::OrphanProduct &orphanProduct(const std::string &label) const
      { return getter(orphanProduct(), label, "orphanProduct"); }
   transport::OrphanProduct &orphanProduct(const std::string &label)
      { return getter(orphanProduct(), label, "orphanProduct"); }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // orphanProduct(value)
   OrphanProducts &orphanProduct(const std::vector<transport::OrphanProduct> &obj)
      { orphanProduct() = obj; return *this; }

   // orphanProduct(index,value)
   OrphanProducts &orphanProduct(
      const std::size_t index,
      const transport::OrphanProduct &obj
   ) {
      orphanProduct(index) = obj; return *this;
   }

   // orphanProduct(label,value)
   OrphanProducts &orphanProduct(
      const std::string &label,
      const transport::OrphanProduct &obj
   ) {
      orphanProduct(label) = obj; return *this;
   }

   // ------------------------
   // Construction
   // ------------------------

   // default
   OrphanProducts() :
      Component{
         BodyText{},
         content.orphanProduct
      }
   {
      Component::finish();
   }

   // copy
   OrphanProducts(const OrphanProducts &other) :
      Component{
         other,
         content.orphanProduct
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   OrphanProducts(OrphanProducts &&other) :
      Component{
         other,
         content.orphanProduct
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   OrphanProducts(const Node &node) :
      Component{
         BodyText{},
         content.orphanProduct
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit OrphanProducts(
      const std::vector<transport::OrphanProduct> &orphanProduct
   ) :
      Component{
         BodyText{},
         content.orphanProduct
      },
      content{
         orphanProduct
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   OrphanProducts &operator=(const OrphanProducts &) = default;

   // move
   OrphanProducts &operator=(OrphanProducts &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/transport/OrphanProducts/src/custom.hpp"

}; // class OrphanProducts

} // namespace transport
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif
