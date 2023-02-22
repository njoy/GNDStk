
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Standard.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::Standard
void wrapStandard(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::Standard;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Standard",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const reduced::Double &
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
      [](cppCLASS &self, const reduced::Double &value)
      {
         self.Double() = value;
      },
      cppCLASS::component_t::documentation("double").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0