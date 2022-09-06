
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_TRANSPORT_FASTREGION
#define TRY_V2_0_TRANSPORT_FASTREGION

#include "try/v2.0/containers/XYs1d.hpp"
#include "try/v2.0/containers/Regions1d.hpp"

namespace try {
namespace v2_0 {
namespace transport {

// -----------------------------------------------------------------------------
// transport::
// class FastRegion
// -----------------------------------------------------------------------------

class FastRegion : public Component<transport::FastRegion> {
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
   static auto CLASS() { return "FastRegion"; }
   static auto FIELD() { return "fastRegion"; }

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

   // default, and from fields
   explicit FastRegion(
      const wrapper<_t> &_XYs1dregions1d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      _XYs1dregions1d(this,_XYs1dregions1d)
   {
      Component::finish();
   }

   // from node
   explicit FastRegion(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   FastRegion(const FastRegion &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   FastRegion(FastRegion &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   FastRegion &operator=(const FastRegion &) = default;
   FastRegion &operator=(FastRegion &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/transport/FastRegion/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class FastRegion

} // namespace transport
} // namespace v2_0
} // namespace try

#endif