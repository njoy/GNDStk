
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/fissionTransport/FissionComponent.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_fissionTransport {

// wrapper for fissionTransport::FissionComponent
void wrapFissionComponent(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = fissionTransport::FissionComponent;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "FissionComponent",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<Integer32> &,
         const XMLName &,
         const XMLName &,
         const std::optional<transport::CrossSection> &,
         const std::optional<transport::OutputChannel> &
      >(),
      py::arg("endf_mt") = std::nullopt,
      py::arg("fission_genre"),
      py::arg("label"),
      py::arg("cross_section") = std::nullopt,
      py::arg("output_channel") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set ENDF_MT
   object.def_property(
      "endf_mt",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.ENDF_MT();
      },
      [](cppCLASS &self, const std::optional<Integer32> &value)
      {
         self.ENDF_MT() = value;
      },
      cppCLASS::component_t::documentation("endf_mt").data()
   );

   // get/set fissionGenre
   object.def_property(
      "fission_genre",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.fissionGenre();
      },
      [](cppCLASS &self, const XMLName &value)
      {
         self.fissionGenre() = value;
      },
      cppCLASS::component_t::documentation("fission_genre").data()
   );

   // get/set label
   object.def_property(
      "label",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.label();
      },
      [](cppCLASS &self, const XMLName &value)
      {
         self.label() = value;
      },
      cppCLASS::component_t::documentation("label").data()
   );

   // get/set crossSection
   object.def_property(
      "cross_section",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.crossSection();
      },
      [](cppCLASS &self, const std::optional<transport::CrossSection> &value)
      {
         self.crossSection() = value;
      },
      cppCLASS::component_t::documentation("cross_section").data()
   );

   // get/set outputChannel
   object.def_property(
      "output_channel",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.outputChannel();
      },
      [](cppCLASS &self, const std::optional<transport::OutputChannel> &value)
      {
         self.outputChannel() = value;
      },
      cppCLASS::component_t::documentation("output_channel").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_fissionTransport
} // namespace python_v2_0
