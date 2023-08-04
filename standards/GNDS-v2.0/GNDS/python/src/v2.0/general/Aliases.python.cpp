
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/Aliases.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::Aliases
void wrapAliases(py::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::Aliases;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Aliases",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<std::vector<general::Alias>> &,
         const std::optional<std::vector<general::MetaStable>> &
      >(),
      py::arg("alias") = std::nullopt,
      py::arg("meta_stable") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set alias
   object.def_property(
      "alias",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.alias();
      },
      [](cppCLASS &self, const std::optional<std::vector<general::Alias>> &value)
      {
         self.alias() = value;
      },
      cppCLASS::component_t::documentation("alias").data()
   );

   // get/set metaStable
   object.def_property(
      "meta_stable",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.metaStable();
      },
      [](cppCLASS &self, const std::optional<std::vector<general::MetaStable>> &value)
      {
         self.metaStable() = value;
      },
      cppCLASS::component_t::documentation("meta_stable").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0