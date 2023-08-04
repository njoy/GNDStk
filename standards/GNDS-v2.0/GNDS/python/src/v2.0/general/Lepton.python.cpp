
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/Lepton.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::Lepton
void wrapLepton(py::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::Lepton;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Lepton",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::string &,
         const std::string &,
         const general::Mass &,
         const general::Spin &,
         const general::Parity &,
         const general::Charge &,
         const general::Halflife &
      >(),
      py::arg("id"),
      py::arg("generation"),
      py::arg("mass"),
      py::arg("spin"),
      py::arg("parity"),
      py::arg("charge"),
      py::arg("halflife"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set id
   object.def_property(
      "id",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.id();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.id() = value;
      },
      cppCLASS::component_t::documentation("id").data()
   );

   // get/set generation
   object.def_property(
      "generation",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.generation();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.generation() = value;
      },
      cppCLASS::component_t::documentation("generation").data()
   );

   // get/set mass
   object.def_property(
      "mass",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.mass();
      },
      [](cppCLASS &self, const general::Mass &value)
      {
         self.mass() = value;
      },
      cppCLASS::component_t::documentation("mass").data()
   );

   // get/set spin
   object.def_property(
      "spin",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.spin();
      },
      [](cppCLASS &self, const general::Spin &value)
      {
         self.spin() = value;
      },
      cppCLASS::component_t::documentation("spin").data()
   );

   // get/set parity
   object.def_property(
      "parity",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.parity();
      },
      [](cppCLASS &self, const general::Parity &value)
      {
         self.parity() = value;
      },
      cppCLASS::component_t::documentation("parity").data()
   );

   // get/set charge
   object.def_property(
      "charge",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.charge();
      },
      [](cppCLASS &self, const general::Charge &value)
      {
         self.charge() = value;
      },
      cppCLASS::component_t::documentation("charge").data()
   );

   // get/set halflife
   object.def_property(
      "halflife",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.halflife();
      },
      [](cppCLASS &self, const general::Halflife &value)
      {
         self.halflife() = value;
      },
      cppCLASS::component_t::documentation("halflife").data()
   );

   // shortcut: get/set fraction
   object.def_property(
      "fraction",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.fraction();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.fraction())> &value)
      {
         self.fraction() = value;
      },
      cppCLASS::component_t::documentation("fraction").data()
   );

   // shortcut: get/set string
   object.def_property(
      "string",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.string();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.string())> &value)
      {
         self.string() = value;
      },
      cppCLASS::component_t::documentation("string").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0