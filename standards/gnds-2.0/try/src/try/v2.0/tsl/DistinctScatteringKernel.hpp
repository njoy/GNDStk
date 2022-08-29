
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_TSL_DISTINCTSCATTERINGKERNEL
#define TRY_V2_0_TSL_DISTINCTSCATTERINGKERNEL

#include "try/v2.0/unknownNamespace/Gridded3d.hpp"

namespace try {
namespace v2_0 {
namespace tsl {

// -----------------------------------------------------------------------------
// tsl::
// class DistinctScatteringKernel
// -----------------------------------------------------------------------------

class DistinctScatteringKernel : public Component<tsl::DistinctScatteringKernel> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "tsl"; }
   static auto CLASS() { return "DistinctScatteringKernel"; }
   static auto FIELD() { return "distinctScatteringKernel"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         std::optional<unknownNamespace::Gridded3d>{}
            / --Child<>("gridded3d")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::optional<unknownNamespace::Gridded3d>> gridded3d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->gridded3d)

   // default, and from fields
   explicit DistinctScatteringKernel(
      const wrapper<std::optional<unknownNamespace::Gridded3d>> &gridded3d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      gridded3d(this,gridded3d)
   {
      Component::finish();
   }

   // from node
   explicit DistinctScatteringKernel(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   DistinctScatteringKernel(const DistinctScatteringKernel &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   DistinctScatteringKernel(DistinctScatteringKernel &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   DistinctScatteringKernel &operator=(const DistinctScatteringKernel &) = default;
   DistinctScatteringKernel &operator=(DistinctScatteringKernel &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/tsl/DistinctScatteringKernel/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class DistinctScatteringKernel

} // namespace tsl
} // namespace v2_0
} // namespace try

#endif
