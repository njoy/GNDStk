
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/pops/Uncertainty.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_pops {

// Uncertainty wrapper
void wrapUncertainty(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = pops::Uncertainty;

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
            const std::optional<pops::Standard> &,
            const std::optional<pops::LogNormal> &,
            const std::optional<pops::ConfidenceIntervals> &,
            const std::optional<pops::Pdf> &
         >(),
         python::arg("standard") = std::nullopt,
         python::arg("log_normal") = std::nullopt,
         python::arg("confidence_intervals") = std::nullopt,
         python::arg("pdf") = std::nullopt,
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
         "pdf",
         [](const Component &self) { return self.pdf(); },
         Component::documentation("pdf").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_pops
} // namespace python_v2_0