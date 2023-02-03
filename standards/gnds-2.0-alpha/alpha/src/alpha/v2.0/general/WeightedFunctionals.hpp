
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_WEIGHTEDFUNCTIONALS
#define ALPHA_V2_0_GENERAL_WEIGHTEDFUNCTIONALS

#include "alpha/v2.0/general/Weighted.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class WeightedFunctionals
// -----------------------------------------------------------------------------

class WeightedFunctionals :
   public Component<general::WeightedFunctionals>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "WeightedFunctionals"; }
   static auto FIELD() { return "weightedFunctionals"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<general::Weighted>
            ("weighted")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<std::vector<general::Weighted>>
      weighted{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->weighted)

   // default
   WeightedFunctionals() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit WeightedFunctionals(
      const wrapper<std::vector<general::Weighted>>
         &weighted
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      weighted(this,weighted)
   {
      Component::finish();
   }

   // from node
   explicit WeightedFunctionals(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   WeightedFunctionals(const WeightedFunctionals &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      weighted(this,other.weighted)
   {
      Component::finish(other);
   }

   // move
   WeightedFunctionals(WeightedFunctionals &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      weighted(this,std::move(other.weighted))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   WeightedFunctionals &operator=(const WeightedFunctionals &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         weighted = other.weighted;
      }
      return *this;
   }

   // move
   WeightedFunctionals &operator=(WeightedFunctionals &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         weighted = std::move(other.weighted);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/WeightedFunctionals/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class WeightedFunctionals

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
