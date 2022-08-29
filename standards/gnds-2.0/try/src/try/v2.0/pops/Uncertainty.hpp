
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_POPS_UNCERTAINTY
#define TRY_V2_0_POPS_UNCERTAINTY

#include "try/v2.0/pops/Standard.hpp"
#include "try/v2.0/pops/LogNormal.hpp"
#include "try/v2.0/pops/ConfidenceIntervals.hpp"
#include "try/v2.0/pops/Pdf.hpp"

namespace try {
namespace v2_0 {
namespace pops {

// -----------------------------------------------------------------------------
// pops::
// class Uncertainty
// -----------------------------------------------------------------------------

class Uncertainty : public Component<pops::Uncertainty> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "pops"; }
   static auto CLASS() { return "Uncertainty"; }
   static auto FIELD() { return "uncertainty"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         std::optional<pops::Standard>{}
            / --Child<>("standard") |
         std::optional<pops::LogNormal>{}
            / --Child<>("logNormal") |
         std::optional<pops::ConfidenceIntervals>{}
            / --Child<>("confidenceIntervals") |
         std::optional<pops::Pdf>{}
            / --Child<>("pdf")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::optional<pops::Standard>> standard{this};
   Field<std::optional<pops::LogNormal>> logNormal{this};
   Field<std::optional<pops::ConfidenceIntervals>> confidenceIntervals{this};
   Field<std::optional<pops::Pdf>> pdf{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->standard, \
      this->logNormal, \
      this->confidenceIntervals, \
      this->pdf)

   // default, and from fields
   explicit Uncertainty(
      const wrapper<std::optional<pops::Standard>> &standard = {},
      const wrapper<std::optional<pops::LogNormal>> &logNormal = {},
      const wrapper<std::optional<pops::ConfidenceIntervals>> &confidenceIntervals = {},
      const wrapper<std::optional<pops::Pdf>> &pdf = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      standard(this,standard),
      logNormal(this,logNormal),
      confidenceIntervals(this,confidenceIntervals),
      pdf(this,pdf)
   {
      Component::finish();
   }

   // from node
   explicit Uncertainty(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Uncertainty(const Uncertainty &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Uncertainty(Uncertainty &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Uncertainty &operator=(const Uncertainty &) = default;
   Uncertainty &operator=(Uncertainty &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/pops/Uncertainty/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Uncertainty

} // namespace pops
} // namespace v2_0
} // namespace try

#endif
