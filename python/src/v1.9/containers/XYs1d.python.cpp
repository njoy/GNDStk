
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v1.9/containers/XYs1d.hpp"

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
      Component::help().c_str()
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
         python::arg("index"),
         python::arg("interpolation") = enums::Interpolation::linlin,
         python::arg("label"),
         python::arg("outer_domain_value"),
         python::arg("axes"),
         python::arg("values"),
         Component::help("constructor").c_str()
      )
      .def_property_readonly(
         "index",
         &Component::index,
         Component::help("index").c_str()
      )
      .def_property_readonly(
         "interpolation",
         &Component::interpolation,
         Component::help("interpolation").c_str()
      )
      .def_property_readonly(
         "label",
         &Component::label,
         Component::help("label").c_str()
      )
      .def_property_readonly(
         "outer_domain_value",
         &Component::outerDomainValue,
         Component::help("outer_domain_value").c_str()
      )
      .def_property_readonly(
         "axes",
         &Component::axes,
         Component::help("axes").c_str()
      )
      .def_property_readonly(
         "values",
         &Component::values,
         Component::help("values").c_str()
      )
   ;
}

} // namespace containers
} // namespace v1_9
