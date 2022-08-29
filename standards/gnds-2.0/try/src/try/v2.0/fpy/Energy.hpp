
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_FPY_ENERGY
#define TRY_V2_0_FPY_ENERGY

#include "try/v2.0/unknownNamespace/Double.hpp"

namespace try {
namespace v2_0 {
namespace fpy {

// -----------------------------------------------------------------------------
// fpy::
// class Energy
// -----------------------------------------------------------------------------

class Energy : public Component<fpy::Energy> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "fpy"; }
   static auto CLASS() { return "Energy"; }
   static auto FIELD() { return "energy"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         unknownNamespace::Double{}
            / --Child<>("Double")
      ;
   }

public:
   using Component::construct;

   // children
   Field<unknownNamespace::Double> Double{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->Double)

   // default, and from fields
   explicit Energy(
      const wrapper<unknownNamespace::Double> &Double = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      Double(this,Double)
   {
      Component::finish();
   }

   // from node
   explicit Energy(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Energy(const Energy &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Energy(Energy &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Energy &operator=(const Energy &) = default;
   Energy &operator=(Energy &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/fpy/Energy/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Energy

} // namespace fpy
} // namespace v2_0
} // namespace try

#endif
