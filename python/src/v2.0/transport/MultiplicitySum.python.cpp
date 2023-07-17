
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/transport/MultiplicitySum.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_transport {

// MultiplicitySum wrapper
void wrapMultiplicitySum(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = transport::MultiplicitySum;

   // create the component
   python::class_<Component> component(
      module,
      "MultiplicitySum",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<Integer32> &,
            const XMLName &,
            const transport::Multiplicity &,
            const transport::Summands &
         >(),
         python::arg("endf_mt") = std::nullopt,
         python::arg("label"),
         python::arg("multiplicity"),
         python::arg("summands"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "endf_mt",
         &Component::ENDF_MT,
         Component::documentation("endf_mt").data()
      )
      .def_property_readonly(
         "label",
         &Component::label,
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "multiplicity",
         python::overload_cast<>(&Component::multiplicity),
         Component::documentation("multiplicity").data()
      )
      .def_property_readonly(
         "summands",
         python::overload_cast<>(&Component::summands),
         Component::documentation("summands").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_transport
} // namespace python_v2_0
