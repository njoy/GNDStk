
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/documentation/Version.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_documentation {

// wrapper for documentation::Version
void wrapVersion(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = documentation::Version;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Version",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<XMLName> &,
         const std::optional<std::string> &,
         const std::optional<XMLName> &
      >(),
      py::arg("encoding") = std::nullopt,
      py::arg("markup") = std::nullopt,
      py::arg("label") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // constructor: from vector
   object.def(
      py::init<
         const std::vector<int> &
      >(),
      py::arg("ints"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // constructor: from vector
   object.def(
      py::init<
         const std::vector<double> &
      >(),
      py::arg("doubles"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // constructor: from vector
   object.def(
      py::init<
         const std::vector<std::string> &
      >(),
      py::arg("strings"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set encoding
   object.def_property(
      "encoding",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.encoding().value();
      },
      [](cppCLASS &self, const XMLName &value)
      {
         self.encoding() = value;
      },
      cppCLASS::component_t::documentation("encoding").data()
   );

   // get/set markup
   object.def_property(
      "markup",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.markup().value();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.markup() = value;
      },
      cppCLASS::component_t::documentation("markup").data()
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

   // get/set vector<int>
   object.def_property(
      "ints",
      [](const cppCLASS &self) -> const std::vector<int> &
      {
         return self.ints();
      },
      [](cppCLASS &self, const std::vector<int> &value)
      {
         self.ints() = value;
      },
      cppCLASS::component_t::documentation("ints").data()
   );

   // get/set vector<double>
   object.def_property(
      "doubles",
      [](const cppCLASS &self) -> const std::vector<double> &
      {
         return self.doubles();
      },
      [](cppCLASS &self, const std::vector<double> &value)
      {
         self.doubles() = value;
      },
      cppCLASS::component_t::documentation("doubles").data()
   );

   // get/set vector<std::string>
   object.def_property(
      "strings",
      [](const cppCLASS &self) -> const std::vector<std::string> &
      {
         return self.strings();
      },
      [](cppCLASS &self, const std::vector<std::string> &value)
      {
         self.strings() = value;
      },
      cppCLASS::component_t::documentation("strings").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_documentation
} // namespace python_v2_0
