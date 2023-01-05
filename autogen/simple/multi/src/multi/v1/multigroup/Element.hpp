
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

class Element :
   public Component<multigroup::Element>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "multigroup"; }
   static auto CLASS() { return "Element"; }
   static auto FIELD() { return "element"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::optional<std::string>{}
            / Meta<>("symbol") |
         int{}
            / Meta<>("atomic_number") |

         // children
         ++Child<multigroup::Isotope>("isotope") |
         --Child<std::optional<multigroup::Foobar>>("foobar")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

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
      this->comment, \
      this->symbol, \
      this->atomic_number, \
      this->isotope, \
      this->foobar)

   // default
   Element() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Element(
      const wrapper<std::optional<std::string>> &symbol,
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
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      symbol(this,other.symbol),
      atomic_number(this,other.atomic_number),
      isotope(this,other.isotope),
      foobar(this,other.foobar)
   {
      Component::finish(other);
   }

   // move
   Element(Element &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      symbol(this,std::move(other.symbol)),
      atomic_number(this,std::move(other.atomic_number)),
      isotope(this,std::move(other.isotope)),
      foobar(this,std::move(other.foobar))
   {
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
