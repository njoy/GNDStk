
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/containers/Gridded2d.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_containers {

// wrapper for containers::Gridded2d
void wrapGridded2d(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = containers::Gridded2d;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Gridded2d",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<XMLName> &,
         const containers::Array &,
         const containers::Axes &
      >(),
      py::arg("label") = std::nullopt,
      py::arg("array"),
      py::arg("axes"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set label
   object.def_property(
      "label",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.label();
      },
      [](cppCLASS &self, const std::optional<XMLName> &value)
      {
         self.label() = value;
      },
      cppCLASS::component_t::documentation("label").data()
   );

   // get/set array
   object.def_property(
      "array",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.array();
      },
      [](cppCLASS &self, const containers::Array &value)
      {
         self.array() = value;
      },
      cppCLASS::component_t::documentation("array").data()
   );

   // get/set axes
   object.def_property(
      "axes",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.axes();
      },
      [](cppCLASS &self, const containers::Axes &value)
      {
         self.axes() = value;
      },
      cppCLASS::component_t::documentation("axes").data()
   );

   // shortcut: get/set axis
   object.def_property(
      "axis",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.axis();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.axis())> &value)
      {
         self.axis() = value;
      },
      cppCLASS::component_t::documentation("axis").data()
   );

   // shortcut: get/set grid
   object.def_property(
      "grid",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.grid();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.grid())> &value)
      {
         self.grid() = value;
      },
      cppCLASS::component_t::documentation("grid").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_containers
} // namespace python_v2_0
