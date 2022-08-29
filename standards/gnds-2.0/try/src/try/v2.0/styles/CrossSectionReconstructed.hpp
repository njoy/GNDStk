
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_STYLES_CROSSSECTIONRECONSTRUCTED
#define TRY_V2_0_STYLES_CROSSSECTIONRECONSTRUCTED

#include "try/v2.0/styles/Temperature.hpp"
#include "try/v2.0/documentation/Documentation.hpp"

namespace try {
namespace v2_0 {
namespace styles {

// -----------------------------------------------------------------------------
// styles::
// class CrossSectionReconstructed
// -----------------------------------------------------------------------------

class CrossSectionReconstructed : public Component<styles::CrossSectionReconstructed> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "styles"; }
   static auto CLASS() { return "CrossSectionReconstructed"; }
   static auto FIELD() { return "crossSectionReconstructed"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::string{}
            / Meta<>("date") |
         XMLName{}
            / Meta<>("label") |
         std::optional<XMLName>{}
            / Meta<>("derivedFrom") |
         // children
         std::optional<styles::Temperature>{}
            / --Child<>("temperature") |
         std::optional<documentation::Documentation>{}
            / --Child<>("documentation")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::string> date{this};
   Field<XMLName> label{this};
   Field<std::optional<XMLName>> derivedFrom{this};

   // children
   Field<std::optional<styles::Temperature>> temperature{this};
   Field<std::optional<documentation::Documentation>> documentation{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->date, \
      this->label, \
      this->derivedFrom, \
      this->temperature, \
      this->documentation)

   // default, and from fields
   explicit CrossSectionReconstructed(
      const wrapper<std::string> &date = {},
      const wrapper<XMLName> &label = {},
      const wrapper<std::optional<XMLName>> &derivedFrom = {},
      const wrapper<std::optional<styles::Temperature>> &temperature = {},
      const wrapper<std::optional<documentation::Documentation>> &documentation = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      date(this,date),
      label(this,label),
      derivedFrom(this,derivedFrom),
      temperature(this,temperature),
      documentation(this,documentation)
   {
      Component::finish();
   }

   // from node
   explicit CrossSectionReconstructed(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   CrossSectionReconstructed(const CrossSectionReconstructed &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   CrossSectionReconstructed(CrossSectionReconstructed &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   CrossSectionReconstructed &operator=(const CrossSectionReconstructed &) = default;
   CrossSectionReconstructed &operator=(CrossSectionReconstructed &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/styles/CrossSectionReconstructed/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class CrossSectionReconstructed

} // namespace styles
} // namespace v2_0
} // namespace try

#endif
