
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Yields.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::Yields
void wrapYields(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::Yields;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Yields",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const reduced::Nuclides &,
         const general::Values &,
         const general::Uncertainty &
      >(),
      py::arg("nuclides"),
      py::arg("values"),
      py::arg("uncertainty"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set nuclides
   object.def_property(
      "nuclides",
      [](const cppCLASS &self)
      {
         return self.nuclides();
      },
      [](cppCLASS &self, const reduced::Nuclides &value)
      {
         self.nuclides() = value;
      },
      cppCLASS::component_t::documentation("nuclides").data()
   );

   // get/set values
   object.def_property(
      "values",
      [](const cppCLASS &self)
      {
         return self.values();
      },
      [](cppCLASS &self, const general::Values &value)
      {
         self.values() = value;
      },
      cppCLASS::component_t::documentation("values").data()
   );

   // get/set uncertainty
   object.def_property(
      "uncertainty",
      [](const cppCLASS &self)
      {
         return self.uncertainty();
      },
      [](cppCLASS &self, const general::Uncertainty &value)
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
