
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/AverageEnergies.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::AverageEnergies
void wrapAverageEnergies(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::AverageEnergies;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "AverageEnergies",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::vector<general::AverageEnergy> &
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
      [](cppCLASS &self, const std::vector<general::AverageEnergy> &value)
      {
         self.averageEnergy() = value;
      },
      cppCLASS::component_t::documentation("average_energy").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
