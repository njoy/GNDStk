
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_POPS_BARYONS
#define TEST_V2_0_POPS_BARYONS

#include "test/v2.0/pops/Baryon.hpp"

namespace test {
namespace v2_0 {
namespace pops {

// -----------------------------------------------------------------------------
// pops::
// class Baryons
// -----------------------------------------------------------------------------

class Baryons :
   public Component<pops::Baryons>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "pops"; }
   static auto CLASS() { return "Baryons"; }
   static auto FIELD() { return "baryons"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<std::optional<pops::Baryon>>("baryon")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<std::optional<std::vector<pops::Baryon>>> baryon{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->baryon)

   // default
   Baryons() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Baryons(
      const wrapper<std::optional<std::vector<pops::Baryon>>> &baryon
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      baryon(this,baryon)
   {
      Component::finish();
   }

   // from node
   explicit Baryons(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Baryons(const Baryons &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      baryon(this,other.baryon)
   {
      Component::finish(other);
   }

   // move
   Baryons(Baryons &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      baryon(this,std::move(other.baryon))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Baryons &operator=(const Baryons &) = default;
   Baryons &operator=(Baryons &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/pops/Baryons/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Baryons

} // namespace pops
} // namespace v2_0
} // namespace test

#endif
