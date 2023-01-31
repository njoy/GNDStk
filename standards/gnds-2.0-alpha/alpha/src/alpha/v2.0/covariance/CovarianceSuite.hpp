
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_COVARIANCE_COVARIANCESUITE
#define ALPHA_V2_0_COVARIANCE_COVARIANCESUITE

#include "alpha/v2.0/common/ExternalFiles.hpp"
#include "alpha/v2.0/common/Styles.hpp"
#include "alpha/v2.0/covariance/CovarianceSections.hpp"
#include "alpha/v2.0/covariance/ParameterCovariances.hpp"

namespace alpha {
namespace v2_0 {
namespace covariance {

// -----------------------------------------------------------------------------
// covariance::
// class CovarianceSuite
// -----------------------------------------------------------------------------

class CovarianceSuite :
   public Component<covariance::CovarianceSuite>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "covariance"; }
   static auto CLASS() { return "CovarianceSuite"; }
   static auto FIELD() { return "covarianceSuite"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("projectile") |
         std::string{}
            / Meta<>("target") |
         std::string{}
            / Meta<>("evaluation") |
         std::string{}
            / Meta<>("interaction") |
         std::string{}
            / Meta<>("format") |

         // children
         --Child<std::optional<common::ExternalFiles>>("externalFiles") |
         --Child<common::Styles>("styles") |
         --Child<std::optional<covariance::CovarianceSections>>("covarianceSections") |
         --Child<std::optional<covariance::ParameterCovariances>>("parameterCovariances")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string> projectile{this};
   Field<std::string> target{this};
   Field<std::string> evaluation{this};
   Field<std::string> interaction{this};
   Field<std::string> format{this};

   // children
   Field<std::optional<common::ExternalFiles>> externalFiles{this};
   Field<common::Styles> styles{this};
   Field<std::optional<covariance::CovarianceSections>> covarianceSections{this};
   Field<std::optional<covariance::ParameterCovariances>> parameterCovariances{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->projectile, \
      this->target, \
      this->evaluation, \
      this->interaction, \
      this->format, \
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

   // from fields, comment excluded
   explicit CovarianceSuite(
      const wrapper<std::string> &projectile,
      const wrapper<std::string> &target = {},
      const wrapper<std::string> &evaluation = {},
      const wrapper<std::string> &interaction = {},
      const wrapper<std::string> &format = {},
      const wrapper<std::optional<common::ExternalFiles>> &externalFiles = {},
      const wrapper<common::Styles> &styles = {},
      const wrapper<std::optional<covariance::CovarianceSections>> &covarianceSections = {},
      const wrapper<std::optional<covariance::ParameterCovariances>> &parameterCovariances = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      projectile(this,projectile),
      target(this,target),
      evaluation(this,evaluation),
      interaction(this,interaction),
      format(this,format),
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
      comment(this,other.comment),
      projectile(this,other.projectile),
      target(this,other.target),
      evaluation(this,other.evaluation),
      interaction(this,other.interaction),
      format(this,other.format),
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
      comment(this,std::move(other.comment)),
      projectile(this,std::move(other.projectile)),
      target(this,std::move(other.target)),
      evaluation(this,std::move(other.evaluation)),
      interaction(this,std::move(other.interaction)),
      format(this,std::move(other.format)),
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

   #include "alpha/v2.0/covariance/CovarianceSuite/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class CovarianceSuite

} // namespace covariance
} // namespace v2_0
} // namespace alpha

#endif
