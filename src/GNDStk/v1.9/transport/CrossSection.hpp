
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDSTK_V1_9_TRANSPORT_CROSSSECTION
#define GNDSTK_V1_9_TRANSPORT_CROSSSECTION

#include "GNDStk/v1.9/containers/XYs1d.hpp"
#include "GNDStk/v1.9/containers/Regions1d.hpp"

namespace njoy {
namespace GNDStk {
namespace v1_9 {
namespace transport {

// -----------------------------------------------------------------------------
// transport::
// class CrossSection
// -----------------------------------------------------------------------------

class CrossSection : public Component<transport::CrossSection> {
   friend class Component;

   using XYs1d_regions1d_t = std::variant<
      containers::XYs1d,
      containers::Regions1d
   >;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "transport"; }
   static auto CLASS() { return "CrossSection"; }
   static auto FIELD() { return "crossSection"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         XYs1d_regions1d_t{}
            / ++(Child<>("XYs1d") || Child<>("regions1d"))
      ;
   }

public:
   using Component::construct;

   // children - variant
   Field<std::vector<XYs1d_regions1d_t>> XYs1d_regions1d{this};
   FieldPart<decltype(XYs1d_regions1d),containers::XYs1d> XYs1d{XYs1d_regions1d};
   FieldPart<decltype(XYs1d_regions1d),containers::Regions1d> regions1d{XYs1d_regions1d};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->XYs1d_regions1d)

   // default, and from fields
   explicit CrossSection(
      const wrapper<std::vector<XYs1d_regions1d_t>> &XYs1d_regions1d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      XYs1d_regions1d(this,XYs1d_regions1d)
   {
      Component::finish();
   }

   // from node
   CrossSection(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   CrossSection(const CrossSection &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   CrossSection(CrossSection &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   CrossSection &operator=(const CrossSection &) = default;
   CrossSection &operator=(CrossSection &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v1.9/transport/CrossSection/src/custom.hpp"
   #undef GNDSTK_COMPONENT

}; // class CrossSection

} // namespace transport
} // namespace v1_9
} // namespace GNDStk
} // namespace njoy

#endif
