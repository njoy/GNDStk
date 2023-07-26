
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_REDUCED_PRODUCT
#define GNDS_V2_0_REDUCED_PRODUCT

#include "gnds/v2.0/general/Multiplicity.hpp"
#include "gnds/v2.0/reduced/Distribution.hpp"

namespace gnds {
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

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "reduced"; }
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
         --Child<general::Multiplicity>
            ("multiplicity") |
         --Child<reduced::Distribution>
            ("distribution")
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
         "distribution"
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
         "distribution"
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
   Field<general::Multiplicity>
      multiplicity{this};
   Field<reduced::Distribution>
      distribution{this};

   // shortcuts
   #define NJOY_GNDSTK_SHORTCUT(to,name) decltype(to.name) &name = to.name
   NJOY_GNDSTK_SHORTCUT(multiplicity(),XYs1d);
   NJOY_GNDSTK_SHORTCUT(distribution(),XYs2d);
   NJOY_GNDSTK_SHORTCUT(multiplicity(),branching1d);
   NJOY_GNDSTK_SHORTCUT(multiplicity(),constant1d);
   NJOY_GNDSTK_SHORTCUT(multiplicity(),polynomial1d);
   NJOY_GNDSTK_SHORTCUT(multiplicity(),reference);
   NJOY_GNDSTK_SHORTCUT(multiplicity(),regions1d);
   NJOY_GNDSTK_SHORTCUT(distribution(),thermalNeutronScatteringLaw);
   NJOY_GNDSTK_SHORTCUT(distribution(),uncorrelated);
   #undef NJOY_GNDSTK_SHORTCUT

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->pid, \
      this->multiplicity, \
      this->distribution \
   )

   // default
   Product() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
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
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      pid(this,pid),
      multiplicity(this,multiplicity),
      distribution(this,distribution)
   {
      Component::finish();
   }

   // from node
   explicit Product(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Product(const Product &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
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
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
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

   #include "gnds/v2.0/reduced/Product/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class Product

} // namespace reduced
} // namespace v2_0
} // namespace gnds

#endif
