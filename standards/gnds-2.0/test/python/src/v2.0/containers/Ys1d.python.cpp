
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/containers/Ys1d.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_containers {

// wrapper for containers::Ys1d
void wrapYs1d(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = containers::Ys1d;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Ys1d",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<enums::Interpolation> &,
         const std::optional<XMLName> &,
         const containers::Axes &,
         const containers::Values &
      >(),
      py::arg("interpolation") = std::nullopt,
      py::arg("label") = std::nullopt,
      py::arg("axes"),
      py::arg("values"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set interpolation
   object.def_property(
      "interpolation",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.interpolation().value();
      },
      [](cppCLASS &self, const enums::Interpolation &value)
      {
         self.interpolation() = value;
      },
      cppCLASS::component_t::documentation("interpolation").data()
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

   // get/set values
   object.def_property(
      "values",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.values();
      },
      [](cppCLASS &self, const containers::Values &value)
      {
         self.values() = value;
      },
      cppCLASS::component_t::documentation("values").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_containers
} // namespace python_v2_0
