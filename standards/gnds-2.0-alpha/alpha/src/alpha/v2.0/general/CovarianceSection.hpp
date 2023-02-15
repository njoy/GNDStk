
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_COVARIANCESECTION
#define ALPHA_V2_0_GENERAL_COVARIANCESECTION

#include "alpha/v2.0/general/RowData.hpp"
#include "alpha/v2.0/general/ColumnData.hpp"
#include "alpha/v2.0/general/CovarianceMatrix.hpp"
#include "alpha/v2.0/general/Mixed.hpp"
#include "alpha/v2.0/general/Sum.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class CovarianceSection
// -----------------------------------------------------------------------------

class CovarianceSection :
   public Component<general::CovarianceSection>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "CovarianceSection"; }
   static auto FIELD() { return "covarianceSection"; }

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
         --Child<general::RowData>
            ("rowData") |
         --Child<std::optional<general::ColumnData>>
            ("columnData") |
         --Child<std::optional<general::CovarianceMatrix>>
            ("covarianceMatrix") |
         --Child<std::optional<general::Mixed>>
            ("mixed") |
         --Child<std::optional<general::Sum>>
            ("sum")
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
         "rowData",
         "columnData",
         "covarianceMatrix",
         "mixed",
         "sum"
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
   Field<general::RowData>
      rowData{this};
   Field<std::optional<general::ColumnData>>
      columnData{this};
   Field<std::optional<general::CovarianceMatrix>>
      covarianceMatrix{this};
   Field<std::optional<general::Mixed>>
      mixed{this};
   Field<std::optional<general::Sum>>
      sum{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->crossTerm, \
      this->rowData, \
      this->columnData, \
      this->covarianceMatrix, \
      this->mixed, \
      this->sum \
   )

   // default
   CovarianceSection() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit CovarianceSection(
      const wrapper<std::string>
         &label,
      const wrapper<std::optional<bool>>
         &crossTerm = {},
      const wrapper<general::RowData>
         &rowData = {},
      const wrapper<std::optional<general::ColumnData>>
         &columnData = {},
      const wrapper<std::optional<general::CovarianceMatrix>>
         &covarianceMatrix = {},
      const wrapper<std::optional<general::Mixed>>
         &mixed = {},
      const wrapper<std::optional<general::Sum>>
         &sum = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      crossTerm(this,crossTerm),
      rowData(this,rowData),
      columnData(this,columnData),
      covarianceMatrix(this,covarianceMatrix),
      mixed(this,mixed),
      sum(this,sum)
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
      comment(this,other.comment),
      label(this,other.label),
      crossTerm(this,other.crossTerm),
      rowData(this,other.rowData),
      columnData(this,other.columnData),
      covarianceMatrix(this,other.covarianceMatrix),
      mixed(this,other.mixed),
      sum(this,other.sum)
   {
      Component::finish(other);
   }

   // move
   CovarianceSection(CovarianceSection &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      crossTerm(this,std::move(other.crossTerm)),
      rowData(this,std::move(other.rowData)),
      columnData(this,std::move(other.columnData)),
      covarianceMatrix(this,std::move(other.covarianceMatrix)),
      mixed(this,std::move(other.mixed)),
      sum(this,std::move(other.sum))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   CovarianceSection &operator=(const CovarianceSection &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         crossTerm = other.crossTerm;
         rowData = other.rowData;
         columnData = other.columnData;
         covarianceMatrix = other.covarianceMatrix;
         mixed = other.mixed;
         sum = other.sum;
      }
      return *this;
   }

   // move
   CovarianceSection &operator=(CovarianceSection &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         crossTerm = std::move(other.crossTerm);
         rowData = std::move(other.rowData);
         columnData = std::move(other.columnData);
         covarianceMatrix = std::move(other.covarianceMatrix);
         mixed = std::move(other.mixed);
         sum = std::move(other.sum);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/CovarianceSection/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class CovarianceSection

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
