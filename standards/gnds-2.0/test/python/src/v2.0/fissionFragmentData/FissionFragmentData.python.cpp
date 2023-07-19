
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/fissionFragmentData/FissionFragmentData.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_fissionFragmentData {

// wrapper for fissionFragmentData::FissionFragmentData
void wrapFissionFragmentData(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = fissionFragmentData::FissionFragmentData;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "FissionFragmentData",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<fissionFragmentData::DelayedNeutrons> &,
         const std::optional<fissionTransport::FissionEnergyReleased> &,
         const std::optional<fpy::ProductYields> &
      >(),
      py::arg("delayed_neutrons") = std::nullopt,
      py::arg("fission_energy_released") = std::nullopt,
      py::arg("product_yields") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set delayedNeutrons
   object.def_property(
      "delayed_neutrons",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.delayedNeutrons();
      },
      [](cppCLASS &self, const std::optional<fissionFragmentData::DelayedNeutrons> &value)
      {
         self.delayedNeutrons() = value;
      },
      cppCLASS::component_t::documentation("delayed_neutrons").data()
   );

   // get/set fissionEnergyReleased
   object.def_property(
      "fission_energy_released",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.fissionEnergyReleased();
      },
      [](cppCLASS &self, const std::optional<fissionTransport::FissionEnergyReleased> &value)
      {
         self.fissionEnergyReleased() = value;
      },
      cppCLASS::component_t::documentation("fission_energy_released").data()
   );

   // get/set productYields
   object.def_property(
      "product_yields",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.productYields();
      },
      [](cppCLASS &self, const std::optional<fpy::ProductYields> &value)
      {
         self.productYields() = value;
      },
      cppCLASS::component_t::documentation("product_yields").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_fissionFragmentData
} // namespace python_v2_0
