
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Recoil.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// Recoil wrapper
void wrapRecoil(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::Recoil;

   // create the component
   python::class_<Component> component(
      module,
      "Recoil",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::string &
         >(),
         python::arg("href"),
         Component::documentation("constructor").data()
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

} // namespace python_general
} // namespace python_v2_0
