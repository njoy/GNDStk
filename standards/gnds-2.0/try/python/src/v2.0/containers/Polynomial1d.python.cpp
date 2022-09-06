
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/containers/Polynomial1d.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_containers {

// Polynomial1d wrapper
void wrapPolynomial1d(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = containers::Polynomial1d;

   // create the component
   python::class_<Component> component(
      module,
      "Polynomial1d",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<XMLName> &,
            const std::optional<Float64> &,
            const std::optional<Integer32> &,
            const Float64 &,
            const Float64 &,
            const containers::Axes &,
            const std::optional<containers::Uncertainty> &,
            const containers::Values &
         >(),
         python::arg("label") = std::nullopt,
         python::arg("outer_domain_value") = std::nullopt,
         python::arg("lower_index") = std::nullopt,
         python::arg("domain_min"),
         python::arg("domain_max"),
         python::arg("axes"),
         python::arg("uncertainty") = std::nullopt,
         python::arg("values"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self) { return self.label(); },
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "outer_domain_value",
         [](const Component &self) { return self.outerDomainValue(); },
         Component::documentation("outer_domain_value").data()
      )
      .def_property_readonly(
         "lower_index",
         [](const Component &self) { return self.lowerIndex().value(); },
         Component::documentation("lower_index").data()
      )
      .def_property_readonly(
         "domain_min",
         [](const Component &self) { return self.domainMin(); },
         Component::documentation("domain_min").data()
      )
      .def_property_readonly(
         "domain_max",
         [](const Component &self) { return self.domainMax(); },
         Component::documentation("domain_max").data()
      )
      .def_property_readonly(
         "axes",
         [](const Component &self) { return self.axes(); },
         Component::documentation("axes").data()
      )
      .def_property_readonly(
         "uncertainty",
         [](const Component &self) { return self.uncertainty(); },
         Component::documentation("uncertainty").data()
      )
      .def_property_readonly(
         "values",
         [](const Component &self) { return self.values(); },
         Component::documentation("values").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_containers
} // namespace python_v2_0