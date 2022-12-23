
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_RESONANCES_LS
#define TEST_V2_0_RESONANCES_LS

#include "test/v2.0/resonances/L.hpp"

namespace test {
namespace v2_0 {
namespace resonances {

// -----------------------------------------------------------------------------
// resonances::
// class Ls
// -----------------------------------------------------------------------------

class Ls : public Component<resonances::Ls> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "resonances"; }
   static auto CLASS() { return "Ls"; }
   static auto FIELD() { return "Ls"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         ++Child<resonances::L>("L")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::vector<resonances::L>> L{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->L)

   // default
   Ls() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields
   explicit Ls(
      const wrapper<std::vector<resonances::L>> &L
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      L(this,L)
   {
      Component::finish();
   }

   // from node
   explicit Ls(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Ls(const Ls &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      L(this,other.L)
   {
      Component::finish(other);
   }

   // move
   Ls(Ls &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      L(this,std::move(other.L))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Ls &operator=(const Ls &) = default;
   Ls &operator=(Ls &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/resonances/Ls/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Ls

} // namespace resonances
} // namespace v2_0
} // namespace test

#endif
