
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/Configurations.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::Configurations
void wrapConfigurations(py::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::Configurations;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Configurations",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::vector<general::Configuration> &
      >(),
      py::arg("configuration"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set configuration
   object.def_property(
      "configuration",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.configuration();
      },
      [](cppCLASS &self, const std::vector<general::Configuration> &value)
      {
         self.configuration() = value;
      },
      cppCLASS::component_t::documentation("configuration").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS
