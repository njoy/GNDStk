
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_DOCUMENTATION_INPUTDECK
#define TEST_V2_0_DOCUMENTATION_INPUTDECK

#include "test/v2.0/key.hpp"

namespace test {
namespace v2_0 {
namespace documentation {

// -----------------------------------------------------------------------------
// documentation::
// class InputDeck
// -----------------------------------------------------------------------------

class InputDeck : public Component<documentation::InputDeck,true> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "documentation"; }
   static auto CLASS() { return "InputDeck"; }
   static auto FIELD() { return "inputDeck"; }

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
            / Meta<>("label") |
         std::optional<XMLName>{}
            / Meta<>("filename")
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
   Field<std::optional<XMLName>> filename{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->encoding, \
      this->markup, \
      this->label, \
      this->filename)

   // default
   InputDeck() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields
   // std::optional replaces Defaulted; this class knows the default(s)
   explicit InputDeck(
      const wrapper<std::optional<XMLName>> &encoding,
      const wrapper<std::optional<std::string>> &markup = {},
      const wrapper<std::optional<XMLName>> &label = {},
      const wrapper<std::optional<XMLName>> &filename = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      encoding(this,defaults.encoding,encoding),
      markup(this,defaults.markup,markup),
      label(this,label),
      filename(this,filename)
   {
      Component::finish();
   }

   // from node
   explicit InputDeck(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // from vector
   template<class T, class = std::enable_if_t<BLOCKDATA::template supported<T>>>
   InputDeck(const std::vector<T> &vector) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(vector);
   }

   // copy
   InputDeck(const InputDeck &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      encoding(this,other.encoding),
      markup(this,other.markup),
      label(this,other.label),
      filename(this,other.filename)
   {
      Component::finish(other);
   }

   // move
   InputDeck(InputDeck &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      encoding(this,std::move(other.encoding)),
      markup(this,std::move(other.markup)),
      label(this,std::move(other.label)),
      filename(this,std::move(other.filename))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   InputDeck &operator=(const InputDeck &) = default;
   InputDeck &operator=(InputDeck &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/documentation/InputDeck/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class InputDeck

} // namespace documentation
} // namespace v2_0
} // namespace test

#endif
