
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_TOP_COVARIANCESUITE
#define GNDS_V2_0_TOP_COVARIANCESUITE

#include "gnds/v2.0/general/ExternalFiles.hpp"
#include "gnds/v2.0/general/Styles.hpp"
#include "gnds/v2.0/general/CovarianceSections.hpp"
#include "gnds/v2.0/general/ParameterCovariances.hpp"

namespace gnds {
namespace v2_0 {
namespace top {

// -----------------------------------------------------------------------------
// top::
// class CovarianceSuite
// -----------------------------------------------------------------------------

class CovarianceSuite :
   public Component<top::CovarianceSuite>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "top"; }
   static auto CLASS() { return "CovarianceSuite"; }
   static auto NODENAME() { return "covarianceSuite"; }

   // Core Interface multi-query to transfer information to/from core Nodes
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
         --Child<std::optional<general::ExternalFiles>>
            ("externalFiles") |
         --Child<general::Styles>
            ("styles") |
         --Child<std::optional<general::CovarianceSections>>
            ("covarianceSections") |
         --Child<std::optional<general::ParameterCovariances>>
            ("parameterCovariances")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "projectile",
         "target",
         "evaluation",
         "interaction",
         "format",
         "externalFiles",
         "styles",
         "covarianceSections",
         "parameterCovariances"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "projectile",
         "target",
         "evaluation",
         "interaction",
         "format",
         "external_files",
         "styles",
         "covariance_sections",
         "parameter_covariances"
      };
      return names;
   }

   // ------------------------
   // Public interface
   // ------------------------

public:

   using component_t = Component;
   using Component::construct;

   // ------------------------
   // Data members
   // ------------------------

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string>
      projectile{this};
   Field<std::string>
      target{this};
   Field<std::string>
      evaluation{this};
   Field<std::string>
      interaction{this};
   Field<std::string>
      format{this};

   // children
   Field<std::optional<general::ExternalFiles>>
      externalFiles{this};
   Field<general::Styles>
      styles{this};
   Field<std::optional<general::CovarianceSections>>
      covarianceSections{this};
   Field<std::optional<general::ParameterCovariances>>
      parameterCovariances{this};

   // shortcuts
   #define NJOY_GNDSTK_SHORTCUT(to,name) decltype(to.name) &name = to.name
   NJOY_GNDSTK_SHORTCUT(styles(),crossSectionReconstructed);
   NJOY_GNDSTK_SHORTCUT(styles().evaluated(),documentation);
   NJOY_GNDSTK_SHORTCUT(styles(),evaluated);
   NJOY_GNDSTK_SHORTCUT(styles().evaluated(),projectileEnergyDomain);
   NJOY_GNDSTK_SHORTCUT(styles().evaluated(),temperature);
   #undef NJOY_GNDSTK_SHORTCUT

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->projectile, \
      this->target, \
      this->evaluation, \
      this->interaction, \
      this->format, \
      this->externalFiles, \
      this->styles, \
      this->covarianceSections, \
      this->parameterCovariances \
   )

   // default
   CovarianceSuite() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit CovarianceSuite(
      const wrapper<std::string>
         &projectile,
      const wrapper<std::string>
         &target = {},
      const wrapper<std::string>
         &evaluation = {},
      const wrapper<std::string>
         &interaction = {},
      const wrapper<std::string>
         &format = {},
      const wrapper<std::optional<general::ExternalFiles>>
         &externalFiles = {},
      const wrapper<general::Styles>
         &styles = {},
      const wrapper<std::optional<general::CovarianceSections>>
         &covarianceSections = {},
      const wrapper<std::optional<general::ParameterCovariances>>
         &parameterCovariances = {}
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
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
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   CovarianceSuite(const CovarianceSuite &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
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
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
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

   // copy
   CovarianceSuite &operator=(const CovarianceSuite &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         projectile = other.projectile;
         target = other.target;
         evaluation = other.evaluation;
         interaction = other.interaction;
         format = other.format;
         externalFiles = other.externalFiles;
         styles = other.styles;
         covarianceSections = other.covarianceSections;
         parameterCovariances = other.parameterCovariances;
      }
      return *this;
   }

   // move
   CovarianceSuite &operator=(CovarianceSuite &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         projectile = std::move(other.projectile);
         target = std::move(other.target);
         evaluation = std::move(other.evaluation);
         interaction = std::move(other.interaction);
         format = std::move(other.format);
         externalFiles = std::move(other.externalFiles);
         styles = std::move(other.styles);
         covarianceSections = std::move(other.covarianceSections);
         parameterCovariances = std::move(other.parameterCovariances);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "gnds/v2.0/top/CovarianceSuite/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class CovarianceSuite

} // namespace top
} // namespace v2_0
} // namespace gnds

#endif
