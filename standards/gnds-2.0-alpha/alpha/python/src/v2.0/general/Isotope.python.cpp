
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Isotope.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// Isotope wrapper
void wrapIsotope(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::Isotope;

   // create the component
   python::class_<Component> component(
      module, "Isotope",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::string &,
            const int &,
            const general::Nuclides &
         >(),
         python::arg("symbol"),
         python::arg("a"),
         python::arg("nuclides"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "symbol",
         [](const Component &self)
         {
            return self.symbol();
         },
         Component::documentation("symbol").data()
      )
      .def_property_readonly(
         "a",
         [](const Component &self)
         {
            return self.A();
         },
         Component::documentation("a").data()
      )
      .def_property_readonly(
         "nuclides",
         [](const Component &self)
         {
            return self.nuclides();
         },
         Component::documentation("nuclides").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions<Component>(component);
}

} // namespace python_general
} // namespace python_v2_0
