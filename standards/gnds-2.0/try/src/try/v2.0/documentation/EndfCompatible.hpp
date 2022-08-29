
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_DOCUMENTATION_ENDFCOMPATIBLE
#define TRY_V2_0_DOCUMENTATION_ENDFCOMPATIBLE

#include "try/v2.0/key.hpp"

namespace try {
namespace v2_0 {
namespace documentation {

// -----------------------------------------------------------------------------
// documentation::
// class EndfCompatible
// -----------------------------------------------------------------------------

class EndfCompatible : public Component<documentation::EndfCompatible,true> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "documentation"; }
   static auto CLASS() { return "EndfCompatible"; }
   static auto FIELD() { return "endfCompatible"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         Defaulted<XMLName>{"ascii"}
            / Meta<>("encoding") |
         Defaulted<std::string>{"enums::GridStyle::none"}
            / Meta<>("markup") |
         std::optional<XMLName>{}
            / Meta<>("label")
      ;
   }

public:
   using Component::construct;
   using BlockData::operator=;

   // defaults
   static inline const struct Defaults {
      static inline const XMLName encoding = "ascii";
      static inline const std::string markup = "enums::GridStyle::none";
   } defaults;

   // metadata
   Field<Defaulted<XMLName>> encoding{this,defaults.encoding};
   Field<Defaulted<std::string>> markup{this,defaults.markup};
   Field<std::optional<XMLName>> label{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->encoding, \
      this->markup, \
      this->label)

   // default, and from fields
   // std::optional replaces Defaulted; this class knows the default(s)
   explicit EndfCompatible(
      const wrapper<std::optional<XMLName>> &encoding = {},
      const wrapper<std::optional<std::string>> &markup = {},
      const wrapper<std::optional<XMLName>> &label = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      encoding(this,defaults.encoding,encoding),
      markup(this,defaults.markup,markup),
      label(this,label)
   {
      Component::finish();
   }

   // from node
   explicit EndfCompatible(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // from vector
   template<class T, class = std::enable_if_t<BLOCKDATA::template supported<T>>>
   EndfCompatible(const std::vector<T> &vector) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(vector);
   }

   // copy
   EndfCompatible(const EndfCompatible &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   EndfCompatible(EndfCompatible &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   EndfCompatible &operator=(const EndfCompatible &) = default;
   EndfCompatible &operator=(EndfCompatible &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/documentation/EndfCompatible/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class EndfCompatible

} // namespace documentation
} // namespace v2_0
} // namespace try

#endif
