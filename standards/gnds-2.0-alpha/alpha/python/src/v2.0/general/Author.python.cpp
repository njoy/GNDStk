
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Author.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::Author
void wrapAuthor(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::Author;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Author",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::string &
      >(),
      py::arg("name"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set name
   object.def_property(
      "name",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.name();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.name() = value;
      },
      cppCLASS::component_t::documentation("name").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
