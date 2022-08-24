
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/containers/Constant1d.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_containers {

// Constant1d wrapper
void wrapConstant1d(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = containers::Constant1d;

   // create the component
   python::class_<Component> component(
      module,
      "Constant1d",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<Float64> &,
            const std::optional<Float64> &,
            const std::optional<XMLName> &,
            const std::optional<Float64> &,
            const std::optional<Float64> &,
            const containers::Axes &
         >(),
         python::arg("domain_max") = std::nullopt,
         python::arg("domain_min") = std::nullopt,
         python::arg("label") = std::nullopt,
         python::arg("outer_domain_value") = std::nullopt,
         python::arg("value") = std::nullopt,
         python::arg("axes"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "domain_max",
         &Component::domainMax,
         Component::documentation("domain_max").data()
      )
      .def_property_readonly(
         "domain_min",
         &Component::domainMin,
         Component::documentation("domain_min").data()
      )
      .def_property_readonly(
         "label",
         &Component::label,
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "outer_domain_value",
         &Component::outerDomainValue,
         Component::documentation("outer_domain_value").data()
      )
      .def_property_readonly(
         "value",
         &Component::value,
         Component::documentation("value").data()
      )
      .def_property_readonly(
         "axes",
         python::overload_cast<>(&Component::axes),
         Component::documentation("axes").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_containers
} // namespace python_v2_0