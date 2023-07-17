
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/covariance/AverageParameterCovariance.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_covariance {

// wrapper for covariance::AverageParameterCovariance
void wrapAverageParameterCovariance(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = covariance::AverageParameterCovariance;
   using _t = std::variant<
      covariance::CovarianceMatrix
   >;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "AverageParameterCovariance",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<bool> &,
         const std::optional<XMLName> &,
         const std::optional<covariance::ColumnData> &,
         const std::optional<covariance::RowData> &,
         const _t &
      >(),
      py::arg("cross_term") = std::nullopt,
      py::arg("label") = std::nullopt,
      py::arg("column_data") = std::nullopt,
      py::arg("row_data") = std::nullopt,
      py::arg("_covariance_matrix"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set crossTerm
   object.def_property(
      "cross_term",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.crossTerm();
      },
      [](cppCLASS &self, const std::optional<bool> &value)
      {
         self.crossTerm() = value;
      },
      cppCLASS::component_t::documentation("cross_term").data()
   );

   // get/set label
   object.def_property(
      "label",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.label();
      },
      [](cppCLASS &self, const std::optional<XMLName> &value)
      {
         self.label() = value;
      },
      cppCLASS::component_t::documentation("label").data()
   );

   // get/set columnData
   object.def_property(
      "column_data",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.columnData();
      },
      [](cppCLASS &self, const std::optional<covariance::ColumnData> &value)
      {
         self.columnData() = value;
      },
      cppCLASS::component_t::documentation("column_data").data()
   );

   // get/set rowData
   object.def_property(
      "row_data",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.rowData();
      },
      [](cppCLASS &self, const std::optional<covariance::RowData> &value)
      {
         self.rowData() = value;
      },
      cppCLASS::component_t::documentation("row_data").data()
   );

   object.def_property(
      "covariance_matrix",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.covarianceMatrix();
      },
      [](cppCLASS &self, const covariance::CovarianceMatrix &value)
      {
         self.covarianceMatrix() = value;
      },
      cppCLASS::component_t::documentation("covariance_matrix").data()
   );

   object.def_property(
      "_covariance_matrix",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self._covarianceMatrix();
      },
      [](cppCLASS &self, const _t &value)
      {
         self._covarianceMatrix() = value;
      },
      cppCLASS::component_t::documentation("_covariance_matrix").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_covariance
} // namespace python_v2_0
