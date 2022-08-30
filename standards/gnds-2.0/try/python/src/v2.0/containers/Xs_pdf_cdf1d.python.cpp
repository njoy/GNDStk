
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/containers/Xs_pdf_cdf1d.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_containers {

// Xs_pdf_cdf1d wrapper
void wrapXs_pdf_cdf1d(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = containers::Xs_pdf_cdf1d;

   // create the component
   python::class_<Component> component(
      module,
      "Xs_pdf_cdf1d",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<Float64> &,
            const unknownNamespace::Xs &,
            const containers::Pdf &,
            const unknownNamespace::Cdf &
         >(),
         python::arg("outer_domain_value") = std::nullopt,
         python::arg("xs"),
         python::arg("pdf"),
         python::arg("cdf"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "outer_domain_value",
         [](const Component &self) { return self.outerDomainValue(); },
         Component::documentation("outer_domain_value").data()
      )
      .def_property_readonly(
         "xs",
         [](const Component &self) { return self.xs(); },
         Component::documentation("xs").data()
      )
      .def_property_readonly(
         "pdf",
         [](const Component &self) { return self.pdf(); },
         Component::documentation("pdf").data()
      )
      .def_property_readonly(
         "cdf",
         [](const Component &self) { return self.cdf(); },
         Component::documentation("cdf").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_containers
} // namespace python_v2_0
