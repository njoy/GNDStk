
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/transport/Uncorrelated.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_transport {

// Uncorrelated wrapper
void wrapUncorrelated(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = transport::Uncorrelated;

   // create the component
   python::class_<Component> component(
      module,
      "Uncorrelated",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<XMLName> &,
            const XMLName &,
            const transport::Angular &,
            const transport::Energy &
         >(),
         python::arg("label") = std::nullopt,
         python::arg("product_frame"),
         python::arg("angular"),
         python::arg("energy"),
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
         "angular",
         python::overload_cast<>(&Component::angular),
         Component::documentation("angular").data()
      )
      .def_property_readonly(
         "energy",
         python::overload_cast<>(&Component::energy),
         Component::documentation("energy").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_transport
} // namespace python_v2_0
