
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_RESONANCES_LEVELSPACING
#define TEST_V2_0_RESONANCES_LEVELSPACING

#include "test/v2.0/containers/Constant1d.hpp"
#include "test/v2.0/containers/XYs1d.hpp"
#include "test/v2.0/containers/Regions1d.hpp"

namespace test {
namespace v2_0 {
namespace resonances {

// -----------------------------------------------------------------------------
// resonances::
// class LevelSpacing
// -----------------------------------------------------------------------------

class LevelSpacing : public Component<resonances::LevelSpacing> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "resonances"; }
   static auto CLASS() { return "LevelSpacing"; }
   static auto FIELD() { return "levelSpacing"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         std::optional<containers::Constant1d>{}
            / --Child<>("constant1d") |
         std::optional<containers::XYs1d>{}
            / --Child<>("XYs1d") |
         std::optional<containers::Regions1d>{}
            / --Child<>("regions1d")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::optional<containers::Constant1d>> constant1d{this};
   Field<std::optional<containers::XYs1d>> XYs1d{this};
   Field<std::optional<containers::Regions1d>> regions1d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->constant1d, \
      this->XYs1d, \
      this->regions1d)

   // default, and from fields
   explicit LevelSpacing(
      const wrapper<std::optional<containers::Constant1d>> &constant1d = {},
      const wrapper<std::optional<containers::XYs1d>> &XYs1d = {},
      const wrapper<std::optional<containers::Regions1d>> &regions1d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      constant1d(this,constant1d),
      XYs1d(this,XYs1d),
      regions1d(this,regions1d)
   {
      Component::finish();
   }

   // from node
   explicit LevelSpacing(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   LevelSpacing(const LevelSpacing &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   LevelSpacing(LevelSpacing &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   LevelSpacing &operator=(const LevelSpacing &) = default;
   LevelSpacing &operator=(LevelSpacing &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/resonances/LevelSpacing/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class LevelSpacing

} // namespace resonances
} // namespace v2_0
} // namespace test

#endif
