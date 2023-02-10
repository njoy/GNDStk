
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/top/CovarianceSuite.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_top {

// wrapper for top::CovarianceSuite
void wrapCovarianceSuite(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = top::CovarianceSuite;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "CovarianceSuite",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::string &,
         const std::string &,
         const std::string &,
         const std::string &,
         const std::string &,
         const std::optional<general::ExternalFiles> &,
         const general::Styles &,
         const std::optional<general::CovarianceSections> &,
         const std::optional<general::ParameterCovariances> &
      >(),
      py::arg("projectile"),
      py::arg("target"),
      py::arg("evaluation"),
      py::arg("interaction"),
      py::arg("format"),
      py::arg("external_files") = std::nullopt,
      py::arg("styles"),
      py::arg("covariance_sections") = std::nullopt,
      py::arg("parameter_covariances") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set projectile
   object.def_property(
      "projectile",
      [](const cppCLASS &self)
      {
         return self.projectile();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.projectile() = value;
      },
      cppCLASS::component_t::documentation("projectile").data()
   );

   // get/set target
   object.def_property(
      "target",
      [](const cppCLASS &self)
      {
         return self.target();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.target() = value;
      },
      cppCLASS::component_t::documentation("target").data()
   );

   // get/set evaluation
   object.def_property(
      "evaluation",
      [](const cppCLASS &self)
      {
         return self.evaluation();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.evaluation() = value;
      },
      cppCLASS::component_t::documentation("evaluation").data()
   );

   // get/set interaction
   object.def_property(
      "interaction",
      [](const cppCLASS &self)
      {
         return self.interaction();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.interaction() = value;
      },
      cppCLASS::component_t::documentation("interaction").data()
   );

   // get/set format
   object.def_property(
      "format",
      [](const cppCLASS &self)
      {
         return self.format();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.format() = value;
      },
      cppCLASS::component_t::documentation("format").data()
   );

   // get/set externalFiles
   object.def_property(
      "external_files",
      [](const cppCLASS &self)
      {
         return self.externalFiles();
      },
      [](cppCLASS &self, const std::optional<general::ExternalFiles> &value)
      {
         self.externalFiles() = value;
      },
      cppCLASS::component_t::documentation("external_files").data()
   );

   // get/set styles
   object.def_property(
      "styles",
      [](const cppCLASS &self)
      {
         return self.styles();
      },
      [](cppCLASS &self, const general::Styles &value)
      {
         self.styles() = value;
      },
      cppCLASS::component_t::documentation("styles").data()
   );

   // get/set covarianceSections
   object.def_property(
      "covariance_sections",
      [](const cppCLASS &self)
      {
         return self.covarianceSections();
      },
      [](cppCLASS &self, const std::optional<general::CovarianceSections> &value)
      {
         self.covarianceSections() = value;
      },
      cppCLASS::component_t::documentation("covariance_sections").data()
   );

   // get/set parameterCovariances
   object.def_property(
      "parameter_covariances",
      [](const cppCLASS &self)
      {
         return self.parameterCovariances();
      },
      [](cppCLASS &self, const std::optional<general::ParameterCovariances> &value)
      {
         self.parameterCovariances() = value;
      },
      cppCLASS::component_t::documentation("parameter_covariances").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_top
} // namespace python_v2_0
