
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_COMMON_CHEMICALELEMENT
#define ALPHA_V2_0_COMMON_CHEMICALELEMENT

#include "alpha/v2.0/atom/Atomic.hpp"
#include "alpha/v2.0/common/Isotopes.hpp"

namespace alpha {
namespace v2_0 {
namespace common {

// -----------------------------------------------------------------------------
// common::
// class ChemicalElement
// -----------------------------------------------------------------------------

class ChemicalElement :
   public Component<common::ChemicalElement>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "common"; }
   static auto CLASS() { return "ChemicalElement"; }
   static auto FIELD() { return "chemicalElement"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("symbol") |
         int{}
            / Meta<>("Z") |
         std::string{}
            / Meta<>("name") |

         // children
         --Child<std::optional<atom::Atomic>>("atomic") |
         --Child<std::optional<common::Isotopes>>("isotopes")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string> symbol{this};
   Field<int> Z{this};
   Field<std::string> name{this};

   // children
   Field<std::optional<atom::Atomic>> atomic{this};
   Field<std::optional<common::Isotopes>> isotopes{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->symbol, \
      this->Z, \
      this->name, \
      this->atomic, \
      this->isotopes)

   // default
   ChemicalElement() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ChemicalElement(
      const wrapper<std::string> &symbol,
      const wrapper<int> &Z = {},
      const wrapper<std::string> &name = {},
      const wrapper<std::optional<atom::Atomic>> &atomic = {},
      const wrapper<std::optional<common::Isotopes>> &isotopes = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      symbol(this,symbol),
      Z(this,Z),
      name(this,name),
      atomic(this,atomic),
      isotopes(this,isotopes)
   {
      Component::finish();
   }

   // from node
   explicit ChemicalElement(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ChemicalElement(const ChemicalElement &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      symbol(this,other.symbol),
      Z(this,other.Z),
      name(this,other.name),
      atomic(this,other.atomic),
      isotopes(this,other.isotopes)
   {
      Component::finish(other);
   }

   // move
   ChemicalElement(ChemicalElement &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      symbol(this,std::move(other.symbol)),
      Z(this,std::move(other.Z)),
      name(this,std::move(other.name)),
      atomic(this,std::move(other.atomic)),
      isotopes(this,std::move(other.isotopes))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   ChemicalElement &operator=(const ChemicalElement &) = default;
   ChemicalElement &operator=(ChemicalElement &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/common/ChemicalElement/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ChemicalElement

} // namespace common
} // namespace v2_0
} // namespace alpha

#endif
