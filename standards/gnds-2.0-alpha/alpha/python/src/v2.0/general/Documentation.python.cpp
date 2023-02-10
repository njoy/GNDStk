
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Documentation.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::Documentation
void wrapDocumentation(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::Documentation;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Documentation",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const general::Authors &,
         const general::Dates &,
         const general::Title &,
         const general::Body &,
         const std::optional<general::EndfCompatible> &
      >(),
      py::arg("authors"),
      py::arg("dates"),
      py::arg("title"),
      py::arg("body"),
      py::arg("endf_compatible") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set authors
   object.def_property(
      "authors",
      [](const cppCLASS &self)
      {
         return self.authors();
      },
      [](cppCLASS &self, const general::Authors &value)
      {
         self.authors() = value;
      },
      cppCLASS::component_t::documentation("authors").data()
   );

   // get/set dates
   object.def_property(
      "dates",
      [](const cppCLASS &self)
      {
         return self.dates();
      },
      [](cppCLASS &self, const general::Dates &value)
      {
         self.dates() = value;
      },
      cppCLASS::component_t::documentation("dates").data()
   );

   // get/set title
   object.def_property(
      "title",
      [](const cppCLASS &self)
      {
         return self.title();
      },
      [](cppCLASS &self, const general::Title &value)
      {
         self.title() = value;
      },
      cppCLASS::component_t::documentation("title").data()
   );

   // get/set body
   object.def_property(
      "body",
      [](const cppCLASS &self)
      {
         return self.body();
      },
      [](cppCLASS &self, const general::Body &value)
      {
         self.body() = value;
      },
      cppCLASS::component_t::documentation("body").data()
   );

   // get/set endfCompatible
   object.def_property(
      "endf_compatible",
      [](const cppCLASS &self)
      {
         return self.endfCompatible();
      },
      [](cppCLASS &self, const std::optional<general::EndfCompatible> &value)
      {
         self.endfCompatible() = value;
      },
      cppCLASS::component_t::documentation("endf_compatible").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
