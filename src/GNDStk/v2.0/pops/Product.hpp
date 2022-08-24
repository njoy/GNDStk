
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_POPS_PRODUCT
#define NJOY_GNDSTK_V2_0_POPS_PRODUCT

// core interface
#include "GNDStk.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// pops::
// class Product
// -----------------------------------------------------------------------------

namespace pops {

class Product : public Component<Product> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "pops"; }
   static auto className() { return "Product"; }
   static auto GNDSName() { return "product"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("label") |
         XMLName{}
            / Meta<>("pid")
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
      // metadata
      XMLName label;
      XMLName pid;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // label
   const XMLName &label() const
      { return content.label; }
   XMLName &label()
      { return content.label; }

   // pid
   const XMLName &pid() const
      { return content.pid; }
   XMLName &pid()
      { return content.pid; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // label(value)
   Product &label(const XMLName &obj)
      { label() = obj; return *this; }

   // pid(value)
   Product &pid(const XMLName &obj)
      { pid() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Product() :
      Component{
         BodyText{},
         content.label,
         content.pid
      }
   {
      Component::finish();
   }

   // copy
   Product(const Product &other) :
      Component{
         other,
         content.label,
         content.pid
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Product(Product &&other) :
      Component{
         other,
         content.label,
         content.pid
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Product(const Node &node) :
      Component{
         BodyText{},
         content.label,
         content.pid
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Product(
      const XMLName &label,
      const XMLName &pid
   ) :
      Component{
         BodyText{},
         content.label,
         content.pid
      },
      content{
         label,
         pid
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Product &operator=(const Product &) = default;

   // move
   Product &operator=(Product &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/pops/Product/src/custom.hpp"

}; // class Product

} // namespace pops
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif