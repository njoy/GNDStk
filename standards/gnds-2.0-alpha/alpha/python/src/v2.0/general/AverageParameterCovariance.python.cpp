
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/AverageParameterCovariance.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// AverageParameterCovariance wrapper
void wrapAverageParameterCovariance(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::AverageParameterCovariance;

   // create the component
   python::class_<Component> component(
      module,
      "AverageParameterCovariance",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::string &,
            const std::optional<bool> &,
            const general::CovarianceMatrix &,
            const general::RowData &,
            const std::optional<general::ColumnData> &
         >(),
         python::arg("label"),
         python::arg("cross_term") = std::nullopt,
         python::arg("covariance_matrix"),
         python::arg("row_data"),
         python::arg("column_data") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self) { return self.label(); },
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "cross_term",
         [](const Component &self) { return self.crossTerm(); },
         Component::documentation("cross_term").data()
      )
      .def_property_readonly(
         "covariance_matrix",
         [](const Component &self) { return self.covarianceMatrix(); },
         Component::documentation("covariance_matrix").data()
      )
      .def_property_readonly(
         "row_data",
         [](const Component &self) { return self.rowData(); },
         Component::documentation("row_data").data()
      )
      .def_property_readonly(
         "column_data",
         [](const Component &self) { return self.columnData(); },
         Component::documentation("column_data").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_general
} // namespace python_v2_0
