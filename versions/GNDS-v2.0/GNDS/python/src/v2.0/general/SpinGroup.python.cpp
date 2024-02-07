
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/SpinGroup.hpp"
#include "definitions.hpp"

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::SpinGroup
void wrapSpinGroup(pybind11::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::SpinGroup;

   // create the Python object
   pybind11::class_<cppCLASS> object(
      module, "SpinGroup",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      pybind11::init<
         const std::string &,
         const int &,
         const int &,
         const general::Channels &,
         const general::ResonanceParameters &
      >(),
      pybind11::arg("label"),
      pybind11::arg("spin"),
      pybind11::arg("parity"),
      pybind11::arg("channels"),
      pybind11::arg("resonance_parameters"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set label
   object.def_property(
      "label",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.label();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.label() = value;
      },
      cppCLASS::component_t::documentation("label").data()
   );

   // get/set spin
   object.def_property(
      "spin",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.spin();
      },
      [](cppCLASS &self, const int &value)
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
      [](cppCLASS &self, const int &value)
      {
         self.parity() = value;
      },
      cppCLASS::component_t::documentation("parity").data()
   );

   // get/set channels
   object.def_property(
      "channels",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.channels();
      },
      [](cppCLASS &self, const general::Channels &value)
      {
         self.channels() = value;
      },
      cppCLASS::component_t::documentation("channels").data()
   );

   // get/set resonanceParameters
   object.def_property(
      "resonance_parameters",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.resonanceParameters();
      },
      [](cppCLASS &self, const general::ResonanceParameters &value)
      {
         self.resonanceParameters() = value;
      },
      cppCLASS::component_t::documentation("resonance_parameters").data()
   );

   // shortcut: get/set channel
   object.def_property(
      "channel",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.channel();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.channel())> &value)
      {
         self.channel() = value;
      },
      cppCLASS::component_t::documentation("channel").data()
   );

   // shortcut: get/set columnHeaders
   object.def_property(
      "column_headers",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.columnHeaders();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.columnHeaders())> &value)
      {
         self.columnHeaders() = value;
      },
      cppCLASS::component_t::documentation("column_headers").data()
   );

   // shortcut: get/set data
   object.def_property(
      "data",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.data();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.data())> &value)
      {
         self.data() = value;
      },
      cppCLASS::component_t::documentation("data").data()
   );

   // shortcut: get/set table
   object.def_property(
      "table",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.table();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.table())> &value)
      {
         self.table() = value;
      },
      cppCLASS::component_t::documentation("table").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS