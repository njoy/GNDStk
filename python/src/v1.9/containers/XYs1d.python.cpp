
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v1.9/containers/XYs1d.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v1_9 {
namespace python_containers {

// XYs1d wrapper
void wrapXYs1d(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v1_9;

   // type aliases
   using Component = containers::XYs1d;

   // create the component
   python::class_<Component> component(
      module,
      "XYs1d",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<int> &,
            const std::optional<enums::Interpolation> &,
            const std::optional<std::string> &,
            const std::optional<double> &,
            const std::optional<containers::Axes> &,
            const containers::Values &
         >(),
         python::arg("index") = std::nullopt,
         python::arg("interpolation") = std::nullopt,
         python::arg("label") = std::nullopt,
         python::arg("outer_domain_value") = std::nullopt,
         python::arg("axes") = std::nullopt,
         python::arg("values"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "index",
         [](const Component &self) { return self.index(); },
         Component::documentation("index").data()
      )
      .def_property_readonly(
         "interpolation",
         [](const Component &self) { return self.interpolation().value(); },
         Component::documentation("interpolation").data()
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
         "axes",
         [](const Component &self) { return self.axes(); },
         Component::documentation("axes").data()
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
} // namespace python_v1_9
