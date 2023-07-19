
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/pops/Spin.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_pops {

// Spin wrapper
void wrapSpin(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = pops::Spin;

   // create the component
   python::class_<Component> component(
      module,
      "Spin",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<std::vector<containers::Fraction>> &
         >(),
         python::arg("fraction") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "fraction",
         python::overload_cast<>(&Component::fraction),
         Component::documentation("fraction").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_pops
} // namespace python_v2_0
