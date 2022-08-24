
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/tsl/ScatteringAtoms.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_tsl {

// ScatteringAtoms wrapper
void wrapScatteringAtoms(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = tsl::ScatteringAtoms;

   // create the component
   python::class_<Component> component(
      module,
      "ScatteringAtoms",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::vector<tsl::ScatteringAtom> &
         >(),
         python::arg("scattering_atom"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "scattering_atom",
         python::overload_cast<>(&Component::scatteringAtom),
         Component::documentation("scattering_atom").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_tsl
} // namespace python_v2_0