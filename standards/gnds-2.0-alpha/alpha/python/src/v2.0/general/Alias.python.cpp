
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Alias.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::Alias
void wrapAlias(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::Alias;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Alias",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<std::string> &,
         const std::optional<std::string> &
      >(),
      py::arg("id") = std::nullopt,
      py::arg("pid") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set id
   object.def_property(
      "id",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.id();
      },
      [](cppCLASS &self, const std::optional<std::string> &value)
      {
         self.id() = value;
      },
      cppCLASS::component_t::documentation("id").data()
   );

   // get/set pid
   object.def_property(
      "pid",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.pid();
      },
      [](cppCLASS &self, const std::optional<std::string> &value)
      {
         self.pid() = value;
      },
      cppCLASS::component_t::documentation("pid").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0