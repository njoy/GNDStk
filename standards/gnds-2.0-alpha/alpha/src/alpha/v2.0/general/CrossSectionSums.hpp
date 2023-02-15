
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_CROSSSECTIONSUMS
#define ALPHA_V2_0_GENERAL_CROSSSECTIONSUMS

#include "alpha/v2.0/general/CrossSectionSum.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class CrossSectionSums
// -----------------------------------------------------------------------------

class CrossSectionSums :
   public Component<general::CrossSectionSums>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "CrossSectionSums"; }
   static auto FIELD() { return "crossSectionSums"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<general::CrossSectionSum>
            ("crossSectionSum")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "crossSectionSum"
      };
      return names;
   }

   // ------------------------
   // Public interface
   // ------------------------

public:

   using component_t = Component;
   using Component::construct;

   // ------------------------
   // Data members
   // ------------------------

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<std::vector<general::CrossSectionSum>>
      crossSectionSum{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->crossSectionSum \
   )

   // default
   CrossSectionSums() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit CrossSectionSums(
      const wrapper<std::vector<general::CrossSectionSum>>
         &crossSectionSum
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      crossSectionSum(this,crossSectionSum)
   {
      Component::finish();
   }

   // from node
   explicit CrossSectionSums(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   CrossSectionSums(const CrossSectionSums &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      crossSectionSum(this,other.crossSectionSum)
   {
      Component::finish(other);
   }

   // move
   CrossSectionSums(CrossSectionSums &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      crossSectionSum(this,std::move(other.crossSectionSum))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   CrossSectionSums &operator=(const CrossSectionSums &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         crossSectionSum = other.crossSectionSum;
      }
      return *this;
   }

   // move
   CrossSectionSums &operator=(CrossSectionSums &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         crossSectionSum = std::move(other.crossSectionSum);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/CrossSectionSums/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class CrossSectionSums

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
