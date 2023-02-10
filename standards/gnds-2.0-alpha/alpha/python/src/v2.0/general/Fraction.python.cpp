
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Fraction.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::Fraction
void wrapFraction(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::Fraction;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Fraction",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::string &,
         const std::string &,
         const std::string &
      >(),
      py::arg("label"),
      py::arg("value"),
      py::arg("unit"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set label
   object.def_property(
      "label",
      [](const cppCLASS &self)
      {
         return self.label();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.label() = value;
      },
      cppCLASS::component_t::documentation("label").data()
   );

   // get/set value
   object.def_property(
      "value",
      [](const cppCLASS &self)
      {
         return self.value();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.value() = value;
      },
      cppCLASS::component_t::documentation("value").data()
   );

   // get/set unit
   object.def_property(
      "unit",
      [](const cppCLASS &self)
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
