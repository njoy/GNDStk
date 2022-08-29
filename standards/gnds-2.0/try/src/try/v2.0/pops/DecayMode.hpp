
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_POPS_DECAYMODE
#define TRY_V2_0_POPS_DECAYMODE

#include "try/v2.0/pops/Probability.hpp"
#include "try/v2.0/pops/InternalConversionCoefficients.hpp"
#include "try/v2.0/pops/PhotonEmissionProbabilities.hpp"
#include "try/v2.0/pops/Q.hpp"
#include "try/v2.0/pops/DecayPath.hpp"
#include "try/v2.0/pops/Spectra.hpp"

namespace try {
namespace v2_0 {
namespace pops {

// -----------------------------------------------------------------------------
// pops::
// class DecayMode
// -----------------------------------------------------------------------------

class DecayMode : public Component<pops::DecayMode> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "pops"; }
   static auto CLASS() { return "DecayMode"; }
   static auto FIELD() { return "decayMode"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("label") |
         enums::DecayType{}
            / Meta<>("mode") |
         // children
         pops::Probability{}
            / --Child<>("probability") |
         std::optional<pops::InternalConversionCoefficients>{}
            / --Child<>("internalConversionCoefficients") |
         std::optional<pops::PhotonEmissionProbabilities>{}
            / --Child<>("photonEmissionProbabilities") |
         std::optional<pops::Q>{}
            / --Child<>("Q") |
         std::optional<pops::DecayPath>{}
            / --Child<>("decayPath") |
         std::optional<pops::Spectra>{}
            / --Child<>("spectra")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<XMLName> label{this};
   Field<enums::DecayType> mode{this};

   // children
   Field<pops::Probability> probability{this};
   Field<std::optional<pops::InternalConversionCoefficients>> internalConversionCoefficients{this};
   Field<std::optional<pops::PhotonEmissionProbabilities>> photonEmissionProbabilities{this};
   Field<std::optional<pops::Q>> Q{this};
   Field<std::optional<pops::DecayPath>> decayPath{this};
   Field<std::optional<pops::Spectra>> spectra{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->mode, \
      this->probability, \
      this->internalConversionCoefficients, \
      this->photonEmissionProbabilities, \
      this->Q, \
      this->decayPath, \
      this->spectra)

   // default, and from fields
   explicit DecayMode(
      const wrapper<XMLName> &label = {},
      const wrapper<enums::DecayType> &mode = {},
      const wrapper<pops::Probability> &probability = {},
      const wrapper<std::optional<pops::InternalConversionCoefficients>> &internalConversionCoefficients = {},
      const wrapper<std::optional<pops::PhotonEmissionProbabilities>> &photonEmissionProbabilities = {},
      const wrapper<std::optional<pops::Q>> &Q = {},
      const wrapper<std::optional<pops::DecayPath>> &decayPath = {},
      const wrapper<std::optional<pops::Spectra>> &spectra = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      mode(this,mode),
      probability(this,probability),
      internalConversionCoefficients(this,internalConversionCoefficients),
      photonEmissionProbabilities(this,photonEmissionProbabilities),
      Q(this,Q),
      decayPath(this,decayPath),
      spectra(this,spectra)
   {
      Component::finish();
   }

   // from node
   explicit DecayMode(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   DecayMode(const DecayMode &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   DecayMode(DecayMode &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   DecayMode &operator=(const DecayMode &) = default;
   DecayMode &operator=(DecayMode &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/pops/DecayMode/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class DecayMode

} // namespace pops
} // namespace v2_0
} // namespace try

#endif
