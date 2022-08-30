
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_CONTAINERS_STRING
#define TRY_V2_0_CONTAINERS_STRING

#include "try/v2.0/key.hpp"

namespace try {
namespace v2_0 {
namespace containers {

// -----------------------------------------------------------------------------
// containers::
// class String
// -----------------------------------------------------------------------------

class String : public Component<containers::String> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "containers"; }
   static auto CLASS() { return "String"; }
   static auto FIELD() { return "string"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::optional<XMLName>{}
            / Meta<>("label") |
         std::optional<XMLName>{}
            / Meta<>("unit") |
         XMLName{}
            / Meta<>("value")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::optional<XMLName>> label{this};
   Field<std::optional<XMLName>> unit{this};
   Field<XMLName> value{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->unit, \
      this->value)

   // default, and from fields
   explicit String(
      const wrapper<std::optional<XMLName>> &label = {},
      const wrapper<std::optional<XMLName>> &unit = {},
      const wrapper<XMLName> &value = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      unit(this,unit),
      value(this,value)
   {
      Component::finish();
   }

   // from node
   explicit String(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   String(const String &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   String(String &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   String &operator=(const String &) = default;
   String &operator=(String &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/containers/String/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class String

} // namespace containers
} // namespace v2_0
} // namespace try

#endif
