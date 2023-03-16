
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/transport/Uncorrelated.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_transport {

// wrapper for transport::Uncorrelated
void wrapUncorrelated(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = transport::Uncorrelated;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Uncorrelated",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<XMLName> &,
         const XMLName &,
         const transport::Angular_uncorrelated &,
         const transport::Energy_uncorrelated &
      >(),
      py::arg("label") = std::nullopt,
      py::arg("product_frame"),
      py::arg("angular_uncorrelated"),
      py::arg("energy_uncorrelated"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set label
   object.def_property(
      "label",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.label();
      },
      [](cppCLASS &self, const std::optional<XMLName> &value)
      {
         self.label() = value;
      },
      cppCLASS::component_t::documentation("label").data()
   );

   // get/set productFrame
   object.def_property(
      "product_frame",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.productFrame();
      },
      [](cppCLASS &self, const XMLName &value)
      {
         self.productFrame() = value;
      },
      cppCLASS::component_t::documentation("product_frame").data()
   );

   // get/set angular_uncorrelated
   object.def_property(
      "angular_uncorrelated",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.angular_uncorrelated();
      },
      [](cppCLASS &self, const transport::Angular_uncorrelated &value)
      {
         self.angular_uncorrelated() = value;
      },
      cppCLASS::component_t::documentation("angular_uncorrelated").data()
   );

   // get/set energy_uncorrelated
   object.def_property(
      "energy_uncorrelated",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.energy_uncorrelated();
      },
      [](cppCLASS &self, const transport::Energy_uncorrelated &value)
      {
         self.energy_uncorrelated() = value;
      },
      cppCLASS::component_t::documentation("energy_uncorrelated").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_transport
} // namespace python_v2_0
