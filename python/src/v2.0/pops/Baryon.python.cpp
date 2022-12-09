
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/pops/Baryon.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_pops {

// Baryon wrapper
void wrapBaryon(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = pops::Baryon;

   // create the component
   python::class_<Component> component(
      module,
      "Baryon",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const XMLName &,
            const std::optional<pops::Charge> &,
            const std::optional<pops::DecayData> &,
            const std::optional<pops::Halflife> &,
            const std::optional<pops::Mass> &,
            const std::optional<pops::Parity> &,
            const std::optional<pops::Spin> &
         >(),
         python::arg("id"),
         python::arg("charge") = std::nullopt,
         python::arg("decay_data") = std::nullopt,
         python::arg("halflife") = std::nullopt,
         python::arg("mass") = std::nullopt,
         python::arg("parity") = std::nullopt,
         python::arg("spin") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "id",
         &Component::id,
         Component::documentation("id").data()
      )
      .def_property_readonly(
         "charge",
         python::overload_cast<>(&Component::charge),
         Component::documentation("charge").data()
      )
      .def_property_readonly(
         "decay_data",
         python::overload_cast<>(&Component::decayData),
         Component::documentation("decay_data").data()
      )
      .def_property_readonly(
         "halflife",
         python::overload_cast<>(&Component::halflife),
         Component::documentation("halflife").data()
      )
      .def_property_readonly(
         "mass",
         python::overload_cast<>(&Component::mass),
         Component::documentation("mass").data()
      )
      .def_property_readonly(
         "parity",
         python::overload_cast<>(&Component::parity),
         Component::documentation("parity").data()
      )
      .def_property_readonly(
         "spin",
         python::overload_cast<>(&Component::spin),
         Component::documentation("spin").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_pops
} // namespace python_v2_0
