
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_FISSIONTRANSPORT_SIMPLEMAXWELLIANFISSION
#define TRY_V2_0_FISSIONTRANSPORT_SIMPLEMAXWELLIANFISSION

#include "try/v2.0/transport/U.hpp"
#include "try/v2.0/transport/Theta.hpp"

namespace try {
namespace v2_0 {
namespace fissionTransport {

// -----------------------------------------------------------------------------
// fissionTransport::
// class SimpleMaxwellianFission
// -----------------------------------------------------------------------------

class SimpleMaxwellianFission : public Component<fissionTransport::SimpleMaxwellianFission> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "fissionTransport"; }
   static auto CLASS() { return "SimpleMaxwellianFission"; }
   static auto FIELD() { return "simpleMaxwellianFission"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         std::optional<transport::U>{}
            / --Child<>("U") |
         std::optional<transport::Theta>{}
            / --Child<>("theta")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::optional<transport::U>> U{this};
   Field<std::optional<transport::Theta>> theta{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->U, \
      this->theta)

   // default, and from fields
   explicit SimpleMaxwellianFission(
      const wrapper<std::optional<transport::U>> &U = {},
      const wrapper<std::optional<transport::Theta>> &theta = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      U(this,U),
      theta(this,theta)
   {
      Component::finish();
   }

   // from node
   explicit SimpleMaxwellianFission(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   SimpleMaxwellianFission(const SimpleMaxwellianFission &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   SimpleMaxwellianFission(SimpleMaxwellianFission &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   SimpleMaxwellianFission &operator=(const SimpleMaxwellianFission &) = default;
   SimpleMaxwellianFission &operator=(SimpleMaxwellianFission &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/fissionTransport/SimpleMaxwellianFission/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class SimpleMaxwellianFission

} // namespace fissionTransport
} // namespace v2_0
} // namespace try

#endif