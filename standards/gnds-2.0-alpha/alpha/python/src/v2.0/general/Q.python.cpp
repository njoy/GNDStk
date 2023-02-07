
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Q.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// Q wrapper
void wrapQ(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::Q;

   // create the component
   python::class_<Component> component(
      module, "Q",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<general::Double> &,
            const std::optional<general::Constant1d> &
         >(),
         python::arg("double") = std::nullopt,
         python::arg("constant1d") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "double",
         [](const Component &self)
         {
            return self.Double();
         },
         Component::documentation("double").data()
      )
      .def_property_readonly(
         "constant1d",
         [](const Component &self)
         {
            return self.constant1d();
         },
         Component::documentation("constant1d").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions<Component>(component);
}

} // namespace python_general
} // namespace python_v2_0
