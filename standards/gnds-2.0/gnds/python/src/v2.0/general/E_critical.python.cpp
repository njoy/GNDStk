
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "gnds/v2.0/general/E_critical.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::E_critical
void wrapE_critical(py::module &module)
{
   using namespace gnds;
   using namespace gnds::v2_0;

   // type aliases
   using cppCLASS = general::E_critical;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "E_critical",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const double &,
         const std::string &
      >(),
      py::arg("value"),
      py::arg("unit"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set value
   object.def_property(
      "value",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.value();
      },
      [](cppCLASS &self, const double &value)
      {
         self.value() = value;
      },
      cppCLASS::component_t::documentation("value").data()
   );

   // get/set unit
   object.def_property(
      "unit",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.unit();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.unit() = value;
      },
      cppCLASS::component_t::documentation("unit").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
