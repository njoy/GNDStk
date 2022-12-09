
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/common/Product.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_common {

// Product wrapper
void wrapProduct(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = common::Product;

   // create the component
   python::class_<Component> component(
      module,
      "Product",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const XMLName &,
            const XMLName &,
            const transport::Distribution &,
            const transport::Multiplicity &,
            const std::optional<transport::OutputChannel> &
         >(),
         python::arg("label"),
         python::arg("pid"),
         python::arg("distribution"),
         python::arg("multiplicity"),
         python::arg("output_channel") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         &Component::label,
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "pid",
         &Component::pid,
         Component::documentation("pid").data()
      )
      .def_property_readonly(
         "distribution",
         python::overload_cast<>(&Component::distribution),
         Component::documentation("distribution").data()
      )
      .def_property_readonly(
         "multiplicity",
         python::overload_cast<>(&Component::multiplicity),
         Component::documentation("multiplicity").data()
      )
      .def_property_readonly(
         "output_channel",
         python::overload_cast<>(&Component::outputChannel),
         Component::documentation("output_channel").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_common
} // namespace python_v2_0
