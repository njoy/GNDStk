
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/transport/ReactionSuite.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_transport {

// ReactionSuite wrapper
void wrapReactionSuite(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = transport::ReactionSuite;

   // create the component
   python::class_<Component> component(
      module,
      "ReactionSuite",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const XMLName &,
            const XMLName &,
            const XMLName &,
            const enums::Frame &,
            const XMLName &,
            const enums::Interaction &,
            const std::optional<common::ExternalFiles> &,
            const styles::Styles &,
            const pops::PoPs_database &,
            const std::optional<resonances::Resonances> &,
            const std::optional<transport::Reactions> &,
            const std::optional<transport::OrphanProducts> &,
            const std::optional<transport::Sums> &,
            const std::optional<fissionTransport::FissionComponents> &,
            const std::optional<transport::Productions> &,
            const std::optional<transport::IncompleteReactions> &,
            const std::optional<appData::ApplicationData> &
         >(),
         python::arg("evaluation"),
         python::arg("format"),
         python::arg("projectile"),
         python::arg("projectile_frame"),
         python::arg("target"),
         python::arg("interaction"),
         python::arg("external_files") = std::nullopt,
         python::arg("styles"),
         python::arg("po_ps"),
         python::arg("resonances") = std::nullopt,
         python::arg("reactions") = std::nullopt,
         python::arg("orphan_products") = std::nullopt,
         python::arg("sums") = std::nullopt,
         python::arg("fission_components") = std::nullopt,
         python::arg("productions") = std::nullopt,
         python::arg("incomplete_reactions") = std::nullopt,
         python::arg("application_data") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "evaluation",
         [](const Component &self) { return self.evaluation(); },
         Component::documentation("evaluation").data()
      )
      .def_property_readonly(
         "format",
         [](const Component &self) { return self.format(); },
         Component::documentation("format").data()
      )
      .def_property_readonly(
         "projectile",
         [](const Component &self) { return self.projectile(); },
         Component::documentation("projectile").data()
      )
      .def_property_readonly(
         "projectile_frame",
         [](const Component &self) { return self.projectileFrame(); },
         Component::documentation("projectile_frame").data()
      )
      .def_property_readonly(
         "target",
         [](const Component &self) { return self.target(); },
         Component::documentation("target").data()
      )
      .def_property_readonly(
         "interaction",
         [](const Component &self) { return self.interaction(); },
         Component::documentation("interaction").data()
      )
      .def_property_readonly(
         "external_files",
         [](const Component &self) { return self.externalFiles(); },
         Component::documentation("external_files").data()
      )
      .def_property_readonly(
         "styles",
         [](const Component &self) { return self.styles(); },
         Component::documentation("styles").data()
      )
      .def_property_readonly(
         "po_ps",
         [](const Component &self) { return self.PoPs(); },
         Component::documentation("po_ps").data()
      )
      .def_property_readonly(
         "resonances",
         [](const Component &self) { return self.resonances(); },
         Component::documentation("resonances").data()
      )
      .def_property_readonly(
         "reactions",
         [](const Component &self) { return self.reactions(); },
         Component::documentation("reactions").data()
      )
      .def_property_readonly(
         "orphan_products",
         [](const Component &self) { return self.orphanProducts(); },
         Component::documentation("orphan_products").data()
      )
      .def_property_readonly(
         "sums",
         [](const Component &self) { return self.sums(); },
         Component::documentation("sums").data()
      )
      .def_property_readonly(
         "fission_components",
         [](const Component &self) { return self.fissionComponents(); },
         Component::documentation("fission_components").data()
      )
      .def_property_readonly(
         "productions",
         [](const Component &self) { return self.productions(); },
         Component::documentation("productions").data()
      )
      .def_property_readonly(
         "incomplete_reactions",
         [](const Component &self) { return self.incompleteReactions(); },
         Component::documentation("incomplete_reactions").data()
      )
      .def_property_readonly(
         "application_data",
         [](const Component &self) { return self.applicationData(); },
         Component::documentation("application_data").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_transport
} // namespace python_v2_0
