
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_CHEMICALELEMENTS
#define GNDS_V2_0_GENERAL_CHEMICALELEMENTS

#include "GNDS/v2.0/general/ChemicalElement.hpp"

namespace GNDS {
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

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "ChemicalElements"; }
   static auto NODENAME() { return "chemicalElements"; }

   // Core Interface multi-query to transfer information to/from core Nodes
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

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "chemicalElement"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "chemical_element"
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
   Field<std::vector<general::ChemicalElement>>
      chemicalElement{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->chemicalElement \
   )

   // default
   ChemicalElements() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ChemicalElements(
      const wrapper<std::vector<general::ChemicalElement>>
         &chemicalElement
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      chemicalElement(this,chemicalElement)
   {
      Component::finish();
   }

   // from node
   explicit ChemicalElements(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ChemicalElements(const ChemicalElements &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      chemicalElement(this,other.chemicalElement)
   {
      Component::finish(other);
   }

   // move
   ChemicalElements(ChemicalElements &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
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

   #include "GNDS/v2.0/general/ChemicalElements/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class ChemicalElements

} // namespace general
} // namespace v2_0
} // namespace GNDS

#endif
