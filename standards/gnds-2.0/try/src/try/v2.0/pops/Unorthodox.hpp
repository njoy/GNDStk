
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_POPS_UNORTHODOX
#define TRY_V2_0_POPS_UNORTHODOX

#include "try/v2.0/pops/Charge.hpp"
#include "try/v2.0/pops/Mass.hpp"

namespace try {
namespace v2_0 {
namespace pops {

// -----------------------------------------------------------------------------
// pops::
// class Unorthodox
// -----------------------------------------------------------------------------

class Unorthodox : public Component<pops::Unorthodox> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "pops"; }
   static auto CLASS() { return "Unorthodox"; }
   static auto FIELD() { return "unorthodox"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("id") |
         // children
         std::optional<pops::Charge>{}
            / --Child<>("charge") |
         std::optional<pops::Mass>{}
            / --Child<>("mass")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<XMLName> id{this};

   // children
   Field<std::optional<pops::Charge>> charge{this};
   Field<std::optional<pops::Mass>> mass{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->id, \
      this->charge, \
      this->mass)

   // default, and from fields
   explicit Unorthodox(
      const wrapper<XMLName> &id = {},
      const wrapper<std::optional<pops::Charge>> &charge = {},
      const wrapper<std::optional<pops::Mass>> &mass = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      id(this,id),
      charge(this,charge),
      mass(this,mass)
   {
      Component::finish();
   }

   // from node
   explicit Unorthodox(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Unorthodox(const Unorthodox &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Unorthodox(Unorthodox &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Unorthodox &operator=(const Unorthodox &) = default;
   Unorthodox &operator=(Unorthodox &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/pops/Unorthodox/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Unorthodox

} // namespace pops
} // namespace v2_0
} // namespace try

#endif
