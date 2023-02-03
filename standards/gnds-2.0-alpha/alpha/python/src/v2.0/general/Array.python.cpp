
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Array.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// Array wrapper
void wrapArray(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::Array;

   // create the component
   python::class_<Component> component(
      module,
      "Array",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::string &,
            const std::optional<std::string> &,
            const general::Values &
         >(),
         python::arg("shape"),
         python::arg("compression") = std::nullopt,
         python::arg("values"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "shape",
         [](const Component &self) { return self.shape(); },
         Component::documentation("shape").data()
      )
      .def_property_readonly(
         "compression",
         [](const Component &self) { return self.compression(); },
         Component::documentation("compression").data()
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

} // namespace python_general
} // namespace python_v2_0
