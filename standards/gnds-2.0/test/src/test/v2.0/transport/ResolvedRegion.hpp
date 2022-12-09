
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_TRANSPORT_RESOLVEDREGION
#define TEST_V2_0_TRANSPORT_RESOLVEDREGION

#include "test/v2.0/containers/XYs1d.hpp"
#include "test/v2.0/containers/Regions1d.hpp"

namespace test {
namespace v2_0 {
namespace transport {

// -----------------------------------------------------------------------------
// transport::
// class ResolvedRegion
// -----------------------------------------------------------------------------

class ResolvedRegion : public Component<transport::ResolvedRegion> {
   friend class Component;

   using _t = std::variant<
      containers::XYs1d,
      containers::Regions1d
   >;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "transport"; }
   static auto CLASS() { return "ResolvedRegion"; }
   static auto FIELD() { return "resolvedRegion"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         _t{}
            / --(Child<>("XYs1d") || Child<>("regions1d"))
      ;
   }

public:
   using Component::construct;

   // children - variant
   Field<_t> _XYs1dregions1d{this};
   FieldPart<decltype(_XYs1dregions1d),containers::XYs1d> XYs1d{_XYs1dregions1d};
   FieldPart<decltype(_XYs1dregions1d),containers::Regions1d> regions1d{_XYs1dregions1d};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->_XYs1dregions1d)

   // default
   ResolvedRegion() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields
   explicit ResolvedRegion(
      const wrapper<_t> &_XYs1dregions1d
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      _XYs1dregions1d(this,_XYs1dregions1d)
   {
      Component::finish();
   }

   // from node
   explicit ResolvedRegion(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ResolvedRegion(const ResolvedRegion &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      _XYs1dregions1d(this,other._XYs1dregions1d)
   {
      Component::finish(other);
   }

   // move
   ResolvedRegion(ResolvedRegion &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      _XYs1dregions1d(this,std::move(other._XYs1dregions1d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   ResolvedRegion &operator=(const ResolvedRegion &) = default;
   ResolvedRegion &operator=(ResolvedRegion &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/transport/ResolvedRegion/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ResolvedRegion

} // namespace transport
} // namespace v2_0
} // namespace test

#endif
