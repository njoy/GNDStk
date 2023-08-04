
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/Time.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::Time
void wrapTime(py::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::Time;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Time",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<general::Double> &,
         const std::optional<general::String> &
      >(),
      py::arg("double") = std::nullopt,
      py::arg("string") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set Double
   object.def_property(
      "double",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.Double();
      },
      [](cppCLASS &self, const std::optional<general::Double> &value)
      {
         self.Double() = value;
      },
      cppCLASS::component_t::documentation("double").data()
   );

   // get/set string
   object.def_property(
      "string",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.string();
      },
      [](cppCLASS &self, const std::optional<general::String> &value)
      {
         self.string() = value;
      },
      cppCLASS::component_t::documentation("string").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS
