
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_DOCUMENTATION_COLLABORATIONS
#define TRY_V2_0_DOCUMENTATION_COLLABORATIONS

#include "try/v2.0/documentation/Collaboration.hpp"

namespace try {
namespace v2_0 {
namespace documentation {

// -----------------------------------------------------------------------------
// documentation::
// class Collaborations
// -----------------------------------------------------------------------------

class Collaborations : public Component<documentation::Collaborations> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "documentation"; }
   static auto CLASS() { return "Collaborations"; }
   static auto FIELD() { return "collaborations"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         documentation::Collaboration{}
            / ++Child<>("collaboration")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::vector<documentation::Collaboration>> collaboration{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->collaboration)

   // default, and from fields
   explicit Collaborations(
      const wrapper<std::vector<documentation::Collaboration>> &collaboration = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      collaboration(this,collaboration)
   {
      Component::finish();
   }

   // from node
   explicit Collaborations(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Collaborations(const Collaborations &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Collaborations(Collaborations &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Collaborations &operator=(const Collaborations &) = default;
   Collaborations &operator=(Collaborations &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/documentation/Collaborations/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Collaborations

} // namespace documentation
} // namespace v2_0
} // namespace try

#endif
