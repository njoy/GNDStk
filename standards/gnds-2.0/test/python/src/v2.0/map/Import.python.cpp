
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/map/Import.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_map {

// Import wrapper
void wrapImport(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = map::Import;

   // create the component
   python::class_<Component> component(
      module,
      "Import",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const XMLName &,
            const checksum &,
            const std::optional<algorithm> &
         >(),
         python::arg("path"),
         python::arg("checksum"),
         python::arg("algorithm") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "path",
         [](const Component &self) { return self.path(); },
         Component::documentation("path").data()
      )
      .def_property_readonly(
         "checksum",
         [](const Component &self) { return self.checksum(); },
         Component::documentation("checksum").data()
      )
      .def_property_readonly(
         "algorithm",
         [](const Component &self) { return self.algorithm(); },
         Component::documentation("algorithm").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_map
} // namespace python_v2_0