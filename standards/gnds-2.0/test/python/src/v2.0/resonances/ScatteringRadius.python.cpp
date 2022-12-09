
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/resonances/ScatteringRadius.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_resonances {

// ScatteringRadius wrapper
void wrapScatteringRadius(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = resonances::ScatteringRadius;
   using _t = std::variant<
      containers::Constant1d,
      containers::XYs1d,
      containers::Regions1d
   >;

   // create the component
   python::class_<Component> component(
      module,
      "ScatteringRadius",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const _t &
         >(),
         python::arg("_constant1d_xys1dregions1d"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "constant1d",
         [](const Component &self) { return self.constant1d(); },
         Component::documentation("constant1d").data()
      )
      .def_property_readonly(
         "xys1d",
         [](const Component &self) { return self.XYs1d(); },
         Component::documentation("xys1d").data()
      )
      .def_property_readonly(
         "regions1d",
         [](const Component &self) { return self.regions1d(); },
         Component::documentation("regions1d").data()
      )
      .def_property_readonly(
         "_constant1d_xys1dregions1d",
         [](const Component &self) { return self._constant1dXYs1dregions1d(); },
         Component::documentation("_constant1d_xys1dregions1d").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_resonances
} // namespace python_v2_0
