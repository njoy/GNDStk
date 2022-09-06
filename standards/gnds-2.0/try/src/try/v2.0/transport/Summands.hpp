
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_TRANSPORT_SUMMANDS
#define TRY_V2_0_TRANSPORT_SUMMANDS

#include "try/v2.0/transport/Add.hpp"

namespace try {
namespace v2_0 {
namespace transport {

// -----------------------------------------------------------------------------
// transport::
// class Summands
// -----------------------------------------------------------------------------

class Summands : public Component<transport::Summands> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "transport"; }
   static auto CLASS() { return "Summands"; }
   static auto FIELD() { return "summands"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         std::optional<transport::Add>{}
            / ++Child<>("add")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::optional<std::vector<transport::Add>>> add{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->add)

   // default, and from fields
   explicit Summands(
      const wrapper<std::optional<std::vector<transport::Add>>> &add = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      add(this,add)
   {
      Component::finish();
   }

   // from node
   explicit Summands(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Summands(const Summands &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Summands(Summands &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Summands &operator=(const Summands &) = default;
   Summands &operator=(Summands &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/transport/Summands/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Summands

} // namespace transport
} // namespace v2_0
} // namespace try

#endif