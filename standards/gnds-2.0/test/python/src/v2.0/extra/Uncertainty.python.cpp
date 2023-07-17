
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/extra/Uncertainty.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_extra {

// wrapper for extra::Uncertainty
void wrapUncertainty(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = extra::Uncertainty;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Uncertainty",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<containers::Standard> &,
         const std::optional<containers::LogNormal> &,
         const std::optional<containers::ConfidenceIntervals> &,
         const std::optional<containers::Covariance> &,
         const std::optional<containers::ListOfCovariances> &
      >(),
      py::arg("standard") = std::nullopt,
      py::arg("log_normal") = std::nullopt,
      py::arg("confidence_intervals") = std::nullopt,
      py::arg("covariance") = std::nullopt,
      py::arg("list_of_covariances") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set standard
   object.def_property(
      "standard",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.standard();
      },
      [](cppCLASS &self, const std::optional<containers::Standard> &value)
      {
         self.standard() = value;
      },
      cppCLASS::component_t::documentation("standard").data()
   );

   // get/set logNormal
   object.def_property(
      "log_normal",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.logNormal();
      },
      [](cppCLASS &self, const std::optional<containers::LogNormal> &value)
      {
         self.logNormal() = value;
      },
      cppCLASS::component_t::documentation("log_normal").data()
   );

   // get/set confidenceIntervals
   object.def_property(
      "confidence_intervals",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.confidenceIntervals();
      },
      [](cppCLASS &self, const std::optional<containers::ConfidenceIntervals> &value)
      {
         self.confidenceIntervals() = value;
      },
      cppCLASS::component_t::documentation("confidence_intervals").data()
   );

   // get/set covariance
   object.def_property(
      "covariance",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.covariance();
      },
      [](cppCLASS &self, const std::optional<containers::Covariance> &value)
      {
         self.covariance() = value;
      },
      cppCLASS::component_t::documentation("covariance").data()
   );

   // get/set listOfCovariances
   object.def_property(
      "list_of_covariances",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.listOfCovariances();
      },
      [](cppCLASS &self, const std::optional<containers::ListOfCovariances> &value)
      {
         self.listOfCovariances() = value;
      },
      cppCLASS::component_t::documentation("list_of_covariances").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_extra
} // namespace python_v2_0
