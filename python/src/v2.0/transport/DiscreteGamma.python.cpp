
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/transport/DiscreteGamma.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_transport {

// DiscreteGamma wrapper
void wrapDiscreteGamma(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = transport::DiscreteGamma;

   // create the component
   python::class_<Component> component(
      module,
      "DiscreteGamma",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<Float64> &,
            const std::optional<Float64> &,
            const std::optional<Float64> &,
            const std::optional<containers::Axes> &
         >(),
         python::arg("domain_max") = std::nullopt,
         python::arg("domain_min") = std::nullopt,
         python::arg("value") = std::nullopt,
         python::arg("axes") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "domain_max",
         &Component::domainMax,
         Component::documentation("domain_max").data()
      )
      .def_property_readonly(
         "domain_min",
         &Component::domainMin,
         Component::documentation("domain_min").data()
      )
      .def_property_readonly(
         "value",
         &Component::value,
         Component::documentation("value").data()
      )
      .def_property_readonly(
         "axes",
         python::overload_cast<>(&Component::axes),
         Component::documentation("axes").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_transport
} // namespace python_v2_0
