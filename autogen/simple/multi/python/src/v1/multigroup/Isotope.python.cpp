
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "multi/v1/multigroup/Isotope.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v1 {
namespace python_multigroup {

// wrapper for multigroup::Isotope
void wrapIsotope(py::module &module)
{
   using namespace multi;
   using namespace multi::v1;

   // type aliases
   using cppCLASS = multigroup::Isotope;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Isotope",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const int &
      >(),
      py::arg("mass_number"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set mass_number
   object.def_property(
      "mass_number",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.mass_number();
      },
      [](cppCLASS &self, const int &value)
      {
         self.mass_number() = value;
      },
      cppCLASS::component_t::documentation("mass_number").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_multigroup
} // namespace python_v1
