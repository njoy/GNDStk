
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_CHEMICALELEMENT
#define ALPHA_V2_0_GENERAL_CHEMICALELEMENT

#include "alpha/v2.0/general/Atomic.hpp"
#include "alpha/v2.0/general/Isotopes.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class ChemicalElement
// -----------------------------------------------------------------------------

class ChemicalElement :
   public Component<general::ChemicalElement>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
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
         --Child<std::optional<general::Atomic>>
            ("atomic") |
         --Child<std::optional<general::Isotopes>>
            ("isotopes")
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
   Field<std::optional<general::Atomic>>
      atomic{this};
   Field<std::optional<general::Isotopes>>
      isotopes{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->symbol, \
      this->Z, \
      this->name, \
      this->atomic, \
      this->isotopes \
   )

   // default
   ChemicalElement() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ChemicalElement(
      const wrapper<std::string>
         &symbol,
      const wrapper<int>
         &Z = {},
      const wrapper<std::string>
         &name = {},
      const wrapper<std::optional<general::Atomic>>
         &atomic = {},
      const wrapper<std::optional<general::Isotopes>>
         &isotopes = {}
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

   // copy
   ChemicalElement &operator=(const ChemicalElement &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         symbol = other.symbol;
         Z = other.Z;
         name = other.name;
         atomic = other.atomic;
         isotopes = other.isotopes;
      }
      return *this;
   }

   // move
   ChemicalElement &operator=(ChemicalElement &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         symbol = std::move(other.symbol);
         Z = std::move(other.Z);
         name = std::move(other.name);
         atomic = std::move(other.atomic);
         isotopes = std::move(other.isotopes);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/ChemicalElement/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ChemicalElement

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
