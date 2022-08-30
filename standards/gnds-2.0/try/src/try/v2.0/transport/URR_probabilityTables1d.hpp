
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_TRANSPORT_URR_PROBABILITYTABLES1D
#define TRY_V2_0_TRANSPORT_URR_PROBABILITYTABLES1D

#include "try/v2.0/containers/XYs2d.hpp"
#include "try/v2.0/containers/Regions2d.hpp"

namespace try {
namespace v2_0 {
namespace transport {

// -----------------------------------------------------------------------------
// transport::
// class URR_probabilityTables1d
// -----------------------------------------------------------------------------

class URR_probabilityTables1d : public Component<transport::URR_probabilityTables1d> {
   friend class Component;

   using _t = std::variant<
      containers::XYs2d,
      containers::Regions2d
   >;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "transport"; }
   static auto CLASS() { return "URR_probabilityTables1d"; }
   static auto FIELD() { return "URR_probabilityTables1d"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("label") |
         // children
         _t{}
            / --(Child<>("XYs2d") || Child<>("regions2d"))
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<XMLName> label{this};

   // children - variant
   Field<_t> _XYs2dregions2d{this};
   FieldPart<decltype(_XYs2dregions2d),containers::XYs2d> XYs2d{_XYs2dregions2d};
   FieldPart<decltype(_XYs2dregions2d),containers::Regions2d> regions2d{_XYs2dregions2d};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->_XYs2dregions2d)

   // default, and from fields
   explicit URR_probabilityTables1d(
      const wrapper<XMLName> &label = {},
      const wrapper<_t> &_XYs2dregions2d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      _XYs2dregions2d(this,_XYs2dregions2d)
   {
      Component::finish();
   }

   // from node
   explicit URR_probabilityTables1d(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   URR_probabilityTables1d(const URR_probabilityTables1d &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   URR_probabilityTables1d(URR_probabilityTables1d &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   URR_probabilityTables1d &operator=(const URR_probabilityTables1d &) = default;
   URR_probabilityTables1d &operator=(URR_probabilityTables1d &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/transport/URR_probabilityTables1d/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class URR_probabilityTables1d

} // namespace transport
} // namespace v2_0
} // namespace try

#endif
