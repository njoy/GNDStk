
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "gnds/v2.0/general/Date.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::Date
void wrapDate(py::module &module)
{
   using namespace gnds;
   using namespace gnds::v2_0;

   // type aliases
   using cppCLASS = general::Date;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Date",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::string &,
         const std::string &
      >(),
      py::arg("value"),
      py::arg("date_type"),
      cppCLASS::component_t::documentation("constructor").data()
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

   // get/set dateType
   object.def_property(
      "date_type",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.dateType();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.dateType() = value;
      },
      cppCLASS::component_t::documentation("date_type").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
