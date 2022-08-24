
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/transport/AngularEnergy.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_transport {

// AngularEnergy wrapper
void wrapAngularEnergy(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = transport::AngularEnergy;

   // create the component
   python::class_<Component> component(
      module,
      "AngularEnergy",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const XMLName &,
            const XMLName &,
            const containers::XYs3d &
         >(),
         python::arg("label"),
         python::arg("product_frame"),
         python::arg("xys3d"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         &Component::label,
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "product_frame",
         &Component::productFrame,
         Component::documentation("product_frame").data()
      )
      .def_property_readonly(
         "xys3d",
         python::overload_cast<>(&Component::XYs3d),
         Component::documentation("xys3d").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_transport
} // namespace python_v2_0