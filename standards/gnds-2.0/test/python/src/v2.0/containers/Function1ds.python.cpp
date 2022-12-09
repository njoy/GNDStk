
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/containers/Function1ds.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_containers {

// Function1ds wrapper
void wrapFunction1ds(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = containers::Function1ds;
   using _t = std::variant<
      containers::XYs1d,
      containers::Constant1d,
      containers::Polynomial1d,
      containers::Legendre,
      containers::Gridded1d
   >;

   // create the component
   python::class_<Component> component(
      module,
      "Function1ds",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::vector<_t> &
         >(),
         python::arg("_xys1dconstant1dpolynomial1d_legendregridded1d"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "_xys1dconstant1dpolynomial1d_legendregridded1d",
         [](const Component &self) { return self._XYs1dconstant1dpolynomial1dLegendregridded1d(); },
         Component::documentation("_xys1dconstant1dpolynomial1d_legendregridded1d").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_containers
} // namespace python_v2_0
