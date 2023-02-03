
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/NuclearAmplitudeExpansion.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// NuclearAmplitudeExpansion wrapper
void wrapNuclearAmplitudeExpansion(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::NuclearAmplitudeExpansion;

   // create the component
   python::class_<Component> component(
      module,
      "NuclearAmplitudeExpansion",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const general::NuclearTerm &,
            const general::RealInterferenceTerm &,
            const general::ImaginaryInterferenceTerm &
         >(),
         python::arg("nuclear_term"),
         python::arg("real_interference_term"),
         python::arg("imaginary_interference_term"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "nuclear_term",
         [](const Component &self) { return self.nuclearTerm(); },
         Component::documentation("nuclear_term").data()
      )
      .def_property_readonly(
         "real_interference_term",
         [](const Component &self) { return self.realInterferenceTerm(); },
         Component::documentation("real_interference_term").data()
      )
      .def_property_readonly(
         "imaginary_interference_term",
         [](const Component &self) { return self.imaginaryInterferenceTerm(); },
         Component::documentation("imaginary_interference_term").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_general
} // namespace python_v2_0
