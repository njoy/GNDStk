
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_MIXED
#define ALPHA_V2_0_GENERAL_MIXED

#include "alpha/v2.0/general/CovarianceMatrix.hpp"
#include "alpha/v2.0/general/Sum.hpp"
#include "alpha/v2.0/general/ShortRangeSelfScalingVariance.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Mixed
// -----------------------------------------------------------------------------

class Mixed :
   public Component<general::Mixed>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Mixed"; }
   static auto NODENAME() { return "mixed"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("label") |

         // children
         ++Child<general::CovarianceMatrix>
            ("covarianceMatrix") |
         ++Child<std::optional<general::Sum>>
            ("sum") |
         --Child<std::optional<general::ShortRangeSelfScalingVariance>>
            ("shortRangeSelfScalingVariance")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "covarianceMatrix",
         "sum",
         "shortRangeSelfScalingVariance"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "covariance_matrix",
         "sum",
         "short_range_self_scaling_variance"
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
      label{this};

   // children
   Field<std::vector<general::CovarianceMatrix>>
      covarianceMatrix{this};
   Field<std::optional<std::vector<general::Sum>>>
      sum{this};
   Field<std::optional<general::ShortRangeSelfScalingVariance>>
      shortRangeSelfScalingVariance{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->covarianceMatrix, \
      this->sum, \
      this->shortRangeSelfScalingVariance \
   )

   // default
   Mixed() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Mixed(
      const wrapper<std::string>
         &label,
      const wrapper<std::vector<general::CovarianceMatrix>>
         &covarianceMatrix = {},
      const wrapper<std::optional<std::vector<general::Sum>>>
         &sum = {},
      const wrapper<std::optional<general::ShortRangeSelfScalingVariance>>
         &shortRangeSelfScalingVariance = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      covarianceMatrix(this,covarianceMatrix),
      sum(this,sum),
      shortRangeSelfScalingVariance(this,shortRangeSelfScalingVariance)
   {
      Component::finish();
   }

   // from node
   explicit Mixed(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Mixed(const Mixed &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      covarianceMatrix(this,other.covarianceMatrix),
      sum(this,other.sum),
      shortRangeSelfScalingVariance(this,other.shortRangeSelfScalingVariance)
   {
      Component::finish(other);
   }

   // move
   Mixed(Mixed &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      covarianceMatrix(this,std::move(other.covarianceMatrix)),
      sum(this,std::move(other.sum)),
      shortRangeSelfScalingVariance(this,std::move(other.shortRangeSelfScalingVariance))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Mixed &operator=(const Mixed &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         covarianceMatrix = other.covarianceMatrix;
         sum = other.sum;
         shortRangeSelfScalingVariance = other.shortRangeSelfScalingVariance;
      }
      return *this;
   }

   // move
   Mixed &operator=(Mixed &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         covarianceMatrix = std::move(other.covarianceMatrix);
         sum = std::move(other.sum);
         shortRangeSelfScalingVariance = std::move(other.shortRangeSelfScalingVariance);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/Mixed/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Mixed

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
