
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_POPS_METASTABLE
#define TEST_V2_0_POPS_METASTABLE

#include "test/v2.0/key.hpp"

namespace test {
namespace v2_0 {
namespace pops {

// -----------------------------------------------------------------------------
// pops::
// class MetaStable
// -----------------------------------------------------------------------------

class MetaStable : public Component<pops::MetaStable> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "pops"; }
   static auto CLASS() { return "MetaStable"; }
   static auto FIELD() { return "metaStable"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("id") |
         Integer32{}
            / Meta<>("metaStableIndex") |
         XMLName{}
            / Meta<>("pid")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<XMLName> id{this};
   Field<Integer32> metaStableIndex{this};
   Field<XMLName> pid{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->id, \
      this->metaStableIndex, \
      this->pid)

   // default, and from fields
   explicit MetaStable(
      const wrapper<XMLName> &id = {},
      const wrapper<Integer32> &metaStableIndex = {},
      const wrapper<XMLName> &pid = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      id(this,id),
      metaStableIndex(this,metaStableIndex),
      pid(this,pid)
   {
      Component::finish();
   }

   // from node
   explicit MetaStable(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   MetaStable(const MetaStable &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   MetaStable(MetaStable &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   MetaStable &operator=(const MetaStable &) = default;
   MetaStable &operator=(MetaStable &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/pops/MetaStable/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class MetaStable

} // namespace pops
} // namespace v2_0
} // namespace test

#endif