
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_DOCUMENTATION_NOTE
#define TEST_V2_0_DOCUMENTATION_NOTE

#include "test/v2.0/key.hpp"

namespace test {
namespace v2_0 {
namespace documentation {

// -----------------------------------------------------------------------------
// documentation::
// class Note
// -----------------------------------------------------------------------------

class Note :
   public Component<documentation::Note,true>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "documentation"; }
   static auto CLASS() { return "Note"; }
   static auto FIELD() { return "note"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

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

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<Defaulted<XMLName>> encoding{this,defaults.encoding};
   Field<Defaulted<std::string>> markup{this,defaults.markup};
   Field<std::optional<XMLName>> label{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->encoding, \
      this->markup, \
      this->label)

   // default
   Note() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   // optional replaces Defaulted; this class knows the default(s)
   explicit Note(
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
   explicit Note(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // from vector
   template<class T, class = std::enable_if_t<BLOCKDATA::template supported<T>>>
   Note(const std::vector<T> &vector) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(vector);
   }

   // copy
   Note(const Note &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      encoding(this,other.encoding),
      markup(this,other.markup),
      label(this,other.label)
   {
      Component::finish(other);
   }

   // move
   Note(Note &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      encoding(this,std::move(other.encoding)),
      markup(this,std::move(other.markup)),
      label(this,std::move(other.label))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Note &operator=(const Note &) = default;
   Note &operator=(Note &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/documentation/Note/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Note

} // namespace documentation
} // namespace v2_0
} // namespace test

#endif
