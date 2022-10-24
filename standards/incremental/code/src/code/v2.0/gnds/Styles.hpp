
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_GNDS_STYLES
#define TEST_V2_0_GNDS_STYLES

#include "test/v2.0/gnds/Evaluated.hpp"

namespace test {
namespace v2_0 {
namespace gnds {

// -----------------------------------------------------------------------------
// gnds::
// class Styles
// -----------------------------------------------------------------------------

class Styles : public Component<gnds::Styles> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "gnds"; }
   static auto CLASS() { return "Styles"; }
   static auto FIELD() { return "styles"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         gnds::Evaluated{}
            / --Child<>("evaluated")
      ;
   }

public:
   using Component::construct;

   // children
   Field<gnds::Evaluated> evaluated{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->evaluated)

   // default, and from fields
   explicit Styles(
      const wrapper<gnds::Evaluated> &evaluated = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      evaluated(this,evaluated)
   {
      std::cout << "ctor: Styles: 1. default/parameters" << std::endl;
      Component::finish();
   }

   // from node
   explicit Styles(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      std::cout << "ctor: Styles: 2. node" << std::endl;
      Component::finish(node);
   }

   // copy
   Styles(const Styles &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      std::cout << "ctor: Styles: 4. copy" << std::endl;
      *this = other;
      Component::finish(other);
   }

   // move
   Styles(Styles &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      std::cout << "ctor: Styles: 5. move" << std::endl;
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Styles &operator=(const Styles &) = default;
   Styles &operator=(Styles &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/gnds/Styles/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Styles

} // namespace gnds
} // namespace v2_0
} // namespace test

#endif
