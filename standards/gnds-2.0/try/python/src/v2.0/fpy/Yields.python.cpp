
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/fpy/Yields.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_fpy {

// Yields wrapper
void wrapYields(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = fpy::Yields;

   // create the component
   python::class_<Component> component(
      module,
      "Yields",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const fpy::Nuclides &,
            const unknownNamespace::Values &,
            const std::optional<pops::Uncertainty> &
         >(),
         python::arg("nuclides"),
         python::arg("values"),
         python::arg("uncertainty") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "nuclides",
         [](const Component &self) { return self.nuclides(); },
         Component::documentation("nuclides").data()
      )
      .def_property_readonly(
         "values",
         [](const Component &self) { return self.values(); },
         Component::documentation("values").data()
      )
      .def_property_readonly(
         "uncertainty",
         [](const Component &self) { return self.uncertainty(); },
         Component::documentation("uncertainty").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_fpy
} // namespace python_v2_0
