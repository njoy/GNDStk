
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "gnds/v2.0/general/Channels.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::Channels
void wrapChannels(py::module &module)
{
   using namespace gnds;
   using namespace gnds::v2_0;

   // type aliases
   using cppCLASS = general::Channels;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Channels",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::vector<general::Channel> &
      >(),
      py::arg("channel"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set channel
   object.def_property(
      "channel",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.channel();
      },
      [](cppCLASS &self, const std::vector<general::Channel> &value)
      {
         self.channel() = value;
      },
      cppCLASS::component_t::documentation("channel").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
