
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_FISSIONTRANSPORT_EFH
#define TRY_V2_0_FISSIONTRANSPORT_EFH

#include "try/v2.0/key.hpp"

namespace try {
namespace v2_0 {
namespace fissionTransport {

// -----------------------------------------------------------------------------
// fissionTransport::
// class EFH
// -----------------------------------------------------------------------------

class EFH : public Component<fissionTransport::EFH> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "fissionTransport"; }
   static auto CLASS() { return "EFH"; }
   static auto FIELD() { return "EFH"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("unit") |
         Float64{}
            / Meta<>("value")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<XMLName> unit{this};
   Field<Float64> value{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->unit, \
      this->value)

   // default, and from fields
   explicit EFH(
      const wrapper<XMLName> &unit = {},
      const wrapper<Float64> &value = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      unit(this,unit),
      value(this,value)
   {
      Component::finish();
   }

   // from node
   explicit EFH(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   EFH(const EFH &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   EFH(EFH &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   EFH &operator=(const EFH &) = default;
   EFH &operator=(EFH &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/fissionTransport/EFH/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class EFH

} // namespace fissionTransport
} // namespace v2_0
} // namespace try

#endif
