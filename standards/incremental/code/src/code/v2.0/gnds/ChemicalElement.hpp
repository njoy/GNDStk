
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_GNDS_CHEMICALELEMENT
#define TEST_V2_0_GNDS_CHEMICALELEMENT

#include "test/v2.0/gnds/Atomic.hpp"

namespace test {
namespace v2_0 {
namespace gnds {

// -----------------------------------------------------------------------------
// gnds::
// class ChemicalElement
// -----------------------------------------------------------------------------

class ChemicalElement : public Component<gnds::ChemicalElement> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "gnds"; }
   static auto CLASS() { return "ChemicalElement"; }
   static auto FIELD() { return "chemicalElement"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::string{}
            / Meta<>("symbol") |
         int{}
            / Meta<>("Z") |
         std::string{}
            / Meta<>("name") |
         // children
         gnds::Atomic{}
            / --Child<>("atomic")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::string> symbol{this};
   Field<int> Z{this};
   Field<std::string> name{this};

   // children
   Field<gnds::Atomic> atomic{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->symbol, \
      this->Z, \
      this->name, \
      this->atomic)

   // default, and from fields
   explicit ChemicalElement(
      const wrapper<std::string> &symbol = {},
      const wrapper<int> &Z = {},
      const wrapper<std::string> &name = {},
      const wrapper<gnds::Atomic> &atomic = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      symbol(this,symbol),
      Z(this,Z),
      name(this,name),
      atomic(this,atomic)
   {
      std::cout << "ctor: ChemicalElement: 1. default/parameters" << std::endl;
      Component::finish();
   }

   // from node
   explicit ChemicalElement(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      std::cout << "ctor: ChemicalElement: 2. node" << std::endl;
      Component::finish(node);
   }

   // copy
   ChemicalElement(const ChemicalElement &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      std::cout << "ctor: ChemicalElement: 4. copy" << std::endl;
      *this = other;
      Component::finish(other);
   }

   // move
   ChemicalElement(ChemicalElement &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      std::cout << "ctor: ChemicalElement: 5. move" << std::endl;
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   ChemicalElement &operator=(const ChemicalElement &) = default;
   ChemicalElement &operator=(ChemicalElement &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/gnds/ChemicalElement/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ChemicalElement

} // namespace gnds
} // namespace v2_0
} // namespace test

#endif
