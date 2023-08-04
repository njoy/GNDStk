
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/Table.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::Table
void wrapTable(py::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::Table;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Table",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const int &,
         const int &,
         const general::ColumnHeaders &,
         const general::Data &
      >(),
      py::arg("rows"),
      py::arg("columns"),
      py::arg("column_headers"),
      py::arg("data"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set rows
   object.def_property(
      "rows",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.rows();
      },
      [](cppCLASS &self, const int &value)
      {
         self.rows() = value;
      },
      cppCLASS::component_t::documentation("rows").data()
   );

   // get/set columns
   object.def_property(
      "columns",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.columns();
      },
      [](cppCLASS &self, const int &value)
      {
         self.columns() = value;
      },
      cppCLASS::component_t::documentation("columns").data()
   );

   // get/set columnHeaders
   object.def_property(
      "column_headers",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.columnHeaders();
      },
      [](cppCLASS &self, const general::ColumnHeaders &value)
      {
         self.columnHeaders() = value;
      },
      cppCLASS::component_t::documentation("column_headers").data()
   );

   // get/set data
   object.def_property(
      "data",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.data();
      },
      [](cppCLASS &self, const general::Data &value)
      {
         self.data() = value;
      },
      cppCLASS::component_t::documentation("data").data()
   );

   // shortcut: get/set column
   object.def_property(
      "column",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.column();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.column())> &value)
      {
         self.column() = value;
      },
      cppCLASS::component_t::documentation("column").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS
