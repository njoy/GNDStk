
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/top/CovarianceSuite.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_top {

// CovarianceSuite wrapper
void wrapCovarianceSuite(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = top::CovarianceSuite;

   // create the component
   python::class_<Component> component(
      module, "CovarianceSuite",
      Component::component_t::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
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
         python::arg("projectile"),
         python::arg("target"),
         python::arg("evaluation"),
         python::arg("interaction"),
         python::arg("format"),
         python::arg("external_files") = std::nullopt,
         python::arg("styles"),
         python::arg("covariance_sections") = std::nullopt,
         python::arg("parameter_covariances") = std::nullopt,
         Component::component_t::documentation("constructor").data()
      )
      .def_property_readonly(
         "projectile",
         [](const Component &self)
         {
            return self.projectile();
         },
         Component::component_t::documentation("projectile").data()
      )
      .def_property_readonly(
         "target",
         [](const Component &self)
         {
            return self.target();
         },
         Component::component_t::documentation("target").data()
      )
      .def_property_readonly(
         "evaluation",
         [](const Component &self)
         {
            return self.evaluation();
         },
         Component::component_t::documentation("evaluation").data()
      )
      .def_property_readonly(
         "interaction",
         [](const Component &self)
         {
            return self.interaction();
         },
         Component::component_t::documentation("interaction").data()
      )
      .def_property_readonly(
         "format",
         [](const Component &self)
         {
            return self.format();
         },
         Component::component_t::documentation("format").data()
      )
      .def_property_readonly(
         "external_files",
         [](const Component &self)
         {
            return self.externalFiles();
         },
         Component::component_t::documentation("external_files").data()
      )
      .def_property_readonly(
         "styles",
         [](const Component &self)
         {
            return self.styles();
         },
         Component::component_t::documentation("styles").data()
      )
      .def_property_readonly(
         "covariance_sections",
         [](const Component &self)
         {
            return self.covarianceSections();
         },
         Component::component_t::documentation("covariance_sections").data()
      )
      .def_property_readonly(
         "parameter_covariances",
         [](const Component &self)
         {
            return self.parameterCovariances();
         },
         Component::component_t::documentation("parameter_covariances").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions<Component>(component);
}

} // namespace python_top
} // namespace python_v2_0
