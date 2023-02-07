
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/top/PoPs.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_top {

// PoPs wrapper
void wrapPoPs(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = top::PoPs;

   // create the component
   python::class_<Component> component(
      module, "PoPs",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::string &,
            const std::string &,
            const std::string &,
            const std::optional<general::Aliases> &,
            const std::optional<general::Baryons> &,
            const std::optional<general::ChemicalElements> &,
            const std::optional<general::Styles> &,
            const std::optional<general::Unorthodoxes> &,
            const std::optional<general::GaugeBosons> &,
            const std::optional<general::Leptons> &
         >(),
         python::arg("name"),
         python::arg("version"),
         python::arg("format"),
         python::arg("aliases") = std::nullopt,
         python::arg("baryons") = std::nullopt,
         python::arg("chemical_elements") = std::nullopt,
         python::arg("styles") = std::nullopt,
         python::arg("unorthodoxes") = std::nullopt,
         python::arg("gauge_bosons") = std::nullopt,
         python::arg("leptons") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "name",
         [](const Component &self)
         {
            return self.name();
         },
         Component::documentation("name").data()
      )
      .def_property_readonly(
         "version",
         [](const Component &self)
         {
            return self.version();
         },
         Component::documentation("version").data()
      )
      .def_property_readonly(
         "format",
         [](const Component &self)
         {
            return self.format();
         },
         Component::documentation("format").data()
      )
      .def_property_readonly(
         "aliases",
         [](const Component &self)
         {
            return self.aliases();
         },
         Component::documentation("aliases").data()
      )
      .def_property_readonly(
         "baryons",
         [](const Component &self)
         {
            return self.baryons();
         },
         Component::documentation("baryons").data()
      )
      .def_property_readonly(
         "chemical_elements",
         [](const Component &self)
         {
            return self.chemicalElements();
         },
         Component::documentation("chemical_elements").data()
      )
      .def_property_readonly(
         "styles",
         [](const Component &self)
         {
            return self.styles();
         },
         Component::documentation("styles").data()
      )
      .def_property_readonly(
         "unorthodoxes",
         [](const Component &self)
         {
            return self.unorthodoxes();
         },
         Component::documentation("unorthodoxes").data()
      )
      .def_property_readonly(
         "gauge_bosons",
         [](const Component &self)
         {
            return self.gaugeBosons();
         },
         Component::documentation("gauge_bosons").data()
      )
      .def_property_readonly(
         "leptons",
         [](const Component &self)
         {
            return self.leptons();
         },
         Component::documentation("leptons").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions<Component>(component);
}

} // namespace python_top
} // namespace python_v2_0
