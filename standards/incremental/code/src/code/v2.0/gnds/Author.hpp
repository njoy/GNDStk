
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

class Author :
   public Component<gnds::Author>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "gnds"; }
   static auto CLASS() { return "Author"; }
   static auto FIELD() { return "author"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("name")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string> name{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->name)

   // default
   Author() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Author(
      const wrapper<std::string> &name
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
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      name(this,other.name)
   {
      Component::finish(other);
   }

   // move
   Author(Author &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      name(this,std::move(other.name))
   {
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
