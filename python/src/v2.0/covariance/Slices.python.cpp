
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/covariance/Slices.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_covariance {

// Slices wrapper
void wrapSlices(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = covariance::Slices;

   // create the component
   python::class_<Component> component(
      module,
      "Slices",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::vector<covariance::Slice> &
         >(),
         python::arg("slice"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "slice",
         python::overload_cast<>(&Component::slice),
         Component::documentation("slice").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_covariance
} // namespace python_v2_0
