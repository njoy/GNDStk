
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_CONTAINERS_PDF
#define TEST_V2_0_CONTAINERS_PDF

#include "test/v2.0/containers/XYs1d.hpp"
#include "test/v2.0/containers/Regions1d.hpp"

namespace test {
namespace v2_0 {
namespace containers {

// -----------------------------------------------------------------------------
// containers::
// class Pdf
// -----------------------------------------------------------------------------

class Pdf : public Component<containers::Pdf> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "containers"; }
   static auto CLASS() { return "Pdf"; }
   static auto FIELD() { return "pdf"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         std::optional<containers::XYs1d>{}
            / --Child<>("XYs1d") |
         std::optional<containers::Regions1d>{}
            / --Child<>("regions1d")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::optional<containers::XYs1d>> XYs1d{this};
   Field<std::optional<containers::Regions1d>> regions1d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->XYs1d, \
      this->regions1d)

   // default, and from fields
   explicit Pdf(
      const wrapper<std::optional<containers::XYs1d>> &XYs1d = {},
      const wrapper<std::optional<containers::Regions1d>> &regions1d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      XYs1d(this,XYs1d),
      regions1d(this,regions1d)
   {
      Component::finish();
   }

   // from node
   explicit Pdf(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Pdf(const Pdf &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Pdf(Pdf &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Pdf &operator=(const Pdf &) = default;
   Pdf &operator=(Pdf &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/containers/Pdf/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Pdf

} // namespace containers
} // namespace v2_0
} // namespace test

#endif
