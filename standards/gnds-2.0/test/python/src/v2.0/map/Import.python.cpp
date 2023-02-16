
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/map/Import.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_map {

// wrapper for map::Import
void wrapImport(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = map::Import;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Import",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const XMLName &,
         const std::string &,
         const std::optional<enums::HashAlgorithm> &
      >(),
      py::arg("path"),
      py::arg("checksum"),
      py::arg("algorithm") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set path
   object.def_property(
      "path",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.path();
      },
      [](cppCLASS &self, const XMLName &value)
      {
         self.path() = value;
      },
      cppCLASS::component_t::documentation("path").data()
   );

   // get/set checksum
   object.def_property(
      "checksum",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.checksum();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.checksum() = value;
      },
      cppCLASS::component_t::documentation("checksum").data()
   );

   // get/set algorithm
   object.def_property(
      "algorithm",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.algorithm();
      },
      [](cppCLASS &self, const std::optional<enums::HashAlgorithm> &value)
      {
         self.algorithm() = value;
      },
      cppCLASS::component_t::documentation("algorithm").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_map
} // namespace python_v2_0
