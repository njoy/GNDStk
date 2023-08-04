
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/CovarianceMatrix.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::CovarianceMatrix
void wrapCovarianceMatrix(py::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::CovarianceMatrix;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "CovarianceMatrix",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::string &,
         const std::string &,
         const std::optional<std::string> &,
         const general::Gridded2d &
      >(),
      py::arg("label"),
      py::arg("type"),
      py::arg("product_frame") = std::nullopt,
      py::arg("gridded2d"),
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

   // get/set type
   object.def_property(
      "type",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.type();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.type() = value;
      },
      cppCLASS::component_t::documentation("type").data()
   );

   // get/set productFrame
   object.def_property(
      "product_frame",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.productFrame();
      },
      [](cppCLASS &self, const std::optional<std::string> &value)
      {
         self.productFrame() = value;
      },
      cppCLASS::component_t::documentation("product_frame").data()
   );

   // get/set gridded2d
   object.def_property(
      "gridded2d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.gridded2d();
      },
      [](cppCLASS &self, const general::Gridded2d &value)
      {
         self.gridded2d() = value;
      },
      cppCLASS::component_t::documentation("gridded2d").data()
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

   // shortcut: get/set values
   object.def_property(
      "values",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.values();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.values())> &value)
      {
         self.values() = value;
      },
      cppCLASS::component_t::documentation("values").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS
