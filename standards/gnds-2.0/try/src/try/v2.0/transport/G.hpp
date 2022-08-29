
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_TRANSPORT_G
#define TRY_V2_0_TRANSPORT_G

#include "try/v2.0/unknownNamespace/XYs1d.hpp"
#include "try/v2.0/unknownNamespace/Regions1d.hpp"

namespace try {
namespace v2_0 {
namespace transport {

// -----------------------------------------------------------------------------
// transport::
// class G
// -----------------------------------------------------------------------------

class G : public Component<transport::G> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "transport"; }
   static auto CLASS() { return "G"; }
   static auto FIELD() { return "g"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         std::optional<unknownNamespace::XYs1d>{}
            / --Child<>("XYs1d") |
         std::optional<unknownNamespace::Regions1d>{}
            / --Child<>("regions1d")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::optional<unknownNamespace::XYs1d>> XYs1d{this};
   Field<std::optional<unknownNamespace::Regions1d>> regions1d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->XYs1d, \
      this->regions1d)

   // default, and from fields
   explicit G(
      const wrapper<std::optional<unknownNamespace::XYs1d>> &XYs1d = {},
      const wrapper<std::optional<unknownNamespace::Regions1d>> &regions1d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      XYs1d(this,XYs1d),
      regions1d(this,regions1d)
   {
      Component::finish();
   }

   // from node
   explicit G(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   G(const G &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   G(G &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   G &operator=(const G &) = default;
   G &operator=(G &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/transport/G/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class G

} // namespace transport
} // namespace v2_0
} // namespace try

#endif
