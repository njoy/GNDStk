
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/abstract/Functional.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_abstract {

// Functional wrapper
void wrapFunctional(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = abstract::Functional;
   using _t = std::variant<
      abstract::Functional,
      containers::Values
   >;

   // create the component
   python::class_<Component> component(
      module,
      "Functional",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<XMLName> &,
            const std::optional<Float64> &,
            const containers::Axes &,
            const std::optional<unknownNamespace::Uncertainty> &,
            const _t &
         >(),
         python::arg("label") = std::nullopt,
         python::arg("outer_domain_value") = std::nullopt,
         python::arg("axes"),
         python::arg("uncertainty") = std::nullopt,
         python::arg("_functionalvalues"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         &Component::label,
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "outer_domain_value",
         &Component::outerDomainValue,
         Component::documentation("outer_domain_value").data()
      )
      .def_property_readonly(
         "axes",
         python::overload_cast<>(&Component::axes),
         Component::documentation("axes").data()
      )
      .def_property_readonly(
         "uncertainty",
         python::overload_cast<>(&Component::uncertainty),
         Component::documentation("uncertainty").data()
      )
      .def_property_readonly(
         "functional",
         python::overload_cast<>(&Component::functional),
         Component::documentation("functional").data()
      )
      .def_property_readonly(
         "values",
         python::overload_cast<>(&Component::values),
         Component::documentation("values").data()
      )
      .def_property_readonly(
         "_functionalvalues",
         python::overload_cast<>(&Component::_functionalvalues),
         Component::documentation("_functionalvalues").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_abstract
} // namespace python_v2_0