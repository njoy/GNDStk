
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
   // type aliases
   using Component = njoy::GNDStk::v1_9::containers::Regions1d;

   // create the component
   python::class_<Component> component(
      module,
      Component::className(),
      Component::help()
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
         python::arg("label"),
         python::arg("outerDomainValue"),
         python::arg("XYs1d"),
         python::arg("axes"),
         Component::help("constructor")
      )
      .def_property_readonly(
         "label",
         &Component::label,
         Component::help("label")
      )
      .def_property_readonly(
         "outerDomainValue",
         &Component::outerDomainValue,
         Component::help("outerDomainValue")
      )
      .def_property_readonly(
         "XYs1d",
         &Component::XYs1d,
         Component::help("XYs1d")
      )
      .def_property_readonly(
         "axes",
         &Component::axes,
         Component::help("axes")
      )
   ;
}

} // namespace containers
} // namespace v1_9
