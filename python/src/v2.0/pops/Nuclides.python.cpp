
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/pops/Nuclides.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_pops {

// Nuclides wrapper
void wrapNuclides(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = pops::Nuclides;

   // create the component
   python::class_<Component> component(
      module,
      "Nuclides",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::vector<pops::Nuclide> &
         >(),
         python::arg("nuclide"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "nuclide",
         python::overload_cast<>(&Component::nuclide),
         Component::documentation("nuclide").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_pops
} // namespace python_v2_0
