
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_COVARIANCE_COVARIANCESUITE
#define TEST_V2_0_COVARIANCE_COVARIANCESUITE

#include "test/v2.0/common/ExternalFiles.hpp"
#include "test/v2.0/styles/Styles.hpp"
#include "test/v2.0/covariance/CovarianceSections.hpp"
#include "test/v2.0/covariance/ParameterCovariances.hpp"

namespace test {
namespace v2_0 {
namespace covariance {

// -----------------------------------------------------------------------------
// covariance::
// class CovarianceSuite
// -----------------------------------------------------------------------------

class CovarianceSuite : public Component<covariance::CovarianceSuite> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "covariance"; }
   static auto CLASS() { return "CovarianceSuite"; }
   static auto FIELD() { return "covarianceSuite"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::optional<XMLName>{}
            / Meta<>("evaluation") |
         std::optional<XMLName>{}
            / Meta<>("projectile") |
         std::optional<XMLName>{}
            / Meta<>("target") |
         enums::Interaction{}
            / Meta<>("interaction") |
         std::optional<Float64>{}
            / Meta<>("version") |
         // children
         --Child<std::optional<common::ExternalFiles>>("externalFiles") |
         --Child<std::optional<styles::Styles>>("styles") |
         --Child<std::optional<covariance::CovarianceSections>>("covarianceSections") |
         --Child<std::optional<covariance::ParameterCovariances>>("parameterCovariances")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::optional<XMLName>> evaluation{this};
   Field<std::optional<XMLName>> projectile{this};
   Field<std::optional<XMLName>> target{this};
   Field<enums::Interaction> interaction{this};
   Field<std::optional<Float64>> version{this};

   // children
   Field<std::optional<common::ExternalFiles>> externalFiles{this};
   Field<std::optional<styles::Styles>> styles{this};
   Field<std::optional<covariance::CovarianceSections>> covarianceSections{this};
   Field<std::optional<covariance::ParameterCovariances>> parameterCovariances{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->evaluation, \
      this->projectile, \
      this->target, \
      this->interaction, \
      this->version, \
      this->externalFiles, \
      this->styles, \
      this->covarianceSections, \
      this->parameterCovariances)

   // default
   CovarianceSuite() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields
   explicit CovarianceSuite(
      const wrapper<std::optional<XMLName>> &evaluation,
      const wrapper<std::optional<XMLName>> &projectile = {},
      const wrapper<std::optional<XMLName>> &target = {},
      const wrapper<enums::Interaction> &interaction = {},
      const wrapper<std::optional<Float64>> &version = {},
      const wrapper<std::optional<common::ExternalFiles>> &externalFiles = {},
      const wrapper<std::optional<styles::Styles>> &styles = {},
      const wrapper<std::optional<covariance::CovarianceSections>> &covarianceSections = {},
      const wrapper<std::optional<covariance::ParameterCovariances>> &parameterCovariances = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      evaluation(this,evaluation),
      projectile(this,projectile),
      target(this,target),
      interaction(this,interaction),
      version(this,version),
      externalFiles(this,externalFiles),
      styles(this,styles),
      covarianceSections(this,covarianceSections),
      parameterCovariances(this,parameterCovariances)
   {
      Component::finish();
   }

   // from node
   explicit CovarianceSuite(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   CovarianceSuite(const CovarianceSuite &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      evaluation(this,other.evaluation),
      projectile(this,other.projectile),
      target(this,other.target),
      interaction(this,other.interaction),
      version(this,other.version),
      externalFiles(this,other.externalFiles),
      styles(this,other.styles),
      covarianceSections(this,other.covarianceSections),
      parameterCovariances(this,other.parameterCovariances)
   {
      Component::finish(other);
   }

   // move
   CovarianceSuite(CovarianceSuite &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      evaluation(this,std::move(other.evaluation)),
      projectile(this,std::move(other.projectile)),
      target(this,std::move(other.target)),
      interaction(this,std::move(other.interaction)),
      version(this,std::move(other.version)),
      externalFiles(this,std::move(other.externalFiles)),
      styles(this,std::move(other.styles)),
      covarianceSections(this,std::move(other.covarianceSections)),
      parameterCovariances(this,std::move(other.parameterCovariances))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   CovarianceSuite &operator=(const CovarianceSuite &) = default;
   CovarianceSuite &operator=(CovarianceSuite &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/covariance/CovarianceSuite/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class CovarianceSuite

} // namespace covariance
} // namespace v2_0
} // namespace test

#endif
