
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/ChemicalElements.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// ChemicalElements wrapper
void wrapChemicalElements(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::ChemicalElements;

   // create the component
   python::class_<Component> component(
      module, "ChemicalElements",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::vector<general::ChemicalElement> &
         >(),
         python::arg("chemical_element"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "chemical_element",
         [](const Component &self)
         {
            return self.chemicalElement();
         },
         Component::documentation("chemical_element").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions<Component>(component);
}

} // namespace python_general
} // namespace python_v2_0
