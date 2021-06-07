
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
      Component::className(),
      Component::help()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<Integer32> &,
            const Defaulted<enums::Interpolation> &,
            const std::optional<XMLName> &,
            const std::optional<Float64> &,
            const std::optional<containers::Axes> &,
            const containers::Values &
         >(),
         python::arg("index"),
         python::arg("interpolation"),
         python::arg("label"),
         python::arg("outerDomainValue"),
         python::arg("axes"),
         python::arg("values"),
         Component::help("constructor")
      )
      .def_property_readonly(
         "index",
         &Component::index,
         Component::help("index")
      )
      .def_property_readonly(
         "interpolation",
         &Component::interpolation,
         Component::help("interpolation")
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
         "axes",
         &Component::axes,
         Component::help("axes")
      )
      .def_property_readonly(
         "values",
         &Component::values,
         Component::help("values")
      )
   ;
}

} // namespace containers
} // namespace v1_9
