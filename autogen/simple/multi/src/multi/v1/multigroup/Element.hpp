
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef MULTI_V1_MULTIGROUP_ELEMENT
#define MULTI_V1_MULTIGROUP_ELEMENT

#include "multi/v1/multigroup/Isotope.hpp"
#include "multi/v1/multigroup/Foobar.hpp"

namespace multi {
namespace v1 {
namespace multigroup {

// -----------------------------------------------------------------------------
// multigroup::
// class Element
// -----------------------------------------------------------------------------

class Element : public Component<multigroup::Element> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "multigroup"; }
   static auto CLASS() { return "Element"; }
   static auto FIELD() { return "element"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::optional<std::string>{}
            / Meta<>("symbol") |
         int{}
            / Meta<>("atomic_number") |
         // children
         multigroup::Isotope{}
            / ++Child<>("isotope") |
         std::optional<multigroup::Foobar>{}
            / --Child<>("foobar")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::optional<std::string>> symbol{this};
   Field<int> atomic_number{this};

   // children
   Field<std::vector<multigroup::Isotope>> isotope{this};
   Field<std::optional<multigroup::Foobar>> foobar{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->symbol, \
      this->atomic_number, \
      this->isotope, \
      this->foobar)

   // default, and from fields
   explicit Element(
      const wrapper<std::optional<std::string>> &symbol = {},
      const wrapper<int> &atomic_number = {},
      const wrapper<std::vector<multigroup::Isotope>> &isotope = {},
      const wrapper<std::optional<multigroup::Foobar>> &foobar = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      symbol(this,symbol),
      atomic_number(this,atomic_number),
      isotope(this,isotope),
      foobar(this,foobar)
   {
      Component::finish();
   }

   // from node
   explicit Element(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Element(const Element &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Element(Element &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Element &operator=(const Element &) = default;
   Element &operator=(Element &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "multi/v1/multigroup/Element/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Element

} // namespace multigroup
} // namespace v1
} // namespace multi

#endif