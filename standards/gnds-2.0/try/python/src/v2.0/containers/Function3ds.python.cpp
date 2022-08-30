
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/containers/Function3ds.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_containers {

// Function3ds wrapper
void wrapFunction3ds(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = containers::Function3ds;
   using _t = std::variant<
      containers::XYs3d,
      containers::Gridded3d
   >;

   // create the component
   python::class_<Component> component(
      module,
      "Function3ds",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::vector<_t> &
         >(),
         python::arg("_xys3dgridded3d"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "_xys3dgridded3d",
         [](const Component &self) { return self._XYs3dgridded3d(); },
         Component::documentation("_xys3dgridded3d").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_containers
} // namespace python_v2_0
