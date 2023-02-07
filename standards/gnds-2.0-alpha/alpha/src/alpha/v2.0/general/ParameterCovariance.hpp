
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_PARAMETERCOVARIANCE
#define ALPHA_V2_0_GENERAL_PARAMETERCOVARIANCE

#include "alpha/v2.0/general/RowData.hpp"
#include "alpha/v2.0/general/ParameterCovarianceMatrix.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class ParameterCovariance
// -----------------------------------------------------------------------------

class ParameterCovariance :
   public Component<general::ParameterCovariance>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "ParameterCovariance"; }
   static auto FIELD() { return "parameterCovariance"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("label") |

         // children
         --Child<general::RowData>
            ("rowData") |
         --Child<general::ParameterCovarianceMatrix>
            ("parameterCovarianceMatrix")
      ;
   }

public:
   using component_t = Component;
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string>
      label{this};

   // children
   Field<general::RowData>
      rowData{this};
   Field<general::ParameterCovarianceMatrix>
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
      const wrapper<std::string>
         &label,
      const wrapper<general::RowData>
         &rowData = {},
      const wrapper<general::ParameterCovarianceMatrix>
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

   #include "alpha/v2.0/general/ParameterCovariance/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ParameterCovariance

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
