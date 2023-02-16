
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_RESONANCES_RESONANCEPARAMETERS
#define TEST_V2_0_RESONANCES_RESONANCEPARAMETERS

#include "test/v2.0/containers/Table.hpp"

namespace test {
namespace v2_0 {
namespace resonances {

// -----------------------------------------------------------------------------
// resonances::
// class ResonanceParameters
// -----------------------------------------------------------------------------

class ResonanceParameters :
   public Component<resonances::ResonanceParameters>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "resonances"; }
   static auto CLASS() { return "ResonanceParameters"; }
   static auto NODENAME() { return "resonanceParameters"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<containers::Table>
            ("table")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "table"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "table"
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
   Field<containers::Table>
      table{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->table \
   )

   // default
   ResonanceParameters() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ResonanceParameters(
      const wrapper<containers::Table>
         &table
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      table(this,table)
   {
      Component::finish();
   }

   // from node
   explicit ResonanceParameters(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ResonanceParameters(const ResonanceParameters &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      table(this,other.table)
   {
      Component::finish(other);
   }

   // move
   ResonanceParameters(ResonanceParameters &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      table(this,std::move(other.table))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   ResonanceParameters &operator=(const ResonanceParameters &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         table = other.table;
      }
      return *this;
   }

   // move
   ResonanceParameters &operator=(ResonanceParameters &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         table = std::move(other.table);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/resonances/ResonanceParameters/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ResonanceParameters

} // namespace resonances
} // namespace v2_0
} // namespace test

#endif
