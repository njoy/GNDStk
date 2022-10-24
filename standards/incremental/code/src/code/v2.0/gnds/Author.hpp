
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef CODE_V2_0_GNDS_AUTHOR
#define CODE_V2_0_GNDS_AUTHOR

#include "code/v2.0/key.hpp"

namespace code {
namespace v2_0 {
namespace gnds {

// -----------------------------------------------------------------------------
// gnds::
// class Author
// -----------------------------------------------------------------------------

class Author : public Component<gnds::Author> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "gnds"; }
   static auto CLASS() { return "Author"; }
   static auto FIELD() { return "author"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::string{}
            / Meta<>("name")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::string> name{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->name)

   // default, and from fields
   explicit Author(
      const wrapper<std::string> &name = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      name(this,name)
   {
      Component::finish();
   }

   // from node
   explicit Author(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Author(const Author &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Author(Author &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Author &operator=(const Author &) = default;
   Author &operator=(Author &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "code/v2.0/gnds/Author/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Author

} // namespace gnds
} // namespace v2_0
} // namespace code

#endif
