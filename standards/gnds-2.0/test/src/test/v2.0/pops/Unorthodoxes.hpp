
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_POPS_UNORTHODOXES
#define TEST_V2_0_POPS_UNORTHODOXES

#include "test/v2.0/pops/Nuclide.hpp"

namespace test {
namespace v2_0 {
namespace pops {

// -----------------------------------------------------------------------------
// pops::
// class Unorthodoxes
// -----------------------------------------------------------------------------

class Unorthodoxes :
   public Component<pops::Unorthodoxes>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "pops"; }
   static auto CLASS() { return "Unorthodoxes"; }
   static auto FIELD() { return "unorthodoxes"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<pops::Nuclide>("unorthodox")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<std::vector<pops::Nuclide>> nuclide{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->nuclide)

   // default
   Unorthodoxes() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Unorthodoxes(
      const wrapper<std::vector<pops::Nuclide>> &nuclide
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      nuclide(this,nuclide)
   {
      Component::finish();
   }

   // from node
   explicit Unorthodoxes(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Unorthodoxes(const Unorthodoxes &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      nuclide(this,other.nuclide)
   {
      Component::finish(other);
   }

   // move
   Unorthodoxes(Unorthodoxes &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      nuclide(this,std::move(other.nuclide))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Unorthodoxes &operator=(const Unorthodoxes &) = default;
   Unorthodoxes &operator=(Unorthodoxes &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/pops/Unorthodoxes/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Unorthodoxes

} // namespace pops
} // namespace v2_0
} // namespace test

#endif
