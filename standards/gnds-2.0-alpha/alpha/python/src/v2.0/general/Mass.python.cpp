
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Mass.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::Mass
void wrapMass(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::Mass;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Mass",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<double> &,
         const std::optional<std::string> &,
         const std::optional<general::Double> &
      >(),
      py::arg("value") = std::nullopt,
      py::arg("unit") = std::nullopt,
      py::arg("double") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set value
   object.def_property(
      "value",
      [](const cppCLASS &self)
      {
         return self.value();
      },
      [](cppCLASS &self, const std::optional<double> &value)
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
      [](cppCLASS &self, const std::optional<std::string> &value)
      {
         self.unit() = value;
      },
      cppCLASS::component_t::documentation("unit").data()
   );

   // get/set Double
   object.def_property(
      "double",
      [](const cppCLASS &self)
      {
         return self.Double();
      },
      [](cppCLASS &self, const std::optional<general::Double> &value)
      {
         self.Double() = value;
      },
      cppCLASS::component_t::documentation("double").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
