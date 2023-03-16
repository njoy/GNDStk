
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/tsl/S_table.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_tsl {

// wrapper for tsl::S_table
void wrapS_table(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = tsl::S_table;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "S_table",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const containers::Gridded2d &
      >(),
      py::arg("gridded2d"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set gridded2d
   object.def_property(
      "gridded2d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.gridded2d();
      },
      [](cppCLASS &self, const containers::Gridded2d &value)
      {
         self.gridded2d() = value;
      },
      cppCLASS::component_t::documentation("gridded2d").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_tsl
} // namespace python_v2_0
