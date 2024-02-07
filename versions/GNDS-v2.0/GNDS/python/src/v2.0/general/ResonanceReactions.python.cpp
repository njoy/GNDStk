
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/ResonanceReactions.hpp"
#include "definitions.hpp"

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::ResonanceReactions
void wrapResonanceReactions(pybind11::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::ResonanceReactions;

   // create the Python object
   pybind11::class_<cppCLASS> object(
      module, "ResonanceReactions",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      pybind11::init<
         const std::vector<general::ResonanceReaction> &
      >(),
      pybind11::arg("resonance_reaction"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set resonanceReaction
   object.def_property(
      "resonance_reaction",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.resonanceReaction();
      },
      [](cppCLASS &self, const std::vector<general::ResonanceReaction> &value)
      {
         self.resonanceReaction() = value;
      },
      cppCLASS::component_t::documentation("resonance_reaction").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS
