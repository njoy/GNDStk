
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_PARAMETERCOVARIANCES
#define GNDS_V2_0_GENERAL_PARAMETERCOVARIANCES

#include "gnds/v2.0/general/ParameterCovariance.hpp"
#include "gnds/v2.0/general/AverageParameterCovariance.hpp"

namespace gnds {
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

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "ParameterCovariances"; }
   static auto NODENAME() { return "parameterCovariances"; }

   // Core Interface multi-query to transfer information to/from core Nodes
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

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "parameterCovariance",
         "averageParameterCovariance"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "parameter_covariance",
         "average_parameter_covariance"
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

   // children
   Field<std::vector<general::ParameterCovariance>>
      parameterCovariance{this};
   Field<std::optional<std::vector<general::AverageParameterCovariance>>>
      averageParameterCovariance{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->parameterCovariance, \
      this->averageParameterCovariance \
   )

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

   #include "gnds/v2.0/general/ParameterCovariances/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ParameterCovariances

} // namespace general
} // namespace v2_0
} // namespace gnds

#endif
