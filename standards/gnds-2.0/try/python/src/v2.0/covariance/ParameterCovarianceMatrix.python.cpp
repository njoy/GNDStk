
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/covariance/ParameterCovarianceMatrix.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_covariance {

// ParameterCovarianceMatrix wrapper
void wrapParameterCovarianceMatrix(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = covariance::ParameterCovarianceMatrix;

   // create the component
   python::class_<Component> component(
      module,
      "ParameterCovarianceMatrix",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const XMLName &,
            const std::optional<XMLName> &,
            const covariance::Parameters &,
            const unknownNamespace::Array &
         >(),
         python::arg("label"),
         python::arg("type") = std::nullopt,
         python::arg("parameters"),
         python::arg("array"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self) { return self.label(); },
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "type",
         [](const Component &self) { return self.type(); },
         Component::documentation("type").data()
      )
      .def_property_readonly(
         "parameters",
         [](const Component &self) { return self.parameters(); },
         Component::documentation("parameters").data()
      )
      .def_property_readonly(
         "array",
         [](const Component &self) { return self.array(); },
         Component::documentation("array").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_covariance
} // namespace python_v2_0
