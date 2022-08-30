
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_TRANSPORT_ANGULAR_UNCORRELATED
#define TRY_V2_0_TRANSPORT_ANGULAR_UNCORRELATED

#include "try/v2.0/containers/XYs2d.hpp"
#include "try/v2.0/transport/Isotropic2d.hpp"
#include "try/v2.0/transport/Forward.hpp"

namespace try {
namespace v2_0 {
namespace transport {

// -----------------------------------------------------------------------------
// transport::
// class Angular_uncorrelated
// -----------------------------------------------------------------------------

class Angular_uncorrelated : public Component<transport::Angular_uncorrelated> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "transport"; }
   static auto CLASS() { return "Angular_uncorrelated"; }
   static auto FIELD() { return "angular"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         std::optional<containers::XYs2d>{}
            / --Child<>("XYs2d") |
         std::optional<transport::Isotropic2d>{}
            / --Child<>("isotropic2d") |
         std::optional<transport::Forward>{}
            / --Child<>("forward")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::optional<containers::XYs2d>> XYs2d{this};
   Field<std::optional<transport::Isotropic2d>> isotropic2d{this};
   Field<std::optional<transport::Forward>> forward{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->XYs2d, \
      this->isotropic2d, \
      this->forward)

   // default, and from fields
   explicit Angular_uncorrelated(
      const wrapper<std::optional<containers::XYs2d>> &XYs2d = {},
      const wrapper<std::optional<transport::Isotropic2d>> &isotropic2d = {},
      const wrapper<std::optional<transport::Forward>> &forward = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      XYs2d(this,XYs2d),
      isotropic2d(this,isotropic2d),
      forward(this,forward)
   {
      Component::finish();
   }

   // from node
   explicit Angular_uncorrelated(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Angular_uncorrelated(const Angular_uncorrelated &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Angular_uncorrelated(Angular_uncorrelated &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Angular_uncorrelated &operator=(const Angular_uncorrelated &) = default;
   Angular_uncorrelated &operator=(Angular_uncorrelated &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/transport/Angular_uncorrelated/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Angular_uncorrelated

} // namespace transport
} // namespace v2_0
} // namespace try

#endif
