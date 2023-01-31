
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_MEAN_BACKGROUND
#define ALPHA_V2_0_MEAN_BACKGROUND

#include "alpha/v2.0/mean/ResolvedRegion.hpp"
#include "alpha/v2.0/mean/FastRegion.hpp"
#include "alpha/v2.0/mean/UnresolvedRegion.hpp"

namespace alpha {
namespace v2_0 {
namespace mean {

// -----------------------------------------------------------------------------
// mean::
// class Background
// -----------------------------------------------------------------------------

class Background :
   public Component<mean::Background>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "mean"; }
   static auto CLASS() { return "Background"; }
   static auto FIELD() { return "background"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<std::optional<mean::ResolvedRegion>>("resolvedRegion") |
         --Child<mean::FastRegion>("fastRegion") |
         --Child<std::optional<mean::UnresolvedRegion>>("unresolvedRegion")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<std::optional<mean::ResolvedRegion>> resolvedRegion{this};
   Field<mean::FastRegion> fastRegion{this};
   Field<std::optional<mean::UnresolvedRegion>> unresolvedRegion{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->resolvedRegion, \
      this->fastRegion, \
      this->unresolvedRegion)

   // default
   Background() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Background(
      const wrapper<std::optional<mean::ResolvedRegion>> &resolvedRegion,
      const wrapper<mean::FastRegion> &fastRegion = {},
      const wrapper<std::optional<mean::UnresolvedRegion>> &unresolvedRegion = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      resolvedRegion(this,resolvedRegion),
      fastRegion(this,fastRegion),
      unresolvedRegion(this,unresolvedRegion)
   {
      Component::finish();
   }

   // from node
   explicit Background(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Background(const Background &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      resolvedRegion(this,other.resolvedRegion),
      fastRegion(this,other.fastRegion),
      unresolvedRegion(this,other.unresolvedRegion)
   {
      Component::finish(other);
   }

   // move
   Background(Background &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      resolvedRegion(this,std::move(other.resolvedRegion)),
      fastRegion(this,std::move(other.fastRegion)),
      unresolvedRegion(this,std::move(other.unresolvedRegion))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Background &operator=(const Background &) = default;
   Background &operator=(Background &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/mean/Background/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Background

} // namespace mean
} // namespace v2_0
} // namespace alpha

#endif
