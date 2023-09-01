
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/DecayPath.hpp"
#include "definitions.hpp"

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::DecayPath
void wrapDecayPath(pybind11::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::DecayPath;

   // create the Python object
   pybind11::class_<cppCLASS> object(
      module, "DecayPath",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      pybind11::init<
         const std::vector<general::Decay> &
      >(),
      pybind11::arg("decay"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set decay
   object.def_property(
      "decay",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.decay();
      },
      [](cppCLASS &self, const std::vector<general::Decay> &value)
      {
         self.decay() = value;
      },
      cppCLASS::component_t::documentation("decay").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS
