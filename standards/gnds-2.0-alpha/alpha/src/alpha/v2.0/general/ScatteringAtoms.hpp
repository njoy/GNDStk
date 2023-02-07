
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_SCATTERINGATOMS
#define ALPHA_V2_0_GENERAL_SCATTERINGATOMS

#include "alpha/v2.0/general/ScatteringAtom.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class ScatteringAtoms
// -----------------------------------------------------------------------------

class ScatteringAtoms :
   public Component<general::ScatteringAtoms>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "ScatteringAtoms"; }
   static auto FIELD() { return "scatteringAtoms"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<general::ScatteringAtom>
            ("scatteringAtom")
      ;
   }

public:
   using component_t = Component;
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<std::vector<general::ScatteringAtom>>
      scatteringAtom{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->scatteringAtom \
   )

   // default
   ScatteringAtoms() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ScatteringAtoms(
      const wrapper<std::vector<general::ScatteringAtom>>
         &scatteringAtom
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      scatteringAtom(this,scatteringAtom)
   {
      Component::finish();
   }

   // from node
   explicit ScatteringAtoms(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ScatteringAtoms(const ScatteringAtoms &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      scatteringAtom(this,other.scatteringAtom)
   {
      Component::finish(other);
   }

   // move
   ScatteringAtoms(ScatteringAtoms &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      scatteringAtom(this,std::move(other.scatteringAtom))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   ScatteringAtoms &operator=(const ScatteringAtoms &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         scatteringAtom = other.scatteringAtom;
      }
      return *this;
   }

   // move
   ScatteringAtoms &operator=(ScatteringAtoms &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         scatteringAtom = std::move(other.scatteringAtom);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/ScatteringAtoms/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ScatteringAtoms

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
