
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_TRANSPORT_REACTION
#define TRY_V2_0_TRANSPORT_REACTION

#include "try/v2.0/transport/DoubleDifferentialCrossSection.hpp"
#include "try/v2.0/transport/CrossSection.hpp"
#include "try/v2.0/transport/OutputChannel.hpp"

namespace try {
namespace v2_0 {
namespace transport {

// -----------------------------------------------------------------------------
// transport::
// class Reaction
// -----------------------------------------------------------------------------

class Reaction : public Component<transport::Reaction> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "transport"; }
   static auto CLASS() { return "Reaction"; }
   static auto FIELD() { return "reaction"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         Integer32{}
            / Meta<>("ENDF_MT") |
         std::optional<XMLName>{}
            / Meta<>("fissionGenre") |
         XMLName{}
            / Meta<>("label") |
         // children
         std::optional<transport::DoubleDifferentialCrossSection>{}
            / --Child<>("doubleDifferentialCrossSection") |
         transport::CrossSection{}
            / --Child<>("crossSection") |
         transport::OutputChannel{}
            / --Child<>("outputChannel")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<Integer32> ENDF_MT{this};
   Field<std::optional<XMLName>> fissionGenre{this};
   Field<XMLName> label{this};

   // children
   Field<std::optional<transport::DoubleDifferentialCrossSection>> doubleDifferentialCrossSection{this};
   Field<transport::CrossSection> crossSection{this};
   Field<transport::OutputChannel> outputChannel{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->ENDF_MT, \
      this->fissionGenre, \
      this->label, \
      this->doubleDifferentialCrossSection, \
      this->crossSection, \
      this->outputChannel)

   // default, and from fields
   explicit Reaction(
      const wrapper<Integer32> &ENDF_MT = {},
      const wrapper<std::optional<XMLName>> &fissionGenre = {},
      const wrapper<XMLName> &label = {},
      const wrapper<std::optional<transport::DoubleDifferentialCrossSection>> &doubleDifferentialCrossSection = {},
      const wrapper<transport::CrossSection> &crossSection = {},
      const wrapper<transport::OutputChannel> &outputChannel = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      ENDF_MT(this,ENDF_MT),
      fissionGenre(this,fissionGenre),
      label(this,label),
      doubleDifferentialCrossSection(this,doubleDifferentialCrossSection),
      crossSection(this,crossSection),
      outputChannel(this,outputChannel)
   {
      Component::finish();
   }

   // from node
   explicit Reaction(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Reaction(const Reaction &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Reaction(Reaction &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Reaction &operator=(const Reaction &) = default;
   Reaction &operator=(Reaction &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/transport/Reaction/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Reaction

} // namespace transport
} // namespace v2_0
} // namespace try

#endif
