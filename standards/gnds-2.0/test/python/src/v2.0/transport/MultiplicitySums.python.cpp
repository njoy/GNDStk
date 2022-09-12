
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/transport/MultiplicitySums.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_transport {

// MultiplicitySums wrapper
void wrapMultiplicitySums(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = transport::MultiplicitySums;

   // create the component
   python::class_<Component> component(
      module,
      "MultiplicitySums",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<std::vector<transport::MultiplicitySum>> &
         >(),
         python::arg("multiplicity_sum") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "multiplicity_sum",
         [](const Component &self) { return self.multiplicitySum(); },
         Component::documentation("multiplicity_sum").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_transport
} // namespace python_v2_0