
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_CONTAINERS_TABLE
#define TEST_V2_0_CONTAINERS_TABLE

#include "test/v2.0/containers/ColumnHeaders.hpp"
#include "test/v2.0/containers/Data.hpp"

namespace test {
namespace v2_0 {
namespace containers {

// -----------------------------------------------------------------------------
// containers::
// class Table
// -----------------------------------------------------------------------------

class Table : public Component<containers::Table> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "containers"; }
   static auto CLASS() { return "Table"; }
   static auto FIELD() { return "table"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         Integer32{}
            / Meta<>("columns") |
         Integer32{}
            / Meta<>("rows") |
         Defaulted<XMLName>{"row-major"}
            / Meta<>("storageOrder") |
         // children
         containers::ColumnHeaders{}
            / --Child<>("columnHeaders") |
         containers::Data{}
            / --Child<>("data")
      ;
   }

public:
   using Component::construct;

   // defaults
   static inline const struct Defaults {
      static inline const XMLName storageOrder = "row-major";
   } defaults;

   // metadata
   Field<Integer32> columns{this};
   Field<Integer32> rows{this};
   Field<Defaulted<XMLName>> storageOrder{this,defaults.storageOrder};

   // children
   Field<containers::ColumnHeaders> columnHeaders{this};
   Field<containers::Data> data{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->columns, \
      this->rows, \
      this->storageOrder, \
      this->columnHeaders, \
      this->data)

   // default, and from fields
   // std::optional replaces Defaulted; this class knows the default(s)
   explicit Table(
      const wrapper<Integer32> &columns = {},
      const wrapper<Integer32> &rows = {},
      const wrapper<std::optional<XMLName>> &storageOrder = {},
      const wrapper<containers::ColumnHeaders> &columnHeaders = {},
      const wrapper<containers::Data> &data = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      columns(this,columns),
      rows(this,rows),
      storageOrder(this,defaults.storageOrder,storageOrder),
      columnHeaders(this,columnHeaders),
      data(this,data)
   {
      Component::finish();
   }

   // from node
   explicit Table(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Table(const Table &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Table(Table &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Table &operator=(const Table &) = default;
   Table &operator=(Table &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/containers/Table/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Table

} // namespace containers
} // namespace v2_0
} // namespace test

#endif
