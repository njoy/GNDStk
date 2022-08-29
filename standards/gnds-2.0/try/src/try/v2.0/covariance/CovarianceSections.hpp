
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_COVARIANCE_COVARIANCESECTIONS
#define TRY_V2_0_COVARIANCE_COVARIANCESECTIONS

#include "try/v2.0/covariance/CovarianceSection.hpp"

namespace try {
namespace v2_0 {
namespace covariance {

// -----------------------------------------------------------------------------
// covariance::
// class CovarianceSections
// -----------------------------------------------------------------------------

class CovarianceSections : public Component<covariance::CovarianceSections> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "covariance"; }
   static auto CLASS() { return "CovarianceSections"; }
   static auto FIELD() { return "covarianceSections"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         std::optional<covariance::CovarianceSection>{}
            / ++Child<>("covarianceSection")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::optional<std::vector<covariance::CovarianceSection>>> covarianceSection{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->covarianceSection)

   // default, and from fields
   explicit CovarianceSections(
      const wrapper<std::optional<std::vector<covariance::CovarianceSection>>> &covarianceSection = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      covarianceSection(this,covarianceSection)
   {
      Component::finish();
   }

   // from node
   explicit CovarianceSections(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   CovarianceSections(const CovarianceSections &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   CovarianceSections(CovarianceSections &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   CovarianceSections &operator=(const CovarianceSections &) = default;
   CovarianceSections &operator=(CovarianceSections &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/covariance/CovarianceSections/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class CovarianceSections

} // namespace covariance
} // namespace v2_0
} // namespace try

#endif
