
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_MULTIPLICITYSUM
#define ALPHA_V2_0_GENERAL_MULTIPLICITYSUM

#include "alpha/v2.0/general/Multiplicity.hpp"
#include "alpha/v2.0/general/Summands.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class MultiplicitySum
// -----------------------------------------------------------------------------

class MultiplicitySum :
   public Component<general::MultiplicitySum>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
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
         --Child<general::Multiplicity>
            ("multiplicity") |
         --Child<general::Summands>
            ("summands")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "ENDF_MT",
         "multiplicity",
         "summands"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "endf_mt",
         "multiplicity",
         "summands"
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

   // metadata
   Field<std::string>
      label{this};
   Field<int>
      ENDF_MT{this};

   // children
   Field<general::Multiplicity>
      multiplicity{this};
   Field<general::Summands>
      summands{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->ENDF_MT, \
      this->multiplicity, \
      this->summands \
   )

   // default
   MultiplicitySum() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit MultiplicitySum(
      const wrapper<std::string>
         &label,
      const wrapper<int>
         &ENDF_MT = {},
      const wrapper<general::Multiplicity>
         &multiplicity = {},
      const wrapper<general::Summands>
         &summands = {}
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

   // copy
   MultiplicitySum &operator=(const MultiplicitySum &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         ENDF_MT = other.ENDF_MT;
         multiplicity = other.multiplicity;
         summands = other.summands;
      }
      return *this;
   }

   // move
   MultiplicitySum &operator=(MultiplicitySum &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         ENDF_MT = std::move(other.ENDF_MT);
         multiplicity = std::move(other.multiplicity);
         summands = std::move(other.summands);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/MultiplicitySum/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class MultiplicitySum

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
