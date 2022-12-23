
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_STYLES_HEATED
#define TEST_V2_0_STYLES_HEATED

#include "test/v2.0/styles/Temperature.hpp"
#include "test/v2.0/documentation/Documentation.hpp"

namespace test {
namespace v2_0 {
namespace styles {

// -----------------------------------------------------------------------------
// styles::
// class Heated
// -----------------------------------------------------------------------------

class Heated : public Component<styles::Heated> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "styles"; }
   static auto CLASS() { return "Heated"; }
   static auto FIELD() { return "heated"; }

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
         // children
         --Child<styles::Temperature>("temperature") |
         --Child<std::optional<documentation::Documentation>>("documentation")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::string> date{this};
   Field<XMLName> derivedFrom{this};
   Field<XMLName> label{this};

   // children
   Field<styles::Temperature> temperature{this};
   Field<std::optional<documentation::Documentation>> documentation{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->date, \
      this->derivedFrom, \
      this->label, \
      this->temperature, \
      this->documentation)

   // default
   Heated() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields
   explicit Heated(
      const wrapper<std::string> &date,
      const wrapper<XMLName> &derivedFrom = {},
      const wrapper<XMLName> &label = {},
      const wrapper<styles::Temperature> &temperature = {},
      const wrapper<std::optional<documentation::Documentation>> &documentation = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      date(this,date),
      derivedFrom(this,derivedFrom),
      label(this,label),
      temperature(this,temperature),
      documentation(this,documentation)
   {
      Component::finish();
   }

   // from node
   explicit Heated(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Heated(const Heated &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      date(this,other.date),
      derivedFrom(this,other.derivedFrom),
      label(this,other.label),
      temperature(this,other.temperature),
      documentation(this,other.documentation)
   {
      Component::finish(other);
   }

   // move
   Heated(Heated &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      date(this,std::move(other.date)),
      derivedFrom(this,std::move(other.derivedFrom)),
      label(this,std::move(other.label)),
      temperature(this,std::move(other.temperature)),
      documentation(this,std::move(other.documentation))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Heated &operator=(const Heated &) = default;
   Heated &operator=(Heated &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/styles/Heated/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Heated

} // namespace styles
} // namespace v2_0
} // namespace test

#endif
