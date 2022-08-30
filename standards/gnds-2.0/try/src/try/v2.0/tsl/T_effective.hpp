
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_TSL_T_EFFECTIVE
#define TRY_V2_0_TSL_T_EFFECTIVE

#include "try/v2.0/containers/XYs1d.hpp"

namespace try {
namespace v2_0 {
namespace tsl {

// -----------------------------------------------------------------------------
// tsl::
// class T_effective
// -----------------------------------------------------------------------------

class T_effective : public Component<tsl::T_effective> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "tsl"; }
   static auto CLASS() { return "T_effective"; }
   static auto FIELD() { return "T_effective"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         containers::XYs1d{}
            / --Child<>("XYs1d")
      ;
   }

public:
   using Component::construct;

   // children
   Field<containers::XYs1d> XYs1d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->XYs1d)

   // default, and from fields
   explicit T_effective(
      const wrapper<containers::XYs1d> &XYs1d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      XYs1d(this,XYs1d)
   {
      Component::finish();
   }

   // from node
   explicit T_effective(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   T_effective(const T_effective &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   T_effective(T_effective &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   T_effective &operator=(const T_effective &) = default;
   T_effective &operator=(T_effective &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/tsl/T_effective/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class T_effective

} // namespace tsl
} // namespace v2_0
} // namespace try

#endif
