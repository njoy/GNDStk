
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_APPDATA_INSTITUTION
#define TRY_V2_0_APPDATA_INSTITUTION

#include "try/v2.0/appData/ENDFconversionFlags.hpp"

namespace try {
namespace v2_0 {
namespace appData {

// -----------------------------------------------------------------------------
// appData::
// class Institution
// -----------------------------------------------------------------------------

class Institution : public Component<appData::Institution> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "appData"; }
   static auto CLASS() { return "Institution"; }
   static auto FIELD() { return "institution"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::optional<XMLName>{}
            / Meta<>("label") |
         // children
         std::optional<appData::ENDFconversionFlags>{}
            / --Child<>("ENDFconversionFlags")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::optional<XMLName>> label{this};

   // children
   Field<std::optional<appData::ENDFconversionFlags>> ENDFconversionFlags{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->ENDFconversionFlags)

   // default, and from fields
   explicit Institution(
      const wrapper<std::optional<XMLName>> &label = {},
      const wrapper<std::optional<appData::ENDFconversionFlags>> &ENDFconversionFlags = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      ENDFconversionFlags(this,ENDFconversionFlags)
   {
      Component::finish();
   }

   // from node
   explicit Institution(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Institution(const Institution &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Institution(Institution &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Institution &operator=(const Institution &) = default;
   Institution &operator=(Institution &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/appData/Institution/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Institution

} // namespace appData
} // namespace v2_0
} // namespace try

#endif