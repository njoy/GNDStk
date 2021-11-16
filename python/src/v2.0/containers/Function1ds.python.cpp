
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/containers/Function1ds.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_containers {

// Function1ds wrapper
void wrapFunction1ds(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = containers::Function1ds;
   using _t = std::variant<
      containers::Legendre,
      containers::XYs1d,
      containers::Constant1d,
      containers::Gridded1d,
      containers::Polynomial1d
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
         python::arg("_legendre_xys1dconstant1dgridded1dpolynomial1d"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "_legendre_xys1dconstant1dgridded1dpolynomial1d",
         python::overload_cast<>(&Component::_LegendreXYs1dconstant1dgridded1dpolynomial1d),
         Component::documentation("_legendre_xys1dconstant1dgridded1dpolynomial1d").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_containers
} // namespace python_v2_0