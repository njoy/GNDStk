
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_MEAN_LS
#define ALPHA_V2_0_MEAN_LS

#include "alpha/v2.0/mean/L.hpp"

namespace alpha {
namespace v2_0 {
namespace mean {

// -----------------------------------------------------------------------------
// mean::
// class Ls
// -----------------------------------------------------------------------------

class Ls :
   public Component<mean::Ls>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "mean"; }
   static auto CLASS() { return "Ls"; }
   static auto FIELD() { return "Ls"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<mean::L>("L")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<std::vector<mean::L>> L{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->L)

   // default
   Ls() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Ls(
      const wrapper<std::vector<mean::L>> &L
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      L(this,L)
   {
      Component::finish();
   }

   // from node
   explicit Ls(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Ls(const Ls &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      L(this,other.L)
   {
      Component::finish(other);
   }

   // move
   Ls(Ls &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      L(this,std::move(other.L))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Ls &operator=(const Ls &) = default;
   Ls &operator=(Ls &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/mean/Ls/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Ls

} // namespace mean
} // namespace v2_0
} // namespace alpha

#endif
