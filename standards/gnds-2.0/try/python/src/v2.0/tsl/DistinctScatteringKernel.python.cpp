
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/tsl/DistinctScatteringKernel.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_tsl {

// DistinctScatteringKernel wrapper
void wrapDistinctScatteringKernel(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = tsl::DistinctScatteringKernel;

   // create the component
   python::class_<Component> component(
      module,
      "DistinctScatteringKernel",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<unknownNamespace::Gridded3d> &
         >(),
         python::arg("gridded3d") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "gridded3d",
         [](const Component &self) { return self.gridded3d(); },
         Component::documentation("gridded3d").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_tsl
} // namespace python_v2_0
