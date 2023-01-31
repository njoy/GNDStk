
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_COMMON_NUCLIDES
#define ALPHA_V2_0_COMMON_NUCLIDES

#include "alpha/v2.0/common/Nuclide.hpp"

namespace alpha {
namespace v2_0 {
namespace common {

// -----------------------------------------------------------------------------
// common::
// class Nuclides
// -----------------------------------------------------------------------------

class Nuclides :
   public Component<common::Nuclides>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "common"; }
   static auto CLASS() { return "Nuclides"; }
   static auto FIELD() { return "nuclides"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<common::Nuclide>("nuclide")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<std::vector<common::Nuclide>> nuclide{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->nuclide)

   // default
   Nuclides() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Nuclides(
      const wrapper<std::vector<common::Nuclide>> &nuclide
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      nuclide(this,nuclide)
   {
      Component::finish();
   }

   // from node
   explicit Nuclides(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Nuclides(const Nuclides &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      nuclide(this,other.nuclide)
   {
      Component::finish(other);
   }

   // move
   Nuclides(Nuclides &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      nuclide(this,std::move(other.nuclide))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Nuclides &operator=(const Nuclides &) = default;
   Nuclides &operator=(Nuclides &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/common/Nuclides/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Nuclides

} // namespace common
} // namespace v2_0
} // namespace alpha

#endif
