
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
   // type aliases
   using Component = njoy::GNDStk::v1_9::containers::Link;

   // create the component
   python::class_<Component> component(
      module,
      Component::className(),
      Component::help()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<bodyText> &
         >(),
         python::arg("href"),
         Component::help("constructor")
      )
      .def_property_readonly(
         "href",
         &Component::href,
         Component::help("href")
      )
   ;
}

} // namespace containers
} // namespace v1_9
