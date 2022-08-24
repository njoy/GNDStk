
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/documentation/Date.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_documentation {

// Date wrapper
void wrapDate(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = documentation::Date;

   // create the component
   python::class_<Component> component(
      module,
      "Date",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const enums::DateType &
         >(),
         python::arg("date_type"),
         Component::documentation("constructor").data()
      )
      .def(
         python::init<
            const std::vector<int> &
         >(),
         python::arg("ints"),
         Component::documentation("constructor").data()
      )
      .def(
         python::init<
            const std::vector<double> &
         >(),
         python::arg("doubles"),
         Component::documentation("constructor").data()
      )
      .def(
         python::init<
            const std::vector<std::string> &
         >(),
         python::arg("strings"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "date_type",
         &Component::dateType,
         Component::documentation("date_type").data()
      )
      .def_property_readonly(
         "ints",
         [] (const Component &self) { return self.ints(); },
         Component::documentation("ints").data()
      )
      .def_property_readonly(
         "doubles",
         [] (const Component &self) { return self.doubles(); },
         Component::documentation("doubles").data()
      )
      .def_property_readonly(
         "strings",
         [] (const Component &self) { return self.strings(); },
         Component::documentation("strings").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_documentation
} // namespace python_v2_0