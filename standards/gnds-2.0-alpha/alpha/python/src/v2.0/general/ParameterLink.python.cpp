
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/ParameterLink.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// ParameterLink wrapper
void wrapParameterLink(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::ParameterLink;

   // create the component
   python::class_<Component> component(
      module, "ParameterLink",
      Component::component_t::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::string &,
            const std::string &,
            const std::optional<int> &,
            const std::optional<int> &
         >(),
         python::arg("label"),
         python::arg("href"),
         python::arg("n_parameters") = std::nullopt,
         python::arg("matrix_start_index") = std::nullopt,
         Component::component_t::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self)
         {
            return self.label();
         },
         Component::component_t::documentation("label").data()
      )
      .def_property_readonly(
         "href",
         [](const Component &self)
         {
            return self.href();
         },
         Component::component_t::documentation("href").data()
      )
      .def_property_readonly(
         "n_parameters",
         [](const Component &self)
         {
            return self.nParameters();
         },
         Component::component_t::documentation("n_parameters").data()
      )
      .def_property_readonly(
         "matrix_start_index",
         [](const Component &self)
         {
            return self.matrixStartIndex();
         },
         Component::component_t::documentation("matrix_start_index").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions<Component>(component);
}

} // namespace python_general
} // namespace python_v2_0
