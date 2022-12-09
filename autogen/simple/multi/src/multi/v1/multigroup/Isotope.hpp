
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef MULTI_V1_MULTIGROUP_ISOTOPE
#define MULTI_V1_MULTIGROUP_ISOTOPE

#include "multi/v1/key.hpp"

namespace multi {
namespace v1 {
namespace multigroup {

// -----------------------------------------------------------------------------
// multigroup::
// class Isotope
// -----------------------------------------------------------------------------

class Isotope : public Component<multigroup::Isotope> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "multigroup"; }
   static auto CLASS() { return "Isotope"; }
   static auto FIELD() { return "isotope"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         int{}
            / Meta<>("mass_number")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<int> mass_number{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->mass_number)

   // default, and from fields
   explicit Isotope(
      const wrapper<int> &mass_number = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      mass_number(this,mass_number)
   {
      Component::finish();
   }

   // from node
   explicit Isotope(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Isotope(const Isotope &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Isotope(Isotope &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Isotope &operator=(const Isotope &) = default;
   Isotope &operator=(Isotope &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "multi/v1/multigroup/Isotope/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Isotope

} // namespace multigroup
} // namespace v1
} // namespace multi

#endif
