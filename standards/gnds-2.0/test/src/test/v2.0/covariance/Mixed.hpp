
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_COVARIANCE_MIXED
#define TEST_V2_0_COVARIANCE_MIXED

#include "test/v2.0/covariance/CovarianceMatrix.hpp"
#include "test/v2.0/covariance/ShortRangeSelfScalingVariance.hpp"
#include "test/v2.0/covariance/Sum.hpp"

namespace test {
namespace v2_0 {
namespace covariance {

// -----------------------------------------------------------------------------
// covariance::
// class Mixed
// -----------------------------------------------------------------------------

class Mixed :
   public Component<covariance::Mixed>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "covariance"; }
   static auto CLASS() { return "Mixed"; }
   static auto FIELD() { return "mixed"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         XMLName{}
            / Meta<>("label") |

         // children
         ++Child<std::optional<covariance::CovarianceMatrix>>("covarianceMatrix") |
         ++Child<std::optional<covariance::ShortRangeSelfScalingVariance>>("shortRangeSelfScalingVariance") |
         ++Child<std::optional<covariance::Sum>>("sum")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<XMLName> label{this};

   // children
   Field<std::optional<std::vector<covariance::CovarianceMatrix>>> covarianceMatrix{this};
   Field<std::optional<std::vector<covariance::ShortRangeSelfScalingVariance>>> shortRangeSelfScalingVariance{this};
   Field<std::optional<std::vector<covariance::Sum>>> sum{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->label, \
      this->covarianceMatrix, \
      this->shortRangeSelfScalingVariance, \
      this->sum)

   // default
   Mixed() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Mixed(
      const wrapper<XMLName> &label,
      const wrapper<std::optional<std::vector<covariance::CovarianceMatrix>>> &covarianceMatrix = {},
      const wrapper<std::optional<std::vector<covariance::ShortRangeSelfScalingVariance>>> &shortRangeSelfScalingVariance = {},
      const wrapper<std::optional<std::vector<covariance::Sum>>> &sum = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      covarianceMatrix(this,covarianceMatrix),
      shortRangeSelfScalingVariance(this,shortRangeSelfScalingVariance),
      sum(this,sum)
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
      shortRangeSelfScalingVariance(this,other.shortRangeSelfScalingVariance),
      sum(this,other.sum)
   {
      Component::finish(other);
   }

   // move
   Mixed(Mixed &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      covarianceMatrix(this,std::move(other.covarianceMatrix)),
      shortRangeSelfScalingVariance(this,std::move(other.shortRangeSelfScalingVariance)),
      sum(this,std::move(other.sum))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Mixed &operator=(const Mixed &) = default;
   Mixed &operator=(Mixed &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/covariance/Mixed/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Mixed

} // namespace covariance
} // namespace v2_0
} // namespace test

#endif
