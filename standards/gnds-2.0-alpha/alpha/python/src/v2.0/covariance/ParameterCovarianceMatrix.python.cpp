
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/covariance/ParameterCovarianceMatrix.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_covariance {

// ParameterCovarianceMatrix wrapper
void wrapParameterCovarianceMatrix(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

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
            const std::string &,
            const std::string &,
            const g3d::Array &,
            const covariance::Parameters &
         >(),
         python::arg("label"),
         python::arg("type"),
         python::arg("array"),
         python::arg("parameters"),
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
         "array",
         [](const Component &self) { return self.array(); },
         Component::documentation("array").data()
      )
      .def_property_readonly(
         "parameters",
         [](const Component &self) { return self.parameters(); },
         Component::documentation("parameters").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_covariance
} // namespace python_v2_0
