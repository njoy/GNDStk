
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/covariance/CovarianceSection.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_covariance {

// CovarianceSection wrapper
void wrapCovarianceSection(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = covariance::CovarianceSection;
   using _t = std::variant<
      covariance::CovarianceMatrix,
      covariance::Sum,
      covariance::Mixed
   >;

   // create the component
   python::class_<Component> component(
      module,
      "CovarianceSection",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<bool> &,
            const std::optional<XMLName> &,
            const covariance::RowData &,
            const std::optional<covariance::ColumnData> &,
            const _t &
         >(),
         python::arg("cross_term") = std::nullopt,
         python::arg("label") = std::nullopt,
         python::arg("row_data"),
         python::arg("column_data") = std::nullopt,
         python::arg("_covariance_matrixsummixed"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "cross_term",
         [](const Component &self) { return self.crossTerm().value(); },
         Component::documentation("cross_term").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self) { return self.label(); },
         Component::documentation("label").data()
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
      .def_property_readonly(
         "covariance_matrix",
         [](const Component &self) { return self.covarianceMatrix(); },
         Component::documentation("covariance_matrix").data()
      )
      .def_property_readonly(
         "sum",
         [](const Component &self) { return self.sum(); },
         Component::documentation("sum").data()
      )
      .def_property_readonly(
         "mixed",
         [](const Component &self) { return self.mixed(); },
         Component::documentation("mixed").data()
      )
      .def_property_readonly(
         "_covariance_matrixsummixed",
         [](const Component &self) { return self._covarianceMatrixsummixed(); },
         Component::documentation("_covariance_matrixsummixed").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_covariance
} // namespace python_v2_0