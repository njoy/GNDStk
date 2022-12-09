
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/transport/F.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_transport {

// F wrapper
void wrapF(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = transport::F;
   using _t = std::variant<
      containers::XYs2d,
      containers::Regions2d
   >;

   // create the component
   python::class_<Component> component(
      module,
      "F",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const _t &
         >(),
         python::arg("_xys2dregions2d"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "xys2d",
         [](const Component &self) { return self.XYs2d(); },
         Component::documentation("xys2d").data()
      )
      .def_property_readonly(
         "regions2d",
         [](const Component &self) { return self.regions2d(); },
         Component::documentation("regions2d").data()
      )
      .def_property_readonly(
         "_xys2dregions2d",
         [](const Component &self) { return self._XYs2dregions2d(); },
         Component::documentation("_xys2dregions2d").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_transport
} // namespace python_v2_0
