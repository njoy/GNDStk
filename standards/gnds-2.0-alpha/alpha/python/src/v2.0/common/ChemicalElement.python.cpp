
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/common/ChemicalElement.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_common {

// ChemicalElement wrapper
void wrapChemicalElement(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = common::ChemicalElement;

   // create the component
   python::class_<Component> component(
      module,
      "ChemicalElement",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::string &,
            const int &,
            const std::string &,
            const std::optional<atom::Atomic> &,
            const std::optional<common::Isotopes> &
         >(),
         python::arg("symbol"),
         python::arg("z"),
         python::arg("name"),
         python::arg("atomic") = std::nullopt,
         python::arg("isotopes") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "symbol",
         [](const Component &self) { return self.symbol(); },
         Component::documentation("symbol").data()
      )
      .def_property_readonly(
         "z",
         [](const Component &self) { return self.Z(); },
         Component::documentation("z").data()
      )
      .def_property_readonly(
         "name",
         [](const Component &self) { return self.name(); },
         Component::documentation("name").data()
      )
      .def_property_readonly(
         "atomic",
         [](const Component &self) { return self.atomic(); },
         Component::documentation("atomic").data()
      )
      .def_property_readonly(
         "isotopes",
         [](const Component &self) { return self.isotopes(); },
         Component::documentation("isotopes").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_common
} // namespace python_v2_0
