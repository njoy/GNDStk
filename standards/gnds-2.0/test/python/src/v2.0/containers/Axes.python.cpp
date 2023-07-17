
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/containers/Axes.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_containers {

// wrapper for containers::Axes
void wrapAxes(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = containers::Axes;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Axes",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<UTF8Text> &,
         const std::optional<std::vector<containers::Axis>> &,
         const std::optional<std::vector<containers::Grid>> &
      >(),
      py::arg("href") = std::nullopt,
      py::arg("axis") = std::nullopt,
      py::arg("grid") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set href
   object.def_property(
      "href",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.href();
      },
      [](cppCLASS &self, const std::optional<UTF8Text> &value)
      {
         self.href() = value;
      },
      cppCLASS::component_t::documentation("href").data()
   );

   // get/set axis
   object.def_property(
      "axis",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.axis();
      },
      [](cppCLASS &self, const std::optional<std::vector<containers::Axis>> &value)
      {
         self.axis() = value;
      },
      cppCLASS::component_t::documentation("axis").data()
   );

   // get/set grid
   object.def_property(
      "grid",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.grid();
      },
      [](cppCLASS &self, const std::optional<std::vector<containers::Grid>> &value)
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
