
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/Summands.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::Summands
void wrapSummands(py::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::Summands;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Summands",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::vector<general::Add> &
      >(),
      py::arg("add"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set add
   object.def_property(
      "add",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.add();
      },
      [](cppCLASS &self, const std::vector<general::Add> &value)
      {
         self.add() = value;
      },
      cppCLASS::component_t::documentation("add").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS
