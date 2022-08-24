
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/abstract/PhysicalQuantity.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_abstract {

// PhysicalQuantity wrapper
void wrapPhysicalQuantity(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = abstract::PhysicalQuantity;

   // create the component
   python::class_<Component> component(
      module,
      "PhysicalQuantity",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const XMLName &,
            const std::optional<XMLName> &,
            const XMLName &,
            const std::optional<documentation::Documentation> &,
            const std::optional<unknownNamespace::Uncertainty> &
         >(),
         python::arg("label"),
         python::arg("unit") = std::nullopt,
         python::arg("value"),
         python::arg("documentation") = std::nullopt,
         python::arg("uncertainty") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         &Component::label,
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "unit",
         &Component::unit,
         Component::documentation("unit").data()
      )
      .def_property_readonly(
         "value",
         &Component::value,
         Component::documentation("value").data()
      )
      .def_property_readonly(
         "documentation",
         python::overload_cast<>(&Component::documentation),
         Component::documentation("documentation").data()
      )
      .def_property_readonly(
         "uncertainty",
         python::overload_cast<>(&Component::uncertainty),
         Component::documentation("uncertainty").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_abstract
} // namespace python_v2_0