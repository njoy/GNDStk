
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/pops/AverageEnergies.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_pops {

// wrapper for pops::AverageEnergies
void wrapAverageEnergies(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = pops::AverageEnergies;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "AverageEnergies",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::vector<pops::AverageEnergy> &
      >(),
      py::arg("average_energy"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set averageEnergy
   object.def_property(
      "average_energy",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.averageEnergy();
      },
      [](cppCLASS &self, const std::vector<pops::AverageEnergy> &value)
      {
         self.averageEnergy() = value;
      },
      cppCLASS::component_t::documentation("average_energy").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_pops
} // namespace python_v2_0
