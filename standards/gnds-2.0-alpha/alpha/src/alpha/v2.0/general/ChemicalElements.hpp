
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_CHEMICALELEMENTS
#define ALPHA_V2_0_GENERAL_CHEMICALELEMENTS

#include "alpha/v2.0/general/ChemicalElement.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class ChemicalElements
// -----------------------------------------------------------------------------

class ChemicalElements :
   public Component<general::ChemicalElements>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "ChemicalElements"; }
   static auto FIELD() { return "chemicalElements"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<general::ChemicalElement>
            ("chemicalElement")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<std::vector<general::ChemicalElement>>
      chemicalElement{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->chemicalElement)

   // default
   ChemicalElements() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ChemicalElements(
      const wrapper<std::vector<general::ChemicalElement>>
         &chemicalElement
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      chemicalElement(this,chemicalElement)
   {
      Component::finish();
   }

   // from node
   explicit ChemicalElements(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ChemicalElements(const ChemicalElements &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      chemicalElement(this,other.chemicalElement)
   {
      Component::finish(other);
   }

   // move
   ChemicalElements(ChemicalElements &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      chemicalElement(this,std::move(other.chemicalElement))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   ChemicalElements &operator=(const ChemicalElements &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         chemicalElement = other.chemicalElement;
      }
      return *this;
   }

   // move
   ChemicalElements &operator=(ChemicalElements &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         chemicalElement = std::move(other.chemicalElement);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/ChemicalElements/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ChemicalElements

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
