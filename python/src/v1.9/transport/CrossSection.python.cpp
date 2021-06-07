
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v1.9/transport/CrossSection.hpp"

// namespace aliases
namespace python = pybind11;

namespace v1_9 {
namespace transport {

// CrossSection wrapper
void wrapCrossSection(python::module &module)
{
   // type aliases
   using Component = njoy::GNDStk::v1_9::transport::CrossSection;

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
            const std::optional<containers::XYs1d> &,
            const std::optional<containers::Regions1d> &,
            const std::vector<VARIANT> &
         >(),
         python::arg("XYs1d"),
         python::arg("regions1d"),
         python::arg("choice"),
         Component::help("constructor")
      )
      .def_property_readonly(
         "XYs1d",
         &Component::XYs1d,
         Component::help("XYs1d")
      )
      .def_property_readonly(
         "regions1d",
         &Component::regions1d,
         Component::help("regions1d")
      )
      .def_property_readonly(
         "choice",
         &Component::choice,
         Component::help("choice")
      )
   ;
}

} // namespace transport
} // namespace v1_9
