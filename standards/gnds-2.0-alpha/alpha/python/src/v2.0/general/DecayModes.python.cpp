
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/DecayModes.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::DecayModes
void wrapDecayModes(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::DecayModes;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "DecayModes",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::vector<general::DecayMode> &
      >(),
      py::arg("decay_mode"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set decayMode
   object.def_property(
      "decay_mode",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.decayMode();
      },
      [](cppCLASS &self, const std::vector<general::DecayMode> &value)
      {
         self.decayMode() = value;
      },
      cppCLASS::component_t::documentation("decay_mode").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
