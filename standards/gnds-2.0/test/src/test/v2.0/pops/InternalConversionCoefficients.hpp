
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_POPS_INTERNALCONVERSIONCOEFFICIENTS
#define TEST_V2_0_POPS_INTERNALCONVERSIONCOEFFICIENTS

#include "test/v2.0/pops/Shell.hpp"

namespace test {
namespace v2_0 {
namespace pops {

// -----------------------------------------------------------------------------
// pops::
// class InternalConversionCoefficients
// -----------------------------------------------------------------------------

class InternalConversionCoefficients : public Component<pops::InternalConversionCoefficients> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "pops"; }
   static auto CLASS() { return "InternalConversionCoefficients"; }
   static auto FIELD() { return "internalConversionCoefficients"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         pops::Shell{}
            / ++Child<>("shell")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::vector<pops::Shell>> shell{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->shell)

   // default, and from fields
   explicit InternalConversionCoefficients(
      const wrapper<std::vector<pops::Shell>> &shell = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      shell(this,shell)
   {
      Component::finish();
   }

   // from node
   explicit InternalConversionCoefficients(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   InternalConversionCoefficients(const InternalConversionCoefficients &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   InternalConversionCoefficients(InternalConversionCoefficients &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   InternalConversionCoefficients &operator=(const InternalConversionCoefficients &) = default;
   InternalConversionCoefficients &operator=(InternalConversionCoefficients &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/pops/InternalConversionCoefficients/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class InternalConversionCoefficients

} // namespace pops
} // namespace v2_0
} // namespace test

#endif