
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_TRANSPORT_MULTIPLICITYSUM
#define TEST_V2_0_TRANSPORT_MULTIPLICITYSUM

#include "test/v2.0/transport/Multiplicity.hpp"
#include "test/v2.0/transport/Summands.hpp"

namespace test {
namespace v2_0 {
namespace transport {

// -----------------------------------------------------------------------------
// transport::
// class MultiplicitySum
// -----------------------------------------------------------------------------

class MultiplicitySum :
   public Component<transport::MultiplicitySum>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "transport"; }
   static auto CLASS() { return "MultiplicitySum"; }
   static auto NODENAME() { return "multiplicitySum"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::optional<Integer32>{}
            / Meta<>("ENDF_MT") |
         XMLName{}
            / Meta<>("label") |

         // children
         --Child<transport::Multiplicity>
            ("multiplicity") |
         --Child<transport::Summands>
            ("summands")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "ENDF_MT",
         "label",
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
         "endf_mt",
         "label",
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
   Field<std::optional<Integer32>>
      ENDF_MT{this};
   Field<XMLName>
      label{this};

   // children
   Field<transport::Multiplicity>
      multiplicity{this};
   Field<transport::Summands>
      summands{this};

   // shortcuts
   #define GNDSTK_SHORTCUT(to,name) decltype(to.name) &name = to.name
   GNDSTK_SHORTCUT(summands(),add);
   #undef GNDSTK_SHORTCUT

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->ENDF_MT, \
      this->label, \
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
      const wrapper<std::optional<Integer32>>
         &ENDF_MT,
      const wrapper<XMLName>
         &label = {},
      const wrapper<transport::Multiplicity>
         &multiplicity = {},
      const wrapper<transport::Summands>
         &summands = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      ENDF_MT(this,ENDF_MT),
      label(this,label),
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
      ENDF_MT(this,other.ENDF_MT),
      label(this,other.label),
      multiplicity(this,other.multiplicity),
      summands(this,other.summands)
   {
      Component::finish(other);
   }

   // move
   MultiplicitySum(MultiplicitySum &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      ENDF_MT(this,std::move(other.ENDF_MT)),
      label(this,std::move(other.label)),
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
         ENDF_MT = other.ENDF_MT;
         label = other.label;
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
         ENDF_MT = std::move(other.ENDF_MT);
         label = std::move(other.label);
         multiplicity = std::move(other.multiplicity);
         summands = std::move(other.summands);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/transport/MultiplicitySum/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class MultiplicitySum

} // namespace transport
} // namespace v2_0
} // namespace test

#endif
