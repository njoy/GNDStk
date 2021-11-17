
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_COVARIANCE_PARAMETERCOVARIANCE
#define NJOY_GNDSTK_V2_0_COVARIANCE_PARAMETERCOVARIANCE

// core interface
#include "GNDStk.hpp"

// v2.0 dependencies
#include "GNDStk/v2.0/unknownNamespace/ParameterCovarianceMatrix.hpp"
#include "GNDStk/v2.0/covariance/RowData.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// covariance::
// class ParameterCovariance
// -----------------------------------------------------------------------------

namespace covariance {

class ParameterCovariance : public Component<ParameterCovariance> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "covariance"; }
   static auto className() { return "ParameterCovariance"; }
   static auto GNDSName() { return "parameterCovariance"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         std::optional<XMLName>{}
            / Meta<>("label") |
         // children
         unknownNamespace::ParameterCovarianceMatrix{}
            / ++Child<>("parameterCovarianceMatrix") |
         covariance::RowData{}
            / --Child<>("rowData")
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
      std::optional<XMLName> label;
      // children
      std::vector<unknownNamespace::ParameterCovarianceMatrix> parameterCovarianceMatrix;
      covariance::RowData rowData;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // label
   const std::optional<XMLName> &label() const
      { return content.label; }
   std::optional<XMLName> &label()
      { return content.label; }

   // parameterCovarianceMatrix
   const std::vector<unknownNamespace::ParameterCovarianceMatrix> &parameterCovarianceMatrix() const
      { return content.parameterCovarianceMatrix; }
   std::vector<unknownNamespace::ParameterCovarianceMatrix> &parameterCovarianceMatrix()
      { return content.parameterCovarianceMatrix; }

   // parameterCovarianceMatrix(index)
   const unknownNamespace::ParameterCovarianceMatrix &parameterCovarianceMatrix(const std::size_t index) const
      { return getter(parameterCovarianceMatrix(), index, "parameterCovarianceMatrix"); }
   unknownNamespace::ParameterCovarianceMatrix &parameterCovarianceMatrix(const std::size_t index)
      { return getter(parameterCovarianceMatrix(), index, "parameterCovarianceMatrix"); }

   // parameterCovarianceMatrix(label)
   const unknownNamespace::ParameterCovarianceMatrix &parameterCovarianceMatrix(const std::string &label) const
      { return getter(parameterCovarianceMatrix(), label, "parameterCovarianceMatrix"); }
   unknownNamespace::ParameterCovarianceMatrix &parameterCovarianceMatrix(const std::string &label)
      { return getter(parameterCovarianceMatrix(), label, "parameterCovarianceMatrix"); }

   // rowData
   const covariance::RowData &rowData() const
      { return content.rowData; }
   covariance::RowData &rowData()
      { return content.rowData; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // label(value)
   ParameterCovariance &label(const std::optional<XMLName> &obj)
      { label() = obj; return *this; }

   // parameterCovarianceMatrix(value)
   ParameterCovariance &parameterCovarianceMatrix(const std::vector<unknownNamespace::ParameterCovarianceMatrix> &obj)
      { parameterCovarianceMatrix() = obj; return *this; }

   // parameterCovarianceMatrix(index,value)
   ParameterCovariance &parameterCovarianceMatrix(
      const std::size_t index,
      const unknownNamespace::ParameterCovarianceMatrix &obj
   ) {
      parameterCovarianceMatrix(index) = obj; return *this;
   }

   // parameterCovarianceMatrix(label,value)
   ParameterCovariance &parameterCovarianceMatrix(
      const std::string &label,
      const unknownNamespace::ParameterCovarianceMatrix &obj
   ) {
      parameterCovarianceMatrix(label) = obj; return *this;
   }

   // rowData(value)
   ParameterCovariance &rowData(const covariance::RowData &obj)
      { rowData() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   ParameterCovariance() :
      Component{
         BodyText{},
         content.label,
         content.parameterCovarianceMatrix,
         content.rowData
      }
   {
      Component::finish();
   }

   // copy
   ParameterCovariance(const ParameterCovariance &other) :
      Component{
         other,
         content.label,
         content.parameterCovarianceMatrix,
         content.rowData
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   ParameterCovariance(ParameterCovariance &&other) :
      Component{
         other,
         content.label,
         content.parameterCovarianceMatrix,
         content.rowData
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   ParameterCovariance(const Node &node) :
      Component{
         BodyText{},
         content.label,
         content.parameterCovarianceMatrix,
         content.rowData
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit ParameterCovariance(
      const std::optional<XMLName> &label,
      const std::vector<unknownNamespace::ParameterCovarianceMatrix> &parameterCovarianceMatrix,
      const covariance::RowData &rowData
   ) :
      Component{
         BodyText{},
         content.label,
         content.parameterCovarianceMatrix,
         content.rowData
      },
      content{
         label,
         parameterCovarianceMatrix,
         rowData
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   ParameterCovariance &operator=(const ParameterCovariance &) = default;

   // move
   ParameterCovariance &operator=(ParameterCovariance &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/covariance/ParameterCovariance/src/custom.hpp"

}; // class ParameterCovariance

} // namespace covariance
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif
