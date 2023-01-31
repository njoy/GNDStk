
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_MEAN_MULTIPLICITYSUM
#define ALPHA_V2_0_MEAN_MULTIPLICITYSUM

#include "alpha/v2.0/common/Multiplicity.hpp"
#include "alpha/v2.0/mean/Summands.hpp"

namespace alpha {
namespace v2_0 {
namespace mean {

// -----------------------------------------------------------------------------
// mean::
// class MultiplicitySum
// -----------------------------------------------------------------------------

class MultiplicitySum :
   public Component<mean::MultiplicitySum>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "mean"; }
   static auto CLASS() { return "MultiplicitySum"; }
   static auto FIELD() { return "multiplicitySum"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("label") |
         int{}
            / Meta<>("ENDF_MT") |

         // children
         --Child<common::Multiplicity>("multiplicity") |
         --Child<mean::Summands>("summands")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string> label{this};
   Field<int> ENDF_MT{this};

   // children
   Field<common::Multiplicity> multiplicity{this};
   Field<mean::Summands> summands{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->label, \
      this->ENDF_MT, \
      this->multiplicity, \
      this->summands)

   // default
   MultiplicitySum() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit MultiplicitySum(
      const wrapper<std::string> &label,
      const wrapper<int> &ENDF_MT = {},
      const wrapper<common::Multiplicity> &multiplicity = {},
      const wrapper<mean::Summands> &summands = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      ENDF_MT(this,ENDF_MT),
      multiplicity(this,multiplicity),
      summands(this,summands)
   {
      Component::finish();
   }

   // from node
   explicit MultiplicitySum(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   MultiplicitySum(const MultiplicitySum &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      ENDF_MT(this,other.ENDF_MT),
      multiplicity(this,other.multiplicity),
      summands(this,other.summands)
   {
      Component::finish(other);
   }

   // move
   MultiplicitySum(MultiplicitySum &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      ENDF_MT(this,std::move(other.ENDF_MT)),
      multiplicity(this,std::move(other.multiplicity)),
      summands(this,std::move(other.summands))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   MultiplicitySum &operator=(const MultiplicitySum &) = default;
   MultiplicitySum &operator=(MultiplicitySum &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/mean/MultiplicitySum/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class MultiplicitySum

} // namespace mean
} // namespace v2_0
} // namespace alpha

#endif
