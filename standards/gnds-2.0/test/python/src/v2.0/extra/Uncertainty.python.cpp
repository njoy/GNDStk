
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/extra/Uncertainty.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_extra {

// Uncertainty wrapper
void wrapUncertainty(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = extra::Uncertainty;

   // create the component
   python::class_<Component> component(
      module,
      "Uncertainty",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<containers::Standard> &,
            const std::optional<containers::LogNormal> &,
            const std::optional<containers::ConfidenceIntervals> &,
            const std::optional<containers::Covariance> &,
            const std::optional<containers::ListOfCovariances> &
         >(),
         python::arg("standard") = std::nullopt,
         python::arg("log_normal") = std::nullopt,
         python::arg("confidence_intervals") = std::nullopt,
         python::arg("covariance") = std::nullopt,
         python::arg("list_of_covariances") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "standard",
         [](const Component &self) { return self.standard(); },
         Component::documentation("standard").data()
      )
      .def_property_readonly(
         "log_normal",
         [](const Component &self) { return self.logNormal(); },
         Component::documentation("log_normal").data()
      )
      .def_property_readonly(
         "confidence_intervals",
         [](const Component &self) { return self.confidenceIntervals(); },
         Component::documentation("confidence_intervals").data()
      )
      .def_property_readonly(
         "covariance",
         [](const Component &self) { return self.covariance(); },
         Component::documentation("covariance").data()
      )
      .def_property_readonly(
         "list_of_covariances",
         [](const Component &self) { return self.listOfCovariances(); },
         Component::documentation("list_of_covariances").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_extra
} // namespace python_v2_0
