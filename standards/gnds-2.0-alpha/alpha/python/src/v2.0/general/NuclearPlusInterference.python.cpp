
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/NuclearPlusInterference.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// NuclearPlusInterference wrapper
void wrapNuclearPlusInterference(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::NuclearPlusInterference;

   // create the component
   python::class_<Component> component(
      module,
      "NuclearPlusInterference",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const double &,
            const reduced::CrossSection &,
            const alt::Distribution &
         >(),
         python::arg("mu_cutoff"),
         python::arg("cross_section"),
         python::arg("distribution"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "mu_cutoff",
         [](const Component &self) { return self.muCutoff(); },
         Component::documentation("mu_cutoff").data()
      )
      .def_property_readonly(
         "cross_section",
         [](const Component &self) { return self.crossSection(); },
         Component::documentation("cross_section").data()
      )
      .def_property_readonly(
         "distribution",
         [](const Component &self) { return self.distribution(); },
         Component::documentation("distribution").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_general
} // namespace python_v2_0
