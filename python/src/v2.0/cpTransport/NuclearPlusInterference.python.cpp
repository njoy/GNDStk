
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/cpTransport/NuclearPlusInterference.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_cpTransport {

// NuclearPlusInterference wrapper
void wrapNuclearPlusInterference(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = cpTransport::NuclearPlusInterference;

   // create the component
   python::class_<Component> component(
      module,
      "NuclearPlusInterference",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const Float64 &,
            const transport::CrossSection &,
            const transport::Distribution &
         >(),
         python::arg("mu_cutoff"),
         python::arg("cross_section"),
         python::arg("distribution"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "mu_cutoff",
         &Component::muCutoff,
         Component::documentation("mu_cutoff").data()
      )
      .def_property_readonly(
         "cross_section",
         python::overload_cast<>(&Component::crossSection),
         Component::documentation("cross_section").data()
      )
      .def_property_readonly(
         "distribution",
         python::overload_cast<>(&Component::distribution),
         Component::documentation("distribution").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_cpTransport
} // namespace python_v2_0