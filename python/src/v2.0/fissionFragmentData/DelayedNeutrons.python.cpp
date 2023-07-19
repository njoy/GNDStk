
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/fissionFragmentData/DelayedNeutrons.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_fissionFragmentData {

// DelayedNeutrons wrapper
void wrapDelayedNeutrons(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = fissionFragmentData::DelayedNeutrons;

   // create the component
   python::class_<Component> component(
      module,
      "DelayedNeutrons",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::vector<fissionFragmentData::DelayedNeutron> &
         >(),
         python::arg("delayed_neutron"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "delayed_neutron",
         python::overload_cast<>(&Component::delayedNeutron),
         Component::documentation("delayed_neutron").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_fissionFragmentData
} // namespace python_v2_0
