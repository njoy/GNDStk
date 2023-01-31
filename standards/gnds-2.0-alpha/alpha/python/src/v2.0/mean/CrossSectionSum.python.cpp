
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/mean/CrossSectionSum.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_mean {

// CrossSectionSum wrapper
void wrapCrossSectionSum(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = mean::CrossSectionSum;

   // create the component
   python::class_<Component> component(
      module,
      "CrossSectionSum",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::string &,
            const int &,
            const mean::Summands &,
            const common::Q &,
            const common::CrossSection &
         >(),
         python::arg("label"),
         python::arg("endf_mt"),
         python::arg("summands"),
         python::arg("q"),
         python::arg("cross_section"),
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
         "summands",
         [](const Component &self) { return self.summands(); },
         Component::documentation("summands").data()
      )
      .def_property_readonly(
         "q",
         [](const Component &self) { return self.Q(); },
         Component::documentation("q").data()
      )
      .def_property_readonly(
         "cross_section",
         [](const Component &self) { return self.crossSection(); },
         Component::documentation("cross_section").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_mean
} // namespace python_v2_0
