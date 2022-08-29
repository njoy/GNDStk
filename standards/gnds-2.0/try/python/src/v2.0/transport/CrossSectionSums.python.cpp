
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/transport/CrossSectionSums.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_transport {

// CrossSectionSums wrapper
void wrapCrossSectionSums(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = transport::CrossSectionSums;

   // create the component
   python::class_<Component> component(
      module,
      "CrossSectionSums",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<std::vector<transport::CrossSectionSum>> &
         >(),
         python::arg("cross_section_sum") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "cross_section_sum",
         [](const Component &self) { return self.crossSectionSum(); },
         Component::documentation("cross_section_sum").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_transport
} // namespace python_v2_0
