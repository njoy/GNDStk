
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/styles/InverseSpeed.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_styles {

// InverseSpeed wrapper
void wrapInverseSpeed(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = styles::InverseSpeed;

   // create the component
   python::class_<Component> component(
      module,
      "InverseSpeed",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const containers::Gridded1d &
         >(),
         python::arg("gridded1d"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "gridded1d",
         python::overload_cast<>(&Component::gridded1d),
         Component::documentation("gridded1d").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_styles
} // namespace python_v2_0