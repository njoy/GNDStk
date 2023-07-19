
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/styles/URR_probabilityTables.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_styles {

// URR_probabilityTables wrapper
void wrapURR_probabilityTables(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = styles::URR_probabilityTables;

   // create the component
   python::class_<Component> component(
      module,
      "URR_probabilityTables",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::string &,
            const XMLName &,
            const XMLName &
         >(),
         python::arg("date"),
         python::arg("derived_from"),
         python::arg("label"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "date",
         &Component::date,
         Component::documentation("date").data()
      )
      .def_property_readonly(
         "derived_from",
         &Component::derivedFrom,
         Component::documentation("derived_from").data()
      )
      .def_property_readonly(
         "label",
         &Component::label,
         Component::documentation("label").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_styles
} // namespace python_v2_0
