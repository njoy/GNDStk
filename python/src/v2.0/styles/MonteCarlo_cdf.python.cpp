
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/styles/MonteCarlo_cdf.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_styles {

// MonteCarlo_cdf wrapper
void wrapMonteCarlo_cdf(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = styles::MonteCarlo_cdf;

   // create the component
   python::class_<Component> component(
      module,
      "MonteCarlo_cdf",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::string &,
            const XMLName &,
            const XMLName &,
            const std::optional<documentation::Documentation> &
         >(),
         python::arg("date"),
         python::arg("derived_from"),
         python::arg("label"),
         python::arg("documentation") = std::nullopt,
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
         "documentation",
         python::overload_cast<>(&Component::documentation),
         Component::documentation("documentation").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_styles
} // namespace python_v2_0
