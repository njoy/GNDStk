
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_TRANSPORT_EVAPORATION
#define TRY_V2_0_TRANSPORT_EVAPORATION

#include "try/v2.0/transport/U.hpp"
#include "try/v2.0/transport/Theta.hpp"

namespace try {
namespace v2_0 {
namespace transport {

// -----------------------------------------------------------------------------
// transport::
// class Evaporation
// -----------------------------------------------------------------------------

class Evaporation : public Component<transport::Evaporation> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "transport"; }
   static auto CLASS() { return "Evaporation"; }
   static auto FIELD() { return "evaporation"; }

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
   explicit Evaporation(
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
   explicit Evaporation(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Evaporation(const Evaporation &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Evaporation(Evaporation &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Evaporation &operator=(const Evaporation &) = default;
   Evaporation &operator=(Evaporation &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/transport/Evaporation/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Evaporation

} // namespace transport
} // namespace v2_0
} // namespace try

#endif
