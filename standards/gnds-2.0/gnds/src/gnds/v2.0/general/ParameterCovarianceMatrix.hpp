
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_PARAMETERCOVARIANCEMATRIX
#define GNDS_V2_0_GENERAL_PARAMETERCOVARIANCEMATRIX

#include "gnds/v2.0/g3d/Array.hpp"
#include "gnds/v2.0/general/Parameters.hpp"

namespace gnds {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class ParameterCovarianceMatrix
// -----------------------------------------------------------------------------

class ParameterCovarianceMatrix :
   public Component<general::ParameterCovarianceMatrix>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "ParameterCovarianceMatrix"; }
   static auto NODENAME() { return "parameterCovarianceMatrix"; }

   // Core Interface multi-query to transfer information to/from core Nodes
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

         // children
         --Child<g3d::Array>
            ("array") |
         --Child<general::Parameters>
            ("parameters")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "type",
         "array",
         "parameters"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "type",
         "array",
         "parameters"
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
   Field<std::string>
      type{this};

   // children
   Field<g3d::Array>
      array{this};
   Field<general::Parameters>
      parameters{this};

   // shortcuts
   #define NJOY_GNDSTK_SHORTCUT(to,name) decltype(to.name) &name = to.name
   NJOY_GNDSTK_SHORTCUT(array(),lengths);
   NJOY_GNDSTK_SHORTCUT(parameters(),parameterLink);
   NJOY_GNDSTK_SHORTCUT(array(),starts);
   NJOY_GNDSTK_SHORTCUT(array(),values);
   #undef NJOY_GNDSTK_SHORTCUT

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->type, \
      this->array, \
      this->parameters \
   )

   // default
   ParameterCovarianceMatrix() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ParameterCovarianceMatrix(
      const wrapper<std::string>
         &label,
      const wrapper<std::string>
         &type = {},
      const wrapper<g3d::Array>
         &array = {},
      const wrapper<general::Parameters>
         &parameters = {}
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      type(this,type),
      array(this,array),
      parameters(this,parameters)
   {
      Component::finish();
   }

   // from node
   explicit ParameterCovarianceMatrix(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ParameterCovarianceMatrix(const ParameterCovarianceMatrix &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      type(this,other.type),
      array(this,other.array),
      parameters(this,other.parameters)
   {
      Component::finish(other);
   }

   // move
   ParameterCovarianceMatrix(ParameterCovarianceMatrix &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      type(this,std::move(other.type)),
      array(this,std::move(other.array)),
      parameters(this,std::move(other.parameters))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   ParameterCovarianceMatrix &operator=(const ParameterCovarianceMatrix &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         type = other.type;
         array = other.array;
         parameters = other.parameters;
      }
      return *this;
   }

   // move
   ParameterCovarianceMatrix &operator=(ParameterCovarianceMatrix &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         type = std::move(other.type);
         array = std::move(other.array);
         parameters = std::move(other.parameters);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "gnds/v2.0/general/ParameterCovarianceMatrix/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class ParameterCovarianceMatrix

} // namespace general
} // namespace v2_0
} // namespace gnds

#endif
