
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/NuclearAmplitudeExpansion.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::NuclearAmplitudeExpansion
void wrapNuclearAmplitudeExpansion(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::NuclearAmplitudeExpansion;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "NuclearAmplitudeExpansion",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const general::NuclearTerm &,
         const general::RealInterferenceTerm &,
         const general::ImaginaryInterferenceTerm &
      >(),
      py::arg("nuclear_term"),
      py::arg("real_interference_term"),
      py::arg("imaginary_interference_term"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set nuclearTerm
   object.def_property(
      "nuclear_term",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.nuclearTerm();
      },
      [](cppCLASS &self, const general::NuclearTerm &value)
      {
         self.nuclearTerm() = value;
      },
      cppCLASS::component_t::documentation("nuclear_term").data()
   );

   // get/set realInterferenceTerm
   object.def_property(
      "real_interference_term",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.realInterferenceTerm();
      },
      [](cppCLASS &self, const general::RealInterferenceTerm &value)
      {
         self.realInterferenceTerm() = value;
      },
      cppCLASS::component_t::documentation("real_interference_term").data()
   );

   // get/set imaginaryInterferenceTerm
   object.def_property(
      "imaginary_interference_term",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.imaginaryInterferenceTerm();
      },
      [](cppCLASS &self, const general::ImaginaryInterferenceTerm &value)
      {
         self.imaginaryInterferenceTerm() = value;
      },
      cppCLASS::component_t::documentation("imaginary_interference_term").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0