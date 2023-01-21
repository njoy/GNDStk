
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_COVARIANCE_PARAMETERCOVARIANCE
#define TEST_V2_0_COVARIANCE_PARAMETERCOVARIANCE

#include "test/v2.0/covariance/RowData.hpp"
#include "test/v2.0/covariance/ParameterCovarianceMatrix.hpp"

namespace test {
namespace v2_0 {
namespace covariance {

// -----------------------------------------------------------------------------
// covariance::
// class ParameterCovariance
// -----------------------------------------------------------------------------

class ParameterCovariance :
   public Component<covariance::ParameterCovariance>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "covariance"; }
   static auto CLASS() { return "ParameterCovariance"; }
   static auto FIELD() { return "parameterCovariance"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::optional<XMLName>{}
            / Meta<>("label") |

         // children
         --Child<covariance::RowData>("rowData") |
         ++Child<covariance::ParameterCovarianceMatrix>("parameterCovarianceMatrix")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::optional<XMLName>> label{this};

   // children
   Field<covariance::RowData> rowData{this};
   Field<std::vector<covariance::ParameterCovarianceMatrix>> parameterCovarianceMatrix{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->label, \
      this->rowData, \
      this->parameterCovarianceMatrix)

   // default
   ParameterCovariance() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ParameterCovariance(
      const wrapper<std::optional<XMLName>> &label,
      const wrapper<covariance::RowData> &rowData = {},
      const wrapper<std::vector<covariance::ParameterCovarianceMatrix>> &parameterCovarianceMatrix = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      rowData(this,rowData),
      parameterCovarianceMatrix(this,parameterCovarianceMatrix)
   {
      Component::finish();
   }

   // from node
   explicit ParameterCovariance(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ParameterCovariance(const ParameterCovariance &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      rowData(this,other.rowData),
      parameterCovarianceMatrix(this,other.parameterCovarianceMatrix)
   {
      Component::finish(other);
   }

   // move
   ParameterCovariance(ParameterCovariance &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      rowData(this,std::move(other.rowData)),
      parameterCovarianceMatrix(this,std::move(other.parameterCovarianceMatrix))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   ParameterCovariance &operator=(const ParameterCovariance &) = default;
   ParameterCovariance &operator=(ParameterCovariance &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/covariance/ParameterCovariance/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ParameterCovariance

} // namespace covariance
} // namespace v2_0
} // namespace test

#endif
