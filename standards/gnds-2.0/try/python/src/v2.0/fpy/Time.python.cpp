
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/fpy/Time.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_fpy {

// Time wrapper
void wrapTime(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = fpy::Time;
   using _t = std::variant<
      containers::Double,
      containers::String
   >;

   // create the component
   python::class_<Component> component(
      module,
      "Time",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const _t &
         >(),
         python::arg("_doublestring"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "double",
         [](const Component &self) { return self.Double(); },
         Component::documentation("double").data()
      )
      .def_property_readonly(
         "string",
         [](const Component &self) { return self.string(); },
         Component::documentation("string").data()
      )
      .def_property_readonly(
         "_doublestring",
         [](const Component &self) { return self._Doublestring(); },
         Component::documentation("_doublestring").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_fpy
} // namespace python_v2_0