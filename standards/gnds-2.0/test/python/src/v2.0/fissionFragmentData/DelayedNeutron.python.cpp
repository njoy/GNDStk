
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/fissionFragmentData/DelayedNeutron.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_fissionFragmentData {

// DelayedNeutron wrapper
void wrapDelayedNeutron(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = fissionFragmentData::DelayedNeutron;

   // create the component
   python::class_<Component> component(
      module,
      "DelayedNeutron",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const XMLName &,
            const fissionFragmentData::Rate &,
            const common::Product &
         >(),
         python::arg("label"),
         python::arg("rate"),
         python::arg("product"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self) { return self.label(); },
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "rate",
         [](const Component &self) { return self.rate(); },
         Component::documentation("rate").data()
      )
      .def_property_readonly(
         "product",
         [](const Component &self) { return self.product(); },
         Component::documentation("product").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_fissionFragmentData
} // namespace python_v2_0
