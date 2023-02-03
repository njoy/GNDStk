
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/CovarianceMatrix.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// CovarianceMatrix wrapper
void wrapCovarianceMatrix(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::CovarianceMatrix;

   // create the component
   python::class_<Component> component(
      module,
      "CovarianceMatrix",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::string &,
            const std::string &,
            const std::optional<std::string> &,
            const general::Gridded2d &
         >(),
         python::arg("label"),
         python::arg("type"),
         python::arg("product_frame") = std::nullopt,
         python::arg("gridded2d"),
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
         "product_frame",
         [](const Component &self) { return self.productFrame(); },
         Component::documentation("product_frame").data()
      )
      .def_property_readonly(
         "gridded2d",
         [](const Component &self) { return self.gridded2d(); },
         Component::documentation("gridded2d").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_general
} // namespace python_v2_0
