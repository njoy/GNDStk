
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/pops/Baryon.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_pops {

// Baryon wrapper
void wrapBaryon(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

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
            const std::optional<pops::Halflife> &,
            const std::optional<pops::Mass> &,
            const std::optional<pops::Spin> &,
            const std::optional<pops::Parity> &,
            const std::optional<pops::DecayData> &
         >(),
         python::arg("id"),
         python::arg("charge") = std::nullopt,
         python::arg("halflife") = std::nullopt,
         python::arg("mass") = std::nullopt,
         python::arg("spin") = std::nullopt,
         python::arg("parity") = std::nullopt,
         python::arg("decay_data") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "id",
         [](const Component &self) { return self.id(); },
         Component::documentation("id").data()
      )
      .def_property_readonly(
         "charge",
         [](const Component &self) { return self.charge(); },
         Component::documentation("charge").data()
      )
      .def_property_readonly(
         "halflife",
         [](const Component &self) { return self.halflife(); },
         Component::documentation("halflife").data()
      )
      .def_property_readonly(
         "mass",
         [](const Component &self) { return self.mass(); },
         Component::documentation("mass").data()
      )
      .def_property_readonly(
         "spin",
         [](const Component &self) { return self.spin(); },
         Component::documentation("spin").data()
      )
      .def_property_readonly(
         "parity",
         [](const Component &self) { return self.parity(); },
         Component::documentation("parity").data()
      )
      .def_property_readonly(
         "decay_data",
         [](const Component &self) { return self.decayData(); },
         Component::documentation("decay_data").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_pops
} // namespace python_v2_0