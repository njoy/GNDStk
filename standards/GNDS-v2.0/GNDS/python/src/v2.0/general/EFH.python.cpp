
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/EFH.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::EFH
void wrapEFH(py::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::EFH;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "EFH",
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