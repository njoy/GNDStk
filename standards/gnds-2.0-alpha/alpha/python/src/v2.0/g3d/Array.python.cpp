
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/g3d/Array.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_g3d {

// wrapper for g3d::Array
void wrapArray(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = g3d::Array;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Array",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::string &,
         const std::optional<std::string> &,
         const std::optional<std::string> &,
         const std::optional<g3d::Starts> &,
         const std::optional<g3d::Lengths> &,
         const general::Values &
      >(),
      py::arg("shape"),
      py::arg("compression") = std::nullopt,
      py::arg("symmetry") = std::nullopt,
      py::arg("starts") = std::nullopt,
      py::arg("lengths") = std::nullopt,
      py::arg("values"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set shape
   object.def_property(
      "shape",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.shape();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.shape() = value;
      },
      cppCLASS::component_t::documentation("shape").data()
   );

   // get/set compression
   object.def_property(
      "compression",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.compression();
      },
      [](cppCLASS &self, const std::optional<std::string> &value)
      {
         self.compression() = value;
      },
      cppCLASS::component_t::documentation("compression").data()
   );

   // get/set symmetry
   object.def_property(
      "symmetry",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.symmetry();
      },
      [](cppCLASS &self, const std::optional<std::string> &value)
      {
         self.symmetry() = value;
      },
      cppCLASS::component_t::documentation("symmetry").data()
   );

   // get/set starts
   object.def_property(
      "starts",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.starts();
      },
      [](cppCLASS &self, const std::optional<g3d::Starts> &value)
      {
         self.starts() = value;
      },
      cppCLASS::component_t::documentation("starts").data()
   );

   // get/set lengths
   object.def_property(
      "lengths",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.lengths();
      },
      [](cppCLASS &self, const std::optional<g3d::Lengths> &value)
      {
         self.lengths() = value;
      },
      cppCLASS::component_t::documentation("lengths").data()
   );

   // get/set values
   object.def_property(
      "values",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.values();
      },
      [](cppCLASS &self, const general::Values &value)
      {
         self.values() = value;
      },
      cppCLASS::component_t::documentation("values").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_g3d
} // namespace python_v2_0
