
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/fissionFragmentData/Rate.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_fissionFragmentData {

// Rate wrapper
void wrapRate(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = fissionFragmentData::Rate;

   // create the component
   python::class_<Component> component(
      module,
      "Rate",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const containers::Double &
         >(),
         python::arg("double"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "double",
         [](const Component &self) { return self.Double(); },
         Component::documentation("double").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_fissionFragmentData
} // namespace python_v2_0
