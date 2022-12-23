
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/fpy/ProductYield.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_fpy {

// ProductYield wrapper
void wrapProductYield(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = fpy::ProductYield;

   // create the component
   python::class_<Component> component(
      module,
      "ProductYield",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const XMLName &,
            const std::optional<fpy::Nuclides> &,
            const fpy::ElapsedTimes &
         >(),
         python::arg("label"),
         python::arg("nuclides") = std::nullopt,
         python::arg("elapsed_times"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self) { return self.label(); },
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "nuclides",
         [](const Component &self) { return self.nuclides(); },
         Component::documentation("nuclides").data()
      )
      .def_property_readonly(
         "elapsed_times",
         [](const Component &self) { return self.elapsedTimes(); },
         Component::documentation("elapsed_times").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_fpy
} // namespace python_v2_0
