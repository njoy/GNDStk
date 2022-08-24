
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/pops/Decay.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_pops {

// Decay wrapper
void wrapDecay(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = pops::Decay;

   // create the component
   python::class_<Component> component(
      module,
      "Decay",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<bool> &,
            const Integer32 &,
            const std::optional<enums::DecayType> &,
            const std::optional<pops::Products> &
         >(),
         python::arg("complete") = std::nullopt,
         python::arg("index"),
         python::arg("mode") = std::nullopt,
         python::arg("products") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "complete",
         [](const Component &self) { return self.complete().value(); },
         Component::documentation("complete").data()
      )
      .def_property_readonly(
         "index",
         &Component::index,
         Component::documentation("index").data()
      )
      .def_property_readonly(
         "mode",
         &Component::mode,
         Component::documentation("mode").data()
      )
      .def_property_readonly(
         "products",
         python::overload_cast<>(&Component::products),
         Component::documentation("products").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_pops
} // namespace python_v2_0