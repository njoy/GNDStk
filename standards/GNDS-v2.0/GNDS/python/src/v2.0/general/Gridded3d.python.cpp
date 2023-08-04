
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/Gridded3d.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::Gridded3d
void wrapGridded3d(py::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::Gridded3d;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Gridded3d",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const general::Axes &,
         const g3d::Array &
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
      [](cppCLASS &self, const g3d::Array &value)
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

   // shortcut: get/set lengths
   object.def_property(
      "lengths",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.lengths();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.lengths())> &value)
      {
         self.lengths() = value;
      },
      cppCLASS::component_t::documentation("lengths").data()
   );

   // shortcut: get/set starts
   object.def_property(
      "starts",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.starts();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.starts())> &value)
      {
         self.starts() = value;
      },
      cppCLASS::component_t::documentation("starts").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS
