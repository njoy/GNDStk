
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/styles/CoulombPlusNuclearElasticMuCutoff.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_styles {

// CoulombPlusNuclearElasticMuCutoff wrapper
void wrapCoulombPlusNuclearElasticMuCutoff(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = styles::CoulombPlusNuclearElasticMuCutoff;

   // create the component
   python::class_<Component> component(
      module,
      "CoulombPlusNuclearElasticMuCutoff",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::string &,
            const XMLName &,
            const XMLName &,
            const Float64 &
         >(),
         python::arg("date"),
         python::arg("derived_from"),
         python::arg("label"),
         python::arg("mu_cutoff"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "date",
         &Component::date,
         Component::documentation("date").data()
      )
      .def_property_readonly(
         "derived_from",
         &Component::derivedFrom,
         Component::documentation("derived_from").data()
      )
      .def_property_readonly(
         "label",
         &Component::label,
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "mu_cutoff",
         &Component::muCutoff,
         Component::documentation("mu_cutoff").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_styles
} // namespace python_v2_0