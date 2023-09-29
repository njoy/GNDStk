
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/ChemicalElements.hpp"
#include "definitions.hpp"

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::ChemicalElements
void wrapChemicalElements(pybind11::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::ChemicalElements;

   // create the Python object
   pybind11::class_<cppCLASS> object(
      module, "ChemicalElements",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      pybind11::init<
         const std::vector<general::ChemicalElement> &
      >(),
      pybind11::arg("chemical_element"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set chemicalElement
   object.def_property(
      "chemical_element",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.chemicalElement();
      },
      [](cppCLASS &self, const std::vector<general::ChemicalElement> &value)
      {
         self.chemicalElement() = value;
      },
      cppCLASS::component_t::documentation("chemical_element").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS
