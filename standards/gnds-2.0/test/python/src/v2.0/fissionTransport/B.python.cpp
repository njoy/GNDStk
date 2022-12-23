
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/fissionTransport/B.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_fissionTransport {

// B wrapper
void wrapB(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = fissionTransport::B;

   // create the component
   python::class_<Component> component(
      module,
      "B",
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

} // namespace python_fissionTransport
} // namespace python_v2_0
