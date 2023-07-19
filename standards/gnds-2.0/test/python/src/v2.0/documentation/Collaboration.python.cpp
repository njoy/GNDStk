
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/documentation/Collaboration.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_documentation {

// wrapper for documentation::Collaboration
void wrapCollaboration(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = documentation::Collaboration;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Collaboration",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const UTF8Text &,
         const std::optional<UTF8Text> &
      >(),
      py::arg("name"),
      py::arg("href") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set name
   object.def_property(
      "name",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.name();
      },
      [](cppCLASS &self, const UTF8Text &value)
      {
         self.name() = value;
      },
      cppCLASS::component_t::documentation("name").data()
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

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_documentation
} // namespace python_v2_0
