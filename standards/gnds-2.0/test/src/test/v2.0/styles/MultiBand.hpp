
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_STYLES_MULTIBAND
#define TEST_V2_0_STYLES_MULTIBAND

#include "test/v2.0/documentation/Documentation.hpp"

namespace test {
namespace v2_0 {
namespace styles {

// -----------------------------------------------------------------------------
// styles::
// class MultiBand
// -----------------------------------------------------------------------------

class MultiBand : public Component<styles::MultiBand> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "styles"; }
   static auto CLASS() { return "MultiBand"; }
   static auto FIELD() { return "multiBand"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::string{}
            / Meta<>("date") |
         XMLName{}
            / Meta<>("derivedFrom") |
         XMLName{}
            / Meta<>("label") |
         Integer32{}
            / Meta<>("numberOfBands") |
         // children
         std::optional<documentation::Documentation>{}
            / --Child<>("documentation")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::string> date{this};
   Field<XMLName> derivedFrom{this};
   Field<XMLName> label{this};
   Field<Integer32> numberOfBands{this};

   // children
   Field<std::optional<documentation::Documentation>> documentation{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->date, \
      this->derivedFrom, \
      this->label, \
      this->numberOfBands, \
      this->documentation)

   // default, and from fields
   explicit MultiBand(
      const wrapper<std::string> &date = {},
      const wrapper<XMLName> &derivedFrom = {},
      const wrapper<XMLName> &label = {},
      const wrapper<Integer32> &numberOfBands = {},
      const wrapper<std::optional<documentation::Documentation>> &documentation = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      date(this,date),
      derivedFrom(this,derivedFrom),
      label(this,label),
      numberOfBands(this,numberOfBands),
      documentation(this,documentation)
   {
      Component::finish();
   }

   // from node
   explicit MultiBand(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   MultiBand(const MultiBand &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   MultiBand(MultiBand &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   MultiBand &operator=(const MultiBand &) = default;
   MultiBand &operator=(MultiBand &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/styles/MultiBand/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class MultiBand

} // namespace styles
} // namespace v2_0
} // namespace test

#endif