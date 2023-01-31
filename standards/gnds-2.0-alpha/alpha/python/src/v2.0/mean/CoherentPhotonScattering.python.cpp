
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/mean/CoherentPhotonScattering.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_mean {

// CoherentPhotonScattering wrapper
void wrapCoherentPhotonScattering(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = mean::CoherentPhotonScattering;

   // create the component
   python::class_<Component> component(
      module,
      "CoherentPhotonScattering",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::string &,
            const std::optional<std::string> &,
            const std::optional<std::string> &,
            const std::optional<std::string> &,
            const std::optional<mean::FormFactor> &,
            const std::optional<mean::RealAnomalousFactor> &,
            const std::optional<mean::ImaginaryAnomalousFactor> &
         >(),
         python::arg("label"),
         python::arg("href") = std::nullopt,
         python::arg("pid") = std::nullopt,
         python::arg("product_frame") = std::nullopt,
         python::arg("form_factor") = std::nullopt,
         python::arg("real_anomalous_factor") = std::nullopt,
         python::arg("imaginary_anomalous_factor") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self) { return self.label(); },
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "href",
         [](const Component &self) { return self.href(); },
         Component::documentation("href").data()
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
         "form_factor",
         [](const Component &self) { return self.formFactor(); },
         Component::documentation("form_factor").data()
      )
      .def_property_readonly(
         "real_anomalous_factor",
         [](const Component &self) { return self.realAnomalousFactor(); },
         Component::documentation("real_anomalous_factor").data()
      )
      .def_property_readonly(
         "imaginary_anomalous_factor",
         [](const Component &self) { return self.imaginaryAnomalousFactor(); },
         Component::documentation("imaginary_anomalous_factor").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_mean
} // namespace python_v2_0
