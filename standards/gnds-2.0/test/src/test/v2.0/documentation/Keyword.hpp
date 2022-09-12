
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_DOCUMENTATION_KEYWORD
#define TEST_V2_0_DOCUMENTATION_KEYWORD

#include "test/v2.0/key.hpp"

namespace test {
namespace v2_0 {
namespace documentation {

// -----------------------------------------------------------------------------
// documentation::
// class Keyword
// -----------------------------------------------------------------------------

class Keyword : public Component<documentation::Keyword,true> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "documentation"; }
   static auto CLASS() { return "Keyword"; }
   static auto FIELD() { return "keyword"; }

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
         XMLName{}
            / Meta<>("type")
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
   Field<XMLName> type{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->encoding, \
      this->markup, \
      this->label, \
      this->type)

   // default, and from fields
   // std::optional replaces Defaulted; this class knows the default(s)
   explicit Keyword(
      const wrapper<std::optional<XMLName>> &encoding = {},
      const wrapper<std::optional<std::string>> &markup = {},
      const wrapper<std::optional<XMLName>> &label = {},
      const wrapper<XMLName> &type = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      encoding(this,defaults.encoding,encoding),
      markup(this,defaults.markup,markup),
      label(this,label),
      type(this,type)
   {
      Component::finish();
   }

   // from node
   explicit Keyword(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // from vector
   template<class T, class = std::enable_if_t<BLOCKDATA::template supported<T>>>
   Keyword(const std::vector<T> &vector) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(vector);
   }

   // copy
   Keyword(const Keyword &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Keyword(Keyword &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Keyword &operator=(const Keyword &) = default;
   Keyword &operator=(Keyword &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/documentation/Keyword/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Keyword

} // namespace documentation
} // namespace v2_0
} // namespace test

#endif