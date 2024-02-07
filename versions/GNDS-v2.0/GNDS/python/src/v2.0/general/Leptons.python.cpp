
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/Leptons.hpp"
#include "definitions.hpp"

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::Leptons
void wrapLeptons(pybind11::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::Leptons;

   // create the Python object
   pybind11::class_<cppCLASS> object(
      module, "Leptons",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      pybind11::init<
         const std::vector<general::Lepton> &
      >(),
      pybind11::arg("lepton"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set lepton
   object.def_property(
      "lepton",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.lepton();
      },
      [](cppCLASS &self, const std::vector<general::Lepton> &value)
      {
         self.lepton() = value;
      },
      cppCLASS::component_t::documentation("lepton").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS
