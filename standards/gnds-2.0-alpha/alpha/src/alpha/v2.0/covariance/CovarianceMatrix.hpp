
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_COVARIANCE_COVARIANCEMATRIX
#define ALPHA_V2_0_COVARIANCE_COVARIANCEMATRIX

#include "alpha/v2.0/common/Gridded2d.hpp"

namespace alpha {
namespace v2_0 {
namespace covariance {

// -----------------------------------------------------------------------------
// covariance::
// class CovarianceMatrix
// -----------------------------------------------------------------------------

class CovarianceMatrix :
   public Component<covariance::CovarianceMatrix>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "covariance"; }
   static auto CLASS() { return "CovarianceMatrix"; }
   static auto FIELD() { return "covarianceMatrix"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("label") |
         std::string{}
            / Meta<>("type") |
         std::optional<std::string>{}
            / Meta<>("productFrame") |

         // children
         --Child<common::Gridded2d>
            ("gridded2d")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string> label{this};
   Field<std::string> type{this};
   Field<std::optional<std::string>> productFrame{this};

   // children
   Field<common::Gridded2d>
      gridded2d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->label, \
      this->type, \
      this->productFrame, \
      this->gridded2d)

   // default
   CovarianceMatrix() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit CovarianceMatrix(
      const wrapper<std::string>
         &label,
      const wrapper<std::string>
         &type = {},
      const wrapper<std::optional<std::string>>
         &productFrame = {},
      const wrapper<common::Gridded2d>
         &gridded2d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      type(this,type),
      productFrame(this,productFrame),
      gridded2d(this,gridded2d)
   {
      Component::finish();
   }

   // from node
   explicit CovarianceMatrix(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   CovarianceMatrix(const CovarianceMatrix &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      type(this,other.type),
      productFrame(this,other.productFrame),
      gridded2d(this,other.gridded2d)
   {
      Component::finish(other);
   }

   // move
   CovarianceMatrix(CovarianceMatrix &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      type(this,std::move(other.type)),
      productFrame(this,std::move(other.productFrame)),
      gridded2d(this,std::move(other.gridded2d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   CovarianceMatrix &operator=(const CovarianceMatrix &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         type = other.type;
         productFrame = other.productFrame;
         gridded2d = other.gridded2d;
      }
      return *this;
   }

   // move
   CovarianceMatrix &operator=(CovarianceMatrix &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         type = std::move(other.type);
         productFrame = std::move(other.productFrame);
         gridded2d = std::move(other.gridded2d);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/covariance/CovarianceMatrix/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class CovarianceMatrix

} // namespace covariance
} // namespace v2_0
} // namespace alpha

#endif
