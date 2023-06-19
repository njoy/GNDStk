
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "code/v2.0/gnds/Configurations.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_gnds {

// wrapper for gnds::Configurations
void wrapConfigurations(py::module &module)
{
   using namespace code;
   using namespace code::v2_0;

   // type aliases
   using cppCLASS = gnds::Configurations;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Configurations",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::vector<gnds::Configuration> &
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
      [](cppCLASS &self, const std::vector<gnds::Configuration> &value)
      {
         self.configuration() = value;
      },
      cppCLASS::component_t::documentation("configuration").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_gnds
} // namespace python_v2_0
