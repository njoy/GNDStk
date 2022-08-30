
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/processed/MultiGroup3d.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_processed {

// MultiGroup3d wrapper
void wrapMultiGroup3d(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = processed::MultiGroup3d;

   // create the component
   python::class_<Component> component(
      module,
      "MultiGroup3d",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const XMLName &,
            const XMLName &,
            const containers::Gridded3d &
         >(),
         python::arg("label"),
         python::arg("product_frame"),
         python::arg("gridded3d"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self) { return self.label(); },
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "product_frame",
         [](const Component &self) { return self.productFrame(); },
         Component::documentation("product_frame").data()
      )
      .def_property_readonly(
         "gridded3d",
         [](const Component &self) { return self.gridded3d(); },
         Component::documentation("gridded3d").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_processed
} // namespace python_v2_0
