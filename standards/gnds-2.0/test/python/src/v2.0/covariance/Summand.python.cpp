
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/covariance/Summand.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_covariance {

// Summand wrapper
void wrapSummand(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = covariance::Summand;

   // create the component
   python::class_<Component> component(
      module,
      "Summand",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<XMLName> &,
            const std::optional<Float64> &,
            const std::optional<std::string> &
         >(),
         python::arg("endf_mfmt") = std::nullopt,
         python::arg("coefficient") = std::nullopt,
         python::arg("href") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "endf_mfmt",
         [](const Component &self) { return self.ENDF_MFMT(); },
         Component::documentation("endf_mfmt").data()
      )
      .def_property_readonly(
         "coefficient",
         [](const Component &self) { return self.coefficient(); },
         Component::documentation("coefficient").data()
      )
      .def_property_readonly(
         "href",
         [](const Component &self) { return self.href(); },
         Component::documentation("href").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_covariance
} // namespace python_v2_0
