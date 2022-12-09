
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "code/v2.0/gnds/Dates.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_gnds {

// Dates wrapper
void wrapDates(python::module &module)
{
   using namespace code;
   using namespace code::v2_0;

   // type aliases
   using Component = gnds::Dates;

   // create the component
   python::class_<Component> component(
      module,
      "Dates",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::vector<gnds::Date> &
         >(),
         python::arg("date"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "date",
         [](const Component &self) { return self.date(); },
         Component::documentation("date").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_gnds
} // namespace python_v2_0
