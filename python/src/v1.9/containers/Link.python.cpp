
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v1.9/containers/Link.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v1_9 {
namespace python_containers {

// Link wrapper
void wrapLink(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v1_9;

   // type aliases
   using Component = containers::Link;

   // create the component
   python::class_<Component> component(
      module,
      "Link",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const UTF8Text &
         >(),
         python::arg("href"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "href",
         &Component::href,
         Component::documentation("href").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_containers
} // namespace python_v1_9
