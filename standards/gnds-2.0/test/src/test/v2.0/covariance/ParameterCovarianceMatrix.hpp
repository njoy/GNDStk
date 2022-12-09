
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_COVARIANCE_PARAMETERCOVARIANCEMATRIX
#define TEST_V2_0_COVARIANCE_PARAMETERCOVARIANCEMATRIX

#include "test/v2.0/covariance/Parameters.hpp"
#include "test/v2.0/containers/Array.hpp"

namespace test {
namespace v2_0 {
namespace covariance {

// -----------------------------------------------------------------------------
// covariance::
// class ParameterCovarianceMatrix
// -----------------------------------------------------------------------------

class ParameterCovarianceMatrix : public Component<covariance::ParameterCovarianceMatrix> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "covariance"; }
   static auto CLASS() { return "ParameterCovarianceMatrix"; }
   static auto FIELD() { return "parameterCovarianceMatrix"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("label") |
         std::optional<XMLName>{}
            / Meta<>("type") |
         // children
         covariance::Parameters{}
            / --Child<>("parameters") |
         containers::Array{}
            / --Child<>("array")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<XMLName> label{this};
   Field<std::optional<XMLName>> type{this};

   // children
   Field<covariance::Parameters> parameters{this};
   Field<containers::Array> array{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->type, \
      this->parameters, \
      this->array)

   // default, and from fields
   explicit ParameterCovarianceMatrix(
      const wrapper<XMLName> &label = {},
      const wrapper<std::optional<XMLName>> &type = {},
      const wrapper<covariance::Parameters> &parameters = {},
      const wrapper<containers::Array> &array = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      type(this,type),
      parameters(this,parameters),
      array(this,array)
   {
      Component::finish();
   }

   // from node
   explicit ParameterCovarianceMatrix(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ParameterCovarianceMatrix(const ParameterCovarianceMatrix &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   ParameterCovarianceMatrix(ParameterCovarianceMatrix &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   ParameterCovarianceMatrix &operator=(const ParameterCovarianceMatrix &) = default;
   ParameterCovarianceMatrix &operator=(ParameterCovarianceMatrix &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/covariance/ParameterCovarianceMatrix/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ParameterCovarianceMatrix

} // namespace covariance
} // namespace v2_0
} // namespace test

#endif
