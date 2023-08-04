
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/Parameters.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::Parameters
void wrapParameters(py::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::Parameters;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Parameters",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::vector<general::ParameterLink> &
      >(),
      py::arg("parameter_link"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set parameterLink
   object.def_property(
      "parameter_link",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.parameterLink();
      },
      [](cppCLASS &self, const std::vector<general::ParameterLink> &value)
      {
         self.parameterLink() = value;
      },
      cppCLASS::component_t::documentation("parameter_link").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS
