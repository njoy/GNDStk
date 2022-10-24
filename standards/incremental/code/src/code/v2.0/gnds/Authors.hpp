
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef CODE_V2_0_GNDS_AUTHORS
#define CODE_V2_0_GNDS_AUTHORS

#include "code/v2.0/gnds/Author.hpp"

namespace code {
namespace v2_0 {
namespace gnds {

// -----------------------------------------------------------------------------
// gnds::
// class Authors
// -----------------------------------------------------------------------------

class Authors : public Component<gnds::Authors> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "gnds"; }
   static auto CLASS() { return "Authors"; }
   static auto FIELD() { return "authors"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         gnds::Author{}
            / ++Child<>("author")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::vector<gnds::Author>> author{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->author)

   // default, and from fields
   explicit Authors(
      const wrapper<std::vector<gnds::Author>> &author = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      author(this,author)
   {
      Component::finish();
   }

   // from node
   explicit Authors(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Authors(const Authors &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Authors(Authors &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Authors &operator=(const Authors &) = default;
   Authors &operator=(Authors &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "code/v2.0/gnds/Authors/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Authors

} // namespace gnds
} // namespace v2_0
} // namespace code

#endif
