
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_POPS_CONFIGURATIONS
#define TEST_V2_0_POPS_CONFIGURATIONS

#include "test/v2.0/pops/Configuration.hpp"

namespace test {
namespace v2_0 {
namespace pops {

// -----------------------------------------------------------------------------
// pops::
// class Configurations
// -----------------------------------------------------------------------------

class Configurations :
   public Component<pops::Configurations>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "pops"; }
   static auto CLASS() { return "Configurations"; }
   static auto NODENAME() { return "configurations"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<pops::Configuration>
            ("configuration")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "configuration"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "configuration"
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
   Field<std::vector<pops::Configuration>>
      configuration{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->configuration \
   )

   // default
   Configurations() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Configurations(
      const wrapper<std::vector<pops::Configuration>>
         &configuration
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      configuration(this,configuration)
   {
      Component::finish();
   }

   // from node
   explicit Configurations(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Configurations(const Configurations &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      configuration(this,other.configuration)
   {
      Component::finish(other);
   }

   // move
   Configurations(Configurations &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      configuration(this,std::move(other.configuration))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Configurations &operator=(const Configurations &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         configuration = other.configuration;
      }
      return *this;
   }

   // move
   Configurations &operator=(Configurations &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         configuration = std::move(other.configuration);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/pops/Configurations/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Configurations

} // namespace pops
} // namespace v2_0
} // namespace test

#endif
