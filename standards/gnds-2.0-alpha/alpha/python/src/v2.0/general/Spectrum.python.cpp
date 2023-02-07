
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Spectrum.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// Spectrum wrapper
void wrapSpectrum(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::Spectrum;

   // create the component
   python::class_<Component> component(
      module, "Spectrum",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::string &,
            const std::string &,
            const std::vector<general::Discrete> &,
            const std::optional<general::Continuum> &
         >(),
         python::arg("label"),
         python::arg("pid"),
         python::arg("discrete"),
         python::arg("continuum") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self)
         {
            return self.label();
         },
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "pid",
         [](const Component &self)
         {
            return self.pid();
         },
         Component::documentation("pid").data()
      )
      .def_property_readonly(
         "discrete",
         [](const Component &self)
         {
            return self.discrete();
         },
         Component::documentation("discrete").data()
      )
      .def_property_readonly(
         "continuum",
         [](const Component &self)
         {
            return self.continuum();
         },
         Component::documentation("continuum").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions<Component>(component);
}

} // namespace python_general
} // namespace python_v2_0
