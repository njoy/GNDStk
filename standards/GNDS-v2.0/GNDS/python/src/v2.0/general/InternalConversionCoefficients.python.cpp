
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/InternalConversionCoefficients.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::InternalConversionCoefficients
void wrapInternalConversionCoefficients(py::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::InternalConversionCoefficients;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "InternalConversionCoefficients",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::vector<general::Shell> &
      >(),
      py::arg("shell"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set shell
   object.def_property(
      "shell",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.shell();
      },
      [](cppCLASS &self, const std::vector<general::Shell> &value)
      {
         self.shell() = value;
      },
      cppCLASS::component_t::documentation("shell").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS
