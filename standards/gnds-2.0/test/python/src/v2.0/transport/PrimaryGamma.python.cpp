
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/transport/PrimaryGamma.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_transport {

// PrimaryGamma wrapper
void wrapPrimaryGamma(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = transport::PrimaryGamma;

   // create the component
   python::class_<Component> component(
      module,
      "PrimaryGamma",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<Float64> &,
            const std::optional<Float64> &,
            const std::optional<Float64> &,
            const std::optional<XMLName> &,
            const std::optional<containers::Axes> &
         >(),
         python::arg("domain_max") = std::nullopt,
         python::arg("domain_min") = std::nullopt,
         python::arg("value") = std::nullopt,
         python::arg("final_state") = std::nullopt,
         python::arg("axes") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "domain_max",
         [](const Component &self) { return self.domainMax(); },
         Component::documentation("domain_max").data()
      )
      .def_property_readonly(
         "domain_min",
         [](const Component &self) { return self.domainMin(); },
         Component::documentation("domain_min").data()
      )
      .def_property_readonly(
         "value",
         [](const Component &self) { return self.value(); },
         Component::documentation("value").data()
      )
      .def_property_readonly(
         "final_state",
         [](const Component &self) { return self.finalState(); },
         Component::documentation("final_state").data()
      )
      .def_property_readonly(
         "axes",
         [](const Component &self) { return self.axes(); },
         Component::documentation("axes").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_transport
} // namespace python_v2_0
