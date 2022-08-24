
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/styles/AverageProductData.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_styles {

// AverageProductData wrapper
void wrapAverageProductData(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = styles::AverageProductData;

   // create the component
   python::class_<Component> component(
      module,
      "AverageProductData",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::string &,
            const std::optional<XMLName> &,
            const XMLName &,
            const std::optional<documentation::Documentation> &,
            const styles::Temperature &
         >(),
         python::arg("date"),
         python::arg("derived_from") = std::nullopt,
         python::arg("label"),
         python::arg("documentation") = std::nullopt,
         python::arg("temperature"),
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
      .def_property_readonly(
         "documentation",
         python::overload_cast<>(&Component::documentation),
         Component::documentation("documentation").data()
      )
      .def_property_readonly(
         "temperature",
         python::overload_cast<>(&Component::temperature),
         Component::documentation("temperature").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_styles
} // namespace python_v2_0