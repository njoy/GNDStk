
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_CONTAINERS_ARRAY
#define TRY_V2_0_CONTAINERS_ARRAY

#include "try/v2.0/containers/Values.hpp"

namespace try {
namespace v2_0 {
namespace containers {

// -----------------------------------------------------------------------------
// containers::
// class Array
// -----------------------------------------------------------------------------

class Array : public Component<containers::Array> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "containers"; }
   static auto CLASS() { return "Array"; }
   static auto FIELD() { return "array"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         IntegerTuple{}
            / Meta<>("shape") |
         std::optional<UTF8Text>{}
            / Meta<>("compression") |
         std::optional<UTF8Text>{}
            / Meta<>("symmetry") |
         std::optional<UTF8Text>{}
            / Meta<>("permutation") |
         Defaulted<UTF8Text>{"row-major"}
            / Meta<>("storageOrder") |
         std::optional<IntegerTuple>{}
            / Meta<>("offset") |
         // children
         std::optional<containers::Values>{}
            / ++Child<>("values") |
         std::optional<containers::Array>{}
            / ++Child<>("array")
      ;
   }

public:
   using Component::construct;

   // defaults
   static inline const struct Defaults {
      static inline const UTF8Text storageOrder = "row-major";
   } defaults;

   // metadata
   Field<IntegerTuple> shape{this};
   Field<std::optional<UTF8Text>> compression{this};
   Field<std::optional<UTF8Text>> symmetry{this};
   Field<std::optional<UTF8Text>> permutation{this};
   Field<Defaulted<UTF8Text>> storageOrder{this,defaults.storageOrder};
   Field<std::optional<IntegerTuple>> offset{this};

   // children
   Field<std::optional<std::vector<containers::Values>>> values{this};
   Field<std::optional<std::vector<containers::Array>>> array{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->shape, \
      this->compression, \
      this->symmetry, \
      this->permutation, \
      this->storageOrder, \
      this->offset, \
      this->values, \
      this->array)

   // default, and from fields
   // std::optional replaces Defaulted; this class knows the default(s)
   explicit Array(
      const wrapper<IntegerTuple> &shape = {},
      const wrapper<std::optional<UTF8Text>> &compression = {},
      const wrapper<std::optional<UTF8Text>> &symmetry = {},
      const wrapper<std::optional<UTF8Text>> &permutation = {},
      const wrapper<std::optional<UTF8Text>> &storageOrder = {},
      const wrapper<std::optional<IntegerTuple>> &offset = {},
      const wrapper<std::optional<std::vector<containers::Values>>> &values = {},
      const wrapper<std::optional<std::vector<containers::Array>>> &array = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      shape(this,shape),
      compression(this,compression),
      symmetry(this,symmetry),
      permutation(this,permutation),
      storageOrder(this,defaults.storageOrder,storageOrder),
      offset(this,offset),
      values(this,values),
      array(this,array)
   {
      Component::finish();
   }

   // from node
   explicit Array(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Array(const Array &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Array(Array &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Array &operator=(const Array &) = default;
   Array &operator=(Array &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/containers/Array/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Array

} // namespace containers
} // namespace v2_0
} // namespace try

#endif
