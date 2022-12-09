
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_FISSIONTRANSPORT_PROMPTPRODUCTKE
#define TEST_V2_0_FISSIONTRANSPORT_PROMPTPRODUCTKE

#include "test/v2.0/containers/XYs1d.hpp"
#include "test/v2.0/containers/Polynomial1d.hpp"

namespace test {
namespace v2_0 {
namespace fissionTransport {

// -----------------------------------------------------------------------------
// fissionTransport::
// class PromptProductKE
// -----------------------------------------------------------------------------

class PromptProductKE : public Component<fissionTransport::PromptProductKE> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "fissionTransport"; }
   static auto CLASS() { return "PromptProductKE"; }
   static auto FIELD() { return "promptProductKE"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         --Child<std::optional<containers::XYs1d>>("XYs1d") |
         --Child<std::optional<containers::Polynomial1d>>("polynomial1d")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::optional<containers::XYs1d>> XYs1d{this};
   Field<std::optional<containers::Polynomial1d>> polynomial1d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->XYs1d, \
      this->polynomial1d)

   // default
   PromptProductKE() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields
   explicit PromptProductKE(
      const wrapper<std::optional<containers::XYs1d>> &XYs1d,
      const wrapper<std::optional<containers::Polynomial1d>> &polynomial1d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      XYs1d(this,XYs1d),
      polynomial1d(this,polynomial1d)
   {
      Component::finish();
   }

   // from node
   explicit PromptProductKE(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   PromptProductKE(const PromptProductKE &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      XYs1d(this,other.XYs1d),
      polynomial1d(this,other.polynomial1d)
   {
      Component::finish(other);
   }

   // move
   PromptProductKE(PromptProductKE &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      XYs1d(this,std::move(other.XYs1d)),
      polynomial1d(this,std::move(other.polynomial1d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   PromptProductKE &operator=(const PromptProductKE &) = default;
   PromptProductKE &operator=(PromptProductKE &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/fissionTransport/PromptProductKE/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class PromptProductKE

} // namespace fissionTransport
} // namespace v2_0
} // namespace test

#endif
