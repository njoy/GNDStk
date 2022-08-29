
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_FISSIONTRANSPORT_PROMPTGAMMAENERGY
#define TRY_V2_0_FISSIONTRANSPORT_PROMPTGAMMAENERGY

#include "try/v2.0/unknownNamespace/XYs1d.hpp"
#include "try/v2.0/unknownNamespace/Polynomial1d.hpp"

namespace try {
namespace v2_0 {
namespace fissionTransport {

// -----------------------------------------------------------------------------
// fissionTransport::
// class PromptGammaEnergy
// -----------------------------------------------------------------------------

class PromptGammaEnergy : public Component<fissionTransport::PromptGammaEnergy> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "fissionTransport"; }
   static auto CLASS() { return "PromptGammaEnergy"; }
   static auto FIELD() { return "promptGammaEnergy"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         std::optional<unknownNamespace::XYs1d>{}
            / --Child<>("XYs1d") |
         std::optional<unknownNamespace::Polynomial1d>{}
            / --Child<>("polynomial1d")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::optional<unknownNamespace::XYs1d>> XYs1d{this};
   Field<std::optional<unknownNamespace::Polynomial1d>> polynomial1d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->XYs1d, \
      this->polynomial1d)

   // default, and from fields
   explicit PromptGammaEnergy(
      const wrapper<std::optional<unknownNamespace::XYs1d>> &XYs1d = {},
      const wrapper<std::optional<unknownNamespace::Polynomial1d>> &polynomial1d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      XYs1d(this,XYs1d),
      polynomial1d(this,polynomial1d)
   {
      Component::finish();
   }

   // from node
   explicit PromptGammaEnergy(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   PromptGammaEnergy(const PromptGammaEnergy &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   PromptGammaEnergy(PromptGammaEnergy &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   PromptGammaEnergy &operator=(const PromptGammaEnergy &) = default;
   PromptGammaEnergy &operator=(PromptGammaEnergy &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/fissionTransport/PromptGammaEnergy/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class PromptGammaEnergy

} // namespace fissionTransport
} // namespace v2_0
} // namespace try

#endif
