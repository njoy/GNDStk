
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_PARAMETERCOVARIANCES
#define ALPHA_V2_0_GENERAL_PARAMETERCOVARIANCES

#include "alpha/v2.0/general/ParameterCovariance.hpp"
#include "alpha/v2.0/general/AverageParameterCovariance.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class ParameterCovariances
// -----------------------------------------------------------------------------

class ParameterCovariances :
   public Component<general::ParameterCovariances>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "ParameterCovariances"; }
   static auto FIELD() { return "parameterCovariances"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<general::ParameterCovariance>
            ("parameterCovariance") |
         ++Child<std::optional<general::AverageParameterCovariance>>
            ("averageParameterCovariance")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<std::vector<general::ParameterCovariance>>
      parameterCovariance{this};
   Field<std::optional<std::vector<general::AverageParameterCovariance>>>
      averageParameterCovariance{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->parameterCovariance, \
      this->averageParameterCovariance)

   // default
   ParameterCovariances() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ParameterCovariances(
      const wrapper<std::vector<general::ParameterCovariance>>
         &parameterCovariance,
      const wrapper<std::optional<std::vector<general::AverageParameterCovariance>>>
         &averageParameterCovariance = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      parameterCovariance(this,parameterCovariance),
      averageParameterCovariance(this,averageParameterCovariance)
   {
      Component::finish();
   }

   // from node
   explicit ParameterCovariances(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ParameterCovariances(const ParameterCovariances &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      parameterCovariance(this,other.parameterCovariance),
      averageParameterCovariance(this,other.averageParameterCovariance)
   {
      Component::finish(other);
   }

   // move
   ParameterCovariances(ParameterCovariances &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      parameterCovariance(this,std::move(other.parameterCovariance)),
      averageParameterCovariance(this,std::move(other.averageParameterCovariance))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   ParameterCovariances &operator=(const ParameterCovariances &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         parameterCovariance = other.parameterCovariance;
         averageParameterCovariance = other.averageParameterCovariance;
      }
      return *this;
   }

   // move
   ParameterCovariances &operator=(ParameterCovariances &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         parameterCovariance = std::move(other.parameterCovariance);
         averageParameterCovariance = std::move(other.averageParameterCovariance);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/ParameterCovariances/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ParameterCovariances

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
