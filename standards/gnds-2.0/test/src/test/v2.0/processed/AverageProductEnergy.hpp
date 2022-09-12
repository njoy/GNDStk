
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_PROCESSED_AVERAGEPRODUCTENERGY
#define TEST_V2_0_PROCESSED_AVERAGEPRODUCTENERGY

#include "test/v2.0/containers/XYs1d.hpp"
#include "test/v2.0/containers/Gridded1d.hpp"
#include "test/v2.0/containers/Regions1d.hpp"

namespace test {
namespace v2_0 {
namespace processed {

// -----------------------------------------------------------------------------
// processed::
// class AverageProductEnergy
// -----------------------------------------------------------------------------

class AverageProductEnergy : public Component<processed::AverageProductEnergy> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "processed"; }
   static auto CLASS() { return "AverageProductEnergy"; }
   static auto FIELD() { return "averageProductEnergy"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         containers::XYs1d{}
            / --Child<>("XYs1d") |
         std::optional<containers::Gridded1d>{}
            / --Child<>("gridded1d") |
         std::optional<containers::Regions1d>{}
            / --Child<>("regions1d")
      ;
   }

public:
   using Component::construct;

   // children
   Field<containers::XYs1d> XYs1d{this};
   Field<std::optional<containers::Gridded1d>> gridded1d{this};
   Field<std::optional<containers::Regions1d>> regions1d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->XYs1d, \
      this->gridded1d, \
      this->regions1d)

   // default, and from fields
   explicit AverageProductEnergy(
      const wrapper<containers::XYs1d> &XYs1d = {},
      const wrapper<std::optional<containers::Gridded1d>> &gridded1d = {},
      const wrapper<std::optional<containers::Regions1d>> &regions1d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      XYs1d(this,XYs1d),
      gridded1d(this,gridded1d),
      regions1d(this,regions1d)
   {
      Component::finish();
   }

   // from node
   explicit AverageProductEnergy(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   AverageProductEnergy(const AverageProductEnergy &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   AverageProductEnergy(AverageProductEnergy &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   AverageProductEnergy &operator=(const AverageProductEnergy &) = default;
   AverageProductEnergy &operator=(AverageProductEnergy &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/processed/AverageProductEnergy/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class AverageProductEnergy

} // namespace processed
} // namespace v2_0
} // namespace test

#endif