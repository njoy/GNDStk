
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_TRANSPORT_PHOTONEMISSIONPROBABILITIES
#define TRY_V2_0_TRANSPORT_PHOTONEMISSIONPROBABILITIES

#include "try/v2.0/pops/Shell.hpp"

namespace try {
namespace v2_0 {
namespace transport {

// -----------------------------------------------------------------------------
// transport::
// class PhotonEmissionProbabilities
// -----------------------------------------------------------------------------

class PhotonEmissionProbabilities : public Component<transport::PhotonEmissionProbabilities> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "transport"; }
   static auto CLASS() { return "PhotonEmissionProbabilities"; }
   static auto FIELD() { return "photonEmissionProbabilities"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         std::optional<pops::Shell>{}
            / --Child<>("shell")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::optional<pops::Shell>> shell{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->shell)

   // default, and from fields
   explicit PhotonEmissionProbabilities(
      const wrapper<std::optional<pops::Shell>> &shell = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      shell(this,shell)
   {
      Component::finish();
   }

   // from node
   explicit PhotonEmissionProbabilities(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   PhotonEmissionProbabilities(const PhotonEmissionProbabilities &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   PhotonEmissionProbabilities(PhotonEmissionProbabilities &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   PhotonEmissionProbabilities &operator=(const PhotonEmissionProbabilities &) = default;
   PhotonEmissionProbabilities &operator=(PhotonEmissionProbabilities &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/transport/PhotonEmissionProbabilities/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class PhotonEmissionProbabilities

} // namespace transport
} // namespace v2_0
} // namespace try

#endif
