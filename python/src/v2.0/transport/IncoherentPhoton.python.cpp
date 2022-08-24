
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/transport/IncoherentPhoton.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_transport {

// IncoherentPhoton wrapper
void wrapIncoherentPhoton(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = transport::IncoherentPhoton;

   // create the component
   python::class_<Component> component(
      module,
      "IncoherentPhoton",
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

} // namespace python_transport
} // namespace python_v2_0