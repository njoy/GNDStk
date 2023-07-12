
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_CONTAINERS_COLUMN
#define TEST_V2_0_CONTAINERS_COLUMN

#include "test/v2.0/key.hpp"

namespace test {
namespace v2_0 {
namespace containers {

// -----------------------------------------------------------------------------
// containers::
// class Column
// -----------------------------------------------------------------------------

class Column :
   public Component<containers::Column>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "containers"; }
   static auto CLASS() { return "Column"; }
   static auto NODENAME() { return "column"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         Integer32{}
            / Meta<>("index") |
         XMLName{}
            / Meta<>("name") |
         std::optional<XMLName>{}
            / Meta<>("unit") |
         std::optional<XMLName>{}
            / Meta<>("types")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "index",
         "name",
         "unit",
         "types"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "index",
         "name",
         "unit",
         "types"
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
   Field<Integer32>
      index{this};
   Field<XMLName>
      name{this};
   Field<std::optional<XMLName>>
      unit{this};
   Field<std::optional<XMLName>>
      types{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->index, \
      this->name, \
      this->unit, \
      this->types \
   )

   // default
   Column() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Column(
      const wrapper<Integer32>
         &index,
      const wrapper<XMLName>
         &name = {},
      const wrapper<std::optional<XMLName>>
         &unit = {},
      const wrapper<std::optional<XMLName>>
         &types = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      index(this,index),
      name(this,name),
      unit(this,unit),
      types(this,types)
   {
      Component::finish();
   }

   // from node
   explicit Column(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Column(const Column &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      index(this,other.index),
      name(this,other.name),
      unit(this,other.unit),
      types(this,other.types)
   {
      Component::finish(other);
   }

   // move
   Column(Column &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      index(this,std::move(other.index)),
      name(this,std::move(other.name)),
      unit(this,std::move(other.unit)),
      types(this,std::move(other.types))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Column &operator=(const Column &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         index = other.index;
         name = other.name;
         unit = other.unit;
         types = other.types;
      }
      return *this;
   }

   // move
   Column &operator=(Column &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         index = std::move(other.index);
         name = std::move(other.name);
         unit = std::move(other.unit);
         types = std::move(other.types);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/containers/Column/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Column

} // namespace containers
} // namespace v2_0
} // namespace test

#endif
