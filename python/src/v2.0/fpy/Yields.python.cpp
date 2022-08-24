
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/fpy/Yields.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_fpy {

// Yields wrapper
void wrapYields(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = fpy::Yields;

   // create the component
   python::class_<Component> component(
      module,
      "Yields",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const fpy::Nuclides &,
            const containers::Values &
         >(),
         python::arg("nuclides"),
         python::arg("values"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "nuclides",
         python::overload_cast<>(&Component::nuclides),
         Component::documentation("nuclides").data()
      )
      .def_property_readonly(
         "values",
         python::overload_cast<>(&Component::values),
         Component::documentation("values").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_fpy
} // namespace python_v2_0