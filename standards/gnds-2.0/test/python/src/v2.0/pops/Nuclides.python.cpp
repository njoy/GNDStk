
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/pops/Nuclides.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_pops {

// wrapper for pops::Nuclides
void wrapNuclides(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = pops::Nuclides;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Nuclides",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::vector<pops::Nuclide> &
      >(),
      py::arg("nuclide"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set nuclide
   object.def_property(
      "nuclide",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.nuclide();
      },
      [](cppCLASS &self, const std::vector<pops::Nuclide> &value)
      {
         self.nuclide() = value;
      },
      cppCLASS::component_t::documentation("nuclide").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_pops
} // namespace python_v2_0
