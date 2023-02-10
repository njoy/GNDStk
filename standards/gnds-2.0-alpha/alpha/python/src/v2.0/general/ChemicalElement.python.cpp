
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/ChemicalElement.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::ChemicalElement
void wrapChemicalElement(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::ChemicalElement;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "ChemicalElement",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::string &,
         const int &,
         const std::string &,
         const std::optional<general::Atomic> &,
         const std::optional<general::Isotopes> &
      >(),
      py::arg("symbol"),
      py::arg("z"),
      py::arg("name"),
      py::arg("atomic") = std::nullopt,
      py::arg("isotopes") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set symbol
   object.def_property(
      "symbol",
      [](const cppCLASS &self)
      {
         return self.symbol();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.symbol() = value;
      },
      cppCLASS::component_t::documentation("symbol").data()
   );

   // get/set Z
   object.def_property(
      "z",
      [](const cppCLASS &self)
      {
         return self.Z();
      },
      [](cppCLASS &self, const int &value)
      {
         self.Z() = value;
      },
      cppCLASS::component_t::documentation("z").data()
   );

   // get/set name
   object.def_property(
      "name",
      [](const cppCLASS &self)
      {
         return self.name();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.name() = value;
      },
      cppCLASS::component_t::documentation("name").data()
   );

   // get/set atomic
   object.def_property(
      "atomic",
      [](const cppCLASS &self)
      {
         return self.atomic();
      },
      [](cppCLASS &self, const std::optional<general::Atomic> &value)
      {
         self.atomic() = value;
      },
      cppCLASS::component_t::documentation("atomic").data()
   );

   // get/set isotopes
   object.def_property(
      "isotopes",
      [](const cppCLASS &self)
      {
         return self.isotopes();
      },
      [](cppCLASS &self, const std::optional<general::Isotopes> &value)
      {
         self.isotopes() = value;
      },
      cppCLASS::component_t::documentation("isotopes").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
