
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_TRANSPORT_RESONANCESLINK
#define TRY_V2_0_TRANSPORT_RESONANCESLINK

#include "try/v2.0/key.hpp"

namespace try {
namespace v2_0 {
namespace transport {

// -----------------------------------------------------------------------------
// transport::
// class ResonancesLink
// -----------------------------------------------------------------------------

class ResonancesLink : public Component<transport::ResonancesLink> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "transport"; }
   static auto CLASS() { return "ResonancesLink"; }
   static auto FIELD() { return "resonances"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::optional<XMLName>{}
            / Meta<>("label") |
         std::string{}
            / Meta<>("href")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::optional<XMLName>> label{this};
   Field<std::string> href{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->href)

   // default, and from fields
   explicit ResonancesLink(
      const wrapper<std::optional<XMLName>> &label = {},
      const wrapper<std::string> &href = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      href(this,href)
   {
      Component::finish();
   }

   // from node
   explicit ResonancesLink(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ResonancesLink(const ResonancesLink &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   ResonancesLink(ResonancesLink &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   ResonancesLink &operator=(const ResonancesLink &) = default;
   ResonancesLink &operator=(ResonancesLink &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/transport/ResonancesLink/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ResonancesLink

} // namespace transport
} // namespace v2_0
} // namespace try

#endif
