
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/Reference.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::Reference
void wrapReference(py::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::Reference;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Reference",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::string &,
         const std::string &
      >(),
      py::arg("label"),
      py::arg("href"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set label
   object.def_property(
      "label",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.label();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.label() = value;
      },
      cppCLASS::component_t::documentation("label").data()
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

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS
