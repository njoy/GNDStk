
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "gnds/v2.0/general/Gridded2d.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::Gridded2d
void wrapGridded2d(py::module &module)
{
   using namespace gnds;
   using namespace gnds::v2_0;

   // type aliases
   using cppCLASS = general::Gridded2d;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Gridded2d",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const general::Axes &,
         const g2d::Array &
      >(),
      py::arg("axes"),
      py::arg("array"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set axes
   object.def_property(
      "axes",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.axes();
      },
      [](cppCLASS &self, const general::Axes &value)
      {
         self.axes() = value;
      },
      cppCLASS::component_t::documentation("axes").data()
   );

   // get/set array
   object.def_property(
      "array",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.array();
      },
      [](cppCLASS &self, const g2d::Array &value)
      {
         self.array() = value;
      },
      cppCLASS::component_t::documentation("array").data()
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

} // namespace python_general
} // namespace python_v2_0
