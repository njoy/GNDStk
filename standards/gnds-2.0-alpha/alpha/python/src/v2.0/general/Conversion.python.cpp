
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Conversion.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// Conversion wrapper
void wrapConversion(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::Conversion;

   // create the component
   python::class_<Component> component(
      module, "Conversion",
      Component::component_t::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::string &,
            const std::string &
         >(),
         python::arg("flags"),
         python::arg("href"),
         Component::component_t::documentation("constructor").data()
      )
      .def_property_readonly(
         "flags",
         [](const Component &self)
         {
            return self.flags();
         },
         Component::component_t::documentation("flags").data()
      )
      .def_property_readonly(
         "href",
         [](const Component &self)
         {
            return self.href();
         },
         Component::component_t::documentation("href").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions<Component>(component);
}

} // namespace python_general
} // namespace python_v2_0
