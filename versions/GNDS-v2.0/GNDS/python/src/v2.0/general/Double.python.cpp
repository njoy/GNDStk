
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/Double.hpp"
#include "definitions.hpp"

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::Double
void wrapDouble(pybind11::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::Double;

   // create the Python object
   pybind11::class_<cppCLASS> object(
      module, "Double",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      pybind11::init<
         const std::string &,
         const double &,
         const std::optional<std::string> &,
         const std::optional<general::Uncertainty> &
      >(),
      pybind11::arg("label"),
      pybind11::arg("value"),
      pybind11::arg("unit") = std::nullopt,
      pybind11::arg("uncertainty") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set label
   object.def_property(
      "label",
      [](const cppCLASS &self) -> decltype(auto)
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
      [](cppCLASS &self, const std::optional<std::string> &value)
      {
         self.unit() = value;
      },
      cppCLASS::component_t::documentation("unit").data()
   );

   // get/set uncertainty
   object.def_property(
      "uncertainty",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.uncertainty();
      },
      [](cppCLASS &self, const std::optional<general::Uncertainty> &value)
      {
         self.uncertainty() = value;
      },
      cppCLASS::component_t::documentation("uncertainty").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS
