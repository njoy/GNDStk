
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "code/v2.0/gnds/Styles.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_gnds {

// wrapper for gnds::Styles
void wrapStyles(py::module &module)
{
   using namespace code;
   using namespace code::v2_0;

   // type aliases
   using cppCLASS = gnds::Styles;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Styles",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const gnds::Evaluated &
      >(),
      py::arg("evaluated"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set evaluated
   object.def_property(
      "evaluated",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.evaluated();
      },
      [](cppCLASS &self, const gnds::Evaluated &value)
      {
         self.evaluated() = value;
      },
      cppCLASS::component_t::documentation("evaluated").data()
   );

   // shortcut: get/set authors
   object.def_property(
      "authors",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.authors();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.authors())> &value)
      {
         self.authors() = value;
      },
      cppCLASS::component_t::documentation("authors").data()
   );

   // shortcut: get/set body
   object.def_property(
      "body",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.body();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.body())> &value)
      {
         self.body() = value;
      },
      cppCLASS::component_t::documentation("body").data()
   );

   // shortcut: get/set dates
   object.def_property(
      "dates",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.dates();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.dates())> &value)
      {
         self.dates() = value;
      },
      cppCLASS::component_t::documentation("dates").data()
   );

   // shortcut: get/set documentation
   object.def_property(
      "documentation",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.documentation();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.documentation())> &value)
      {
         self.documentation() = value;
      },
      cppCLASS::component_t::documentation("documentation").data()
   );

   // shortcut: get/set endfCompatible
   object.def_property(
      "endf_compatible",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.endfCompatible();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.endfCompatible())> &value)
      {
         self.endfCompatible() = value;
      },
      cppCLASS::component_t::documentation("endf_compatible").data()
   );

   // shortcut: get/set title
   object.def_property(
      "title",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.title();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.title())> &value)
      {
         self.title() = value;
      },
      cppCLASS::component_t::documentation("title").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_gnds
} // namespace python_v2_0
