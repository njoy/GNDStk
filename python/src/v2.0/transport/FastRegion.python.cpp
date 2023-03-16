
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/transport/FastRegion.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_transport {

// FastRegion wrapper
void wrapFastRegion(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = transport::FastRegion;
   using _t = std::variant<
      containers::XYs1d,
      containers::Regions1d
   >;

   // create the component
   python::class_<Component> component(
      module,
      "FastRegion",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const _t &
         >(),
         python::arg("_xys1dregions1d"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "xys1d",
         python::overload_cast<>(&Component::XYs1d),
         Component::documentation("xys1d").data()
      )
      .def_property_readonly(
         "regions1d",
         python::overload_cast<>(&Component::regions1d),
         Component::documentation("regions1d").data()
      )
      .def_property_readonly(
         "_xys1dregions1d",
         python::overload_cast<>(&Component::_XYs1dregions1d),
         Component::documentation("_xys1dregions1d").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_transport
} // namespace python_v2_0
