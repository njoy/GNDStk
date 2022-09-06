
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_FPY_YIELDS
#define TRY_V2_0_FPY_YIELDS

#include "try/v2.0/fpy/Nuclides.hpp"
#include "try/v2.0/containers/Values.hpp"
#include "try/v2.0/containers/Uncertainty.hpp"

namespace try {
namespace v2_0 {
namespace fpy {

// -----------------------------------------------------------------------------
// fpy::
// class Yields
// -----------------------------------------------------------------------------

class Yields : public Component<fpy::Yields> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "fpy"; }
   static auto CLASS() { return "Yields"; }
   static auto FIELD() { return "yields"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         fpy::Nuclides{}
            / --Child<>("nuclides") |
         containers::Values{}
            / --Child<>("values") |
         std::optional<containers::Uncertainty>{}
            / --Child<>("uncertainty")
      ;
   }

public:
   using Component::construct;

   // children
   Field<fpy::Nuclides> nuclides{this};
   Field<containers::Values> values{this};
   Field<std::optional<containers::Uncertainty>> uncertainty{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->nuclides, \
      this->values, \
      this->uncertainty)

   // default, and from fields
   explicit Yields(
      const wrapper<fpy::Nuclides> &nuclides = {},
      const wrapper<containers::Values> &values = {},
      const wrapper<std::optional<containers::Uncertainty>> &uncertainty = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      nuclides(this,nuclides),
      values(this,values),
      uncertainty(this,uncertainty)
   {
      Component::finish();
   }

   // from node
   explicit Yields(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Yields(const Yields &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Yields(Yields &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Yields &operator=(const Yields &) = default;
   Yields &operator=(Yields &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/fpy/Yields/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Yields

} // namespace fpy
} // namespace v2_0
} // namespace try

#endif
