
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_CONTAINERS_STANDARD
#define TRY_V2_0_CONTAINERS_STANDARD

#include "try/v2.0/containers/Double.hpp"

namespace try {
namespace v2_0 {
namespace containers {

// -----------------------------------------------------------------------------
// containers::
// class Standard
// -----------------------------------------------------------------------------

class Standard : public Component<containers::Standard> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "containers"; }
   static auto CLASS() { return "Standard"; }
   static auto FIELD() { return "standard"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         containers::Double{}
            / --Child<>("Double")
      ;
   }

public:
   using Component::construct;

   // children
   Field<containers::Double> Double{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->Double)

   // default, and from fields
   explicit Standard(
      const wrapper<containers::Double> &Double = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      Double(this,Double)
   {
      Component::finish();
   }

   // from node
   explicit Standard(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Standard(const Standard &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Standard(Standard &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Standard &operator=(const Standard &) = default;
   Standard &operator=(Standard &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/containers/Standard/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Standard

} // namespace containers
} // namespace v2_0
} // namespace try

#endif
