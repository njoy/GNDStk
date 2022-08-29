
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/pops/DecayPath.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_pops {

// DecayPath wrapper
void wrapDecayPath(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = pops::DecayPath;

   // create the component
   python::class_<Component> component(
      module,
      "DecayPath",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::vector<pops::Decay> &
         >(),
         python::arg("decay"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "decay",
         [](const Component &self) { return self.decay(); },
         Component::documentation("decay").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_pops
} // namespace python_v2_0
