
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/pops/Isotopes.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_pops {

// Isotopes wrapper
void wrapIsotopes(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = pops::Isotopes;

   // create the component
   python::class_<Component> component(
      module,
      "Isotopes",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::vector<pops::Isotope> &
         >(),
         python::arg("isotope"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "isotope",
         [](const Component &self) { return self.isotope(); },
         Component::documentation("isotope").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_pops
} // namespace python_v2_0
