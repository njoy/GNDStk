
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v1.9/containers/Regions1d.hpp"

// namespace aliases
namespace python = pybind11;

namespace v1_9 {
namespace containers {

// Regions1d wrapper
void wrapRegions1d(python::module &module)
{
   using namespace njoy::GNDStk;

   // type aliases
   using Component = njoy::GNDStk::v1_9::containers::Regions1d;

   // create the component
   python::class_<Component> component(
      module,
      "Regions1d",
      Component::help().c_str()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<XMLName> &,
            const std::optional<Float64> &,
            const containers::XYs1d &,
            const std::optional<containers::Axes> &
         >(),
         python::arg("label") = std::nullopt,
         python::arg("outer_domain_value") = std::nullopt,
         python::arg("xys1d"),
         python::arg("axes") = std::nullopt,
         Component::help("constructor").c_str()
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
         "xys1d",
         &Component::XYs1d,
         Component::help("xys1d").c_str()
      )
      .def_property_readonly(
         "axes",
         &Component::axes,
         Component::help("axes").c_str()
      )
   ;
}

} // namespace containers
} // namespace v1_9
