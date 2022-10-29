
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

   // default
   Author() :
      GNDSTK_COMPONENT(BlockData{})
   {
      std::cout << "ctor: Author: default" << std::endl;
      Component::finish();
   }

   // from fields
   explicit Author(
      const wrapper<std::string> &name
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      name(this,name)
   {
      std::cout << "ctor: Author: fields" << std::endl;
      Component::finish();
   }

   // from node
   explicit Author(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      std::cout << "ctor: Author: node" << std::endl;
      Component::finish(node);
   }

   // copy
   Author(const Author &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      std::cout << "ctor: Author: copy" << std::endl;
      *this = other;
      Component::finish(other);
   }

   // move
   Author(Author &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      std::cout << "ctor: Author: move" << std::endl;
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Author &operator=(const Author &other)
   {
      if (this != &other) {
         name = other.name;
      }
      std::cout << "assign: Author: copy" << std::endl;
      return *this;
   }

   // move
   Author &operator=(Author &&other)
   {
      if (this != &other) {
         name = std::move(other.name);
      }
      std::cout << "assign: Author: move" << std::endl;
      return *this;
   }

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
