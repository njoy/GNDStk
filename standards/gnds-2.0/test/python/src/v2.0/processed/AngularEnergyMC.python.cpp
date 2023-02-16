
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/processed/AngularEnergyMC.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_processed {

// wrapper for processed::AngularEnergyMC
void wrapAngularEnergyMC(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = processed::AngularEnergyMC;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "AngularEnergyMC",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const XMLName &,
         const XMLName &,
         const transport::Angular_uncorrelated &,
         const transport::AngularEnergy &
      >(),
      py::arg("label"),
      py::arg("product_frame"),
      py::arg("angular_uncorrelated"),
      py::arg("angular_energy"),
      cppCLASS::component_t::documentation("constructor").data()
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

   // get/set angularEnergy
   object.def_property(
      "angular_energy",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.angularEnergy();
      },
      [](cppCLASS &self, const transport::AngularEnergy &value)
      {
         self.angularEnergy() = value;
      },
      cppCLASS::component_t::documentation("angular_energy").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_processed
} // namespace python_v2_0
