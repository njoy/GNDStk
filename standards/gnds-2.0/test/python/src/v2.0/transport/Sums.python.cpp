
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/transport/Sums.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_transport {

// Sums wrapper
void wrapSums(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = transport::Sums;

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
            const transport::CrossSectionSums &,
            const std::optional<transport::MultiplicitySums> &
         >(),
         python::arg("cross_section_sums"),
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

} // namespace python_transport
} // namespace python_v2_0
