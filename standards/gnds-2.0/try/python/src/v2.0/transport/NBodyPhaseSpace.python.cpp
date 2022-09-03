
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/transport/NBodyPhaseSpace.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_transport {

// NBodyPhaseSpace wrapper
void wrapNBodyPhaseSpace(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = transport::NBodyPhaseSpace;

   // create the component
   python::class_<Component> component(
      module,
      "NBodyPhaseSpace",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<Integer32> &,
            const std::optional<tsl::Mass> &
         >(),
         python::arg("number_of_products") = std::nullopt,
         python::arg("mass") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "number_of_products",
         [](const Component &self) { return self.numberOfProducts(); },
         Component::documentation("number_of_products").data()
      )
      .def_property_readonly(
         "mass",
         [](const Component &self) { return self.mass(); },
         Component::documentation("mass").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_transport
} // namespace python_v2_0
