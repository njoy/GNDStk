
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_FISSIONFRAGMENTDATA_DELAYEDNEUTRONS
#define TEST_V2_0_FISSIONFRAGMENTDATA_DELAYEDNEUTRONS

#include "test/v2.0/fissionFragmentData/DelayedNeutron.hpp"

namespace test {
namespace v2_0 {
namespace fissionFragmentData {

// -----------------------------------------------------------------------------
// fissionFragmentData::
// class DelayedNeutrons
// -----------------------------------------------------------------------------

class DelayedNeutrons :
   public Component<fissionFragmentData::DelayedNeutrons>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "fissionFragmentData"; }
   static auto CLASS() { return "DelayedNeutrons"; }
   static auto NODENAME() { return "delayedNeutrons"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<fissionFragmentData::DelayedNeutron>
            ("delayedNeutron")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "delayedNeutron"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "delayed_neutron"
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
   Field<std::vector<fissionFragmentData::DelayedNeutron>>
      delayedNeutron{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->delayedNeutron \
   )

   // default
   DelayedNeutrons() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit DelayedNeutrons(
      const wrapper<std::vector<fissionFragmentData::DelayedNeutron>>
         &delayedNeutron
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      delayedNeutron(this,delayedNeutron)
   {
      Component::finish();
   }

   // from node
   explicit DelayedNeutrons(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   DelayedNeutrons(const DelayedNeutrons &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      delayedNeutron(this,other.delayedNeutron)
   {
      Component::finish(other);
   }

   // move
   DelayedNeutrons(DelayedNeutrons &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      delayedNeutron(this,std::move(other.delayedNeutron))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   DelayedNeutrons &operator=(const DelayedNeutrons &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         delayedNeutron = other.delayedNeutron;
      }
      return *this;
   }

   // move
   DelayedNeutrons &operator=(DelayedNeutrons &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         delayedNeutron = std::move(other.delayedNeutron);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/fissionFragmentData/DelayedNeutrons/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class DelayedNeutrons

} // namespace fissionFragmentData
} // namespace v2_0
} // namespace test

#endif
