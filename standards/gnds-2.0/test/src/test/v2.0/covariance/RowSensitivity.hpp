
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_COVARIANCE_ROWSENSITIVITY
#define TEST_V2_0_COVARIANCE_ROWSENSITIVITY

#include "test/v2.0/containers/Array.hpp"

namespace test {
namespace v2_0 {
namespace covariance {

// -----------------------------------------------------------------------------
// covariance::
// class RowSensitivity
// -----------------------------------------------------------------------------

class RowSensitivity : public Component<covariance::RowSensitivity> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "covariance"; }
   static auto CLASS() { return "RowSensitivity"; }
   static auto FIELD() { return "rowSensitivity"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         containers::Array{}
            / --Child<>("array")
      ;
   }

public:
   using Component::construct;

   // children
   Field<containers::Array> array{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->array)

   // default, and from fields
   explicit RowSensitivity(
      const wrapper<containers::Array> &array = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      array(this,array)
   {
      Component::finish();
   }

   // from node
   explicit RowSensitivity(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   RowSensitivity(const RowSensitivity &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   RowSensitivity(RowSensitivity &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   RowSensitivity &operator=(const RowSensitivity &) = default;
   RowSensitivity &operator=(RowSensitivity &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/covariance/RowSensitivity/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class RowSensitivity

} // namespace covariance
} // namespace v2_0
} // namespace test

#endif
