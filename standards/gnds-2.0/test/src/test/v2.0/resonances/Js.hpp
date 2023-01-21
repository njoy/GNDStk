
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_RESONANCES_JS
#define TEST_V2_0_RESONANCES_JS

#include "test/v2.0/resonances/J.hpp"

namespace test {
namespace v2_0 {
namespace resonances {

// -----------------------------------------------------------------------------
// resonances::
// class Js
// -----------------------------------------------------------------------------

class Js :
   public Component<resonances::Js>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "resonances"; }
   static auto CLASS() { return "Js"; }
   static auto FIELD() { return "Js"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<resonances::J>("J")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<std::vector<resonances::J>> J{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->J)

   // default
   Js() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Js(
      const wrapper<std::vector<resonances::J>> &J
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      J(this,J)
   {
      Component::finish();
   }

   // from node
   explicit Js(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Js(const Js &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      J(this,other.J)
   {
      Component::finish(other);
   }

   // move
   Js(Js &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      J(this,std::move(other.J))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Js &operator=(const Js &) = default;
   Js &operator=(Js &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/resonances/Js/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Js

} // namespace resonances
} // namespace v2_0
} // namespace test

#endif
