
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/L.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::L
void wrapL(py::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::L;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "L",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::string &,
         const int &,
         const general::Js &
      >(),
      py::arg("label"),
      py::arg("value"),
      py::arg("js"),
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

   // get/set value
   object.def_property(
      "value",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.value();
      },
      [](cppCLASS &self, const int &value)
      {
         self.value() = value;
      },
      cppCLASS::component_t::documentation("value").data()
   );

   // get/set Js
   object.def_property(
      "js",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.Js();
      },
      [](cppCLASS &self, const general::Js &value)
      {
         self.Js() = value;
      },
      cppCLASS::component_t::documentation("js").data()
   );

   // shortcut: get/set J
   object.def_property(
      "j",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.J();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.J())> &value)
      {
         self.J() = value;
      },
      cppCLASS::component_t::documentation("j").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS
