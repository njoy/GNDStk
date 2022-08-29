
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/atomic/IncoherentPhotonScattering.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_atomic {

// IncoherentPhotonScattering wrapper
void wrapIncoherentPhotonScattering(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = atomic::IncoherentPhotonScattering;

   // create the component
   python::class_<Component> component(
      module,
      "IncoherentPhotonScattering",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<std::string> &,
            const std::optional<XMLName> &,
            const std::optional<XMLName> &,
            const enums::Frame &,
            const std::optional<atomic::ScatteringFactor> &
         >(),
         python::arg("href") = std::nullopt,
         python::arg("label") = std::nullopt,
         python::arg("pid") = std::nullopt,
         python::arg("product_frame"),
         python::arg("scattering_factor") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "href",
         [](const Component &self) { return self.href(); },
         Component::documentation("href").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self) { return self.label(); },
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "pid",
         [](const Component &self) { return self.pid(); },
         Component::documentation("pid").data()
      )
      .def_property_readonly(
         "product_frame",
         [](const Component &self) { return self.productFrame(); },
         Component::documentation("product_frame").data()
      )
      .def_property_readonly(
         "scattering_factor",
         [](const Component &self) { return self.scatteringFactor(); },
         Component::documentation("scattering_factor").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_atomic
} // namespace python_v2_0
