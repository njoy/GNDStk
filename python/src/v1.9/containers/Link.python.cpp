
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v1.9/containers/Link.hpp"

// namespace aliases
namespace python = pybind11;

namespace v1_9 {
namespace containers {

// Link wrapper
void wrapLink(python::module &module)
{
   using namespace njoy::GNDStk;

   // type aliases
   using Component = njoy::GNDStk::v1_9::containers::Link;

   // create the component
   python::class_<Component> component(
      module,
      "Link",
      Component::help().c_str()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<bodyText> &
         >(),
         python::arg("href"),
         Component::help("constructor").c_str()
      )
      .def_property_readonly(
         "href",
         &Component::href,
         Component::help("href").c_str()
      )
   ;
}

} // namespace containers
} // namespace v1_9
