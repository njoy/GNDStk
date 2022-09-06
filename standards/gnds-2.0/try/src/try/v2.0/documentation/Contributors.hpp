
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_DOCUMENTATION_CONTRIBUTORS
#define TRY_V2_0_DOCUMENTATION_CONTRIBUTORS

#include "try/v2.0/documentation/Author.hpp"

namespace try {
namespace v2_0 {
namespace documentation {

// -----------------------------------------------------------------------------
// documentation::
// class Contributors
// -----------------------------------------------------------------------------

class Contributors : public Component<documentation::Contributors> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "documentation"; }
   static auto CLASS() { return "Contributors"; }
   static auto FIELD() { return "contributors"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         documentation::Author{}
            / ++Child<>("contributor")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::vector<documentation::Author>> contributor{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->contributor)

   // default, and from fields
   explicit Contributors(
      const wrapper<std::vector<documentation::Author>> &contributor = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      contributor(this,contributor)
   {
      Component::finish();
   }

   // from node
   explicit Contributors(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Contributors(const Contributors &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Contributors(Contributors &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Contributors &operator=(const Contributors &) = default;
   Contributors &operator=(Contributors &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/documentation/Contributors/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Contributors

} // namespace documentation
} // namespace v2_0
} // namespace try

#endif