
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/pops/Unorthodoxes.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_pops {

// Unorthodoxes wrapper
void wrapUnorthodoxes(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = pops::Unorthodoxes;

   // create the component
   python::class_<Component> component(
      module,
      "Unorthodoxes",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::vector<pops::Unorthodox> &
         >(),
         python::arg("unorthodox"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "unorthodox",
         python::overload_cast<>(&Component::unorthodox),
         Component::documentation("unorthodox").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_pops
} // namespace python_v2_0