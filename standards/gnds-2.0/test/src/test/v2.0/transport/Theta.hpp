
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_TRANSPORT_THETA
#define TEST_V2_0_TRANSPORT_THETA

#include "test/v2.0/containers/XYs1d.hpp"
#include "test/v2.0/containers/Regions1d.hpp"

namespace test {
namespace v2_0 {
namespace transport {

// -----------------------------------------------------------------------------
// transport::
// class Theta
// -----------------------------------------------------------------------------

class Theta : public Component<transport::Theta> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "transport"; }
   static auto CLASS() { return "Theta"; }
   static auto FIELD() { return "theta"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         --Child<std::optional<containers::XYs1d>>("XYs1d") |
         --Child<std::optional<containers::Regions1d>>("regions1d")
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

   // default
   Theta() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields
   explicit Theta(
      const wrapper<std::optional<containers::XYs1d>> &XYs1d,
      const wrapper<std::optional<containers::Regions1d>> &regions1d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      XYs1d(this,XYs1d),
      regions1d(this,regions1d)
   {
      Component::finish();
   }

   // from node
   explicit Theta(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Theta(const Theta &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      XYs1d(this,other.XYs1d),
      regions1d(this,other.regions1d)
   {
      Component::finish(other);
   }

   // move
   Theta(Theta &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      XYs1d(this,std::move(other.XYs1d)),
      regions1d(this,std::move(other.regions1d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Theta &operator=(const Theta &) = default;
   Theta &operator=(Theta &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/transport/Theta/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Theta

} // namespace transport
} // namespace v2_0
} // namespace test

#endif
