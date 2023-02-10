
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Nuclides.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::Nuclides
void wrapNuclides(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::Nuclides;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Nuclides",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::vector<general::Nuclide> &
      >(),
      py::arg("nuclide"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set nuclide
   object.def_property(
      "nuclide",
      [](const cppCLASS &self)
      {
         return self.nuclide();
      },
      [](cppCLASS &self, const std::vector<general::Nuclide> &value)
      {
         self.nuclide() = value;
      },
      cppCLASS::component_t::documentation("nuclide").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
