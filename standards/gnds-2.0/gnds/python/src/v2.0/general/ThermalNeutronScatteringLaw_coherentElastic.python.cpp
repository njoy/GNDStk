
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "gnds/v2.0/general/ThermalNeutronScatteringLaw_coherentElastic.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::ThermalNeutronScatteringLaw_coherentElastic
void wrapThermalNeutronScatteringLaw_coherentElastic(py::module &module)
{
   using namespace gnds;
   using namespace gnds::v2_0;

   // type aliases
   using cppCLASS = general::ThermalNeutronScatteringLaw_coherentElastic;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "ThermalNeutronScatteringLaw_coherentElastic",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::string &,
         const std::string &,
         const std::string &,
         const general::S_table &
      >(),
      py::arg("label"),
      py::arg("pid"),
      py::arg("product_frame"),
      py::arg("s_table"),
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

   // get/set pid
   object.def_property(
      "pid",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.pid();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.pid() = value;
      },
      cppCLASS::component_t::documentation("pid").data()
   );

   // get/set productFrame
   object.def_property(
      "product_frame",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.productFrame();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.productFrame() = value;
      },
      cppCLASS::component_t::documentation("product_frame").data()
   );

   // get/set S_table
   object.def_property(
      "s_table",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.S_table();
      },
      [](cppCLASS &self, const general::S_table &value)
      {
         self.S_table() = value;
      },
      cppCLASS::component_t::documentation("s_table").data()
   );

   // shortcut: get/set array
   object.def_property(
      "array",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.array();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.array())> &value)
      {
         self.array() = value;
      },
      cppCLASS::component_t::documentation("array").data()
   );

   // shortcut: get/set axes
   object.def_property(
      "axes",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.axes();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.axes())> &value)
      {
         self.axes() = value;
      },
      cppCLASS::component_t::documentation("axes").data()
   );

   // shortcut: get/set gridded2d
   object.def_property(
      "gridded2d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.gridded2d();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.gridded2d())> &value)
      {
         self.gridded2d() = value;
      },
      cppCLASS::component_t::documentation("gridded2d").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
