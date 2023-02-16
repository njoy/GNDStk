
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/styles/HeatedMultiGroup.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_styles {

// wrapper for styles::HeatedMultiGroup
void wrapHeatedMultiGroup(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = styles::HeatedMultiGroup;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "HeatedMultiGroup",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::string &,
         const XMLName &,
         const XMLName &,
         const styles::Transportables &,
         const styles::Flux &,
         const styles::InverseSpeed &,
         const std::optional<documentation::Documentation> &
      >(),
      py::arg("date"),
      py::arg("derived_from"),
      py::arg("label"),
      py::arg("transportables"),
      py::arg("flux"),
      py::arg("inverse_speed"),
      py::arg("documentation") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set date
   object.def_property(
      "date",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.date();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.date() = value;
      },
      cppCLASS::component_t::documentation("date").data()
   );

   // get/set derivedFrom
   object.def_property(
      "derived_from",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.derivedFrom();
      },
      [](cppCLASS &self, const XMLName &value)
      {
         self.derivedFrom() = value;
      },
      cppCLASS::component_t::documentation("derived_from").data()
   );

   // get/set label
   object.def_property(
      "label",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.label();
      },
      [](cppCLASS &self, const XMLName &value)
      {
         self.label() = value;
      },
      cppCLASS::component_t::documentation("label").data()
   );

   // get/set transportables
   object.def_property(
      "transportables",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.transportables();
      },
      [](cppCLASS &self, const styles::Transportables &value)
      {
         self.transportables() = value;
      },
      cppCLASS::component_t::documentation("transportables").data()
   );

   // get/set flux
   object.def_property(
      "flux",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.flux();
      },
      [](cppCLASS &self, const styles::Flux &value)
      {
         self.flux() = value;
      },
      cppCLASS::component_t::documentation("flux").data()
   );

   // get/set inverseSpeed
   object.def_property(
      "inverse_speed",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.inverseSpeed();
      },
      [](cppCLASS &self, const styles::InverseSpeed &value)
      {
         self.inverseSpeed() = value;
      },
      cppCLASS::component_t::documentation("inverse_speed").data()
   );

   // get/set documentation
   object.def_property(
      "documentation",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.documentation();
      },
      [](cppCLASS &self, const std::optional<documentation::Documentation> &value)
      {
         self.documentation() = value;
      },
      cppCLASS::component_t::documentation("documentation").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_styles
} // namespace python_v2_0
