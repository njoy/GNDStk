
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/transport/WeightedFunctionals.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_transport {

// WeightedFunctionals wrapper
void wrapWeightedFunctionals(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = transport::WeightedFunctionals;

   // create the component
   python::class_<Component> component(
      module,
      "WeightedFunctionals",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const transport::Weighted &
         >(),
         python::arg("weighted"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "weighted",
         python::overload_cast<>(&Component::weighted),
         Component::documentation("weighted").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_transport
} // namespace python_v2_0