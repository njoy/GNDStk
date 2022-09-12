
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/documentation/ExforDataSet.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_documentation {

// ExforDataSet wrapper
void wrapExforDataSet(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = documentation::ExforDataSet;

   // create the component
   python::class_<Component> component(
      module,
      "ExforDataSet",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const XMLName &,
            const std::string &,
            const std::optional<documentation::CovarianceScript> &,
            const std::optional<documentation::CorrectionScript> &,
            const std::optional<documentation::Note> &
         >(),
         python::arg("subentry"),
         python::arg("retrieval_date"),
         python::arg("covariance_script") = std::nullopt,
         python::arg("correction_script") = std::nullopt,
         python::arg("note") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "subentry",
         [](const Component &self) { return self.subentry(); },
         Component::documentation("subentry").data()
      )
      .def_property_readonly(
         "retrieval_date",
         [](const Component &self) { return self.retrievalDate(); },
         Component::documentation("retrieval_date").data()
      )
      .def_property_readonly(
         "covariance_script",
         [](const Component &self) { return self.covarianceScript(); },
         Component::documentation("covariance_script").data()
      )
      .def_property_readonly(
         "correction_script",
         [](const Component &self) { return self.correctionScript(); },
         Component::documentation("correction_script").data()
      )
      .def_property_readonly(
         "note",
         [](const Component &self) { return self.note(); },
         Component::documentation("note").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_documentation
} // namespace python_v2_0