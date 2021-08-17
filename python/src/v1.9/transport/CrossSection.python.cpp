
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v1.9/transport/CrossSection.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v1_9 {
namespace python_transport {

// CrossSection wrapper
void wrapCrossSection(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v1_9;

   // type aliases
   using Component = transport::CrossSection;
   using XYS1D_REGIONS1D = std::variant<
      containers::XYs1d,
      containers::Regions1d
   >;

   // create the component
   python::class_<Component> component(
      module,
      "CrossSection",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::vector<XYS1D_REGIONS1D> &
         >(),
         python::arg("xys1d_regions1d"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "xys1d_regions1d",
         python::overload_cast<>(&Component::XYs1d_regions1d),
         Component::documentation("xys1d_regions1d").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_transport
} // namespace python_v1_9
