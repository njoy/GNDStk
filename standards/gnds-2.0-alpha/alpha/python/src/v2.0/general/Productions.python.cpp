
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Productions.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::Productions
void wrapProductions(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::Productions;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Productions",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::vector<general::Production> &
      >(),
      py::arg("production"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set production
   object.def_property(
      "production",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.production();
      },
      [](cppCLASS &self, const std::vector<general::Production> &value)
      {
         self.production() = value;
      },
      cppCLASS::component_t::documentation("production").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
