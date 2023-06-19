
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/documentation/Date.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_documentation {

// wrapper for documentation::Date
void wrapDate(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = documentation::Date;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Date",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const enums::DateType &,
         const std::string &
      >(),
      py::arg("date_type"),
      py::arg("value"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set dateType
   object.def_property(
      "date_type",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.dateType();
      },
      [](cppCLASS &self, const enums::DateType &value)
      {
         self.dateType() = value;
      },
      cppCLASS::component_t::documentation("date_type").data()
   );

   // get/set value
   object.def_property(
      "value",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.value();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.value() = value;
      },
      cppCLASS::component_t::documentation("value").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_documentation
} // namespace python_v2_0
