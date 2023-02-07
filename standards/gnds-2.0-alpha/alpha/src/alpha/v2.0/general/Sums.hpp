
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_SUMS
#define ALPHA_V2_0_GENERAL_SUMS

#include "alpha/v2.0/general/CrossSectionSums.hpp"
#include "alpha/v2.0/general/MultiplicitySums.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Sums
// -----------------------------------------------------------------------------

class Sums :
   public Component<general::Sums>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Sums"; }
   static auto FIELD() { return "sums"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<std::optional<general::CrossSectionSums>>
            ("crossSectionSums") |
         --Child<std::optional<general::MultiplicitySums>>
            ("multiplicitySums")
      ;
   }

public:
   using component_t = Component;
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<std::optional<general::CrossSectionSums>>
      crossSectionSums{this};
   Field<std::optional<general::MultiplicitySums>>
      multiplicitySums{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->crossSectionSums, \
      this->multiplicitySums \
   )

   // default
   Sums() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Sums(
      const wrapper<std::optional<general::CrossSectionSums>>
         &crossSectionSums,
      const wrapper<std::optional<general::MultiplicitySums>>
         &multiplicitySums = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      crossSectionSums(this,crossSectionSums),
      multiplicitySums(this,multiplicitySums)
   {
      Component::finish();
   }

   // from node
   explicit Sums(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Sums(const Sums &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      crossSectionSums(this,other.crossSectionSums),
      multiplicitySums(this,other.multiplicitySums)
   {
      Component::finish(other);
   }

   // move
   Sums(Sums &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      crossSectionSums(this,std::move(other.crossSectionSums)),
      multiplicitySums(this,std::move(other.multiplicitySums))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Sums &operator=(const Sums &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         crossSectionSums = other.crossSectionSums;
         multiplicitySums = other.multiplicitySums;
      }
      return *this;
   }

   // move
   Sums &operator=(Sums &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         crossSectionSums = std::move(other.crossSectionSums);
         multiplicitySums = std::move(other.multiplicitySums);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/Sums/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Sums

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
