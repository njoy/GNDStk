
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

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "covariance"; }
   static auto CLASS() { return "ParameterCovariance"; }
   static auto NODENAME() { return "parameterCovariance"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::optional<XMLName>{}
            / Meta<>("label") |

         // children
         --Child<covariance::RowData>
            ("rowData") |
         ++Child<covariance::ParameterCovarianceMatrix>
            ("parameterCovarianceMatrix")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "rowData",
         "parameterCovarianceMatrix"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "row_data",
         "parameter_covariance_matrix"
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
   Field<std::optional<XMLName>>
      label{this};

   // children
   Field<covariance::RowData>
      rowData{this};
   Field<std::vector<covariance::ParameterCovarianceMatrix>>
      parameterCovarianceMatrix{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->rowData, \
      this->parameterCovarianceMatrix \
   )

   // default
   ParameterCovariance() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ParameterCovariance(
      const wrapper<std::optional<XMLName>>
         &label,
      const wrapper<covariance::RowData>
         &rowData = {},
      const wrapper<std::vector<covariance::ParameterCovarianceMatrix>>
         &parameterCovarianceMatrix = {}
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

   // copy
   ParameterCovariance &operator=(const ParameterCovariance &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         rowData = other.rowData;
         parameterCovarianceMatrix = other.parameterCovarianceMatrix;
      }
      return *this;
   }

   // move
   ParameterCovariance &operator=(ParameterCovariance &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         rowData = std::move(other.rowData);
         parameterCovarianceMatrix = std::move(other.parameterCovarianceMatrix);
      }
      return *this;
   }

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
