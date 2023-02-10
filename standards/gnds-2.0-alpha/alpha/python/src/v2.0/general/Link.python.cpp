
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Link.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::Link
void wrapLink(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::Link;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Link",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::string &
      >(),
      py::arg("href"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set href
   object.def_property(
      "href",
      [](const cppCLASS &self)
      {
         return self.href();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.href() = value;
      },
      cppCLASS::component_t::documentation("href").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
