
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/containers/Cdf_in_xs_pdf_cdf1d.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_containers {

// Cdf_in_xs_pdf_cdf1d wrapper
void wrapCdf_in_xs_pdf_cdf1d(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = containers::Cdf_in_xs_pdf_cdf1d;

   // create the component
   python::class_<Component> component(
      module,
      "Cdf_in_xs_pdf_cdf1d",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const containers::Values &
         >(),
         python::arg("values"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "values",
         [](const Component &self) { return self.values(); },
         Component::documentation("values").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_containers
} // namespace python_v2_0