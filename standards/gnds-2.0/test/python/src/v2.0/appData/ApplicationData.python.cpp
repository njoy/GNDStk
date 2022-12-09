
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/appData/ApplicationData.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_appData {

// ApplicationData wrapper
void wrapApplicationData(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = appData::ApplicationData;

   // create the component
   python::class_<Component> component(
      module,
      "ApplicationData",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<appData::Institution> &
         >(),
         python::arg("institution") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "institution",
         [](const Component &self) { return self.institution(); },
         Component::documentation("institution").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_appData
} // namespace python_v2_0
