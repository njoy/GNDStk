
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_PRODUCTYIELD
#define GNDS_V2_0_GENERAL_PRODUCTYIELD

#include "gnds/v2.0/reduced/Nuclides.hpp"
#include "gnds/v2.0/general/ElapsedTimes.hpp"

namespace gnds {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class ProductYield
// -----------------------------------------------------------------------------

class ProductYield :
   public Component<general::ProductYield>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "ProductYield"; }
   static auto NODENAME() { return "productYield"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::optional<std::string>{}
            / Meta<>("label") |

         // children
         --Child<std::optional<reduced::Nuclides>>
            ("nuclides") |
         --Child<general::ElapsedTimes>
            ("elapsedTimes")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "nuclides",
         "elapsedTimes"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "nuclides",
         "elapsed_times"
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
   Field<std::optional<std::string>>
      label{this};

   // children
   Field<std::optional<reduced::Nuclides>>
      nuclides{this};
   Field<general::ElapsedTimes>
      elapsedTimes{this};

   // shortcuts
   #define NJOY_GNDSTK_SHORTCUT(to,name) decltype(to.name) &name = to.name
   NJOY_GNDSTK_SHORTCUT(elapsedTimes(),elapsedTime);
   #undef NJOY_GNDSTK_SHORTCUT

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->nuclides, \
      this->elapsedTimes \
   )

   // default
   ProductYield() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ProductYield(
      const wrapper<std::optional<std::string>>
         &label,
      const wrapper<std::optional<reduced::Nuclides>>
         &nuclides = {},
      const wrapper<general::ElapsedTimes>
         &elapsedTimes = {}
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      nuclides(this,nuclides),
      elapsedTimes(this,elapsedTimes)
   {
      Component::finish();
   }

   // from node
   explicit ProductYield(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ProductYield(const ProductYield &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      nuclides(this,other.nuclides),
      elapsedTimes(this,other.elapsedTimes)
   {
      Component::finish(other);
   }

   // move
   ProductYield(ProductYield &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      nuclides(this,std::move(other.nuclides)),
      elapsedTimes(this,std::move(other.elapsedTimes))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   ProductYield &operator=(const ProductYield &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         nuclides = other.nuclides;
         elapsedTimes = other.elapsedTimes;
      }
      return *this;
   }

   // move
   ProductYield &operator=(ProductYield &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         nuclides = std::move(other.nuclides);
         elapsedTimes = std::move(other.elapsedTimes);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "gnds/v2.0/general/ProductYield/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class ProductYield

} // namespace general
} // namespace v2_0
} // namespace gnds

#endif
