
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_TABLE
#define GNDS_V2_0_GENERAL_TABLE

#include "GNDS/v2.0/general/ColumnHeaders.hpp"
#include "GNDS/v2.0/general/Data.hpp"

namespace GNDS {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Table
// -----------------------------------------------------------------------------

class Table :
   public Component<general::Table>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Table"; }
   static auto NODENAME() { return "table"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         int{}
            / Meta<>("rows") |
         int{}
            / Meta<>("columns") |

         // children
         --Child<general::ColumnHeaders>
            ("columnHeaders") |
         --Child<general::Data>
            ("data")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "rows",
         "columns",
         "columnHeaders",
         "data"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "rows",
         "columns",
         "column_headers",
         "data"
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
   Field<int>
      rows{this};
   Field<int>
      columns{this};

   // children
   Field<general::ColumnHeaders>
      columnHeaders{this};
   Field<general::Data>
      data{this};

   // shortcuts
   #define NJOY_GNDSTK_SHORTCUT(to,name) decltype(to.name) &name = to.name
   NJOY_GNDSTK_SHORTCUT(columnHeaders(),column);
   #undef NJOY_GNDSTK_SHORTCUT

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->rows, \
      this->columns, \
      this->columnHeaders, \
      this->data \
   )

   // default
   Table() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Table(
      const wrapper<int>
         &rows,
      const wrapper<int>
         &columns = {},
      const wrapper<general::ColumnHeaders>
         &columnHeaders = {},
      const wrapper<general::Data>
         &data = {}
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      rows(this,rows),
      columns(this,columns),
      columnHeaders(this,columnHeaders),
      data(this,data)
   {
      Component::finish();
   }

   // from node
   explicit Table(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Table(const Table &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      rows(this,other.rows),
      columns(this,other.columns),
      columnHeaders(this,other.columnHeaders),
      data(this,other.data)
   {
      Component::finish(other);
   }

   // move
   Table(Table &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      rows(this,std::move(other.rows)),
      columns(this,std::move(other.columns)),
      columnHeaders(this,std::move(other.columnHeaders)),
      data(this,std::move(other.data))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Table &operator=(const Table &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         rows = other.rows;
         columns = other.columns;
         columnHeaders = other.columnHeaders;
         data = other.data;
      }
      return *this;
   }

   // move
   Table &operator=(Table &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         rows = std::move(other.rows);
         columns = std::move(other.columns);
         columnHeaders = std::move(other.columnHeaders);
         data = std::move(other.data);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDS/v2.0/general/Table/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class Table

} // namespace general
} // namespace v2_0
} // namespace GNDS

#endif