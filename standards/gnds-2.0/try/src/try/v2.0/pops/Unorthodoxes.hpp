
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_POPS_UNORTHODOXES
#define TRY_V2_0_POPS_UNORTHODOXES

#include "try/v2.0/pops/Nuclide.hpp"

namespace try {
namespace v2_0 {
namespace pops {

// -----------------------------------------------------------------------------
// pops::
// class Unorthodoxes
// -----------------------------------------------------------------------------

class Unorthodoxes : public Component<pops::Unorthodoxes> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "pops"; }
   static auto CLASS() { return "Unorthodoxes"; }
   static auto FIELD() { return "unorthodoxes"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         pops::Nuclide{}
            / ++Child<>("unorthodox")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::vector<pops::Nuclide>> unorthodox{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->unorthodox)

   // default, and from fields
   explicit Unorthodoxes(
      const wrapper<std::vector<pops::Nuclide>> &unorthodox = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      unorthodox(this,unorthodox)
   {
      Component::finish();
   }

   // from node
   explicit Unorthodoxes(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Unorthodoxes(const Unorthodoxes &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Unorthodoxes(Unorthodoxes &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Unorthodoxes &operator=(const Unorthodoxes &) = default;
   Unorthodoxes &operator=(Unorthodoxes &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/pops/Unorthodoxes/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Unorthodoxes

} // namespace pops
} // namespace v2_0
} // namespace try

#endif
