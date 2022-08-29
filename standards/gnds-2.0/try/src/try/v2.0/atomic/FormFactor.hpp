
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_ATOMIC_FORMFACTOR
#define TRY_V2_0_ATOMIC_FORMFACTOR

#include "try/v2.0/unknownNamespace/XYs1d.hpp"
#include "try/v2.0/unknownNamespace/Regions1d.hpp"

namespace try {
namespace v2_0 {
namespace atomic {

// -----------------------------------------------------------------------------
// atomic::
// class FormFactor
// -----------------------------------------------------------------------------

class FormFactor : public Component<atomic::FormFactor> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "atomic"; }
   static auto CLASS() { return "FormFactor"; }
   static auto FIELD() { return "formFactor"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         std::optional<unknownNamespace::XYs1d>{}
            / --Child<>("XYs1d") |
         std::optional<unknownNamespace::Regions1d>{}
            / --Child<>("regions1d")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::optional<unknownNamespace::XYs1d>> XYs1d{this};
   Field<std::optional<unknownNamespace::Regions1d>> regions1d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->XYs1d, \
      this->regions1d)

   // default, and from fields
   explicit FormFactor(
      const wrapper<std::optional<unknownNamespace::XYs1d>> &XYs1d = {},
      const wrapper<std::optional<unknownNamespace::Regions1d>> &regions1d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      XYs1d(this,XYs1d),
      regions1d(this,regions1d)
   {
      Component::finish();
   }

   // from node
   explicit FormFactor(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   FormFactor(const FormFactor &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   FormFactor(FormFactor &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   FormFactor &operator=(const FormFactor &) = default;
   FormFactor &operator=(FormFactor &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/atomic/FormFactor/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class FormFactor

} // namespace atomic
} // namespace v2_0
} // namespace try

#endif
