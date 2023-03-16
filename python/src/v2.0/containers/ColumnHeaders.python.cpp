
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/containers/ColumnHeaders.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_containers {

// ColumnHeaders wrapper
void wrapColumnHeaders(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = containers::ColumnHeaders;

   // create the component
   python::class_<Component> component(
      module,
      "ColumnHeaders",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::vector<containers::Column> &
         >(),
         python::arg("column"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "column",
         python::overload_cast<>(&Component::column),
         Component::documentation("column").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_containers
} // namespace python_v2_0
