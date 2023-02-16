
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "proto/v1.9/containers/Link.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v1_9 {
namespace python_containers {

// wrapper for containers::Link
void wrapLink(py::module &module)
{
   using namespace proto;
   using namespace proto::v1_9;

   // type aliases
   using cppCLASS = containers::Link;

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
      [](const cppCLASS &self) -> decltype(auto)
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

} // namespace python_containers
} // namespace python_v1_9
