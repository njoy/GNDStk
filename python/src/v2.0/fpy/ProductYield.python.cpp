
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/fpy/ProductYield.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_fpy {

// ProductYield wrapper
void wrapProductYield(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = fpy::ProductYield;

   // create the component
   python::class_<Component> component(
      module,
      "ProductYield",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const XMLName &,
            const fpy::ElapsedTimes &,
            const std::optional<fpy::Nuclides> &
         >(),
         python::arg("label"),
         python::arg("elapsed_times"),
         python::arg("nuclides") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         &Component::label,
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "elapsed_times",
         python::overload_cast<>(&Component::elapsedTimes),
         Component::documentation("elapsed_times").data()
      )
      .def_property_readonly(
         "nuclides",
         python::overload_cast<>(&Component::nuclides),
         Component::documentation("nuclides").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_fpy
} // namespace python_v2_0