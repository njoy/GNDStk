
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/ResonanceParameters.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::ResonanceParameters
void wrapResonanceParameters(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::ResonanceParameters;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "ResonanceParameters",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const general::Table &
      >(),
      py::arg("table"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set table
   object.def_property(
      "table",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.table();
      },
      [](cppCLASS &self, const general::Table &value)
      {
         self.table() = value;
      },
      cppCLASS::component_t::documentation("table").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0