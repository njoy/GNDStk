
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/pops/Isotopes.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_pops {

// wrapper for pops::Isotopes
void wrapIsotopes(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = pops::Isotopes;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Isotopes",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::vector<pops::Isotope> &
      >(),
      py::arg("isotope"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set isotope
   object.def_property(
      "isotope",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.isotope();
      },
      [](cppCLASS &self, const std::vector<pops::Isotope> &value)
      {
         self.isotope() = value;
      },
      cppCLASS::component_t::documentation("isotope").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_pops
} // namespace python_v2_0
