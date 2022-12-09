
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_FPY_ELAPSEDTIMES
#define TEST_V2_0_FPY_ELAPSEDTIMES

#include "test/v2.0/fpy/ElapsedTime.hpp"

namespace test {
namespace v2_0 {
namespace fpy {

// -----------------------------------------------------------------------------
// fpy::
// class ElapsedTimes
// -----------------------------------------------------------------------------

class ElapsedTimes : public Component<fpy::ElapsedTimes> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "fpy"; }
   static auto CLASS() { return "ElapsedTimes"; }
   static auto FIELD() { return "elapsedTimes"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         fpy::ElapsedTime{}
            / ++Child<>("elapsedTime")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::vector<fpy::ElapsedTime>> elapsedTime{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->elapsedTime)

   // default, and from fields
   explicit ElapsedTimes(
      const wrapper<std::vector<fpy::ElapsedTime>> &elapsedTime = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      elapsedTime(this,elapsedTime)
   {
      Component::finish();
   }

   // from node
   explicit ElapsedTimes(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ElapsedTimes(const ElapsedTimes &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   ElapsedTimes(ElapsedTimes &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   ElapsedTimes &operator=(const ElapsedTimes &) = default;
   ElapsedTimes &operator=(ElapsedTimes &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/fpy/ElapsedTimes/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ElapsedTimes

} // namespace fpy
} // namespace v2_0
} // namespace test

#endif
