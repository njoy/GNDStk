
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_COVARIANCE_COVARIANCESECTION
#define TEST_V2_0_COVARIANCE_COVARIANCESECTION

#include "test/v2.0/covariance/RowData.hpp"
#include "test/v2.0/covariance/ColumnData.hpp"
#include "test/v2.0/covariance/CovarianceMatrix.hpp"
#include "test/v2.0/covariance/Sum.hpp"
#include "test/v2.0/covariance/Mixed.hpp"

namespace test {
namespace v2_0 {
namespace covariance {

// -----------------------------------------------------------------------------
// covariance::
// class CovarianceSection
// -----------------------------------------------------------------------------

class CovarianceSection : public Component<covariance::CovarianceSection> {
   friend class Component;

   using _t = std::variant<
      covariance::CovarianceMatrix,
      covariance::Sum,
      covariance::Mixed
   >;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "covariance"; }
   static auto CLASS() { return "CovarianceSection"; }
   static auto FIELD() { return "covarianceSection"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         Defaulted<bool>{false}
            / Meta<>("crossTerm") |
         std::optional<XMLName>{}
            / Meta<>("label") |
         // children
         --Child<covariance::RowData>("rowData") |
         --Child<std::optional<covariance::ColumnData>>("columnData") |
         _t{}
            / --(Child<>("covarianceMatrix") || Child<>("sum") || Child<>("mixed"))
      ;
   }

public:
   using Component::construct;

   // defaults
   static inline const struct Defaults {
      static inline const bool crossTerm = false;
   } defaults;

   // metadata
   Field<Defaulted<bool>> crossTerm{this,defaults.crossTerm};
   Field<std::optional<XMLName>> label{this};

   // children
   Field<covariance::RowData> rowData{this};
   Field<std::optional<covariance::ColumnData>> columnData{this};

   // children - variant
   Field<_t> _covarianceMatrixsummixed{this};
   FieldPart<decltype(_covarianceMatrixsummixed),covariance::CovarianceMatrix> covarianceMatrix{_covarianceMatrixsummixed};
   FieldPart<decltype(_covarianceMatrixsummixed),covariance::Sum> sum{_covarianceMatrixsummixed};
   FieldPart<decltype(_covarianceMatrixsummixed),covariance::Mixed> mixed{_covarianceMatrixsummixed};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->crossTerm, \
      this->label, \
      this->rowData, \
      this->columnData, \
      this->_covarianceMatrixsummixed)

   // default
   CovarianceSection() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields
   // std::optional replaces Defaulted; this class knows the default(s)
   explicit CovarianceSection(
      const wrapper<std::optional<bool>> &crossTerm,
      const wrapper<std::optional<XMLName>> &label = {},
      const wrapper<covariance::RowData> &rowData = {},
      const wrapper<std::optional<covariance::ColumnData>> &columnData = {},
      const wrapper<_t> &_covarianceMatrixsummixed = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      crossTerm(this,defaults.crossTerm,crossTerm),
      label(this,label),
      rowData(this,rowData),
      columnData(this,columnData),
      _covarianceMatrixsummixed(this,_covarianceMatrixsummixed)
   {
      Component::finish();
   }

   // from node
   explicit CovarianceSection(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   CovarianceSection(const CovarianceSection &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      crossTerm(this,other.crossTerm),
      label(this,other.label),
      rowData(this,other.rowData),
      columnData(this,other.columnData),
      _covarianceMatrixsummixed(this,other._covarianceMatrixsummixed)
   {
      Component::finish(other);
   }

   // move
   CovarianceSection(CovarianceSection &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      crossTerm(this,std::move(other.crossTerm)),
      label(this,std::move(other.label)),
      rowData(this,std::move(other.rowData)),
      columnData(this,std::move(other.columnData)),
      _covarianceMatrixsummixed(this,std::move(other._covarianceMatrixsummixed))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   CovarianceSection &operator=(const CovarianceSection &) = default;
   CovarianceSection &operator=(CovarianceSection &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/covariance/CovarianceSection/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class CovarianceSection

} // namespace covariance
} // namespace v2_0
} // namespace test

#endif
