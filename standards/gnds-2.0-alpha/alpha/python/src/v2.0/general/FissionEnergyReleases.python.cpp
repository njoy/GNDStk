
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/FissionEnergyReleases.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::FissionEnergyReleases
void wrapFissionEnergyReleases(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::FissionEnergyReleases;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "FissionEnergyReleases",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::vector<general::FissionEnergyRelease> &
      >(),
      py::arg("fission_energy_release"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set fissionEnergyRelease
   object.def_property(
      "fission_energy_release",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.fissionEnergyRelease();
      },
      [](cppCLASS &self, const std::vector<general::FissionEnergyRelease> &value)
      {
         self.fissionEnergyRelease() = value;
      },
      cppCLASS::component_t::documentation("fission_energy_release").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
