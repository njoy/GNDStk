
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_COVARIANCE_MIXED
#define NJOY_GNDSTK_V2_0_COVARIANCE_MIXED

// core interface
#include "GNDStk.hpp"

// v2.0 dependencies
#include "GNDStk/v2.0/covariance/CovarianceMatrix.hpp"
#include "GNDStk/v2.0/covariance/ShortRangeSelfScalingVariance.hpp"
#include "GNDStk/v2.0/covariance/Sum.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// covariance::
// class Mixed
// -----------------------------------------------------------------------------

namespace covariance {

class Mixed : public Component<Mixed> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "covariance"; }
   static auto className() { return "Mixed"; }
   static auto GNDSName() { return "mixed"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("label") |
         // children
         std::optional<covariance::CovarianceMatrix>{}
            / ++Child<>("covarianceMatrix") |
         std::optional<covariance::ShortRangeSelfScalingVariance>{}
            / ++Child<>("shortRangeSelfScalingVariance") |
         std::optional<covariance::Sum>{}
            / ++Child<>("sum")
      ;
   }

public:

   using Component::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static inline const struct Defaults {
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      XMLName label;
      // children
      std::optional<std::vector<covariance::CovarianceMatrix>> covarianceMatrix;
      std::optional<std::vector<covariance::ShortRangeSelfScalingVariance>> shortRangeSelfScalingVariance;
      std::optional<std::vector<covariance::Sum>> sum;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // label
   const XMLName &label() const
      { return content.label; }
   XMLName &label()
      { return content.label; }

   // covarianceMatrix
   const std::optional<std::vector<covariance::CovarianceMatrix>> &covarianceMatrix() const
      { return content.covarianceMatrix; }
   std::optional<std::vector<covariance::CovarianceMatrix>> &covarianceMatrix()
      { return content.covarianceMatrix; }

   // covarianceMatrix(index)
   const covariance::CovarianceMatrix &covarianceMatrix(const std::size_t index) const
      { return getter(covarianceMatrix(), index, "covarianceMatrix"); }
   covariance::CovarianceMatrix &covarianceMatrix(const std::size_t index)
      { return getter(covarianceMatrix(), index, "covarianceMatrix"); }

   // covarianceMatrix(label)
   const covariance::CovarianceMatrix &covarianceMatrix(const std::string &label) const
      { return getter(covarianceMatrix(), label, "covarianceMatrix"); }
   covariance::CovarianceMatrix &covarianceMatrix(const std::string &label)
      { return getter(covarianceMatrix(), label, "covarianceMatrix"); }

   // shortRangeSelfScalingVariance
   const std::optional<std::vector<covariance::ShortRangeSelfScalingVariance>> &shortRangeSelfScalingVariance() const
      { return content.shortRangeSelfScalingVariance; }
   std::optional<std::vector<covariance::ShortRangeSelfScalingVariance>> &shortRangeSelfScalingVariance()
      { return content.shortRangeSelfScalingVariance; }

   // shortRangeSelfScalingVariance(index)
   const covariance::ShortRangeSelfScalingVariance &shortRangeSelfScalingVariance(const std::size_t index) const
      { return getter(shortRangeSelfScalingVariance(), index, "shortRangeSelfScalingVariance"); }
   covariance::ShortRangeSelfScalingVariance &shortRangeSelfScalingVariance(const std::size_t index)
      { return getter(shortRangeSelfScalingVariance(), index, "shortRangeSelfScalingVariance"); }

   // shortRangeSelfScalingVariance(label)
   const covariance::ShortRangeSelfScalingVariance &shortRangeSelfScalingVariance(const std::string &label) const
      { return getter(shortRangeSelfScalingVariance(), label, "shortRangeSelfScalingVariance"); }
   covariance::ShortRangeSelfScalingVariance &shortRangeSelfScalingVariance(const std::string &label)
      { return getter(shortRangeSelfScalingVariance(), label, "shortRangeSelfScalingVariance"); }

   // sum
   const std::optional<std::vector<covariance::Sum>> &sum() const
      { return content.sum; }
   std::optional<std::vector<covariance::Sum>> &sum()
      { return content.sum; }

   // sum(index)
   const covariance::Sum &sum(const std::size_t index) const
      { return getter(sum(), index, "sum"); }
   covariance::Sum &sum(const std::size_t index)
      { return getter(sum(), index, "sum"); }

   // sum(label)
   const covariance::Sum &sum(const std::string &label) const
      { return getter(sum(), label, "sum"); }
   covariance::Sum &sum(const std::string &label)
      { return getter(sum(), label, "sum"); }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // label(value)
   Mixed &label(const XMLName &obj)
      { label() = obj; return *this; }

   // covarianceMatrix(value)
   Mixed &covarianceMatrix(const std::optional<std::vector<covariance::CovarianceMatrix>> &obj)
      { covarianceMatrix() = obj; return *this; }

   // covarianceMatrix(index,value)
   Mixed &covarianceMatrix(
      const std::size_t index,
      const covariance::CovarianceMatrix &obj
   ) {
      covarianceMatrix(index) = obj; return *this;
   }

   // covarianceMatrix(label,value)
   Mixed &covarianceMatrix(
      const std::string &label,
      const covariance::CovarianceMatrix &obj
   ) {
      covarianceMatrix(label) = obj; return *this;
   }

   // shortRangeSelfScalingVariance(value)
   Mixed &shortRangeSelfScalingVariance(const std::optional<std::vector<covariance::ShortRangeSelfScalingVariance>> &obj)
      { shortRangeSelfScalingVariance() = obj; return *this; }

   // shortRangeSelfScalingVariance(index,value)
   Mixed &shortRangeSelfScalingVariance(
      const std::size_t index,
      const covariance::ShortRangeSelfScalingVariance &obj
   ) {
      shortRangeSelfScalingVariance(index) = obj; return *this;
   }

   // shortRangeSelfScalingVariance(label,value)
   Mixed &shortRangeSelfScalingVariance(
      const std::string &label,
      const covariance::ShortRangeSelfScalingVariance &obj
   ) {
      shortRangeSelfScalingVariance(label) = obj; return *this;
   }

   // sum(value)
   Mixed &sum(const std::optional<std::vector<covariance::Sum>> &obj)
      { sum() = obj; return *this; }

   // sum(index,value)
   Mixed &sum(
      const std::size_t index,
      const covariance::Sum &obj
   ) {
      sum(index) = obj; return *this;
   }

   // sum(label,value)
   Mixed &sum(
      const std::string &label,
      const covariance::Sum &obj
   ) {
      sum(label) = obj; return *this;
   }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Mixed() :
      Component{
         BodyText{},
         content.label,
         content.covarianceMatrix,
         content.shortRangeSelfScalingVariance,
         content.sum
      }
   {
      Component::finish();
   }

   // copy
   Mixed(const Mixed &other) :
      Component{
         other,
         content.label,
         content.covarianceMatrix,
         content.shortRangeSelfScalingVariance,
         content.sum
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Mixed(Mixed &&other) :
      Component{
         other,
         content.label,
         content.covarianceMatrix,
         content.shortRangeSelfScalingVariance,
         content.sum
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Mixed(const Node &node) :
      Component{
         BodyText{},
         content.label,
         content.covarianceMatrix,
         content.shortRangeSelfScalingVariance,
         content.sum
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Mixed(
      const XMLName &label,
      const std::optional<std::vector<covariance::CovarianceMatrix>> &covarianceMatrix,
      const std::optional<std::vector<covariance::ShortRangeSelfScalingVariance>> &shortRangeSelfScalingVariance,
      const std::optional<std::vector<covariance::Sum>> &sum
   ) :
      Component{
         BodyText{},
         content.label,
         content.covarianceMatrix,
         content.shortRangeSelfScalingVariance,
         content.sum
      },
      content{
         label,
         covarianceMatrix,
         shortRangeSelfScalingVariance,
         sum
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Mixed &operator=(const Mixed &) = default;

   // move
   Mixed &operator=(Mixed &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/covariance/Mixed/src/custom.hpp"

}; // class Mixed

} // namespace covariance
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif
