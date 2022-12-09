
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_STYLES_EQUALPROBABLEBINS
#define TEST_V2_0_STYLES_EQUALPROBABLEBINS

#include "test/v2.0/documentation/Documentation.hpp"

namespace test {
namespace v2_0 {
namespace styles {

// -----------------------------------------------------------------------------
// styles::
// class EqualProbableBins
// -----------------------------------------------------------------------------

class EqualProbableBins : public Component<styles::EqualProbableBins> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "styles"; }
   static auto CLASS() { return "EqualProbableBins"; }
   static auto FIELD() { return "equalProbableBins"; }

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
            / Meta<>("numberOfBins") |
         // children
         --Child<std::optional<documentation::Documentation>>("documentation")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::string> date{this};
   Field<XMLName> derivedFrom{this};
   Field<XMLName> label{this};
   Field<Integer32> numberOfBins{this};

   // children
   Field<std::optional<documentation::Documentation>> documentation{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->date, \
      this->derivedFrom, \
      this->label, \
      this->numberOfBins, \
      this->documentation)

   // default
   EqualProbableBins() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields
   explicit EqualProbableBins(
      const wrapper<std::string> &date,
      const wrapper<XMLName> &derivedFrom = {},
      const wrapper<XMLName> &label = {},
      const wrapper<Integer32> &numberOfBins = {},
      const wrapper<std::optional<documentation::Documentation>> &documentation = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      date(this,date),
      derivedFrom(this,derivedFrom),
      label(this,label),
      numberOfBins(this,numberOfBins),
      documentation(this,documentation)
   {
      Component::finish();
   }

   // from node
   explicit EqualProbableBins(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   EqualProbableBins(const EqualProbableBins &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      date(this,other.date),
      derivedFrom(this,other.derivedFrom),
      label(this,other.label),
      numberOfBins(this,other.numberOfBins),
      documentation(this,other.documentation)
   {
      Component::finish(other);
   }

   // move
   EqualProbableBins(EqualProbableBins &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      date(this,std::move(other.date)),
      derivedFrom(this,std::move(other.derivedFrom)),
      label(this,std::move(other.label)),
      numberOfBins(this,std::move(other.numberOfBins)),
      documentation(this,std::move(other.documentation))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   EqualProbableBins &operator=(const EqualProbableBins &) = default;
   EqualProbableBins &operator=(EqualProbableBins &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/styles/EqualProbableBins/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class EqualProbableBins

} // namespace styles
} // namespace v2_0
} // namespace test

#endif
