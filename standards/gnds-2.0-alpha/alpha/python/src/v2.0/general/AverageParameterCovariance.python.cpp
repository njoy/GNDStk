
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/AverageParameterCovariance.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::AverageParameterCovariance
void wrapAverageParameterCovariance(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::AverageParameterCovariance;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "AverageParameterCovariance",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::string &,
         const std::optional<bool> &,
         const general::CovarianceMatrix &,
         const general::RowData &,
         const std::optional<general::ColumnData> &
      >(),
      py::arg("label"),
      py::arg("cross_term") = std::nullopt,
      py::arg("covariance_matrix"),
      py::arg("row_data"),
      py::arg("column_data") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set label
   object.def_property(
      "label",
      [](const cppCLASS &self)
      {
         return self.label();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.label() = value;
      },
      cppCLASS::component_t::documentation("label").data()
   );

   // get/set crossTerm
   object.def_property(
      "cross_term",
      [](const cppCLASS &self)
      {
         return self.crossTerm();
      },
      [](cppCLASS &self, const std::optional<bool> &value)
      {
         self.crossTerm() = value;
      },
      cppCLASS::component_t::documentation("cross_term").data()
   );

   // get/set covarianceMatrix
   object.def_property(
      "covariance_matrix",
      [](const cppCLASS &self)
      {
         return self.covarianceMatrix();
      },
      [](cppCLASS &self, const general::CovarianceMatrix &value)
      {
         self.covarianceMatrix() = value;
      },
      cppCLASS::component_t::documentation("covariance_matrix").data()
   );

   // get/set rowData
   object.def_property(
      "row_data",
      [](const cppCLASS &self)
      {
         return self.rowData();
      },
      [](cppCLASS &self, const general::RowData &value)
      {
         self.rowData() = value;
      },
      cppCLASS::component_t::documentation("row_data").data()
   );

   // get/set columnData
   object.def_property(
      "column_data",
      [](const cppCLASS &self)
      {
         return self.columnData();
      },
      [](cppCLASS &self, const std::optional<general::ColumnData> &value)
      {
         self.columnData() = value;
      },
      cppCLASS::component_t::documentation("column_data").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
