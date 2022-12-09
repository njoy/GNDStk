
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_TRANSPORT_CROSSSECTIONSUMS
#define TEST_V2_0_TRANSPORT_CROSSSECTIONSUMS

#include "test/v2.0/transport/CrossSectionSum.hpp"

namespace test {
namespace v2_0 {
namespace transport {

// -----------------------------------------------------------------------------
// transport::
// class CrossSectionSums
// -----------------------------------------------------------------------------

class CrossSectionSums : public Component<transport::CrossSectionSums> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "transport"; }
   static auto CLASS() { return "CrossSectionSums"; }
   static auto FIELD() { return "crossSectionSums"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         std::optional<transport::CrossSectionSum>{}
            / ++Child<>("crossSectionSum")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::optional<std::vector<transport::CrossSectionSum>>> crossSectionSum{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->crossSectionSum)

   // default, and from fields
   explicit CrossSectionSums(
      const wrapper<std::optional<std::vector<transport::CrossSectionSum>>> &crossSectionSum = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      crossSectionSum(this,crossSectionSum)
   {
      Component::finish();
   }

   // from node
   explicit CrossSectionSums(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   CrossSectionSums(const CrossSectionSums &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   CrossSectionSums(CrossSectionSums &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   CrossSectionSums &operator=(const CrossSectionSums &) = default;
   CrossSectionSums &operator=(CrossSectionSums &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/transport/CrossSectionSums/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class CrossSectionSums

} // namespace transport
} // namespace v2_0
} // namespace test

#endif
