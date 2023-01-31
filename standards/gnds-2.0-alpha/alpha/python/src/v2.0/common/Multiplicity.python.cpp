
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/common/Multiplicity.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_common {

// Multiplicity wrapper
void wrapMultiplicity(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = common::Multiplicity;

   // create the component
   python::class_<Component> component(
      module,
      "Multiplicity",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<common::Constant1d> &,
            const std::optional<common::XYs1d> &,
            const std::optional<mean::Regions1d> &,
            const std::optional<common::Polynomial1d> &,
            const std::optional<mean::Reference> &,
            const std::optional<mean::Branching1d> &,
            const std::optional<mean::Branching3d> &,
            const std::optional<mean::Unspecified> &
         >(),
         python::arg("constant1d") = std::nullopt,
         python::arg("xys1d") = std::nullopt,
         python::arg("regions1d") = std::nullopt,
         python::arg("polynomial1d") = std::nullopt,
         python::arg("reference") = std::nullopt,
         python::arg("branching1d") = std::nullopt,
         python::arg("branching3d") = std::nullopt,
         python::arg("unspecified") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "constant1d",
         [](const Component &self) { return self.constant1d(); },
         Component::documentation("constant1d").data()
      )
      .def_property_readonly(
         "xys1d",
         [](const Component &self) { return self.XYs1d(); },
         Component::documentation("xys1d").data()
      )
      .def_property_readonly(
         "regions1d",
         [](const Component &self) { return self.regions1d(); },
         Component::documentation("regions1d").data()
      )
      .def_property_readonly(
         "polynomial1d",
         [](const Component &self) { return self.polynomial1d(); },
         Component::documentation("polynomial1d").data()
      )
      .def_property_readonly(
         "reference",
         [](const Component &self) { return self.reference(); },
         Component::documentation("reference").data()
      )
      .def_property_readonly(
         "branching1d",
         [](const Component &self) { return self.branching1d(); },
         Component::documentation("branching1d").data()
      )
      .def_property_readonly(
         "branching3d",
         [](const Component &self) { return self.branching3d(); },
         Component::documentation("branching3d").data()
      )
      .def_property_readonly(
         "unspecified",
         [](const Component &self) { return self.unspecified(); },
         Component::documentation("unspecified").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_common
} // namespace python_v2_0
