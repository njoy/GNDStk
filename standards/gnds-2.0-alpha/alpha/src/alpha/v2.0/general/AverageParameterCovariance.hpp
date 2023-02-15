
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_AVERAGEPARAMETERCOVARIANCE
#define ALPHA_V2_0_GENERAL_AVERAGEPARAMETERCOVARIANCE

#include "alpha/v2.0/general/CovarianceMatrix.hpp"
#include "alpha/v2.0/general/RowData.hpp"
#include "alpha/v2.0/general/ColumnData.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class AverageParameterCovariance
// -----------------------------------------------------------------------------

class AverageParameterCovariance :
   public Component<general::AverageParameterCovariance>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "AverageParameterCovariance"; }
   static auto FIELD() { return "averageParameterCovariance"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("label") |
         std::optional<bool>{}
            / Meta<>("crossTerm") |

         // children
         --Child<general::CovarianceMatrix>
            ("covarianceMatrix") |
         --Child<general::RowData>
            ("rowData") |
         --Child<std::optional<general::ColumnData>>
            ("columnData")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "crossTerm",
         "covarianceMatrix",
         "rowData",
         "columnData"
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
   Field<std::optional<bool>>
      crossTerm{this};

   // children
   Field<general::CovarianceMatrix>
      covarianceMatrix{this};
   Field<general::RowData>
      rowData{this};
   Field<std::optional<general::ColumnData>>
      columnData{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->crossTerm, \
      this->covarianceMatrix, \
      this->rowData, \
      this->columnData \
   )

   // default
   AverageParameterCovariance() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit AverageParameterCovariance(
      const wrapper<std::string>
         &label,
      const wrapper<std::optional<bool>>
         &crossTerm = {},
      const wrapper<general::CovarianceMatrix>
         &covarianceMatrix = {},
      const wrapper<general::RowData>
         &rowData = {},
      const wrapper<std::optional<general::ColumnData>>
         &columnData = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      crossTerm(this,crossTerm),
      covarianceMatrix(this,covarianceMatrix),
      rowData(this,rowData),
      columnData(this,columnData)
   {
      Component::finish();
   }

   // from node
   explicit AverageParameterCovariance(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   AverageParameterCovariance(const AverageParameterCovariance &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      crossTerm(this,other.crossTerm),
      covarianceMatrix(this,other.covarianceMatrix),
      rowData(this,other.rowData),
      columnData(this,other.columnData)
   {
      Component::finish(other);
   }

   // move
   AverageParameterCovariance(AverageParameterCovariance &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      crossTerm(this,std::move(other.crossTerm)),
      covarianceMatrix(this,std::move(other.covarianceMatrix)),
      rowData(this,std::move(other.rowData)),
      columnData(this,std::move(other.columnData))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   AverageParameterCovariance &operator=(const AverageParameterCovariance &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         crossTerm = other.crossTerm;
         covarianceMatrix = other.covarianceMatrix;
         rowData = other.rowData;
         columnData = other.columnData;
      }
      return *this;
   }

   // move
   AverageParameterCovariance &operator=(AverageParameterCovariance &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         crossTerm = std::move(other.crossTerm);
         covarianceMatrix = std::move(other.covarianceMatrix);
         rowData = std::move(other.rowData);
         columnData = std::move(other.columnData);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/AverageParameterCovariance/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class AverageParameterCovariance

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
