
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Sums.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// Sums wrapper
void wrapSums(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::Sums;

   // create the component
   python::class_<Component> component(
      module,
      "Sums",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<general::CrossSectionSums> &,
            const std::optional<general::MultiplicitySums> &
         >(),
         python::arg("cross_section_sums") = std::nullopt,
         python::arg("multiplicity_sums") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "cross_section_sums",
         [](const Component &self) { return self.crossSectionSums(); },
         Component::documentation("cross_section_sums").data()
      )
      .def_property_readonly(
         "multiplicity_sums",
         [](const Component &self) { return self.multiplicitySums(); },
         Component::documentation("multiplicity_sums").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_general
} // namespace python_v2_0
