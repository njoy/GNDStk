
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/cpTransport/RutherfordScattering.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_cpTransport {

// RutherfordScattering wrapper
void wrapRutherfordScattering(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = cpTransport::RutherfordScattering;

   // create the component
   python::class_<Component> component(
      module,
      "RutherfordScattering",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
         >(),
         Component::documentation("constructor").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_cpTransport
} // namespace python_v2_0
