
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Grid.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// Grid wrapper
void wrapGrid(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::Grid;

   // create the component
   python::class_<Component> component(
      module,
      "Grid",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const int &,
            const std::string &,
            const std::string &,
            const std::string &,
            const std::optional<std::string> &,
            const std::optional<general::Link> &,
            const std::optional<general::Values> &
         >(),
         python::arg("index"),
         python::arg("label"),
         python::arg("unit"),
         python::arg("style"),
         python::arg("interpolation") = std::nullopt,
         python::arg("link") = std::nullopt,
         python::arg("values") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "index",
         [](const Component &self) { return self.index(); },
         Component::documentation("index").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self) { return self.label(); },
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "unit",
         [](const Component &self) { return self.unit(); },
         Component::documentation("unit").data()
      )
      .def_property_readonly(
         "style",
         [](const Component &self) { return self.style(); },
         Component::documentation("style").data()
      )
      .def_property_readonly(
         "interpolation",
         [](const Component &self) { return self.interpolation(); },
         Component::documentation("interpolation").data()
      )
      .def_property_readonly(
         "link",
         [](const Component &self) { return self.link(); },
         Component::documentation("link").data()
      )
      .def_property_readonly(
         "values",
         [](const Component &self) { return self.values(); },
         Component::documentation("values").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_general
} // namespace python_v2_0
