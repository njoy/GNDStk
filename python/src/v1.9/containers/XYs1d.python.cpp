
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v1.9/containers/XYs1d.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace v1_9 {
namespace containers {

// XYs1d wrapper
void wrapXYs1d(python::module &module)
{
   using namespace njoy::GNDStk;

   // type aliases
   using Component = njoy::GNDStk::v1_9::containers::XYs1d;

   // create the component
   python::class_<Component> component(
      module,
      "XYs1d",
      Component::documentation().c_str()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<Integer32> &,
            const enums::Interpolation &,
            const std::optional<XMLName> &,
            const std::optional<Float64> &,
            const std::optional<containers::Axes> &,
            const containers::Values &
         >(),
         python::arg("index") = std::nullopt,
         python::arg("interpolation") = enums::Interpolation::linlin,
         python::arg("label") = std::nullopt,
         python::arg("outer_domain_value") = std::nullopt,
         python::arg("axes") = std::nullopt,
         python::arg("values"),
         Component::documentation("constructor").c_str()
      )
      .def_property_readonly(
         "index",
         &Component::index,
         Component::documentation("index").c_str()
      )
      .def_property_readonly(
         "interpolation",
         &Component::interpolation,
         Component::documentation("interpolation").c_str()
      )
      .def_property_readonly(
         "label",
         &Component::label,
         Component::documentation("label").c_str()
      )
      .def_property_readonly(
         "outer_domain_value",
         &Component::outerDomainValue,
         Component::documentation("outer_domain_value").c_str()
      )
      .def_property_readonly(
         "axes",
         &Component::axes,
         Component::documentation("axes").c_str()
      )
      .def_property_readonly(
         "values",
         &Component::values,
         Component::documentation("values").c_str()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace containers
} // namespace v1_9
