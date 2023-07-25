
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "gnds/v2.0/general/Isotope.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::Isotope
void wrapIsotope(py::module &module)
{
   using namespace gnds;
   using namespace gnds::v2_0;

   // type aliases
   using cppCLASS = general::Isotope;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Isotope",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::string &,
         const int &,
         const general::Nuclides &
      >(),
      py::arg("symbol"),
      py::arg("a"),
      py::arg("nuclides"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set symbol
   object.def_property(
      "symbol",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.symbol();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.symbol() = value;
      },
      cppCLASS::component_t::documentation("symbol").data()
   );

   // get/set A
   object.def_property(
      "a",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.A();
      },
      [](cppCLASS &self, const int &value)
      {
         self.A() = value;
      },
      cppCLASS::component_t::documentation("a").data()
   );

   // get/set nuclides
   object.def_property(
      "nuclides",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.nuclides();
      },
      [](cppCLASS &self, const general::Nuclides &value)
      {
         self.nuclides() = value;
      },
      cppCLASS::component_t::documentation("nuclides").data()
   );

   // shortcut: get/set nuclide
   object.def_property(
      "nuclide",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.nuclide();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.nuclide())> &value)
      {
         self.nuclide() = value;
      },
      cppCLASS::component_t::documentation("nuclide").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
