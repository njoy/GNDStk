
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/transport/Forward.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_transport {

// Forward wrapper
void wrapForward(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = transport::Forward;

   // create the component
   python::class_<Component> component(
      module,
      "Forward",
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
