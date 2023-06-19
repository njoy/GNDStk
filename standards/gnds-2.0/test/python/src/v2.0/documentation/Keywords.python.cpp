
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/documentation/Keywords.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_documentation {

// wrapper for documentation::Keywords
void wrapKeywords(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = documentation::Keywords;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Keywords",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::vector<documentation::Keyword> &
      >(),
      py::arg("keyword"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set keyword
   object.def_property(
      "keyword",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.keyword();
      },
      [](cppCLASS &self, const std::vector<documentation::Keyword> &value)
      {
         self.keyword() = value;
      },
      cppCLASS::component_t::documentation("keyword").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_documentation
} // namespace python_v2_0
