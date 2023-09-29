
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_MULTIPLICITYSUMS
#define GNDS_V2_0_GENERAL_MULTIPLICITYSUMS

#include "GNDS/v2.0/general/MultiplicitySum.hpp"

namespace GNDS {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class MultiplicitySums
// -----------------------------------------------------------------------------

class MultiplicitySums :
   public Component<general::MultiplicitySums>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "MultiplicitySums"; }
   static auto NODENAME() { return "multiplicitySums"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<general::MultiplicitySum>
            ("multiplicitySum")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "multiplicitySum"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "multiplicity_sum"
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
   Field<std::vector<general::MultiplicitySum>>
      multiplicitySum{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->multiplicitySum \
   )

   // default
   MultiplicitySums() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit MultiplicitySums(
      const wrapper<std::vector<general::MultiplicitySum>>
         &multiplicitySum
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      multiplicitySum(this,multiplicitySum)
   {
      Component::finish();
   }

   // from node
   explicit MultiplicitySums(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   MultiplicitySums(const MultiplicitySums &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      multiplicitySum(this,other.multiplicitySum)
   {
      Component::finish(other);
   }

   // move
   MultiplicitySums(MultiplicitySums &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      multiplicitySum(this,std::move(other.multiplicitySum))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   MultiplicitySums &operator=(const MultiplicitySums &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         multiplicitySum = other.multiplicitySum;
      }
      return *this;
   }

   // move
   MultiplicitySums &operator=(MultiplicitySums &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         multiplicitySum = std::move(other.multiplicitySum);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDS/v2.0/general/MultiplicitySums/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class MultiplicitySums

} // namespace general
} // namespace v2_0
} // namespace GNDS

#endif
