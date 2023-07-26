
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_NBODYPHASESPACE
#define GNDS_V2_0_GENERAL_NBODYPHASESPACE

#include "gnds/v2.0/general/Mass.hpp"

namespace gnds {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class NBodyPhaseSpace
// -----------------------------------------------------------------------------

class NBodyPhaseSpace :
   public Component<general::NBodyPhaseSpace>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "NBodyPhaseSpace"; }
   static auto NODENAME() { return "NBodyPhaseSpace"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         int{}
            / Meta<>("numberOfProducts") |

         // children
         --Child<general::Mass>
            ("mass")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "numberOfProducts",
         "mass"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "number_of_products",
         "mass"
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
   Field<int>
      numberOfProducts{this};

   // children
   Field<general::Mass>
      mass{this};

   // shortcuts
   #define NJOY_GNDSTK_SHORTCUT(to,name) decltype(to.name) &name = to.name
   NJOY_GNDSTK_SHORTCUT(mass(),Double);
   #undef NJOY_GNDSTK_SHORTCUT

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->numberOfProducts, \
      this->mass \
   )

   // default
   NBodyPhaseSpace() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit NBodyPhaseSpace(
      const wrapper<int>
         &numberOfProducts,
      const wrapper<general::Mass>
         &mass = {}
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      numberOfProducts(this,numberOfProducts),
      mass(this,mass)
   {
      Component::finish();
   }

   // from node
   explicit NBodyPhaseSpace(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   NBodyPhaseSpace(const NBodyPhaseSpace &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      numberOfProducts(this,other.numberOfProducts),
      mass(this,other.mass)
   {
      Component::finish(other);
   }

   // move
   NBodyPhaseSpace(NBodyPhaseSpace &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      numberOfProducts(this,std::move(other.numberOfProducts)),
      mass(this,std::move(other.mass))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   NBodyPhaseSpace &operator=(const NBodyPhaseSpace &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         numberOfProducts = other.numberOfProducts;
         mass = other.mass;
      }
      return *this;
   }

   // move
   NBodyPhaseSpace &operator=(NBodyPhaseSpace &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         numberOfProducts = std::move(other.numberOfProducts);
         mass = std::move(other.mass);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "gnds/v2.0/general/NBodyPhaseSpace/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class NBodyPhaseSpace

} // namespace general
} // namespace v2_0
} // namespace gnds

#endif
