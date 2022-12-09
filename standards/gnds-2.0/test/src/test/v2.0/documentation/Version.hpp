
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_DOCUMENTATION_VERSION
#define TEST_V2_0_DOCUMENTATION_VERSION

#include "test/v2.0/key.hpp"

namespace test {
namespace v2_0 {
namespace documentation {

// -----------------------------------------------------------------------------
// documentation::
// class Version
// -----------------------------------------------------------------------------

class Version : public Component<documentation::Version,true> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "documentation"; }
   static auto CLASS() { return "Version"; }
   static auto FIELD() { return "version"; }

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

   // default
   Version() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields
   // std::optional replaces Defaulted; this class knows the default(s)
   explicit Version(
      const wrapper<std::optional<XMLName>> &encoding,
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
   explicit Version(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // from vector
   template<class T, class = std::enable_if_t<BLOCKDATA::template supported<T>>>
   Version(const std::vector<T> &vector) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(vector);
   }

   // copy
   Version(const Version &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      encoding(this,other.encoding),
      markup(this,other.markup),
      label(this,other.label)
   {
      Component::finish(other);
   }

   // move
   Version(Version &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      encoding(this,std::move(other.encoding)),
      markup(this,std::move(other.markup)),
      label(this,std::move(other.label))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Version &operator=(const Version &) = default;
   Version &operator=(Version &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/documentation/Version/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Version

} // namespace documentation
} // namespace v2_0
} // namespace test

#endif
