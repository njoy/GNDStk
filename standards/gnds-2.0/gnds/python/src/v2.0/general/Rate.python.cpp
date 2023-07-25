
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "gnds/v2.0/general/Rate.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::Rate
void wrapRate(py::module &module)
{
   using namespace gnds;
   using namespace gnds::v2_0;

   // type aliases
   using cppCLASS = general::Rate;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Rate",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const general::Double &
      >(),
      py::arg("double"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set Double
   object.def_property(
      "double",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.Double();
      },
      [](cppCLASS &self, const general::Double &value)
      {
         self.Double() = value;
      },
      cppCLASS::component_t::documentation("double").data()
   );

   // shortcut: get/set uncertainty
   object.def_property(
      "uncertainty",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.uncertainty();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.uncertainty())> &value)
      {
         self.uncertainty() = value;
      },
      cppCLASS::component_t::documentation("uncertainty").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
