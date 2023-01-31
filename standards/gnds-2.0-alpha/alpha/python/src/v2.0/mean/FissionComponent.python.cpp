
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/mean/FissionComponent.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_mean {

// FissionComponent wrapper
void wrapFissionComponent(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = mean::FissionComponent;

   // create the component
   python::class_<Component> component(
      module,
      "FissionComponent",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::string &,
            const int &,
            const std::string &,
            const common::CrossSection &,
            const common::OutputChannel &
         >(),
         python::arg("label"),
         python::arg("endf_mt"),
         python::arg("fission_genre"),
         python::arg("cross_section"),
         python::arg("output_channel"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self) { return self.label(); },
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "endf_mt",
         [](const Component &self) { return self.ENDF_MT(); },
         Component::documentation("endf_mt").data()
      )
      .def_property_readonly(
         "fission_genre",
         [](const Component &self) { return self.fissionGenre(); },
         Component::documentation("fission_genre").data()
      )
      .def_property_readonly(
         "cross_section",
         [](const Component &self) { return self.crossSection(); },
         Component::documentation("cross_section").data()
      )
      .def_property_readonly(
         "output_channel",
         [](const Component &self) { return self.outputChannel(); },
         Component::documentation("output_channel").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_mean
} // namespace python_v2_0
